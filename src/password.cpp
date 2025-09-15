/*********************************************************************************************************************************
 *                                                                                                                   ;           *
 *                                                                                                                  ED.          *
 *                        ,;                             ,;                                                  :      E#Wi         *
 *                      f#i          .    .            f#i j.         t                                      Ef     E###G.       *
 *             ..     .E#t  GEEEEEEELDi   Dt         .E#t  EW,        Ej             ..           ..       : E#t    E#fD#W;      *
 *            ;W,    i#W,   ,;;L#K;;.E#i  E#i       i#W,   E##j       E#,           ;W,          ,W,     .Et E#t    E#t t##L     *
 *           j##,   L#D.       t#E   E#t  E#t      L#D.    E###D.     E#t          j##,         t##,    ,W#t E#t    E#t  .E#K,   *
 *          G###, :K#Wfff;     t#E   E#t  E#t    :K#Wfff;  E#jG#W;    E#t         G###,        L###,   j###t E#t fi E#t    j##f  *
 *        :E####, i##WLLLLt    t#E   E########f. i##WLLLLt E#t t##f   E#t       :E####,      .E#j##,  G#fE#t E#t L#jE#t    :E#K: *
 *       ;W#DG##,  .E#L        t#E   E#j..K#j...  .E#L     E#t  :K#E: E#t      ;W#DG##,     ;WW; ##,:K#i E#t E#t L#LE#t   t##L   *
 *      j###DW##,    f#E:      t#E   E#t  E#t       f#E:   E#KDDDD###iE#t     j###DW##,    j#E.  ##f#W,  E#t E#tf#E:E#t .D#W;    *
 *     G##i,,G##,     ,WW;     t#E   E#t  E#t        ,WW;  E#f,t#Wi,,,E#t    G##i,,G##,  .D#L    ###K:   E#t E###f  E#tiW#G.     *
 *   :K#K:   L##,      .D#;    t#E   f#t  f#t         .D#; E#t  ;#W:  E#t  :K#K:   L##, :K#t     ##D.    E#t E#K,   E#K##i       *
 *  ;##D.    L##,        tt     fE    ii   ii           tt DWi   ,KK: E#t ;##D.    L##, ...      #G      ..  EL     E##D.        *
 *  ,,,      .,,                 :                                    ,;. ,,,      .,,           j           :      E#t          *
 *                                                                                                                  L:           *
 *********************************************************************************************************************************
 *                                                                                                                               *
 *                 Modern password hashing using Argon2 for improved security - /dev/null Industries                             * 
 *                                 Argon2 - https://argon2-cffi.readthedocs.io/en/stable/                                        *
 *                               Commented fully for better understanding on how this works.                                     *
 *********************************************************************************************************************************/

#include <string>
#include <vector>
#include <cstring>
#include <cstdint>
#include <cstdlib>
#include <cstdio>
#include <unistd.h>
#include <fcntl.h>
#include <argon2.h>
#include "password.hpp"
#include "mud.hpp"

/*
 * Security Notes:
 * This implementation uses Argon2id for password hashing, which provides significantly
 * better security than traditional crypt() functions. Key advantages include:
 *
 * 1. Memory-hard algorithm: Argon2 requires substantial memory usage, making it resistant
 *    to hardware-accelerated attacks using GPUs or ASICs.
 *
 * 2. Configurable parameters: Time cost (iterations), memory cost, and parallelism can be
 *    tuned to balance security with performance based on system capabilities.
 *
 * 3. Resistance to rainbow tables: Unique salts and the algorithm's complexity make
 *    precomputed attacks impractical.
 *
 * 4. Future-proof: Argon2 was selected as the winner of the Password Hashing Competition
 *    and is designed to remain secure against emerging threats.
 *
 * 5. Migration support: Legacy crypt() hashes are automatically verified and can be
 *    upgraded to Argon2 during password changes for backward compatibility.
 *
 * Unlike basic crypt() which uses simple hashing algorithms vulnerable to brute-Force
 * and dictionary attacks, Argon2 provides robust protection against modern attack vectors.
 */

namespace {
    // Argon2id configuration constants
    constexpr uint32_t Argon2TimeCost = 3;        // iterations
    constexpr uint32_t Argon2MemoryCost = 1 << 16; // memory in KiB (64 MiB)
    constexpr uint32_t Argon2Parallelism = 1;       // lanes
    constexpr size_t SaltLength = 16;               // 128-bit salt
    constexpr size_t HashLength = 32;               // 256-bit hash
    constexpr const char* Argon2Prefix = "$argon2id$";
    
    /**
     * @brief Generate cryptographically secure random bytes
     * @param buffer Buffer to fill with random data
     * @param length Number of bytes to generate
     * @return true on success, false on failure
     */
    bool generate_secure_random(uint8_t* buffer, size_t length) {
        int Fd = ::open("/dev/urandom", O_RDONLY);
        if (Fd >= 0) {
            ssize_t bytes_read = ::read(Fd, buffer, length);
            ::close(Fd);
            if (bytes_read == static_cast<ssize_t>(length)) {
                return true;
            }
        }
        
        // Fallback to stdlib rand (less secure but functional)
        for (size_t i = 0; i < length; ++i) {
            buffer[i] = static_cast<uint8_t>(rand() & 0xFF);
        }
        return false;
    }
}

std::string hash_password(std::string_view password, std::string_view salt_in) {
    // Prepare salt bytes (if provided, use those bytes; else create random bytes)
    std::vector<uint8_t> salt_bytes;
    if (!salt_in.empty()) {
        salt_bytes.assign(salt_in.begin(), salt_in.end());
    } else {
        salt_bytes.resize(SaltLength);
        generate_secure_random(salt_bytes.data(), SaltLength);
    }

    // Compute required encoded length and allocate string buffer
    size_t encoded_len = argon2_encodedlen(Argon2TimeCost, Argon2MemoryCost,
                                           Argon2Parallelism, salt_bytes.size(),
                                           HashLength, Argon2_id);
    std::string encoded;
    encoded.resize(encoded_len);

    int rc = argon2id_hash_encoded(Argon2TimeCost, Argon2MemoryCost, Argon2Parallelism,
                                   password.data(), password.size(),
                                   salt_bytes.data(), salt_bytes.size(),
                                   HashLength,
                                   &encoded[0], encoded_len);
    if (rc != Argon2Ok) {
        bug("argon2id_hash_encoded failed: %s", argon2_error_message(rc));
        return std::string();
    }

    // Resize to actual length (encoded is NUL-terminated C string)
    encoded.resize(strlen(encoded.c_str()));
    return encoded;
}
// Verify a password against a stored hash (supports Argon2 and legacy crypt)
bool verify_password(std::string_view password, std::string_view stored_hash) {
    if (password.empty() || stored_hash.empty()) {
        return false;
    }

    // Check if this is an Argon2 hash
    if (stored_hash.substr(0, strlen(Argon2Prefix)) == Argon2Prefix) {
        int rc = argon2id_verify(stored_hash.data(), password.data(), password.size());
        return rc == Argon2Ok;
    } else {
        // Legacy verification using crypt
        const char* encrypted = crypt(password.data(), stored_hash.data());
        return encrypted && (strcmp(encrypted, stored_hash.data()) == 0);
    }
}
// Generate a new random salt (for legacy crypt, if needed)
std::string generate_salt() {
    std::string salt;
    salt.resize(SaltLength);
    generate_secure_random(reinterpret_cast<uint8_t*>(&salt[0]), SaltLength);
    return salt;
}
// Migrate a password from legacy crypt to Argon2 (if it matches)
std::string migrate_password(std::string_view password, std::string_view old_hash) {
    if (password.empty() || old_hash.empty()) {
        return old_hash.empty() ? std::string() : std::string(old_hash);
    }

    // First verify the password against the old hash
    const char* encrypted = crypt(password.data(), old_hash.data());
    if (!encrypted || strcmp(encrypted, old_hash.data()) != 0) {
        // Password doesn't match the old hash, return unchanged
        return std::string(old_hash);
    }

    // Create a new Argon2 hash
    return hash_password(password);
}

// Utility function to check if we should upgrade a password hash
bool should_upgrade_hash(std::string_view hash) {
    // If it doesn't start with the Argon2 prefix, it needs to be upgraded
    return hash.empty() || hash.substr(0, strlen(Argon2Prefix)) != Argon2Prefix;
}
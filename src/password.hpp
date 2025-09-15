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
#pragma once
#include <string>

/**
 * @file password.hpp
 * @brief Modern Argon2-based password hashing for enhanced security
 * 
 * This module provides secure password hashing using Argon2id, which offers
 * significant security improvements over traditional crypt() functions:
 * - Memory-hard algorithm resistant to GPU/ASIC attacks
 * - Configurable time/memory costs for performance tuning
 * - Automatic salt generation and management
 * - Backward compatibility with legacy crypt() hashes
 */

/**

 * @brief Hash a password using Argon2id
 * @param password The password to hash (required)
 * @param salt Optional salt bytes; if empty, generates random salt
 * @return Encoded Argon2id hash string, or empty string on failure
 */
std::string hash_password(std::string_view password, std::string_view salt = "");

/**

 * @brief Verify a password against a stored hash
 * @param password The password to verify
 * @param stored_hash The stored hash (Argon2 or legacy crypt)
 * @return true if password matches, false otherwise
 */
bool verify_password(std::string_view password, std::string_view stored_hash);

/**

 * @brief Generate a cryptographically secure random salt
 * @return 16 bytes of random salt data
 */
std::string generate_salt();

/**

 * @brief Migrate a legacy crypt hash to Argon2
 * @param password The original password
 * @param old_hash The legacy hash to migrate from
 * @return New Argon2 hash if migration successful, original hash otherwise
 */
std::string migrate_password(std::string_view password, std::string_view old_hash);

/**

 * @brief Check if a hash should be upgraded to Argon2
 * @param hash The hash to check
 * @return true if hash needs upgrading, false if already Argon2
 */
bool should_upgrade_hash(std::string_view hash);


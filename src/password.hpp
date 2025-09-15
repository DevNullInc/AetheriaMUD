
/*****************************************************************************************
 *                      .___________. __    __   _______                                 *
 *                      |           ||  |  |  | |   ____|                                *
 *                      `---|  |----`|  |__|  | |  |__                                   *
 *                          |  |     |   __   | |   __|                                  *
 *                          |  |     |  |  |  | |  |____                                 *
 *                          |__|     |__|  |__| |_______|                                *
 *                                                                                       *
 *                _______  __  .__   __.      ___       __                               *
 *               |   ____||  | |  \ |  |     /   \     |  |                              *
 *               |  |__   |  | |   \|  |    /  ^  \    |  |                              *
 *               |   __|  |  | |  . `  |   /  /_\  \   |  |                              *
 *               |  |     |  | |  |\   |  /  _____  \  |  `----.                         *
 *               |__|     |__| |__| \__| /__/     \__\ |_______|                         *
 *                                                                                       *
 *      _______ .______    __       _______.  ______    _______   _______                *
 *     |   ____||   _  \  |  |     /       | /  __  \  |       \ |   ____|               *
 *     |  |__   |  |_)  | |  |    |   (----`|  |  |  | |  .--.  ||  |__                  *
 *     |   __|  |   ___/  |  |     \   \    |  |  |  | |  |  |  ||   __|                 *
 *     |  |____ |  |      |  | .----)   |   |  `--'  | |  '--'  ||  |____                *
 *     |_______|| _|      |__| |_______/     \______/  |_______/ |_______|               *
 *****************************************************************************************
 *                                                                                       *
 * Modern password hashing using Argon2 for improved security - /dev/null Industries     *
 * Argon2 - https://argon2-cffi.readthedocs.io/en/stable/                                *
 *  Commented fully for better understanding on how this works.                          *
 *                                                                                       *
 *****************************************************************************************/
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


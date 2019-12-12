/**
 * @file
 * Regex library
 *
 * @copyright
 * @verbatim
   Copyright @ 2017 Audi Electronics Venture GmbH. All rights reserved.

       This Source Code Form is subject to the terms of the Mozilla
       Public License, v. 2.0. If a copy of the MPL was not distributed
       with this file, You can obtain one at https://mozilla.org/MPL/2.0/.

   If it is not possible or desirable to put the notice in a particular file, then
   You may include the notice in a location (such as a LICENSE file in a
   relevant directory) where a recipient would be likely to look for such a notice.

   You may add additional accurate notices of copyright ownership.
   @endverbatim
*/

#ifndef A_UTILS_UTIL_REGEX_SOURCE_INCLUDED_
#define A_UTILS_UTIL_REGEX_SOURCE_INCLUDED_

#include <string>
#include "a_util/memory/unique_ptr.h"

namespace a_util
{
namespace regex
{

/// RegularExpression implements regular expression matching
class RegularExpression
{
public:
    /// Anchor type
    typedef enum
    {
        AT_Unanchored, // No anchoring
        AT_Start,      // Anchor at start only
        AT_Both        // Anchor at start and end
    } AnchorType;

public:
    /**
     * Default constructor
     */
    RegularExpression();

    /**
     * Constructor with a preinitialized pattern
     *
     * @param pattern [in] The regular expression pattern
     * @param case_sensitive [in] Whether or not the match is case sensitive
     * @note On error, the instance is initialized to the default state/the pattern is not set
     */
    RegularExpression(const std::string& pattern, bool case_sensitive = true);

    /**
     * DTOR
     */
    ~RegularExpression();

    /**
     * Copy constructor
     *
     * @param other [in] The object to copy.
     */
    RegularExpression(const RegularExpression& other);

    /**
     * Copy assignment operator
     *
     * @param other [in] The element to copy to.
     * @return     [in] A reference of the local object.
     */
    RegularExpression& operator=(const RegularExpression& other);

    /**
     * Sets the regular expression pattern
     *
     * @param pattern [in] The regular expression string
     * @param case_sensitive [in] Whether or not the match is case sensitive
     * @retval False if the pattern is invalid, see \c getError for details
     */
    bool setPattern(const std::string& pattern, bool case_sensitive = true);

    /**
     * Returns the current pattern (expression).
     *
     * @return The current pattern.
     */
    std::string getPattern() const;

    /**
     * Returns any error description for the pattern. Empty string if pattern is valid
     *
     * @return The current error.
     */
    const std::string& getError() const;

    /**
     * Checks if the whole string matches the pattern.
     *
     * @param text [in] The string to match
     * @return true if the string matches, false otherwise
     */
    bool fullMatch(const std::string& text) const;

    /**
     * Checks if the whole string matches the pattern,
     * extracting up to 16 capture groups in the process
     *
     * @param text [in] The string to match
     * @param arg1 [out] Capture argument 1
     * @param arg2 [out] Capture argument 2
     * @param arg3 [out] Capture argument 3
     * @param arg4 [out] Capture argument 4
     * @param arg5 [out] Capture argument 5
     * @param arg6 [out] Capture argument 6
     * @param arg7 [out] Capture argument 7
     * @param arg8 [out] Capture argument 8
     * @param arg9 [out] Capture argument 9
     * @param arg10 [out] Capture argument 10
     * @param arg11 [out] Capture argument 11
     * @param arg12 [out] Capture argument 12
     * @param arg13 [out] Capture argument 13
     * @param arg14 [out] Capture argument 14
     * @param arg15 [out] Capture argument 15
     * @param arg16 [out] Capture argument 16
     * @return true if the string matches, false otherwise
     */
    bool fullMatch(const std::string& text,
                   std::string& arg1,
                   std::string& arg2 = noArg(),
                   std::string& arg3 = noArg(),
                   std::string& arg4 = noArg(),
                   std::string& arg5 = noArg(),
                   std::string& arg6 = noArg(),
                   std::string& arg7 = noArg(),
                   std::string& arg8 = noArg(),
                   std::string& arg9 = noArg(),
                   std::string& arg10 = noArg(),
                   std::string& arg11 = noArg(),
                   std::string& arg12 = noArg(),
                   std::string& arg13 = noArg(),
                   std::string& arg14 = noArg(),
                   std::string& arg15 = noArg(),
                   std::string& arg16 = noArg()) const;

    /**
     * Matches a string
     * @param text  [in] The string to match
     * @param anchor [in] See @ref AnchorType
     * @param consumed [out] The length of the match
     * @return truy if the string matches, otherwise false
     */
    bool match(const std::string& text, AnchorType anchor, int& consumed) const;

private: // stattic helpers
    /// Empty argument
    static std::string& noArg();

private: // data
    class Implementation;
    memory::unique_ptr<Implementation> _impl;
};

} // namespace regex
} // namespace a_util

#endif // A_UTILS_UTIL_REGEX_SOURCE_INCLUDED_

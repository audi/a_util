/**
 * @file
 * System API abstractions
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

#ifndef A_UTIL_UTIL_SYSTEM_SYSTEM_HEADER_INCLUDED
#define A_UTIL_UTIL_SYSTEM_SYSTEM_HEADER_INCLUDED

#include <string>
#include "a_util/base/types.h" //timestamp_t

namespace a_util
{
namespace system
{

/// Returns the current user name
std::string getCurrentUserName();

/// Returns the host name
std::string getHostname();

/// Returns the last system error code (platform specific, errno or GetLastError)
int getLastSystemError();

/// Resets the last system error code to '0' (platform specific, "errno =" or "::SetLastError()")
void resetLastSystemError();

/// Returns the description string associated with the passed system error code
std::string formatSystemError(int system_error_code);

/// Yields the current thread to the operating system,
/// scheduled to awake after a period of milliseconds
void sleepMilliseconds(std::uint32_t ms);

/// Yields the current thread to the operating system,
/// scheduled to awake after a period of microseconds.
/// @note: To achieve the highed resolution, use \ref HighResSchedulingSupport!
void sleepMicroseconds(std::uint64_t us);

/// Returns the current milliseconds passed since system start
timestamp_t getCurrentMilliseconds();

/// Returns the current microseconds passed since the first invocation (or -1 if not available)
/// @note This method requires high-resolution timer support in the OS
timestamp_t getCurrentMicroseconds();

/// RAII class requesting high resolution scheduling support from the OS
/// for the duration of its lifetime.
class HighResSchedulingSupport
{
public:
    /// CTOR - requests support from OS (::timeBeginPeriod(1))
    HighResSchedulingSupport();

    /// DTOR - relinquishes support from the OS (::timeEndPeriod(1))
    ~HighResSchedulingSupport();

    /// Check whether high resolution scheduling is supported
    bool isSupported() const;

private:
    HighResSchedulingSupport(const HighResSchedulingSupport&);            // = delete;
    HighResSchedulingSupport& operator=(const HighResSchedulingSupport&); // = delete;

private:
    unsigned int _handle;
};

} // namespace system
} // namespace a_util

#endif // A_UTIL_UTIL_SYSTEM_SYSTEM_HEADER_INCLUDED

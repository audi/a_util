/**
 * @file
 * Timer API
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

#ifndef A_UTIL_UTIL_SYSTEM_TIMER_DECL_INCLUDED
#define A_UTIL_UTIL_SYSTEM_TIMER_DECL_INCLUDED

#include <cstdint>

namespace a_util
{
namespace experimental
{

// forward declaration
template <typename T>
class NullaryDelegate;

} // namespace experimental
namespace system
{

/// Periodic timer running in a separate thread
/// - Invokes a callback periodically
/// - If an invocation takes longer than the period, any missed expirations are lost!
/// - The callback is invoked from a different thread, take care about thread safety!
class Timer
{
public:
    /// Default CTOR
    Timer();

    /// DTOR - Calls stop()
    ~Timer();

    /// Function CTOR - Call \ref start to start the timer
    Timer(std::uint64_t period_us, void (*Function)());

    /// Member CTOR - Call \ref start to start the timer
    template <typename M, typename T>
    Timer(std::uint64_t period_us, M method, T& instance);

    /// Sets the callback for the timer
    void setCallback(void (*Function)());

    /// Sets the callback for the timer
    template <typename M, typename T>
    void setCallback(M method, T& instance);

    /// Sets the period used by this timer (restarts the timer if already running)
    /// 0 -> One shot timer
    void setPeriod(std::uint64_t period_us);

    /// Returns the currently configured period of the timer
    std::uint64_t getPeriod() const;

    /// Starts the timer
    /// @return Returns false if the timer is already running
    bool start();

    /// Stops the timer - blocks until the callback returns!
    /// @return Returns false if the timer is already stopped
    bool stop();

    /// Returns whether the timer is currently running
    bool isRunning() const;

private:
    Timer(const Timer&);            // = delete;
    Timer& operator=(const Timer&); // = delete;
    void init();
    void setCallback(const a_util::experimental::NullaryDelegate<void>& cb);

private:
    struct Implementation;
    Implementation* _impl;
};

} // namespace system
} // namespace a_util

#endif // A_UTIL_UTIL_SYSTEM_TIMER_DECL_INCLUDED

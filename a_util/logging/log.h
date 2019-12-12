/**
 * @file
 * Logging API
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

#ifndef A_UTIL_UTIL_LOG_HEADER_INCLUDED
#define A_UTIL_UTIL_LOG_HEADER_INCLUDED

#include "a_util/base/types.h"
#include "a_util/base/delegate.h"
#include "a_util/strings/strings_format.h"
#include "a_util/strings/strings_functions.h"

namespace a_util
{
namespace logging
{

/**
 * Log levels.
 */
enum LogLevel
{
    None = 0,
    Error = 10,
    Warning = 20,
    Info = 30,
    Dump = 40,
    Debug = Dump,
    All = 0xFF
};

/**
 * A log entry
 */
struct LogEntry
{
    timestamp_t time_stamp; ///< time stamp of the log message.
    std::uint8_t log_level; ///< the log level, see @ref LogLevel.
    std::string message;    ///< the message text
    std::string source;     ///< the origin of the entry
};

/**
 * Adds a new log entry to the current logger.
 * @param[in] entry The new log entry.
 */
void addEntry(const LogEntry& entry);

/**
 * Adds a new log entry to the current logger.
 * Automatically timestamps the entry.
 * @param[in] log_level The severity, @ref LogLevel.
 * @param[in] message The message text (optional)
 * @param[in] source A string describing the source location (optional).
 */
void addEntry(std::uint8_t log_level,
              const std::string& message = a_util::strings::empty_string,
              const std::string& source = a_util::strings::empty_string);

/**
 * Logger interface definition
 */
typedef experimental::UnaryDelegate<void, const LogEntry&> Logger;

/**
 * Sets the currently used logger.
 * @param[in] log The new logger method.
 */
void setLogger(Logger log);

/**
 * Returns the currently used logger.
 * @return The currently used logger.
 */
Logger getLogger();

/**
 * Returns the default string representation of a log entry.
 * @param[in] entry The log entry.
 * @return the string representation of the log entry.
 */
std::string defaultFormat(const LogEntry& entry);

/**
 * Default logging method, that writes log messages to stdout.
 * @param[in] entry The log entry.
 */
void defaultLogger(const LogEntry& entry);

/// internal
#define _A_UTILS_STRINGIFY(__number) #__number
/// internal
#define _A_UTILS_TO_STRING(__number) _A_UTILS_STRINGIFY(__number)
/// internal
#define LOG_ADD_ENTRY(__level, ...)                                                                \
    a_util::logging::addEntry(__level,                                                             \
                              a_util::strings::format(__VA_ARGS__),                                \
                              __FILE__ "(" _A_UTILS_TO_STRING(__LINE__) ")")

#ifdef _DEBUG
/// Logs a dump message
#define LOG_DUMP(...) LOG_ADD_ENTRY(a_util::logging::Dump, __VA_ARGS__)
#else
/// Logs a dump message
#define LOG_DUMP(...)
#endif
/// Logs an info message
#define LOG_INFO(...) LOG_ADD_ENTRY(a_util::logging::Info, __VA_ARGS__)
/// Logs a warning message
#define LOG_WARNING(...) LOG_ADD_ENTRY(a_util::logging::Warning, __VA_ARGS__)
/// Logs an error message
#define LOG_ERROR(...) LOG_ADD_ENTRY(a_util::logging::Error, __VA_ARGS__)

} // namespace logging
} // namespace a_util

#endif // A_UTIL_UTIL_LOG_HEADER_INCLUDED

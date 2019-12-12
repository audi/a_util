/**
 * @file
 * Process API
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

#ifndef A_UTIL_UTIL_PROCESS_PROCESS_HEADER_INCLUDED
#define A_UTIL_UTIL_PROCESS_PROCESS_HEADER_INCLUDED

#include <string>
#include "a_util/filesystem.h"

namespace a_util
{
namespace process
{
/**
 * Returns the current process id.
 *
 * @return Id of the current process
 */
uint64_t getCurrentProcessId();

/**
 * Starts an program as detached process and optionally wait for the application to close down.
 * The new process will use the environment block af the calling process.
 *
 * @param       executable_file  [in] executable file or command to call.
 * @param       arguments        [in] Arguments passing to the executable.
 * @param       working_path     [in] Working path. If empty the current working directory is used.
 * @param       wait_for_exit    [in] Bool that specifies if the function should wait for the
 * application to close down. only if set to true the return value will be used for applications
 * return value.
 * @return      returns the exit code of the application only if the wait_for_exit is set to bool.
 * otherwise it is only -1 if starting failed
 *
 */
uint32_t execute(const a_util::filesystem::Path& executable_file,
                 const std::string& arguments,
                 const a_util::filesystem::Path& working_path,
                 bool wait_for_exit);

/**
 * Starts an executable and wait for the application to close down.
 * The new process will use the environment block af the calling process.
 *
 * @param       executable_file  [in] executable file or command to call.
 * @param       arguments        [in] Arguments passing to the executable.
 * @param       working_path     [in] Working path. If empty the current working directory is used.
 * @param       std_out          [in] Standard out of the program started.
 *
 * @return      returns the exit code of the application.
 *
 */
uint32_t execute(const a_util::filesystem::Path& executable_file,
                 const std::string& arguments,
                 const a_util::filesystem::Path& working_path,
                 std::string& std_out);

/**
 * Starts an executable and wait for the application to close down.
 * The new process will use the environment block af the calling process.
 *
 * @param       executable_file  [in] executable file or command to call.
 * @param       arguments        [in] Arguments passing to the executable.
 * @param       working_path     [in] Working path. If empty the current working directory is used.
 * @param       std_out          [in] Standard out of the program started.
 * @param       std_err          [in] Standard error of the program started.
 *
 * @return      returns the exit code of the application.
 *
 */
uint32_t execute(const a_util::filesystem::Path& executable_file,
                 const std::string& arguments,
                 const a_util::filesystem::Path& working_path,
                 std::string& std_out,
                 std::string& std_err);

/**
 * Retrieves the current value of the environment variable given in \p environment_variable_name.
 * The environment variable is retrieved is only valid within the current process.
 *
 * @param       environment_variable_name  [in] the environment variable name to retrieve the value
 * for.
 *
 * @return      returns the value of the environment variable given in \p environment_variable_name.
 * This function will throw if failed
 *
 */
std::string getEnvVar(const std::string& environment_variable_name);

/**
 * Retrieves the current value of the environment variable given in \p environment_variable_name.
 * The environment variable is retrieved is only valid within the current process.
 * If variable is not set the \p default_value is returned.
 *
 * @param       environment_variable_name  [in] the environment variable name to retrieve the value
 * for.
 * @param       default_value  [in] the default value is variable is not set.
 *
 * @return      returns the value of the environment variable given in \p environment_variable_name
 * or the default_value
 * @retval      \p default_value if not set
 *
 */
std::string getEnvVar(const std::string& environment_variable_name,
                      const std::string& default_value);

/**
 * Puts the value of the environment variable given in \p environment_variable_name to the current
 * process environment areas. The environment variable is only valid within the current process.
 * Depending on the used process API the environment will be either copied to any child process or
 * not. If using @ref execute functions of this process API the new process uses a copy of the
 * environment of the calling process. Will throw if failed.
 *
 * @param       environment_variable_name  [in] the environment variable name to set the value for.
 * @param       environment_variable_value [in] the environment variable value.
 *
 *
 */
void setEnvVar(const std::string& environment_variable_name,
               const std::string& environment_variable_value);

} // namespace process
} // namespace a_util

#include "a_util/process/detail/process_impl.h"

#endif // A_UTIL_UTIL_PROCESS_PROCESS_HEADER_INCLUDED

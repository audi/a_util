/**
 * @file
 * Class for file system access. This class wraps all function calls for file system access.
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

#ifndef _A_UTILS_UTIL_FILESYSTEM_FILESYSTEM_INCLUDED_
#define _A_UTILS_UTIL_FILESYSTEM_FILESYSTEM_INCLUDED_

#include "a_util/filesystem/path.h"
#include "a_util/memory.h"
#include "a_util/strings.h"

namespace a_util
{
/// The filesystem namespaces holds various free functions used to interact with
/// the host filesystem
namespace filesystem
{

typedef enum
{
    OK,
    OPEN_FAILED,
    GENERAL_FAILURE, /* ...reporting in! Major Mistake will be with you in a moment. */
    IO_ERROR,
    INVALID_PATH,
    ACCESS_DENIED
} Error;

/// Enum used in the enumDirectory method
typedef enum
{
    /// Lists files in the directory
    ED_FILES = 0x1,
    /// Lists directories in the directory
    ED_DIRECTORIES = 0x2
} EnumDirFlags;

/**
 * Temp directory of the system
 *
 * @return Returns the temp directory of the system
 */
Path getTempDirectory();

/**
 * Current working directory
 *
 * @return Returns the current working directory path
 */
Path getWorkingDirectory();

/**
 * Sets the working directory
 *
 * @param [in] path The new working directory
 * @return Returns standard result
 * @retval INVALID_PATH The path is invalid/nonexisting or a file path
 * @retval GENERAL_FAILURE The OS failed to set the working directory
 */
Error setWorkingDirectory(const Path& path);

/**
 * This function reads a complete text file into a string
 *
 * @param  file_path      [in]  Path of file to be read
 * @param  content [out] Destination string to be filled
 * @return Standard Error Code
 */
Error readTextFile(const Path& file_path, std::string& content);

/**
 * This function reads a complete text file into a vector of lines
 *
 * @param  file_path      [in]  Path of file to be read
 * @param  vec_lines       [out] Destination vector to be filled
 * @return Standard Error Code
 */
Error readTextLines(const Path& file_path, std::vector<std::string>& vec_lines);

/**
 * This function writes a string into a text file, overwriting any old contents.
 *
 * @param  file_path      [in] Path of file to be read
 * @param  content [in] String to be written to the file
 * @return Standard Error Code
 */
Error writeTextFile(const Path& file_path, const std::string& content);

/**
 * Lists all entries in a directory
 *
 * @param  dir_path [in] The directory.
 * @param  vec_entries [out] The entry result vector
 * @param  flags [in] Flags defining the behaviour of the method (see \ref EnumDirFlags)
 *
 * @return Standard Result Code
 * @retval INVALID_PATH The path does not exist or is not a directory
 */
Error enumDirectory(const Path& dir_path,
                    std::vector<Path>& vec_entries,
                    std::int32_t flags = ED_FILES | ED_DIRECTORIES);

/**
 * Checks whether the path exists on the filesystem
 *
 * @param [in] path The path to check
 * @retval true if the path exists, false otherwise
 */
bool exists(const Path& path);

/**
 * Creates a directory on the filesystem
 *
 * @param path [in] The path to create
 * @note All nonexistant subpaths are created
 * @retval true if the directory was created or already exists, false otherwise
 */
bool createDirectory(const Path& path);

/**
 * Checks whether the path points to a file on the filesystem
 *
 * @param [in] file_path The path to check
 * @retval true if the path points to a file, false otherwise
 */
bool isFile(const Path& file_path);

/**
 * Checks whether the path points to a directory on the filesystem
 *
 * @param [in] dir_path The path to check
 * @retval true if the path points to a directory, false otherwise
 */
bool isDirectory(const Path& dir_path);

/**
 * Removes the element pointed to by a path, whether it's a file or a directory.
 *
 * @param  path [in] Path to the element to be deleted
 * @return Standard Error Code
 * @retval ACCESS_DENIED The OS denied the deletion
 * @retval INVALID_PATH The path is invalid
 */
bool remove(const Path& path);

/**
 * Renames/moves the element pointed to by a path to another path,
 * whether it's a file or a directory.
 *
 * @param  path [in] Path to the element to be moved
 * @param  new_path [in] New path for the element
 * @return Standard Error Code
 * @retval ACCESS_DENIED The OS denied the rename
 * @retval INVALID_PATH Either one of the paths is invalid
 */
bool rename(const Path& path, const Path& new_path);

} // namespace filesystem
} // namespace a_util

#endif // _A_UTILS_UTIL_FILESYSTEM_FILESYSTEM_INCLUDED_

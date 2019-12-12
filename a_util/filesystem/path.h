/**
 * @file
 * Class for path handling
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

#ifndef _A_UTILS_UTIL_FILESYSTEM_PATH_INCLUDED_
#define _A_UTILS_UTIL_FILESYSTEM_PATH_INCLUDED_

#include "a_util/memory.h"
#include "a_util/strings.h"
#include <stdexcept>

namespace a_util
{
namespace filesystem
{
/// forward declarations
class Path;
Path getWorkingDirectory();

/// Exception class used by Path methods
class PathException : public std::runtime_error
{
public:
    PathException(const std::string& message);
};

/**
 * File/Directory path class
 * This class represents paths on the filesystem. Only syntactic aspects of paths are handled,
 * the path may not exist or not even be allowed to exist on the current platform.
 */
class Path
{
public:
    /**
     * Path separator types
     */
    typedef enum
    {
        /// Unix
        PS_ForwardSlash = 0,
        /// Windows
        PS_BackwardSlash = 1,
        /// Depending on current platform
        PS_Native = 2
    } PathSeparator;

public:
    /**
     * Default CTOR for an empty path
     */
    Path();

    /**
     * CTOR
     * @param [in] path The instance to copy from
     */
    Path(const Path& path);

    /**
     * Assignment Operator
     * @param [in] path The instance to copy from
     */
    Path& operator=(const Path& path);

    /**
     * Initializing CTOR
     * @param [in] path The file or directory path to initialize the instance
     * \note If the path is invalid, the instance is initialized to the empty state
     */
    Path(const std::string& path);

    /**
     * Initializing CTOR
     * @param [in] path The file or directory path to initialize the instance
     * \note If the path is invalid, the instance is initialized to the empty state
     */
    Path(const char* path);

    /**
     * Nonvirtual DTOR
     */
    ~Path();

    /**
     * Converts the path to the native string representation
     * @retval The string representation of the path (or empty string for empty path),
     *         using the platform native separator
     */
    operator std::string() const;

    /**
     * Returns the string representation of the current path using the specified separator
     * @param [in] separator The separator to use
     * @retval The string representation of the path (or empty string for empty path)
     */
    std::string toString(PathSeparator separator = PS_Native) const;

    /**
     * Set the current path of the instance, handling platform aspects or any trailing slashes.
     * @param [in] path The new path
     * @retval False if the path is invalid and cannot be set
     */
    bool setPath(const std::string& path);

    /**
     * Appends a relative file or directory path or another file extension to the current path
     * @param [in] path The (relative) (file-)path or file extension to append
     * @note This method will throw a PathException if path is absolute
     * @return Returns *this, to be able to chain additional method calls
     */
    Path& append(const Path& path);

    /**
     * Returns the root path of the directory/file
     * Usually "C:" or "D:" on Windows, on Unix-like systems it's always "/"
     * e.g.: "/dir/subdir/file.txt" returns "/", "C:/dir" returns "C:"
     * @note: For network paths, the host is returned (e.g. "\\ci-aev\test" returns "\\ci-aev")
     * @return A path instance pointing to the root directory
     */
    Path getRoot() const;

    /**
     * Returns the parent path of the directory/file
     * e.g.: "/dir/subdir/file.txt" returns "/dir/subdir", "/dir/subdir" returns "/dir"
     * @note If called on a root path, *this is returned
     * @return A path instance pointing to the parent directory (or root)
     */
    Path getParent() const;

    /**
     * Returns the name of the directory/file
     * e.g.: "/dir/subdir/file.txt" returns "file.txt", "/dir/subdir" returns "subdir"
     * @return The last element of the path
     */
    Path getLastElement() const;

    /**
     * Returns the extension of the file (without the '.')
     * e.g.: "/dir/subdir/file.txt" returns "txt", "/dir/subdir" returns ""
     * @return The extension or an empty string if the path is a directory or has no extension
     */
    std::string getExtension() const;

    /**
     * Replaces the extension of the path
     * @note If the path is a file path, the extension is replaced. If it's a directory path,
     * the extension is added, making it a file path in the process
     * @param [in] extension The new extension (without '.'!)
     * @return Returns *this, to be able to chain additional method calls
     */
    Path& replaceExtension(const std::string& extension);

    /**
     * Removed the last part of the path, making it a directory path.
     * @note Does nothing if the current path already is at the root
     * @return Returns *this, to be able to chain additional method calls
     */
    Path& removeLastElement();

    /**
     * Makes the current path canonical.
     * This means that all occurences of '.' and '..' are evaluated syntactically
     * e.g.: "/./dir/../dir/file.txt" is replaced by "/file.txt"
     * @note If the path is already canonical, no changes are made!
     * @return Returns *this, to be able to chain additional method calls
     */
    Path& makeCanonical();

    /**
     * Makes the current path relative to a specified parent directory (default: working directory)
     * @note If the path is already relative, no changes are made!
     * @param [in] oParent The parent directory
     * @return Returns *this, to be able to chain additional method calls
     */
    // Path& MakeRelative(const Path& oParent = filesystem::getWorkingDirectory());

    /**
     * Makes the current path absolute, using a specified parent directory (default: working
     * directory)
     * @note If the path is already absolute, no changes are made!
     * @param [in] oParent The parent directory
     * @return Returns *this, to be able to chain additional method calls
     */
    // Path& MakeAbsolute(const Path& oParent = filesystem::getWorkingDirectory());

    /**
     * Returns whether the current path is relative
     * @note This Method throws a PathException is the current path is empty
     * @retval true if the path is relative, false otherwise
     */
    bool isRelative() const;

    /**
     * Returns whether the current path is absolute
     * @note This Method throws a PathException is the current path is empty
     * @retval true if the path is absolute, false otherwise
     */
    bool isAbsolute() const;

    /**
     * Returns whether the current path is empty
     * @retval true if the path is empty, false otherwise
     */
    bool isEmpty() const;

    /**
     * Clears the path and resets it to the empty state
     * @return Returns *this, to be able to chain additional method calls
     */
    Path& Clear();

private:
    class Implementation;
    memory::unique_ptr<Implementation> _impl;
    friend bool operator==(const Path&, const Path&);
};

/**
 * Compares the path to another instance
 * @note The paths are compared syntactically, any canonicalization must be done manually!
 * @param [in] a The left path
 * @param [in] b The right path (so philosophical...)
 * @retval true if the paths are equal, false otherwise
 */
bool operator==(const Path& a, const Path& b);

/// Non-Equality, see operator==
bool operator!=(const Path& a, const Path& b);

/**
 * Appends two paths, forming a new path
 * @param [in] a The left path
 * @param [in] b The right path
 * @retval A new path combined from a and b (or empty, in case of an error)
 */
Path operator+(const Path& a, const Path& b);

} // namespace filesystem
} // namespace a_util

#endif // _A_UTILS_UTIL_FILESYSTEM_PATH_INCLUDED_

/**
 * @file
 * Raw memory related functionality
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

#ifndef _A_UTILS_UTIL_MEMORY_MEMORY_INCLUDED_
#define _A_UTILS_UTIL_MEMORY_MEMORY_INCLUDED_

#include <cstdint>
#include "a_util/memory/memorybuffer.h"
#include "a_util/memory/unique_ptr.h"

namespace a_util
{
namespace memory
{

class MemoryBuffer;

/**
 * Portable safe memcopy
 * @param dest [inout] Destination pointer
 * @param dest_size [in] Available bytes in the destination memory buffer
 * @param source [in] Source pointer
 * @param source_size [in] Number of bytes to copy from the source buffer
 * @retval False if either of the pointer arguments is zero or bytes_to_copy > dest_size
 */
bool copy(void* dest, std::size_t dest_size, const void* source, std::size_t bytes_to_copy);

/**
 * Portable memcopy
 * @param dest [inout] Destination pointer
 * @param source [in] Source pointer
 * @param source_size [in] Number of bytes to copy from the source buffer
 * @retval False if either of the pointer arguments is zero
 */
bool copy(void* dest, const void* source, std::size_t bytes_to_copy);

/**
 * Copies a buffer into a MemoryBuffer instance (allocating memory if neccessary)
 * @param buffer [inout] Destination memory buffer
 * @param source [in] Source pointer
 * @param source_size [in] Number of bytes to copy from the source buffer
 * @retval False if source is zero or allocation fails
 */
bool copy(MemoryBuffer& buffer, const void* source, std::size_t bytes_to_copy);

/**
 * Portable safe memset
 * @param dest [inout] Destination pointer
 * @param dest_size [in] Available bytes in the destination memory buffer
 * @param value [in] Byte value used to fill the range
 * @param bytes_to_set [in] Number of bytes to set at the destination
 * @retval False if dest is zero or bytes_to_set > dest_size
 */
bool set(void* dest, std::size_t dest_size, std::uint8_t value, std::size_t bytes_to_set);

/**
 * Portable memset
 * @param dest [inout] Destination pointer
 * @param value [in] Byte value used to fill the range
 * @param bytes_to_set [in] Number of bytes to set at the destination
 * @retval False if dest is zero
 */
bool set(void* dest, std::uint8_t value, std::size_t bytes_to_set);

/**
 * memset for a MemoryBuffer instance (allocating memory if neccessary)
 * @param buffer [inout] Destination memory buffer
 * @param bytes_to_set [in] Number of bytes to set at the destination
 * @param value [in] Byte value used to fill the buffer
 * @retval False if memory allocation fails
 */
bool set(MemoryBuffer& buffer, std::uint8_t value, std::size_t bytes_to_set);

/**
 * Portable safe memzero
 * @param dest [inout] Destination pointer
 * @param dest_size [in] Available bytes in the destination memory buffer
 * @param bytes_to_zero [in] Number of bytes to zero at the destination
 * @retval False if dest is zero or bytes_to_zero > dest_size
 */
bool zero(void* dest, std::size_t dest_size, std::size_t bytes_to_zero);

/**
 * Portable memzero
 * @param dest [inout] Destination pointer
 * @param bytes_to_zero [in] Number of bytes to zero at the destination
 * @retval False if dest is zero
 */
bool zero(void* dest, std::size_t bytes_to_zero);

/**
 * memzero for a MemoryBuffer instance (allocating memory if neccessary)
 * @param buffer [inout] Destination memory buffer
 * @param bytes_to_zero [in] Number of bytes to zero at the destination
 * @retval False if memory allocation fails
 */
bool zero(MemoryBuffer& buffer, std::size_t bytes_to_zero);

/**
 * Portable safe memcmp
 * @param buf1 [in] First buffer to compare
 * @param buf1_size [in] Available bytes in the first memory buffer
 * @param buf2 [in] Second buffer to compare
 * @param buf2_size [in] Available bytes in the second memory buffer
 * @note This function throws a std::invalid_argument exception if either of the
 *       buffers is a @c nullptr or the sizes are different!
 * @return <0 buf1 is less than buf2, >0 buf1 is greater than buf2, 0 both buffers are equal
 */
int compare(const void* buf1, std::size_t buf1_size, const void* buf2, std::size_t buf2_size);

/**
 * Check whether the given memory range is entirely initialized to zero
 * @param[in] buffer Pointer to beginning of buffer to check for zero-initialized values
 * @param[in] buffer_size Size of the buffer
 * @return @c true if all values of @c buffer over the entire @c buffer_size is initialized to
 *         0x00. False otherwise
 */
bool isZero(const void* buffer, std::size_t buffer_size);

/// Returns the value with its byte order swapped
bool swapEndianess(bool value);
/// @overload
std::int8_t swapEndianess(std::int8_t value);
/// @overload
std::uint8_t swapEndianess(std::uint8_t value);
/// @overload
std::int16_t swapEndianess(std::int16_t value);
/// @overload
std::uint16_t swapEndianess(std::uint16_t value);
/// @overload
std::int32_t swapEndianess(std::int32_t value);
/// @overload
std::uint32_t swapEndianess(std::uint32_t value);
/// @overload
std::int64_t swapEndianess(std::int64_t value);
/// @overload
std::uint64_t swapEndianess(std::uint64_t value);

} // namespace memory
} // namespace a_util

#endif // _A_UTILS_UTIL_MEMORY_MEMORY_INCLUDED_

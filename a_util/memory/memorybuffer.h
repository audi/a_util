/**
 * @file
 * Memory buffer container
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

#ifndef _A_UTILS_UTIL_MEMORY_MEMORYBUFFER_INCLUDED_
#define _A_UTILS_UTIL_MEMORY_MEMORYBUFFER_INCLUDED_

#include "a_util/memory/unique_ptr.h"

namespace a_util
{
namespace memory
{

/// Memory buffer class, encapsulates a raw memory buffer
class MemoryBuffer
{
public:
    /// Default CTOR - does not allocate any buffer memory
    MemoryBuffer();

    /**
     * CTOR with initial size of the buffer (allocates memory and zero-initializes the buffer)
     * @param[in] initial_size The initial buffer size
     */
    MemoryBuffer(std::size_t initial_size);

    /**
     * CTOR initializing from a foreign buffer
     * Attaches a memory buffer to the instance (non-owning!)
     *
     * @param buffer Pointer to the memory buffer
     * @param size Size of the memory buffer
     */
    MemoryBuffer(void* buffer, std::size_t size);

    /// Nonvirtual DTOR - Frees any owned memory
    ~MemoryBuffer();

    /// Copy constructor
    MemoryBuffer(const MemoryBuffer& other);

    /// Assignment operator
    MemoryBuffer& operator=(const MemoryBuffer& other);

    /**
     * Allocates and zero-initializes a memory buffer (freeing the old one if applicable)
     * @param new_size The new size of the buffer (0 equals reset())
     * @retval True if the allocation succeeded, false otherwise
     */
    bool allocate(std::size_t new_size);

    /**
     * Resets the instance (freeing any owned memory)
     */
    void reset();

    /// Returns the current size of the buffer
    std::size_t getSize() const;

    /// Returns the pointer to the current buffer, or @c nullptr if the current size is zero
    void* getPtr() const;

    /**
     * Attaches a memory buffer to the instance (non-owning!)
     *
     * @param buffer Pointer to the memory buffer
     * @param size Size of the memory buffer
     */
    void attach(void* buffer, std::size_t size);

    /// Swaps internals with the other instance (fast operation)
    void swap(MemoryBuffer& other);

private:
    struct Implementation;
    a_util::memory::unique_ptr<Implementation> _impl;
};

/// Comparison operator for MemoryBuffer
bool operator==(const MemoryBuffer& buf1, const MemoryBuffer& buf2);
bool operator!=(const MemoryBuffer& buf1, const MemoryBuffer& buf2);

} // namespace memory
} // namespace a_util

#endif // _A_UTILS_UTIL_MEMORY_MEMORYBUFFER_INCLUDED_

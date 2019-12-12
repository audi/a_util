/**
 * @file
 * Specialize an reference counted object class without dynamic memory allocation
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

#ifndef A_UTIL_UTIL_RESULT_IMPL_REFERENCE_COUNTED_OBJECT_DISABLE_DYNAMIC_ALLOC_HEADER_INCLUDED
#define A_UTIL_UTIL_RESULT_IMPL_REFERENCE_COUNTED_OBJECT_DISABLE_DYNAMIC_ALLOC_HEADER_INCLUDED

#include <cstddef> //std::size_t
#include "a_util/result/detail/error_description_intf.h"
#include "a_util/result/impl/reference_counted_object.h"

namespace a_util
{
namespace result
{
namespace detail
{

/// type needed by ResultType implementation
struct ErrorDescriptionType
{
};

/**
 * Specialization to disable dynamic allocation with new() by providing an operator new overload
 */
template <>
class ReferenceCountedObject<IErrorDescription, ErrorDescriptionType>
{
public:
    // should never be used
    ReferenceCountedObject(...)
    {
    }

    static void* operator new(std::size_t)
    {
        return nullptr;
    }
    static void operator delete(void*, std::size_t)
    {
    }
};

} // namespace detail
} // namespace result
} // namespace a_util

#endif // A_UTIL_UTIL_RESULT_IMPL_REFERENCE_COUNTED_OBJECT_DISABLE_DYNAMIC_ALLOC_HEADER_INCLUDED

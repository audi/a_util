/**
 * @file
 * Implementation of helper structs and functions for detailed result descriptions
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

#ifndef A_UTIL_UTIL_RESULT_IMPL_DESCRIPTION_PRIVATE_HEADER_INCLUDED
#define A_UTIL_UTIL_RESULT_IMPL_DESCRIPTION_PRIVATE_HEADER_INCLUDED

#include <new>
#include "a_util/result/impl/reference_counted_object.h"
#include "a_util/result/detail/result_description_decl.h"

namespace a_util
{
namespace result
{
namespace detail
{

template <typename DescriptionType>                   // class template parameter
template <typename Implementation, typename... Args>  // method template parameters
typename ResultDescription<DescriptionType>::SelfType // return type
    ResultDescription<DescriptionType>::makeResultDescription(std::int32_t error_code,
                                                              Args&&... args)
{
    typedef ReferenceCountedObject<DescriptionType, Implementation> ReferenceCountedImplType;
    SelfType oDescription;

    // do not use std::nothrow overload as corresponding 'new'-operator can only be overloaded
    // global
    try
    {
        // first parameter of the detailed description must be of type error code
        oDescription._pointer_to_result_or_error_code = reinterpret_cast<std::uint64_t>(
            new ReferenceCountedImplType(error_code, std::forward<Args>(args)...));
    }
    catch (const std::bad_alloc&) // new failed to alloc
    {
        oDescription._pointer_to_result_or_error_code = 0;
    }

    if (0 != oDescription._pointer_to_result_or_error_code)
    {
        typedef
            typename TraitsType::ReferenceCountedDescriptionType ReferenceCountedDescriptionType;
        const ReferenceCountedDescriptionType* const pReferenceCountedObject =
            reinterpret_cast<ReferenceCountedDescriptionType* const>(
                oDescription._pointer_to_result_or_error_code);

        pReferenceCountedObject->addReference();
        // the detailed description is allowed only if the MSB is not set to 1!
        // in reality this should never happen.
        if (TraitsType::isErrorCodeSet(oDescription._pointer_to_result_or_error_code))
        {
            // not allowed, only create the error code
            pReferenceCountedObject->removeReference();
            oDescription._pointer_to_result_or_error_code = 0;
        }
        else
        {
            return oDescription;
        }
    }
    return SelfType::makeResultDescription(error_code);
}

} // namespace detail
} // namespace result
} // namespace a_util

#endif // A_UTIL_UTIL_RESULT_IMPL_DESCRIPTION_PRIVATE_HEADER_INCLUDED

/**
 * @file
 * Standard type declarations.
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
 *
 * QNX support Copyright (c) 2019 by dSPACE GmbH, Paderborn, Germany. All Rights Reserved
 */

#ifndef A_UTIL_UTIL_BASE_TYPES_H
#define A_UTIL_UTIL_BASE_TYPES_H

#include <cstdint>
#include <atomic>

/// type definition for a handle value
typedef void* handle_t; /* h */
/// type definition for a time value. This is always in microseconds
/// (if not the declaration of a use needs to mark this explicit).
typedef std::int64_t timestamp_t; /* n */
/// atomic version of timestamp_t
#ifdef __QNX__
typedef std::atomic_int_fast64_t atomic_timestamp_t;
#else
typedef std::atomic<timestamp_t> atomic_timestamp_t;
#endif

#endif /* A_UTIL_UTIL_BASE_TYPES_H */

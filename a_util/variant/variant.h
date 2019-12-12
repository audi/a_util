/**
 * @file
 * Variant container
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

#ifndef _A_UTILS_UTIL_VARIANT_VARIANT_HEADER_INCLUDED_
#define _A_UTILS_UTIL_VARIANT_VARIANT_HEADER_INCLUDED_

#include <cstdint>
#include "a_util/memory/unique_ptr.h"

namespace a_util
{
namespace variant
{

/// Enumeration of variant types
typedef enum
{
    VT_Empty = 0,
    VT_Bool = 1,
    VT_Int8 = 2,
    VT_UInt8 = 3,
    VT_Int16 = 4,
    VT_UInt16 = 5,
    VT_Int32 = 6,
    VT_UInt32 = 7,
    VT_Int64 = 8,
    VT_UInt64 = 9,
    VT_Float = 10,
    VT_Double = 11,
    VT_String = 12,

    VT_Float32 = VT_Float,
    VT_Float64 = VT_Double,
} VariantType;

/**
 * Container type, able to store any primitive data type (and arrays thereof)
 */
class Variant
{
public:
    /// CTOR: VT_Empty
    Variant();
    /// CTOR: VT_Bool
    Variant(bool value);
    /// CTOR: VT_Int8
    Variant(std::int8_t value);
    /// CTOR: VT_UInt8
    Variant(std::uint8_t value);
    /// CTOR: VT_Int16
    Variant(std::int16_t value);
    /// CTOR: VT_UInt16
    Variant(std::uint16_t value);
    /// CTOR: VT_Int32
    Variant(std::int32_t value);
    /// CTOR: VT_UInt32
    Variant(std::uint32_t value);
    /// CTOR: VT_Int64
    Variant(std::int64_t value);
    /// CTOR: VT_UInt64
    Variant(std::uint64_t value);
    /// CTOR: VT_Float32
    Variant(float value);
    /// CTOR: VT_Float64
    Variant(double value);
    /// CTOR: VT_String
    Variant(const char* value);

    /// CCTOR
    Variant(const Variant& other_var);

    /// Assignment operator
    Variant& operator=(const Variant& other_var);

    /// Non-virtual DTOR
    ~Variant();

    /// Returns the current underlying data type of the instance
    VariantType getType() const;

    /// Returns the current array size of the instance
    std::size_t getArraySize() const;

    /// Returns whether the instance stores an array of any kind
    bool isArray() const;

    /// Returns whether the instance is in the empty state (VT_Empty)
    bool isEmpty() const;

    /// Resets the instance to VT_Empty
    void reset();

    /// Resets the instance to a new value
    void reset(bool value);
    /// @copydoc Resets()
    void reset(std::int8_t value);
    /// @copydoc Resets()
    void reset(std::uint8_t value);
    /// @copydoc Resets()
    void reset(std::int16_t value);
    /// @copydoc Resets()
    void reset(std::uint16_t value);
    /// @copydoc Resets()
    void reset(std::int32_t value);
    /// @copydoc Resets()
    void reset(std::uint32_t value);
    /// @copydoc Resets()
    void reset(std::int64_t value);
    /// @copydoc Resets()
    void reset(std::uint64_t value);
    /// @copydoc Resets()
    void reset(float value);
    /// @copydoc Resets()
    void reset(double value);
    /// @copydoc Resets()
    void reset(const char* value);

    /// Resets the instance to a new array
    void reset(const bool* array_storage, std::size_t array_size);
    /// @copydoc reset()
    void reset(const std::int8_t* array_storage, std::size_t array_size);
    /// @copydoc reset()
    void reset(const std::uint8_t* array_storage, std::size_t array_size);
    /// @copydoc reset()
    void reset(const std::int16_t* array_storage, std::size_t array_size);
    /// @copydoc reset()
    void reset(const std::uint16_t* array_storage, std::size_t array_size);
    /// @copydoc reset()
    void reset(const std::int32_t* array_storage, std::size_t array_size);
    /// @copydoc reset()
    void reset(const std::uint32_t* array_storage, std::size_t array_size);
    /// @copydoc reset()
    void reset(const std::int64_t* array_storage, std::size_t array_size);
    /// @copydoc reset()
    void reset(const std::uint64_t* array_storage, std::size_t array_size);
    /// @copydoc reset()
    void reset(const float* array_storage, std::size_t array_size);
    /// @copydoc reset()
    void reset(const double* array_storage, std::size_t array_size);

    /// Gets the value of the instance, optionally at an array index
    bool getBool(std::size_t array_index = 0) const;
    /// @copydoc getBool()
    std::int8_t getInt8(std::size_t array_index = 0) const;
    /// @copydoc getBool()
    std::uint8_t getUInt8(std::size_t array_index = 0) const;
    /// @copydoc getBool()
    std::int16_t getInt16(std::size_t array_index = 0) const;
    /// @copydoc getBool()
    std::uint16_t getUInt16(std::size_t array_index = 0) const;
    /// @copydoc getBool()
    std::int32_t getInt32(std::size_t array_index = 0) const;
    /// @copydoc getBool()
    std::uint32_t getUInt32(std::size_t array_index = 0) const;
    /// @copydoc getBool()
    std::int64_t getInt64(std::size_t array_index = 0) const;
    /// @copydoc getBool()
    std::uint64_t getUInt64(std::size_t array_index = 0) const;
    /// @copydoc getBool()
    float getFloat(std::size_t array_index = 0) const;
    /// @copydoc getBool()
    double getDouble(std::size_t array_index = 0) const;
    /// Gets the value of the instance (strings are not supported in arrays!)
    const char* getString() const;

    /// Provided for compatibility reasons
    float getFloat32(std::size_t array_index = 0) const;
    /// Provided for compatibility reasons
    double getFloat64(std::size_t array_index = 0) const;

    /// Converts the value of the instance
    bool asBool() const;
    /// @copydoc asBool()
    std::int8_t asInt8() const;
    /// @copydoc asBool()
    std::uint8_t asUInt8() const;
    /// @copydoc asBool()
    std::int16_t asInt16() const;
    /// @copydoc asBool()
    std::uint16_t asUInt16() const;
    /// @copydoc asBool()
    std::int32_t asInt32() const;
    /// @copydoc asBool()
    std::uint32_t asUInt32() const;
    /// @copydoc asBool()
    std::int64_t asInt64() const;
    /// @copydoc asBool()
    std::uint64_t asUInt64() const;
    /// @copydoc asBool()
    float asFloat() const;
    /// @copydoc asBool()
    double asDouble() const;
    /// @copydoc asBool()
    std::string asString() const;

    /// @copydoc As()
    operator bool() const;
    /// @copydoc As()
    operator std::int8_t() const;
    /// @copydoc As()
    operator std::uint8_t() const;
    /// @copydoc As()
    operator std::int16_t() const;
    /// @copydoc As()
    operator std::uint16_t() const;
    /// @copydoc As()
    operator std::int32_t() const;
    /// @copydoc As()
    operator std::uint32_t() const;
    /// @copydoc As()
    operator std::int64_t() const;
    /// @copydoc As()
    operator std::uint64_t() const;
    /// @copydoc As()
    operator float() const;
    /// @copydoc As()
    operator double() const;
    /// @copydoc As()
    operator std::string() const;

    /// @copydoc reset()
    Variant& operator=(bool value);
    /// @copydoc reset()
    Variant& operator=(std::int8_t value);
    /// @copydoc reset()
    Variant& operator=(std::uint8_t value);
    /// @copydoc reset()
    Variant& operator=(std::int16_t value);
    /// @copydoc reset()
    Variant& operator=(std::uint16_t value);
    /// @copydoc reset()
    Variant& operator=(std::int32_t value);
    /// @copydoc reset()
    Variant& operator=(std::uint32_t value);
    /// @copydoc reset()
    Variant& operator=(std::int64_t value);
    /// @copydoc reset()
    Variant& operator=(std::uint64_t value);
    /// @copydoc reset()
    Variant& operator=(float value);
    /// @copydoc reset()
    Variant& operator=(double value);
    /// @copydoc reset()
    Variant& operator=(const char* value);

private:
    class Implementation;
    memory::unique_ptr<Implementation> _impl;
    friend bool operator==(const Variant&, const Variant&);
};

/// Non-equality
bool operator!=(const Variant& a, const Variant& b);

} // namespace variant
} // namespace a_util

#endif // _A_UTILS_UTIL_VARIANT_VARIANT_HEADER_INCLUDED_

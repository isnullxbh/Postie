/**
 * @file    AreUniqueFields.hpp
 * @author  Oleg E. Vorobiov <isnullxbh(at)gmail.com>
 * @date    02.01.2024
 */

#pragma once

#include <ext/type_list.hpp>

namespace Postie::Models::Detail
{

template<auto UID>
struct FieldHasUid
{
    template<typename Field>
    struct Predicate
    {
        static constexpr auto value = Field::uid == UID;
    };
};

template<typename...>
struct AreUniqueFields;

template<typename Field, typename... Fields>
struct AreUniqueFields<Field, Fields...>
{
private:
    using FieldTypes = ext::type_list<Fields...>;

    template<typename T>
    using Predicate = FieldHasUid<Field::uid>::template Predicate<T>;

public:
    static constexpr auto value =
        FieldTypes::template find_if<Predicate> == FieldTypes::npos &&
        AreUniqueFields<Fields...>::value;
};

template<typename Field>
struct AreUniqueFields<Field>
{
    static constexpr auto value = true;
};

} // namespace Postie::Models::Detail

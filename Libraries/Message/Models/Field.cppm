/**
 * @file    Field.cppm
 * @author  Oleg E. Vorobiov <isnullxbh(at)gmail.com>
 * @date    07.06.2024
 */

module;

#include <type_traits>

export module Postie.Models.Field;
export import Postie.Base.FixedString;

namespace Postie::Models
{

export template<typename T, FixedString Name>
struct Field
{
    using Type = T;
    static constexpr FixedString name { Name };
};

namespace Detail
{

template<typename T>
struct IsFieldImpl : std::false_type
{};

template<typename T, FixedString Name>
struct IsFieldImpl<Field<T, Name>> : std::true_type
{};

} // namespace Detail

export template<typename T>
struct IsField : Detail::IsFieldImpl<std::remove_cv_t<T>>
{};

} // namespace Postie::Models

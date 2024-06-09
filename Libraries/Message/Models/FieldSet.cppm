/**
 * @file    FieldSet.cppm
 * @author  Oleg E. Vorobiov <isnullxbh(at)gmail.com>
 * @date    07.06.2024
 */

module;

#include <string_view>

export module Postie.Models.FieldSet;

export import Postie.Base.TypeList;
export import Postie.Models.Field;

namespace Postie::Models
{

template<typename... Fields>
consteval auto haveUniqueNames(TypeList<Fields...>) noexcept -> bool
{
    std::string_view names[sizeof...(Fields)];
    auto store_name = [i = 0, &names]<typename T>(TypeHolder<T>) mutable { names[i++] = T::name.data(); };
    (store_name(TypeHolder<Fields>()), ...);

    auto res { true };
    for (std::size_t i = 0; i < sizeof...(Fields); ++i)
    {
        for (std::size_t j = i + 1; j < sizeof...(Fields); ++j)
        {
            if (names[i] == names[j])
            {
                res = false;
                break;
            }
        }
    }
    return res;
}

static_assert( haveUniqueNames(TypeList<Field<char, "abc">, Field<char, "bcd">>()));
static_assert(!haveUniqueNames(TypeList<Field<char, "abc">, Field<char, "abc">>()));

export template<typename... Fields>
    requires (IsField<Fields>::value && ...)
          && requires { haveUniqueNames(TypeList<Fields...>()); }
struct FieldSet
{
    using Items = TypeList<Fields...>;
};

} // namespace Postie::Models

/**
 * @file    TypeList.cppm
 * @author  Oleg E. Vorobiov <isnullxbh(at)gmail.com>
 * @date    07.06.2024
 */

export module Postie.Base.TypeList;

namespace Postie
{

export template<typename... Ts>
struct TypeList
{};

export template<typename T>
struct TypeHolder
{
    using Type = T;
};

} // namespace Postie

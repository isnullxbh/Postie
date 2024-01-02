/**
 * @file    FieldSet.hpp
 * @author  Oleg E. Vorobiov <isnullxbh(at)gmail.com>
 * @date    01.01.2024
 */

#pragma once

#include <ext/type_list.hpp>

#include <Postie/Models/Detail/AreUniqueFields.hpp>

namespace Postie::Models
{

/// A field set model.
/// @tparam  Fields Field types.
/// @ingroup postie-message-set
/// @since   0.1.0
template<typename... Fields>
struct FieldSet : ext::type_list<Fields...>
{
    static_assert(Detail::AreUniqueFields<Fields...>::value, "Fields must have unique UIDs");
};

} // namespace Postie::Models

/**
 * @file    MessageSet.hpp
 * @author  Oleg E. Vorobiov <isnullxbh(at)gmail.com>
 * @date    02.01.2024
 */

#pragma once

#include <ext/type_list.hpp>

#include <Postie/Models/Detail/AreUniqueMessages.hpp>

namespace Postie::Models
{

/// A message set model.
/// @tparam  Messages Message types.
/// @ingroup postie-message-set
/// @since   0.1.0
template<typename... Messages>
struct MessageSet : ext::type_list<Messages...>
{
    static_assert(Detail::AreUniqueMessages<Messages...>::value, "Messages must have unique UIDs");
};

} // namespace Postie::Models

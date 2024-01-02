/**
 * @file    Message.hpp
 * @author  Oleg E. Vorobiov <isnullxbh(at)gmail.com>
 * @date    01.01.2024
 */

#pragma once

namespace Postie::Models
{

/// A base class for message models.
/// @tparam  UID A message identifier.
/// @ingroup postie-message-set
/// @since   0.1.0
template<auto UID>
struct Message
{
    /// A message identifier that is unique within the specified message set.
    static constexpr auto uid = UID;
};

} // namespace Postie::Models

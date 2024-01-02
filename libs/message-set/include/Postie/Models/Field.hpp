/**
 * @file    Field.hpp
 * @author  Oleg E. Vorobiov <isnullxbh(at)gmail.com>
 * @date    01.01.2024
 */

#pragma once

namespace Postie::Models
{

/// A base class for field models.
/// @tparam  UID A field identifier.
/// @ingroup postie-message-set
/// @since   0.1.0
template<auto UID>
struct Field
{
    /// A field identifier that is unique within the field set of the specified message.
    static constexpr auto uid = UID;
};

} // namespace Postie::Models

/**
 * @file    MapMessage.hpp
 * @author  Oleg E. Vorobiov <isnullxbh(at)gmail.com>
 * @date    01.01.2024
 */

#pragma once

#include <Postie/Models/Message.hpp>

namespace Postie::Models
{

/// A map message model.
/// @tparam  UID          A message identifier.
/// @tparam  FieldSetType A field set type.
/// @ingroup postie-message-set
/// @since   0.1.0
template<auto UID, typename FieldSetType>
struct MapMessage : Message<UID>
{
    using FieldSet = FieldSetType; ///< A field set type.
};

} // namespace Postie::Models

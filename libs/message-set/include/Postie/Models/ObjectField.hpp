/**
 * @file    ObjectField.hpp
 * @author  Oleg E. Vorobiov <isnullxbh(at)gmail.com>
 * @date    01.01.2024
 */

#pragma once

#include <Postie/Models/Field.hpp>

namespace Postie::Models
{

/// An object field model.
/// @tparam  UID A field identifier.
/// @tparam  T   Object type.
/// @ingroup postie-message-set
/// @since   0.1.0
template<auto UID, typename T>
struct ObjectField : Field<UID>
{
    using Type = T; ///< Object type.
};

} // namespace Postie::Models

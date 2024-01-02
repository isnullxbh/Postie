/**
 * @file    Models.hpp
 * @author  Oleg E. Vorobiov <isnullxbh(at)gmail.com>
 * @date    01.01.2024
 */

#pragma once

/// @defgroup postie Postie

/// @defgroup postie-message-set Message sets
/// @ingroup  postie

#include <Postie/Models/Field.hpp>
#include <Postie/Models/FieldSet.hpp>
#include <Postie/Models/MapMessage.hpp>
#include <Postie/Models/Message.hpp>
#include <Postie/Models/MessageSet.hpp>
#include <Postie/Models/ObjectField.hpp>

/// An entry-point namespace for the Postie library.
/// @ingroup postie
/// @since   0.1.0
namespace Postie {}

/// Contains models of the corresponding structural components of a message set.
/// @ingroup postie-message-set
/// @since   0.1.0
namespace Postie::Models {}

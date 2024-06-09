/**
 * @file    Message.cppm
 * @author  Oleg E. Vorobiov <isnullxbh(at)gmail.com>
 * @date    09.06.2024
 */

module;

#include <type_traits>

export module Postie.Models.Message;
export import Postie.MessageType;

namespace Postie::Models
{

export template<MessageType Type>
struct Message
{
    static constexpr MessageType type = Type;
};

namespace Detail
{

template<typename T>
struct IsMessageImpl : std::false_type
{};

template<template<MessageType, typename...> typename ConcreteMessage, MessageType Type>
struct IsMessageImpl<ConcreteMessage<Type>>
    : std::bool_constant<std::is_base_of_v<Message<Type>, ConcreteMessage<Type>>>
{};

} // namespace Detail

export template<typename T>
struct IsMessage : Detail::IsMessageImpl<T>
{};

} // namespace Postie::Models

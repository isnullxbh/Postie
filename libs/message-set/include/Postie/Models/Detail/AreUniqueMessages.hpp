/**
 * @file    AreUniqueMessages.hpp
 * @author  Oleg E. Vorobiov <isnullxbh(at)gmail.com>
 * @date    02.01.2024
 */

#pragma once

#include <ext/type_list.hpp>

namespace Postie::Models::Detail
{

template<auto UID>
struct MessageHasUid
{
    template<typename Message>
    struct Predicate
    {
        static constexpr auto value = Message::uid == UID;
    };
};

template<typename... Messages>
struct AreUniqueMessages;

template<typename Message, typename... Messages>
struct AreUniqueMessages<Message, Messages...>
{
private:
    using MessageTypes = ext::type_list<Messages...>;

    template<typename T>
    using Predicate = MessageHasUid<Message::uid>::template Predicate<T>;

public:
    static constexpr auto value =
        MessageTypes::template find_if<Predicate> == MessageTypes::npos &&
        AreUniqueMessages<Messages...>::value;
};

template<typename Message>
struct AreUniqueMessages<Message>
{
    static constexpr auto value = true;
};

} // namespace Postie::Models::Detail

/**
 * @file    MessageSet.cppm
 * @author  Oleg E. Vorobiov <isnullxbh(at)gmail.com>
 * @date    09.06.2024
 */

module;

#include <cstddef>

export module Postie.Models.MessageSet;

export import Postie.Base.TypeList;
export import Postie.Models.Message;

namespace Postie::Models
{

template<typename... Messages>
consteval auto haveUniqueTypes(TypeList<Messages...>) noexcept -> bool
{
    constexpr auto n = sizeof...(Messages);

    MessageType types[n];
    auto init = [i = 0, &types]<typename ConcreteMessage>(TypeHolder<ConcreteMessage>) mutable { types[i++] = ConcreteMessage::type; };
    (init(TypeHolder<Messages>()), ...);

    auto res { true };
    for (std::size_t i = 0; i < n; ++i)
    {
        for (std::size_t j = i + 1; j < n; ++j)
        {
            if (types[i] == types[j])
            {
                res = false;
                break;
            }
        }
    }
    return res;
}

static_assert( haveUniqueTypes(TypeList<Message<MessageType(1)>, Message<MessageType(2)>>()));
static_assert(!haveUniqueTypes(TypeList<Message<MessageType(1)>, Message<MessageType(1)>>()));

export template<typename... Messages>
    requires (IsMessage<Messages>::value && ...)
          && requires { haveUniqueTypes(TypeList<Messages...>()); }
struct MessageSet
{
    using Items = TypeList<Messages...>;
};

} // namespace Postie::Models

/**
 * @file    MessageType.cppm
 * @author  Oleg E. Vorobiov <isnullxbh(at)gmail.com>
 * @date    09.06.2024
 */

module;

#include <cstdint>

export module Postie.MessageType;

namespace Postie
{

export class MessageType
{
public:
    MessageType() = default;

    constexpr explicit MessageType(std::uint32_t value)
        : _value(value)
    {}

    MessageType(const MessageType&) = default;

    auto operator=(const MessageType&) -> MessageType& = default;

    constexpr auto value() const noexcept -> std::uint32_t
    {
        return _value;
    }

    constexpr auto operator==(const MessageType& rhs) const noexcept
    {
        return _value == rhs._value;
    }

    std::uint32_t _value { 0 };
};

} // namespace Postie

/**
 * @file    Message.cppm
 * @author  Oleg E. Vorobiov <isnullxbh(at)gmail.com>
 * @date    07.06.2024
 */

export module Postie.Message;
export import Postie.MessageType;

namespace Postie
{

using MessageId = int;

class Message
{
public:
    virtual ~Message() = default;
    virtual auto id() const noexcept -> MessageId = 0;
    virtual auto type() const noexcept -> MessageType = 0;
};

} // namespace Postie

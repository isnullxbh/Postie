/**
 * @file    FieldMessage.cppm
 * @author  Oleg E. Vorobiov <isnullxbh(at)gmail.com>
 * @date    07.06.2024
 */

export module Postie.Models.FieldMessage;

export import Postie.Models.Field;

namespace Postie::Models
{

export template<auto Type, typename FieldSetT>
struct FieldMessage
{
    static constexpr auto type { Type };
    using FieldSet = FieldSetT;
};

} // namespace Postie::Models

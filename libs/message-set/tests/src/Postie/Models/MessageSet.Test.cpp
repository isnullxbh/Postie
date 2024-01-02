/**
 * @file    MessageSet.Test.cpp
 * @author  Oleg E. Vorobiov <isnullxbh(at)gmail.com>
 * @date    02.01.2024
 */

#include <gtest/gtest.h>

#include <Postie/Models/MessageSet.hpp>
#include <Postie/Models/MapMessage.hpp>
#include <Postie/Models/FieldSet.hpp>
#include <Postie/Models/ObjectField.hpp>

TEST(MessageSetTests, Base)
{
    using namespace Postie::Models;

    using Message1 = MapMessage<10, FieldSet<ObjectField<1, int>, ObjectField<2, char>>>;
    using Message2 = MapMessage<11, FieldSet<ObjectField<1, char>, ObjectField<2, char>>>;
    using Message3 = MapMessage<12, FieldSet<ObjectField<1, int>, ObjectField<2, double>>>;

    using TestMessageSet = MessageSet<Message1, Message2, Message3>;
    static_assert(TestMessageSet::size == 3);
    static_assert(TestMessageSet::contains<Message1>);
    static_assert(TestMessageSet::contains<Message2>);
    static_assert(TestMessageSet::contains<Message3>);
}

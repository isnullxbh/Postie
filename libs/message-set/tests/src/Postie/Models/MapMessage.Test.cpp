/**
 * @file    MapMessage.Test.cpp
 * @author  Oleg E. Vorobiov <isnullxbh(at)gmail.com>
 * @date    01.01.2024
 */

#include <gtest/gtest.h>

#include <Postie/Models/FieldSet.hpp>
#include <Postie/Models/MapMessage.hpp>
#include <Postie/Models/ObjectField.hpp>

TEST(MapMessageTests, Base)
{
    using namespace Postie::Models;

    using TestFieldSet =
        FieldSet<ObjectField<10, int>,
                 ObjectField<11, double>,
                 ObjectField<12, char>>;

    constexpr auto uid { 11 };
    using TestMessage = MapMessage<uid, TestFieldSet>;
    static_assert(TestMessage::uid == uid);
    static_assert(std::is_same_v<TestMessage::FieldSet, TestFieldSet>);
}

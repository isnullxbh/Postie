/**
 * @file    ObjectField.Test.cpp
 * @author  Oleg E. Vorobiov <isnullxbh(at)gmail.com>
 * @date    01.01.2024
 */

#include <type_traits>

#include <gtest/gtest.h>

#include <Postie/Models/ObjectField.hpp>

TEST(ObjectFieldTests, Base)
{
    using namespace Postie::Models;
    constexpr auto uid { 11 };
    using TestField = ObjectField<uid, int>;
    static_assert(TestField::uid == uid);
    static_assert(std::is_same_v<TestField::Type, int>);
}

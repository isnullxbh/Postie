/**
 * @file    Message.Test.cpp
 * @author  Oleg E. Vorobiov <isnullxbh(at)gmail.com>
 * @date    01.01.2024
 */

#include <gtest/gtest.h>

#include <Postie/Models/Message.hpp>

TEST(MessageTests, Base)
{
    using namespace Postie::Models;
    constexpr auto uid { 11 };
    static_assert(Message<uid>::uid == uid);
}

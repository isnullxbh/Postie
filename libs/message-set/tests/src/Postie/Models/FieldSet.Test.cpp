/**
 * @file    FieldSet.Test.cpp
 * @author  Oleg E. Vorobiov <isnullxbh(at)gmail.com>
 * @date    01.01.2024
 */

#include <type_traits>

#include <gtest/gtest.h>

#include <Postie/Models/FieldSet.hpp>
#include <Postie/Models/ObjectField.hpp>

TEST(FieldSetTests, Base)
{
    using namespace Postie::Models;

    using Field1 = ObjectField<10, int>;
    using Field2 = ObjectField<11, double>;
    using Field3 = ObjectField<12, char>;
    using TestFieldSet = FieldSet<Field1, Field2, Field3>;

    static_assert(TestFieldSet::size == 3);
    static_assert(std::is_same_v<TestFieldSet::get<0>, Field1>);
    static_assert(std::is_same_v<TestFieldSet::get<1>, Field2>);
    static_assert(std::is_same_v<TestFieldSet::get<2>, Field3>);
}

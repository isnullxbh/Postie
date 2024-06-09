/**
 * @file    FixedString.cppm
 * @author  Oleg E. Vorobiov <isnullxbh(at)gmail.com>
 * @date    07.06.2024
 */

module;

#include <cstddef>

export module Postie.Base.FixedString;

namespace Postie
{

export template<typename Char, std::size_t N>
class BasicFixedString
{
public:
    constexpr BasicFixedString(const Char(&s)[N + 1])
    {
        for (std::size_t i = 0; i <= N; ++i)
        {
            _data[i] = s[i];
        }
    }

    constexpr auto size() const noexcept -> std::size_t
    {
        return N;
    }

    constexpr auto data() const noexcept -> const Char*
    {
        return _data;
    }

    constexpr auto operator[](std::size_t index) const noexcept -> Char
    {
        return _data[index];
    }

    Char _data[N + 1];
};


export template<typename Char, std::size_t N>
BasicFixedString(const Char(&)[N]) -> BasicFixedString<Char, N - 1>;

#if __cpp_deduction_guides >= 201907L
export template<std::size_t N>
using FixedString = BasicFixedString<char, N>;
#else
// Clang 18 does not support CTADs for alias templates, but GCC 14 does.
export template<std::size_t N>
class FixedString : public BasicFixedString<char, N>
{
public:
    using BasicFixedString<char, N>::BasicFixedString;
};

export template<std::size_t N>
FixedString(const char(&)[N]) -> FixedString<N - 1>;
#endif // __cpp_deduction_guides >= 201907L

} // namespace Postie

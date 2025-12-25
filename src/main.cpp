#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <vector>
#include <format>

void print_line();

int main()
{
    std::vector<float> age_types{15.5f, 18.0f, 24.5f, 29.5f, 34.5f, 39.5f};

    const auto [min_it, max_it] = std::minmax_element(age_types.begin(), age_types.end());

    constexpr float l_minimum = 0.0f;
    constexpr float l_maximum = 10.0f;

    std::vector<int> heights;
    heights.reserve(age_types.size());

    const std::map<int, std::string> columns{
        {0, std::string{static_cast<char>(0xF0), static_cast<char>(0x9F), static_cast<char>(0x9F), static_cast<char>(0xA6)}},
        {1, std::string{static_cast<char>(0xF0), static_cast<char>(0x9F), static_cast<char>(0x9F), static_cast<char>(0xAA)}},
        {2, std::string{static_cast<char>(0xF0), static_cast<char>(0x9F), static_cast<char>(0x9F), static_cast<char>(0xA9)}},
        {3, std::string{static_cast<char>(0xF0), static_cast<char>(0x9F), static_cast<char>(0x9F), static_cast<char>(0xA8)}},
        {4, std::string{static_cast<char>(0xF0), static_cast<char>(0x9F), static_cast<char>(0x9F), static_cast<char>(0xA7)}},
        {5, std::string{static_cast<char>(0xF0), static_cast<char>(0x9F), static_cast<char>(0x9F), static_cast<char>(0xA5)}}};

    /* linear height interpolation */
    for (float age : age_types)
    {
        const float t = (age - *min_it) / (*max_it - *min_it);
        const float scaled = std::lerp(l_minimum, l_maximum, t);
        heights.push_back(static_cast<int>(scaled));
    }

    /* draw */
    for (int level = static_cast<int>(l_maximum) - 1; level >= 0; level--)
    {
        for (std::size_t i = 0; i < heights.size(); i++)
        {
            if (heights[i] >= level)
            {
                std::cout << columns.find(static_cast<int>(i))->second << ' ';
            }

            else
            {
                std::cout << std::format("{:3}", "");
            }
        }

        std::cout << std::endl;
    }

    print_line();

    for (float age : age_types)
    {
        std::cout << age << ' ';
    }

    std::cout << std::endl;

    print_line();

    return 0;
}

void print_line()
{
    const std::string sep{static_cast<char>(0xF0), static_cast<char>(0x9F), static_cast<char>(0x9E), static_cast<char>(0x84)};

    for (int i = 0; i < 45; ++i)
    {
        std::cout << sep;
    }

    std::cout << std::endl;
}
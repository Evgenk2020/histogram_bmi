#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

void print_line();

int main()
{
    std::vector<float> age_types = {15.5, 18.0, 24.5, 29.5, 34.5, 39.5};
    const auto [min, max] = std::minmax_element(std::cbegin(age_types), std::cend(age_types));
    const float l_minimum = 0.0f;
    const float l_maximum = 10.0f;
    std::vector<std::div_t> div_te_vector;

    std::map<int, std::string> columns{
        {0, {(char)0xf0, (char)0x9f, (char)0x9f, (char)0xa6}},
        {1, {(char)0xf0, (char)0x9f, (char)0x9f, (char)0xaa}},
        {2, {(char)0xf0, (char)0x9f, (char)0x9f, (char)0xa9}},
        {3, {(char)0xf0, (char)0x9f, (char)0x9f, (char)0xa8}},
        {4, {(char)0xf0, (char)0x9f, (char)0x9f, (char)0xa7}},
        {5, {(char)0xf0, (char)0x9f, (char)0x9f, (char)0xa5}}};

    for (auto &a : age_types)
    {
        float _linear_interpolation = std::lerp(l_minimum, l_maximum, (a - *min) / (*max - *min));
        div_te_vector.push_back(std::div(static_cast<int>(_linear_interpolation), 1));
    }

    int wil = static_cast<int>(l_maximum);
    while (wil--)
    {
        int i = 0;
        for (auto &a : div_te_vector)
        {
            (a.quot < wil) ? (std::cout << "   ") : ((a.quot == wil) ? (std::cout << columns.at(i) << ' ') : (std::cout << columns.at(i) << ' '));
            i++;
        }

        std::cout << std::endl;
    }

    print_line();

    for (auto &a : age_types)
    {
        std::cout << a << ' ';
    }

    std::cout << std::endl;
    print_line();

    return 0;
}

void print_line()
{
    const std::string str{(char)0xf0, (char)0x9f, (char)0x9e, (char)0x84};
    for (int i = 0; i < 45; i++)
    {
        std::cout << str;
    }

    std::cout << std::endl;
}
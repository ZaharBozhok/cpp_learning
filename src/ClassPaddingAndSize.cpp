#include "gtest/gtest.h"
#include <bitset>
#include <tuple>
#include <cxxabi.h>
#include <type_traits>

std::string demangleClassName(auto v)
{
    int status = -4; /* Some magic for ABI */

    std::unique_ptr<char, void (*)(void *)> res{
        abi::__cxa_demangle(typeid(v).name(), NULL, NULL, &status),
        std::free};
    return (status == 0) ? res.get() : typeid(v).name();
}

void show(auto v)
{
    std::string name = demangleClassName(v);
    if (std::is_pod<decltype(v)>::value)
    {
        std::cout << "   [t = " << name << "]" << '\n'
                  << "      sizeof = " << sizeof(v) << '\n'
                  << "      value = " << v << '\n';
    }
    else
    {
        std::cout << "   [t = " << name << "]" << '\n'
                  << "      sizeof = " << sizeof(v) << '\n';
    }
}

void printClassInfo(const auto &v)
{
    std::string name = demangleClassName(v);
    std::cout << "[T = " << name << "]" << '\n'
              << "   sizeof = " << sizeof(v) << '\n'
              << "   alignment_of = " << std::alignment_of<decltype(v)>::value << '\n';
    std::apply([](auto &&...args)
               { ((show(args)), ...); },
               v);
    std::cout << '\n';
}

TEST(ClassPaddingAndSize, testik)
{
    printClassInfo(std::tuple<char, short int>('a', 1));
    printClassInfo(std::tuple<short int, char, int>(1, 'a', 1));
    printClassInfo(std::tuple<char, double, int>(1, 1.2, 1));
    printClassInfo(std::tuple<double, int, char>(1.2, 1, 'a'));
}
#include <iostream>
#include <string>
#include <utility>

int main()
{
    std::string str1 = "Hello";
    std::cout << "str1 = " << str1 << "\n";

    std::cout << "after std::string str2 = std::move(str1); \n";
    std::string str2 = std::move(str1);
    std::cout << "str2 = " << str2 << "\n";
    std::cout << "str1 = " << str1 << "\n";
}
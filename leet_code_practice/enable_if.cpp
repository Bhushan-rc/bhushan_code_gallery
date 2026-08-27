#include <iostream>

template<typename T>
typename std::enable_if<std::is_integral<T>::value, void>::type
process(T val) {

    std::cout << "\n integer val : " << val;
}

template<typename T>
typename std::enable_if<std::is_floating_point<T>::value, void>::type
process(T val) {

    std::cout << "\n floating val : " << val;
}

int main() {

    process(10);
    process(15.5);
}
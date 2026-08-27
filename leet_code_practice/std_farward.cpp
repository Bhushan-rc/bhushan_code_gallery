#include <iostream>

void process(int& x) {

    std::cout << "Lvalue\n";
}

void process(int&& x) {

    std::cout << "Rvalue\n";
}

void process(std::string& x) {

    std::cout << "Lvalue\n";
}

void process(std::string&& x) {

    std::cout << "\n Rvalue : " << x;
}

template<typename T>
void wrapper(T&& value) {

    process(std::forward<T>(value));
}

int main() {
    
    int x = 10;
    wrapper(x);       // Lvalue
    wrapper(10);      // Rvalue

    std::string txt = "ABC";

    wrapper(txt);       // Lvalue
    wrapper("PQR");      // Rvalue
}
#include<iostream>

class Base {

    public:
    virtual void show() = 0; /* {
        std::cout<<"Base\n";
    }*/
};

class Derived1 : public Base {

    public:
    void show() {
        std::cout<<"Derived1\n";
    }
};

class Derived2 : public Base {

    public:
    void show() {
        std::cout<<"Derived2\n";
    }
};

int main() {

    Base *ptr;

    ptr = new Derived1;
    ptr->show();    // output : Derived1
    delete ptr;

    ptr = new Derived2;
    ptr->show();    // output : Derived2
    delete ptr;
}
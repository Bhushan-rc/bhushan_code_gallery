#include <iostream>

class Base {
public:
    virtual ~Base() {}
};

class Derived1 : public Base {
public:
    void show() {
        std::cout << " Derived1\n\n";
    }
};

class Derived2 : public Base {
public:
    void show() {
        std::cout << " Derived2\n\n";
    }
};

int main() {

    Base* pBase = new Derived1();
    Derived1* pDerived1 = dynamic_cast<Derived1*>(pBase);

    std::cout << " 1) pBase = new " << typeid(*pBase).name() << "\t\t\t\t\t pBase = " << pBase << '\n';
    std::cout << "    Derived1* pDerived1 = dynamic_cast<Derived1*>(pBase)" << "\t pDerived1 = " << pDerived1 << "\n";
    std::cout << "    Output of pDerived1->show()\t\t\t\t\t";

    if (pDerived1)
        pDerived1->show();
    else
        std::cout << " Function not executed\n\n";
    delete pBase;

    pBase = new Derived1();
    Derived2* pDerived2 = dynamic_cast<Derived2*>(pBase);   // this will assign NULL as pBase is initialized with Derived1
                                                            // and dynamically casted to Derived2

    std::cout << " 2) pBase = new " << typeid(*pBase).name() << "\t\t\t\t\t pBase = " << pBase << '\n';
    std::cout << "    Derived2* pDerived2 = dynamic_cast<Derived2*>(pBase)" << "\t pDerived2 = " << pDerived2 << "\n";
    std::cout << "    Output of pDerived2->show()\t\t\t\t\t";

    if (pDerived2)
        pDerived2->show();  // this will not execute
    else
        std::cout << " Function not executed\n\n";
    
    delete pBase;
}
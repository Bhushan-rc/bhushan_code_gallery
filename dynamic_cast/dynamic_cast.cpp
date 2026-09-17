#include <iostream>

/*
    \author:    Bhushan R Chaudhari
    \date:      17/09/2026
    \brief:     program for use of dynamic_cast
*/

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

    std::cout << "\n * dynamic_cast is used for Run-Time Type Identification (RTTI)\n";
    
    std::cout << "\n * For RTTI to identify the dynamic type through a base pointer/reference,"; 
    std::cout << "\n   the base class generally needs to be polymorphic, ie. it has at least one virtual function\n";
    
    std::cout << "\n * In this example class Base contains a virtual destructor : virtual ~Base();";
    std::cout << "\n   the virtual destructor is commonly used because it also makes the class polymorphic";
    std::cout << "\n   and ensures proper destruction through a base pointer\n";

    std::cout << "\n ===================================================================================== \n";

    std::cout << "\n # RTTI is a C++ mechanism used to determine an object's actual type at runtime.";
    std::cout << "\n   It is primarily provided through dynamic_cast and typeid. RTTI is useful when";
    std::cout << "\n   a base-class pointer or reference refers to an object of a derived class. For"; 
    std::cout << "\n   polymorphic classes, the base class must have at least 1 virtual function for"; 
    std::cout << "\n   runtime type information to work correctly.\n";

    std::cout << "\n # One important distinction : RTTI and virtual function dispatch are related to";
    std::cout << "\n   runtime polymorphism but they are not the same thing. Virtual dispatch chooses";
    std::cout << "\n   which function to execute; RTTI determines what the object's runtime type is.\n\n";
}
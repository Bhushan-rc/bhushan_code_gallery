#include<iostream>

/*
    \author:    Bhushan R Chaudhari
    \date:      15/09/2024
    \brief:     this is a program for operator overloading which is easy to 
                understand while reading program or its output
*/

class TestClass {

    private:
    int mem1 = 0, mem2 = 0, mem3 = 0;
    int array[5];

    public:
    TestClass() { 

        std::cout << "\n\t in constructor TestClass()";
    }

    ~TestClass() {

        std::cout << "\n\t in destructor ~TestClass()";
    }

    TestClass(int v1, int v2, int v3) : mem1(v1), mem2(v2), mem3(v3) {

        std::cout << "\n TestClass(int v1, int v2, int v3)";
    }
 
    TestClass &operator = (const TestClass &obj) {
        
        std::cout << "\n TestClass &operator = (const TestClass &obj)";
        mem1 = obj.mem1;
        mem2 = obj.mem2;
        mem3 = obj.mem3;
        return *this;
    }

    TestClass operator + (const TestClass &obj) {

        std::cout<< "\n TestClass &operator + (const TestClass &obj)";

        TestClass out;
        out.mem1 = mem1 + obj.mem1;
        out.mem2 = mem2 + obj.mem2;
        out.mem3 = mem3 + obj.mem3;
        return out;
    }

    TestClass &operator ++ () {

        std::cout << "\n TestClass &operator ++ ()";
        mem1 += 1;
        mem2 += 1;
        mem3 += 1;
        return *this;
    }

    TestClass operator ++ (int) {

        std::cout << "\n TestClass operator ++ (int)";
        TestClass obj = *this;
        mem1++;
        mem2++;
        mem3++;
        return obj;
    }
    
    bool operator == (const TestClass &obj) {

        std::cout << "\n bool operator == (const TestClass &obj)";
        bool ret = mem1 == obj.mem1;
        ret = mem2 == obj.mem2;
        ret = mem3 == obj.mem3;
        return ret;
    }

    static void* operator new[] (std::size_t cnt) {

        std::cout << "\n static void* operator new[] (std::size_t size)";
        void *ptr = ::operator new [](cnt);
        return ptr; 
    }

    static void operator delete[] (void *ptr) {

        std::cout << "\n static void* operator delete[] (void *ptr)";
        ::operator delete [](ptr);
    }

    int operator [] (int id) {

        std::cout << "\n int operator [] (int id)";
        return array[id];
    }

    void operator () (int cnt) {

        std::cout << "\n void operator () (int cnt)";
        for(int i = 0; i < cnt; ++i) {

            array[i] = (i + 1) * 10;
            std::cout<<"\n\t assigning : array[" << i << "] = " << array[i];
        }
    }
    
    friend std::ostream &operator << (std::ostream &out, TestClass &obj) {

        std::cout << "\n\t friend std::ostream &operator << (std::ostream &out, TestClass &obj)";
        out << "\n\t mem1 : " << obj.mem1
            << "\n\t mem2 : " << obj.mem2
            << "\n\t mem3 : " << obj.mem3
            << std::endl;
        return out;
    }

    friend std::istream &operator >> (std::istream &in, TestClass &obj) {

        std::cout << "\n\t friend std::istream &operator >> (std::istream &in, TestClass &obj)";
        std::cout << "\n\t enter int values for mem1, mem2, mem3 : ";
        in >> obj.mem1 >> obj.mem2 >> obj.mem3;
        return in;
    }
};

int main() {
    
    system("cls");

    std::cout << "\n =========================================================";
    TestClass obj1(1, 2, 3), obj2;
    std::cout<< "\n\t in obj1";
    std::cout<< obj1;
    getchar();

    std::cout << "\n =========================================================";
    std::cout<< "\n overloading operator = ";
    obj2 = obj1;
    std::cout<< "\n\t in obj2";
    std::cout<< obj2;
    getchar();

    std::cout << "\n =========================================================";
    std::cout<< "\n overloading operator + ";
    TestClass obj3 = obj1 + obj2;
    std::cout<< "\n\t in obj3";
    std::cout<< obj3;
    getchar();

    std::cout << "\n =========================================================";
    std::cout<< "\n overloading operator pre ++ ";
    ++obj3;
    std::cout<< "\n\t in obj3";
    std::cout<< obj3;
    getchar();

    std::cout << "\n =========================================================";
    std::cout<< "\n overloading operator post ++ ";
    TestClass obj4 = obj3++;
    std::cout<< "\n\t in obj4";
    std::cout<< obj4;
    getchar();

    std::cout << "\n =========================================================";
    std::cout<< "\n overloading operator == ";
    std::cout<< " obj1 == obj2 : " << (obj1 == obj2) << "\n";
    std::cout<< "\t in obj1";
    std::cout<< obj1;
    std::cout<< "\t in obj2";
    std::cout<< obj2;
    getchar();
    
    std::cout << "\n =========================================================";
    std::cout<< "\n overloading operator new[] ";
    TestClass *ptr = new TestClass[5];
    TestClass obj = *ptr;
    getchar();

    std::cout << "\n\n =========================================================";
    std::cout<< "\n functor : overloading operator () ";
    obj(5);
    getchar();
    
    std::cout << "\n\n =========================================================";
    std::cout<< "\n overloading operator [] ";
    for(int i = 0; i < 5; ++i) {
        
        std::cout<<"\n\t reading obj[" << i << "] : " << obj[i] << " ";
    }
    getchar();
    
    std::cout << "\n\n =========================================================";
    std::cout<< "\n overloading operator delete[] ";
    delete []ptr;
    getchar();
 
    std::cout << "\n =========================================================";
    std::cout << "\n overloading operator >> ";
    std::cin >> obj;
    std::cout << "\n\t in obj";
    std::cout << obj;
    getchar();
    
    std::cout << "\n\n =========================================================";
    std::cout<< "\n Operators that can be overloaded"
            << "\n\t + \t - \t * \t / \t %"
            << "\n\t ++ \t --"
            << "\n\t == \t != \t < \t > \t <= \t >="
            << "\n\t = \t += \t -= \t *= \t /="
            << "\n\t [] \t ()"
            << "\n\t << \t >>"
            << "\n\t & \t | \t ^ \t ~"
            << "\n\t && \t || \t !"
            << "\n\t -> \t ->*"
            << "\n\t new \t delete"
            << "\n\t new[] \t delete[]";
    getchar();

    std::cout << "\n\n =========================================================";
    std::cout<< "\n Operators that cannot be overloaded"
            << "\n\t :: \t Scope resolution"
            << "\n\t . \t Member access"
            << "\n\t .* \t Pointer-to-member"
            << "\n\t ?: \t Ternary conditional"
            << "\n\t sizeof"
            << "\n\t typeid"
            << "\n\t alignof";
    getchar();
    
    std::cout << "\n\n";
    return 0;
}
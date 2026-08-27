#include <iostream>
#include <unordered_map>
#include <string>

struct Employee
{
    int id;
    std::string name;

    Employee() {}
    Employee(int _id, std::string _name) : id(_id), name(_name) {}
    
    void operator () (int _id, std::string _name) {

        id = _id;
        name = _name;
    }

    bool operator == (const Employee& other) const {

        return id == other.id && name == other.name;
    }

    friend std::ostream & operator << (std::ostream &out, Employee &emp) {

        out << "\n [ id : " << emp.id << ", name : " << emp.name << " ] = ";
        return out;
    }
};

struct EmployeeHash
{
    std::size_t operator()(const Employee& e) const {

        std::size_t h1 = std::hash<int> {} (e.id);
        std::size_t h2 = std::hash<std::string> {} (e.name);
        std::size_t ret = h1 ^ (h2 << 1);
        return ret;
    }
};

int main()
{
    std::unordered_map<Employee, int, EmployeeHash> employees;

    employees[{101, "AAA"}] = 110000;
    employees[{102, "BBB"}] = 120000;
    employees[{103, "CCC"}] = 130000;
    employees[{104, "DDD"}] = 140000;

    Employee emp;
    
    emp(101, "AAA");
    std::cout << emp << employees[emp] << '\n';

    emp(102, "BBB");
    std::cout << emp << employees[emp] << '\n';

    emp(103, "CCC");
    std::cout << emp << employees[emp] << '\n';

    emp(104, "DDD");
    std::cout << emp << employees[emp] << '\n';

    return 0;
}
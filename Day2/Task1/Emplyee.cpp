#include <iostream>
#include <string>
#include "separateInterface.cpp"
using namespace std;

int main()
{
    Employee e1 = Employee("Haseeb", "mardan");
    Employee e2 = Employee("Bilal", "Malakand");
    Employee e3 = Employee("Muhammad Hammad", "Pindi");

    e1.ShowMembers();

    Employee* objPtr = new Salaried_Emp("Haseeb","Mardan",300);
    objPtr ->calculateSalary();
}

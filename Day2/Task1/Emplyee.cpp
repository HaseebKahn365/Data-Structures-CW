#include <iostream>
#include <string>
#include "separateInterface.cpp"
using namespace std;

int main()
{

    Employee* Salaried_Emp_Ptr = new Salaried_Emp("Haseeb","Mardan",300);
    //300 dollars paid daily to the Salaried Employee
    Salaried_Emp_Ptr ->calculateSalary();


    Employee* Hourly_Emp_Ptr = new Hourly_Emp("Muhammad Bilal", "Malakan", 8*30, 34);
    //8 hours per day for 30 days. 34 dollars per hour 
    Hourly_Emp_Ptr -> calculateSalary();
}

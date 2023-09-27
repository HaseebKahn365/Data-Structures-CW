#include <iostream>
#include <vector>
#include <string>
#include "separateInterface.cpp" 

using namespace std;
int main() {
    Employee *empPtr = new Salaried_Emp("Haseeb", "My Adress", 100);
    empPtr -> calculateSalary();

    
    vector<Employee*> employees;

    employees.push_back(new Salaried_Emp("Haseeb", "Mardan", 1000));
    employees.push_back(new Hourly_Emp("Bilal", "Malakand", 40, 20));

    for(int i=0 ; i<7000000000; i++){

        employees.push_back(new Salaried_Emp( "Hamza "+  std::to_string(i), "Malakand", 1000));
        
    }

    for (auto emp : employees) {
        emp->calculateSalary();
        emp->ShowMembers();
    }

   
    return 0;
}
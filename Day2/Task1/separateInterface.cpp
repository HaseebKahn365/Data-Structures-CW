#include<iostream>
using namespace std;

class Employee{
    string name;
    string address;

    public:
    Employee(string name1, string adress2) : name(name1), address(adress2){};

    void ShowMembers(){
        cout<<"Name of the employee: "<< name<< "\n";
        cout<<"Adress of the employee: "<<address<<"\n";
    }

    virtual void calculateSalary(){};

};

class Hourly_Emp : public Employee{

    int hours;
    int salaryPerHour;

    public:

    Hourly_Emp(string name1, string address1, int no_of_hours, int salary_per_hour) : Employee(name1, address1), hours(no_of_hours), salaryPerHour(salary_per_hour){}

    void calculateSalary(){
        cout<<"Salary of the Salaried Employee is "<<salaryPerHour *hours<<endl;
    }
    
    void showMembers(){
        ShowMembers();
        cout<<"now of the hours: "<< hours<< "\n";
        cout<<"Salary per hour of the employee: "<<salaryPerHour<<"\n";

    }


};



class Salaried_Emp : public Employee{

    int salaryPerDay;

    public:
    Salaried_Emp(string name1, string address1, int SalaryPerDay) : Employee(name1, address1), salaryPerDay(SalaryPerDay){}

    
    void calculateSalary(){
        cout<<"Salary of the salaried employee is "<< salaryPerDay*30<<endl;
    }

    void showMembers(){
        ShowMembers();
        cout<<"Salary per day of the salaried employee: "<<salaryPerDay<<"\n";

    }

};
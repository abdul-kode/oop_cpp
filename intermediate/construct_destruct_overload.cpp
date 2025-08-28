#include<iostream>
#include <string>
using namespace std;

class Employee {
    public:
    string name;
    int id;
    int salary;

    // constructor
    Employee();
    // constructor overload
    // type or no of parameters must different
    Employee(int salary);
    // destructor
    ~Employee();
};

Employee::Employee() {
    salary = 10000;
    cout<<"\nDefualt Constructor is called!"<<endl;
}

Employee::Employee(int salary) {
    this->salary = salary;
    cout<<"Costructor Overloaded and the value of salary is now not default."<<endl;
}

Employee::~Employee() {
    cout<<"Killing the instance\n"<<endl;
}



int main () {
    Employee *e1;
    e1 = new Employee;

    cout<<"First Employee() Salary is ..."<<endl;
    cout<<e1->salary<<endl;
    delete e1;

    Employee *e2 = new Employee(20000);
    cout<<"Second Employee(20000) is called ..."<<endl;
    cout<<"Salary is: "<<e2->salary<<endl;
    delete e2;

    // fixing the dangling pointer
    e1= NULL; //don't want to use anymore
    e2= NULL;

    cout<<"End of main"<<endl;
    return 0;
}

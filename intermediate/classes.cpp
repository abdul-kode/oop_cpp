#include<iostream>
using namespace std;

class Employee {
    public:
    string name;
    int id;

    void sign_in(){
        cout<<"Signing in ..."<<endl;
    }
    void sign_out();
};

// just to show that it can be made out of class but you must prototype it in the class
void Employee::sign_out(){
    cout<<"Signing out ..."<<endl;
}


int main () {
    // simply making an instance and playing with it
    Employee e1;
    e1.name = "Nauman";
    cout<<"\nName: "<<e1.name<<endl;
    e1.sign_in();

    // making an instance but pointing a pointer to it

    // stack object
    Employee *e2;
    e2 = &e1;
    // instead of writing like that i will use heap object

    // heap object
    Employee *e = new Employee;
    e->name = "Mr. Nauman";
    cout<<"\nName: "<<e->name<<endl;
    e->sign_out();
    cout<<endl;
    delete e;
    return 0;
}

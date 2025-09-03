#include<iostream>
using namespace std;

class Employee {
    protected:
    int pay_rate;

    public:
    friend void access_payrate_directly (Employee *e);

    void set_pay_rate (int pay_rate);

    int get_pay_rate ();

};
void Employee::set_pay_rate(int pay_rate) {
    if (pay_rate > 15000) {
        this->pay_rate = pay_rate;
    }
    else {
        cout<<"Payrate "<<pay_rate<<" not acceptable."<<endl;
    }
}
int Employee::get_pay_rate(){
    return pay_rate;
}

// For faculty members
class Faculty_members : public Employee {
    public:
    // override
    void set_pay_rate (int pay_rate);
};
void Faculty_members::set_pay_rate(int pay_rate) {
    if (pay_rate > 25000) {
        this->pay_rate = pay_rate;
    }
    else {
        cout<<"Payrate "<<pay_rate<<" not acceptable."<<endl;
    }
}

// Friends
void access_payrate_directly (Employee *e) {
    cout<<"Payrate: "<<e->pay_rate<<endl;
}

int main () {
    Employee *a = new Employee;

    a->set_pay_rate(18000);
    cout<<"Current payrate: "<<a->get_pay_rate()<<endl;

    a->set_pay_rate(14999);
    cout<<"Current payrate: "<<a->get_pay_rate()<<endl;

    a->set_pay_rate(23982398);
    cout<<"Current payrate: "<<a->get_pay_rate()<<endl;

    delete a;

    Faculty_members *f = new Faculty_members;

    f->set_pay_rate(39499);
    cout<<"\nCurrent payrate: "<<f->get_pay_rate()<<endl;

    f->set_pay_rate(23334);
    cout<<"Current payrate: "<<f->get_pay_rate()<<endl;

    f->set_pay_rate(3232324);
    cout<<"Current payrate: "<<f->get_pay_rate()<<endl;

    f->set_pay_rate(64445334);
    cout<<"Current payrate: "<<f->get_pay_rate()<<endl;
    delete  f;

    cout<<"\nFriend function use"<<endl;
    Employee *e = new Employee;
    e->set_pay_rate(16000);
    access_payrate_directly(e);

    return 0;
}

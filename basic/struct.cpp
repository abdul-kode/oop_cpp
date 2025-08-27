#include<iostream>
using namespace std;

struct teacher{
    string name;
    string sub;
    int id;
};

int main () {
    teacher t1;
    t1.name = "Bilal";
    t1.sub = "DLD";
    t1.id = 2024;

    // array of struct
    teacher t[5];
    t[0].name = "Bilal";

    cout<<t1.name<<" using simple variable"<<endl;
    cout<<t1.id<<endl;
    cout<<t[0].name<<" using array"<<endl;


}

#include <algorithm>
#include<iostream>
#include <tuple>
using namespace std;

class Plugin {

    public:
    void apply_filter(int img[5][5]);
    virtual void apply_filter2(int img[5][5]);

    //making a pure virtual function
    virtual void pure_fun() = 0;
};
void Plugin :: apply_filter (int img[5][5]) {
    cout<<"Doing nothing ..."<<endl;
}
void Plugin :: apply_filter2 (int img[5][5]) {
    cout<<"Testing virtual function"<<endl;
}

// to make the img black
class Mk_it_black : public Plugin {
    public:
    void apply_filter(int img[5][5]);
    void apply_filter2(int img[5][5]);
    void pure_fun();
};
void Mk_it_black :: apply_filter(int img[5][5]) {
    for (int i=0; i<5; i++){
        for (int j=0; j<5; j++){
            img[i][j] = 0;
        }
    }
}
void Mk_it_black :: apply_filter2 (int img[5][5]) {
    for (int i=0; i<5; i++){
        for (int j=0; j<5; j++){
            img[i][j] = 0;
        }
    }
}
void Mk_it_black :: pure_fun() {
    cout<<"\nJust calling the abstract function"<<endl;
}

// to make the img white
class Mk_it_white : public Plugin {
    public:
    void apply_filter2(int img[5][5]);
    void pure_fun();
};
void Mk_it_white :: apply_filter2(int img[5][5]) {
    for (int i=0; i<5; i++){
        for (int j=0; j<5; j++){
            img[i][j] = 255;
        }
    }
}
void Mk_it_white :: pure_fun() {
    cout<<"\nJust calling the abstract function"<<endl;
}


void intialize_img (int a[5][5]) {
    int val = 0;
    for (int i=0; i<5; i++){
        for (int j=0; j<5; j++){
            a[i][j] = val;
            val += 1;
        }
    }
}
void display_img (int a[5][5]) {
    for (int i=0; i<5; i++){
        for (int j=0; j<5; j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

Plugin * select_filter(int a[5][5]) {
    string plugin_name = "MIB";

    Plugin *sf;
    if (plugin_name=="MIW") {
        cout<<"White filter: "<<endl;
        sf = new Mk_it_white;
    }
    else {
        cout<<"Black filter: "<<endl;
        sf = new Mk_it_black;
    }
    return sf;
}

int main () {
    int img[5][5];
    intialize_img(img); //intitalizing the matrix

    cout<<"\nBefor: "<<endl;
    display_img(img);

    cout<<"\nUsing reference variable without virtual function ..."<<endl;
    Plugin *p;
    Mk_it_black *mb = new Mk_it_black; // creating child class instance
    p = mb; // storing child class instance in reference variable
    p->apply_filter(img); //this will display "Doing nothing"

    // if we want to actually use the child class functin throung parent class reference variable
    // we must change the parent class fucntion to virtual
    cout<<"\nUsing reference varaibel with virtual function ..."<<endl;
    Plugin *p1;
    Mk_it_white *mw = new Mk_it_white; // creating child class instance
    p = mw; // storing child class instance in reference variable
    p->apply_filter2(img); //this will convert the img to white
    cout<<"After white filter: "<<endl;
    display_img(img);

    //still have a problem of filters using in main function!
    intialize_img(img);
    cout<<"\nInitialized agian: "<<endl;
    display_img(img);
    cout<<"\nTo avoid using 3rd party plugin names in main class, making a separate function"<<endl;
    Plugin *p2;
    p2 = select_filter(img);
    p2->apply_filter2(img);
    display_img(img);

    //using pure virtual fxn(abstract)
    Plugin *ab;
    // You can not instantiate the abstract class. E.g: Plugin *ab = new Plugin; or Plugin q;

    Mk_it_black *m_ab = new Mk_it_black;
    ab = m_ab;
    m_ab->pure_fun();

    return 0;
}

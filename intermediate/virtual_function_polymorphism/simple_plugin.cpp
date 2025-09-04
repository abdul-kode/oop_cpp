#include<iostream>
#include <tuple>
using namespace std;

class Plugin {

    public:
    void apply_filter(int img[5][5]);
};
void Plugin :: apply_filter (int img[5][5]) {
    cout<<"Doing nothing ..."<<endl;
}

// to make the img black
class Mk_it_black : public Plugin {
    public:
    void apply_filter(int img[5][5]);
};
void Mk_it_black :: apply_filter(int img[5][5]) {
    for (int i=0; i<5; i++){
        for (int j=0; j<5; j++){
            img[i][j] = 0;
        }
    }
}

// to make the img white
class Mk_it_white : public Plugin {
    public:
    void apply_filter(int img[5][5]);
};
void Mk_it_white :: apply_filter(int img[5][5]) {
    for (int i=0; i<5; i++){
        for (int j=0; j<5; j++){
            img[i][j] = 255;
        }
    }
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


int main () {
    int img[5][5];
    intialize_img(img); //intitalizing the matrix

    cout<<"Befor: "<<endl;
    display_img(img);

    cout<<"\nCalling Parent class filter function ..."<<endl;
    Plugin *p = new Plugin;
    p->apply_filter(img);

    cout<<"\nAfter White filter : "<<endl;
    Mk_it_black *b = new Mk_it_black;
    b->apply_filter(img);
    display_img(img);
    delete b;

    cout<<"\nAfter Black filter : "<<endl;
    Mk_it_white *w = new Mk_it_white;
    w->apply_filter(img);
    display_img(img);


}

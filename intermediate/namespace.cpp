#include<iostream>

namespace first {
    int var = 3;
}

namespace second {
    int var = 5;
}

int main () {
    std::cout<<"\nwithout using namespace: (Manually)"<<std::endl;
    std::cout<<"First Var: "<<first::var<<std::endl;

    using namespace std;
    cout<<"\nUsing namespace standard for just cout: "<<endl;
    cout<<"Manually Second Var: "<<second::var<<endl;

    using namespace first;
    cout<<"\nUsing namespace std and first"<<endl;
    cout<<"First Var: "<<var<<endl;

    cout<<"\nWe can not use two namespace with same global variables"<<endl;
    using namespace second;
    // cout<<var<<endl; this will raise error bcz
    // the compiler will not know which var we are talking about
    cout<<"Manually first: "<<first::var<<endl;
    cout<<"Manually second: "<<second::var<<endl;

    return 0;
}

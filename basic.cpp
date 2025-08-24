#include <iostream>
using namespace std;

int main () {
    char C;
    C = 'A';

    cout<<C<<endl; // in memory it will store as int but compiler know to treat it like character

    int v;
    cout<<"Enter your age: ";
    cin>>v;

    // Note: values other then zero(0) is consider true e.g 3, 212, 40 in boolean
    if (v > 17){ // Here if the value is greater than 17 e.g 18, 32, 442 it will return true and so the if statement will execute
        cout<<"You can vote bcz you are consider an adult now"<<endl;
    }
    else {
        cout<<"You can not vote bcz your age is below 18"<<endl;
    }

    for (int i=0; i<20; i+=2){ // i is a function local scope variable
        cout<<i<<endl;
    }

    // array
    int a[3][3];

    for (int i=0; i<3; i++){
        for (int j=1; j<4; j++){
            a[i][j] = i*j;
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

    // character array

    char c[] = "Hello1";

    for (int i; i<7; i++){
        cout<<c[i]<<endl; /*in this output we observe an empty line at the end
        it's because character array store an extra thing called null terminator
        the empty line is not because of that null terminator but it is because there
        is nothing and the loop execute it and so in loop there is endl which cause the empty line*/
    }

    // now char c[] == string a which means you can simply use string
    // also we can use it without using loop and that's the power of string or charater array
    // e.g:

    string s = "Hello2";
    cout<<c<<endl;
    cout<<s<<endl;    //by deafult cout know to stop at null terminator
    cout<<s.length()<<endl;


    return 0;
}

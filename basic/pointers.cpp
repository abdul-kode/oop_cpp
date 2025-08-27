#include <iostream>
using namespace std;

int main () {
    int *p; // store an address (Note: pointer is an integer pointer it can not point any value other than int)
    int x;

    x = 25;
    p = &x;

    cout<<"Address of x                 :"<<&x<<endl; //print the address of x variable on console
    cout<<"Value of x                   :"<<x<<endl;  //will print the value of x on console
    cout<<"Value of x through pointer   :"<<*p<<endl; //print the value stored on the address of x to which p is pointing
    cout<<"Address of pointer p         :"<<&p<<endl; //print the address of pointer p

    int a[] = {1, 2, 3};
    int *p2 = a;

    // the below code will print same output of address of starting array a
    cout<<"\nAddress of array a:"<<endl;
    cout<<"using address operater   :"<<&a[0]<<endl;
    cout<<"simply calling a         :"<<a<<endl;
    cout<<"print value of pointer   :"<<p2<<endl;

    cout<<"\n1st value of array a                               : ";
    cout<<a[0]<<endl;   //this will print the value of array at index 0

    /* now we can also icrement the pointer
    which will shift the pointing from
    0 index to 1st index of the array */

    cout<<"2nd value of array a using pointer increment method: ";
    p2 = p2+1;
    cout<<*p2<<endl; // 2 will be print on console as a[1] = 2
}

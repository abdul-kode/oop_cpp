#include <iostream>
#define SIZE 5
#define ABS(a) ((a)<0 ? -(a) : (a)) //this is an example of Macros(look like function but not actually is.)
#define UTILITY_SERIVICE
using namespace std;

#ifdef UTILITY_SERIVICE
int calculate_bills_amout (int i, int j, int k) {
    return i+j+k;
}
#endif


int main () {
    for (int i=0; i<SIZE; i++) {
        cout<<i+1<<endl;
    }

    cout<<"Abs value: "<<ABS(-5)<<endl; //after preprocessor this line will look like this: cout<<ABS(-5) ((-5)<0 ? -(a) : (a))

    #ifdef UTILITY_SERIVICE
    int total_amount = calculate_bills_amout(3, 3, 4);
    cout<<"Bills total amount: "<<total_amount<<endl;
    #endif

    return 0;




}

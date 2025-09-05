#include<iostream>
using namespace std;

template<class T>
T find_min (T x, T y) {
    T result;
    result = (x < y) ? x : y;
    return result;
}

int main () {
    int result;
    result = find_min<int>(4, 3);
    cout<<"Min of int: "<<result<<endl;

    string result2;
    result2 = find_min<string>("Ali", "Usaman");
    cout<<"Min of string: "<<result2<<endl;

    return 0;

    //different from macros because work at runtime not compile time
}

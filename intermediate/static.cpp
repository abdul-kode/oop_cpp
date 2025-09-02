#include <iostream>
using namespace std;

class User {
    int id;
    static int next_id;

    public:
    static int next_user_id ();

    User() {
        id = User::next_user_id();
    }

    int get_id () {
        return id;
    }


};
int User::next_id = 0;

int User::next_user_id () {
    next_id++;
    return next_id;
}


int fib(int n) {
    static int count = 0;

    if (n == -1) {
        return count;
    }

    count += 1;

    if (n<=1) {
        return n;
    }
    else {
        return fib(n-2) + fib(n-1);
    }

}

int main () {
    User u;
    cout<<"User u ID: "<<u.get_id()<<endl;

    User v;
    cout<<"User v ID: "<<v.get_id()<<endl;

    fib(30);
    cout<<"Count: "<<fib(-1)<<endl;

    return 0;
}

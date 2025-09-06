#include <cstdio>
#include<iostream>
#include <unistd.h>
using namespace std;

#define SIZE 5

void pause_dis () {
    getchar();
}

class Queue {
    private:
    float q[SIZE];
    bool is_full, is_empty;
    int in, out;

    void inc(int *arrow);

    public:
    Queue();
    void enqueue (float val);
    float dequeue ();
    void display_queue ();
};
Queue::Queue () {
    cout<<"Construtor Called ..."<<endl;
    for (int i=0; i<SIZE; i++){
        q[i] = 0;
    }

    in = out = 0;
    is_full = false;
    is_empty = true;
}
void Queue::inc(int *arrow) {
    if (*arrow+1 == SIZE) {
        *arrow = 0;
    }
    else {
        *arrow += 1;
    }
}
void Queue::enqueue (float val) {
    if (is_full) {
        throw "Queue is Full";
    }

    q[in] = val;
    inc(&in);

    if (in==out){
        is_full = true;
    }
    is_empty = false;
}
float Queue::dequeue() {
    float val;
    if (is_empty) {
        throw "Queue is empty,nothing to dequeue ...";
    }

    val = q[out];
    inc(&out);

    if (in==out){
        is_empty = true;
    }
    is_full = false;

    return val;
}
void Queue::display_queue() {
    cout << "[\t";
    for (int i=0; i<SIZE; i++){
        cout << q[i] << "\t";
    }
    cout << "]" << endl;

    cout<<" \t";
    for (int i=0; i<SIZE; i++) {
        cout<<i<<"\t";
    }
    cout << " " << endl;

    cout<<" ";
    for (int i=0; i<=in; i++) {
        cout<< "\t";
    }
    cout<<"^in"<<endl;

    cout<<" ";
    for (int i=0; i<=out; i++) {
        cout<< "\t";
    }
    cout<<"^out"<<endl;

    pause_dis();
}

int main () {
    Queue que;

    que.display_queue();

    que.enqueue(10.43);
    que.display_queue();

    que.enqueue(22.65);
    que.display_queue();

    que.enqueue(34.23);
    que.display_queue();

    que.enqueue(46.56);
    que.display_queue();

    que.enqueue(58.21);
    que.display_queue();

    // que.enqueue(328); this will throw error if we decomment it
    // we can also handle this with try catch like below ...

    try {
        cout << endl << "Now dequeue ..."<<endl;
        cout << "Got val: " << que.dequeue() <<endl; que.display_queue();
        cout << "Got val: " << que.dequeue() <<endl; que.display_queue();
        cout << "Got val: " << que.dequeue() <<endl; que.display_queue();
        cout << "Got val: " << que.dequeue() <<endl; que.display_queue();
        cout << "Got val: " << que.dequeue() <<endl; que.display_queue();

        cout << "Got val: " << que.dequeue() <<endl; que.display_queue(); //throw error

    }
    catch (const char *msg) {
        cout<<msg<<endl;
    }

    return 0;
}

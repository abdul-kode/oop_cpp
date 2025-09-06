#include<iostream>
#include<vector> //no hetrogenety

using namespace std;

void output_vector_values(vector<int> v);
void reverse_output_vector_values(vector<int> rv);
vector<int> remove(vector<int> rm, int index);

int main () {
    vector<int> marks;

    for (int i=1; i<=5; i++) {
        marks.push_back(i*10);
    }

    int val = marks[1];
    cout<<"\nAt index 1: "<<val<<endl;

    output_vector_values(marks);
    reverse_output_vector_values(marks);
    marks = remove(marks, 1); // 1 is index
    cout<<"\nThe value at index 1 has been removed!"<<endl;
    output_vector_values(marks);

    cout<<endl;
    return 0;
}

void output_vector_values(vector<int> v) {
    cout<<"[ ";
    for (auto i=v.begin(); i!=v.end(); i++){
        cout<<*i<<" ";
    }
    cout<<"]"<<endl;

    // alternatively
    // cout<<"[ ";
    // for (int x: v) {
    //     cout<<x<<" ";
    // }
    // cout<<"]"<<endl;
}
void reverse_output_vector_values(vector<int> rv) {
    cout<<"[ ";
    // for (auto i=rv.end(); i!=rv.begin(); i--){
    //     cout<<*i<<" ";
    // }
    // the above code give us one wrong value in the start so don't do like that
    for (auto i=rv.rbegin(); i!=rv.rend(); i++) {
        cout<<*i<<" ";
    }
    cout<<"]"<<endl;
}
vector<int> remove(vector<int> rm, int index) {
    auto it = rm.begin();
    it += index;
    rm.erase(it);


    return rm;
}

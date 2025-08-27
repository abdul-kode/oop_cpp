#include <iostream>
#include <fstream>
using namespace std;

int main () {
    ofstream fout;
    // string abs_path = "/home/abdul_kaan/Coding/on_git/cpp_learning/build/example.txt";
    string rel_path = "./build/example.txt";
    string line_w = "Sohail: Hello, How are you!\nRishma: I'm fine what about you?";
    fout.open(rel_path);
    cout<<"\nFile opened in write mode"<<endl;
    fout<<line_w;
    fout.close();
    cout<<"File is closed\n"<<endl;

    ifstream fin;
    rel_path = "./build/example.txt";
    fin.open(rel_path);
    cout<<"File opened read mode"<<endl;
    string line_r;
    while (getline(fin, line_r)) {
        cout<<line_r<<endl;
    }
    fin.close();
    cout<<"File is closed\n"<<endl;
}

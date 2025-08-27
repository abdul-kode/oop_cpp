#include <iostream>
#include <fstream>
using namespace std;

void output(int a[][3], int rows, int columns);

int main () {
    int pixels[3][3];
    int val = 1;
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            pixels[i][j] = val;
            val += 1;
        }
    }
    // Reading Pixels
    cout<<"Reading Pixels ..."<<endl;
    output(pixels, 3, 3);

    // making a file and storing binary data in it
    string path = "./build/data.bin";
    val = 1;
    ofstream fout(path, ios::binary);
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            fout.write((char *)&pixels[i][j], sizeof(int));
        }
    }
    fout.close();

    // reseting data
    cout<<"Reseting pixels..."<<endl;
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            pixels[i][j] = 0;
        }
    }

    output(pixels, 3, 3);

    // reading from the file
    cout<<"Reading again but this time from file..."<<endl;
    ifstream fin(path, ios::binary);
    if (fin.fail()) {
        cout<<"Failed to read the file ..."<<endl;
    }
    else {
        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                fin.read((char *)&pixels[i][j], sizeof(int));
            }
        }
    }
    fin.close();
    output(pixels, 3, 3);
}

void output(int a[][3], int rows, int columns) {
    for (int i=0; i<rows; i++) {
        for (int j=0; j<columns; j++) {
            cout<<a[i][j]<< " ";
        }
        cout<<endl;
    }
}

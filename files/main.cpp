//
//  main.cpp
//  files
//
//  Created by Артем on 02.04.2020.
//  Copyright © 2020 Артем. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

void ReadAll(const string& path){
    ofstream output("output.txt");
    ifstream input(path);
    if (input){
        string line;
        while (getline(input,line)) {
            cout << line << endl;
            output << line << endl;
        }
    }
}

int main(int argc, const char * argv[]) {
    //const string path = "/Users/artem/Documents/Coursera/белый пояс/files/files/input.txt";
    const string path = "input.txt";
    ReadAll(path);
    return 0;
}

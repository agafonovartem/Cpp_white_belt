//
//  main.cpp
//  tabular_ro
//
//  Created by Артем on 03.04.2020.
//  Copyright © 2020 Артем. All rights reserved.
//
#include <fstream>
#include <iostream>
#include <iomanip>


using namespace std;

void ReadTable (string path){
    ifstream input(path);
    int m, n, k;
    if (input){
        input >> n >> m;
        for (int i = 0; i < n; i ++){
            for (int j = 0; j < m; j ++){
                input >> k;
                input.ignore(1);
                if (j < m - 1){
                    cout << setw(10) << k << ' ';
                }
                else{
                    cout << setw(10) << k << endl;
                }
            }
        }
        
    }
}

int main(int argc, const char * argv[]) {
    //string path = "/Users/artem/Documents/Coursera/белый пояс/tabular_ro/tabular_ro/input.txt";
    string path = "input.txt";
    ReadTable(path);
    return 0;
}

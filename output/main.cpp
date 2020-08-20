//
//  main.cpp
//  output
//
//  Created by Артем on 03.04.2020.
//  Copyright © 2020 Артем. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>


using namespace std;


int main() {
    //ifstream input("/Users/artem/Documents/Coursera/белый пояс/output/output/input.txt");
    ifstream input("input.txt");
    float n;
    string line;
    while (input >> n){
        cout << fixed << setprecision(3) << n << endl;
    }
    return 0;
}

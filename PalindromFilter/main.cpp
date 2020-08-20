//
//  main.cpp
//  PalindromFilter
//
//  Created by Артем on 01.12.2019.
//  Copyright © 2019 Артем. All rights reserved.
//

#include <iostream>
#include <iostream>
#include <string>
using namespace std;


bool IsPalindrom(string w){
    for (int i = 0; i < w.size(); i++){
        if (w[i] != w[w.size() - 1 - i]){
            return false;
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

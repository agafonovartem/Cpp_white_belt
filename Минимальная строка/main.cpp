//
//  main.cpp
//  Минимальная строка
//
//  Created by Артем on 26.11.2019.
//  Copyright © 2019 Артем. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    string a, b, c;
    cin >> a >> b >> c;
    if (a < b){
        if (b < c){
            cout << a;
            }
        else{
            if (a < c){
                cout << a;
            }
            else {
                cout << c;
            }
        }
    }
    else{
        if (b > c){
            cout << c;
        }
        else{
            cout << b;
            }
        }
    
    return 0;
}

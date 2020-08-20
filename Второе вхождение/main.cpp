//
//  main.cpp
//  Второе вхождение
//
//  Created by Артем on 26.11.2019.
//  Copyright © 2019 Артем. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;


int main(int argc, const char * argv[]) {
    string s;
    int flag = 0;
    cin >> s;
    for (int i = 0; i < s.size(); i++){
        if (s[i] == 'f'){
            flag ++;
            if (flag == 2){
                cout << i;
            }
        }
    }
    if (flag == 1){
        cout << -1;
    }
    if (flag == 0){
        cout << -2;
    }
    return 0;
}

//
//  main.cpp
//  НОД
//
//  Created by Артем on 26.11.2019.
//  Copyright © 2019 Артем. All rights reserved.
//

#include <iostream>
using namespace::std;
int main(int argc, const char * argv[]) {
    int a, b, q, r;
    cin >> a >> b;
    
    q = a / b;
    r = a % b;
    while (r != 0) {
        a = b;
        b = r;
        q = a / b;
        r = a % b;
    }
    
    cout << b;
    
    
    return 0;
}

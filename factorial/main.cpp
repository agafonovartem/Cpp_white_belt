//
//  main.cpp
//  factorial
//
//  Created by Артем on 01.12.2019.
//  Copyright © 2019 Артем. All rights reserved.
//

#include <iostream>
using namespace std;

int Factorial(int n){
    if (n <= 0){
        return 1;
    }
    
    else{
        int S = 1;
        for (int i = 1; i <= n; i++){
            S = S * i;
        }
        return S;
    }
    }
    

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    cout << Factorial(n);
    return 0;
}

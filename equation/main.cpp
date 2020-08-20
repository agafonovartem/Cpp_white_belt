//
//  main.cpp
//  equation
//
//  Created by Артем on 26.11.2019.
//  Copyright © 2019 Артем. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, const char * argv[]) {
    double a, b, c;
    double det, x1, x2;
    cin >> a >> b >> c;
    if (a != 0){
        det = b*b - 4*a*c;
        if (det >=0){
            x1 = (sqrt(det) - b) / (2 * a);
            x2 = (- sqrt(det) - b) / (2 * a);
            if (x1 == x2){
                cout << x1;
            }
            else{
                cout << x1 << " " << x2;
            }
        }
    }
    else{
        if (b != 0) {
            x1 = -c / b;
            cout << x1;
            }
        }
    
    return 0;
}


//
//  main.cpp
//  двоичная система
//
//  Created by Артем on 26.11.2019.
//  Copyright © 2019 Артем. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    int N, r;
    vector<int> answer;
    cin >> N;
    
    do{
        r = N % 2;
        answer.push_back(r);
        N = N / 2;
        
    } while(N > 0);
    
    for (long i = answer.size() - 1; i >= 0 ;i--){
        cout << answer[i];
    }
    return 0;
}

//
//  main.cpp
//  sort_mod
//
//  Created by Артем on 23.03.2020.
//  Copyright © 2020 Артем. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        v.push_back(a);
    }
    
    sort(begin(v), end(v), [](int x, int y){return (abs(x) < abs(y));});
    for (const auto& i : v){
        cout << i << " ";
    }
    return 0;
}

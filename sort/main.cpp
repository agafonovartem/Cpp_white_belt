//
//  main.cpp
//  sort
//
//  Created by Артем on 26.03.2020.
//  Copyright © 2020 Артем. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    vector<int> a = {1, 2, 5, 9, 0, 12 };
    sort(a.begin(), a.end());
    for (auto item: a){
        cout << item  << " ";
    }
    return 0;
}

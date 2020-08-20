//
//  main.cpp
//  unique_strings
//
//  Created by Артем on 22.03.2020.
//  Copyright © 2020 Артем. All rights reserved.
//

#include <iostream>
#include <set>
using namespace std;

int main() {
    int n;
    set<string> set;
    string s;
    
    cin >> n;
    
    for (int i = 0; i < n; i++){
        cin >> s;
        set.insert(s);
    }
    cout << set.size() << endl;
    return 0;
}

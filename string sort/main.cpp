//
//  main.cpp
//  string sort
//
//  Created by Артем on 23.03.2020.
//  Copyright © 2020 Артем. All rights reserved.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <ctype.h>
using namespace std;


string lowercase(string& s){
    for (auto& i : s){
        i = tolower(i);
        //cout << i;
    }
    return s;
}

int main() {
    int n;
    cin >> n;
    vector<string> v;
    
    
    
    for (int i = 0; i < n; i++){
        string a;
        cin >> a;
        v.push_back(a);
    }
    
    sort(begin(v), end(v), [](string a, string b){
        return lowercase(a) < lowercase(b);
    });
    for (const auto& i : v){
        cout << i << " ";
    }
    return 0;
}

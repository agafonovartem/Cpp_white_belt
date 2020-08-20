//
//  main.cpp
//  set_of_values
//
//  Created by Артем on 22.03.2020.
//  Copyright © 2020 Артем. All rights reserved.
//

#include <iostream>
#include <map>
#include <set>
using namespace  std;


set<string> BuildMapValuesSet(const map<int, string>& m) {
    set<string> s;
    for (const auto& item : m){
        s.insert(item.second);
    }
    return s;
}

/*
int main(int argc, const char * argv[]) {
    set<string> values = BuildMapValuesSet({
        {1, "odd"},
        {2, "even"},
        {3, "odd"},
        {4, "even"},
        {5, "odd"}
    });

    for (const string& value : values) {
      cout << value << endl;
    }
    return 0;
}
*/

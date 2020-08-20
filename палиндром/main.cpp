//
//  main.cpp
//  палиндром
//
//  Created by Артем on 01.12.2019.
//  Copyright © 2019 Артем. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;


bool IsPalindrom(string w){
    for (int i = 0; i < w.size(); i++){
        if (w[i] != w[w.size() - 1 - i]){
            return false;
        }
    }
    return true;
}

 vector<string> PalindromFilter(vector<string> words, int minLength){
     vector<string> answer;
     for (auto w: words){
         if (IsPalindrom(w) == true && w.size() >= minLength){
             answer.push_back(w);
         }
     }
     return answer;
}

int main(int argc, const char * argv[]) {
    vector<string> words ((istream_iterator<string>(cin )));
    
    
    return 0;
}

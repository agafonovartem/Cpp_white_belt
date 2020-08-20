//
//  main.cpp
//  synonyms
//
//  Created by Артем on 22.03.2020.
//  Copyright © 2020 Артем. All rights reserved.
//

#include <iostream>
#include <map>
#include <set>

using namespace std;
void Print(const map<string, set<string>>& voc){
    for (const auto& item : voc){
        cout << item.first << " : ";
        for (const auto& s : item.second){
            cout << s << " ";
        }
        cout << endl;
    }
}

void Add(map<string, set<string>>& voc){
    string word1, word2;
    cin >> word1 >> word2;
    voc[word1].insert(word2);
    voc[word2].insert(word1);
    //Print(voc);
}



void Count(map<string, set<string>>& voc){
    string word1;
    cin >> word1;
    cout << voc[word1].size() << endl;
    //Print(voc);
}

void Check(map<string, set<string>>& voc){
    string word1, word2;
    cin >> word1 >> word2;
    if (voc[word1].count(word2) == 1 || voc[word2].count(word1) == 1){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}
void ReadCommands(){
    int n;
    cin >> n;
    map<string, set<string>> voc;
    for (int i = 0; i < n; i++){
        string command;
        cin >> command;
        if (command == "ADD"){
            Add(voc);
        }
        else if (command == "COUNT"){
            Count(voc);
        }
        else if (command == "CHECK"){
            Check(voc);
        }
    }
}


int main(int argc, const char * argv[]) {
    ReadCommands();
    return 0;
}

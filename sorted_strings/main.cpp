//
//  main.cpp
//  sorted_strings
//
//  Created by Артем on 23.03.2020.
//  Copyright © 2020 Артем. All rights reserved.
//

#include <iostream>
#include <vector>
#include <vector>
using namespace std;


class SortedStrings {
public:
  void AddString(const string& s) {
       strings.push_back(s);
  }
  vector<string> GetSortedStrings() {
      sort(strings.begin(), strings.end());
      return strings;
  }
private:
    vector<string> strings;
};

void PrintSortedStrings(SortedStrings& strings) {
  for (const string& s : strings.GetSortedStrings()) {
    cout << s << " ";
  }
  cout << endl;
}

int main() {
  SortedStrings strings;
  
  strings.AddString("first");
  strings.AddString("third");
  strings.AddString("second");
  PrintSortedStrings(strings);
  
  strings.AddString("second");
  PrintSortedStrings(strings);
  
  return 0;
}

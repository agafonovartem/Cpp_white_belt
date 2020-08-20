//
//  main.cpp
//  ReversibleString
//
//  Created by Артем on 27.03.2020.
//  Copyright © 2020 Артем. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class ReversibleString{
    
    
  public :
    ReversibleString(){
        str = "";}
    ReversibleString(const string& newstr){
        str = newstr;
    }
    void Reverse(){
        string res = "";
        for (int i = str.size() - 1; i >= 0 ; i--){
            res = res + str[i];
        }
        str = res;
    }
     string ToString() const {
        return str;
    }
    
  private :
    string str;
    
};


int main() {
  ReversibleString s("live");
  s.Reverse();
  cout << s.ToString() << endl;
  
  s.Reverse();
  const ReversibleString& s_ref = s;
  string tmp = s_ref.ToString();
  cout << tmp << endl;
  
  ReversibleString empty;
  cout << '"' << empty.ToString() << '"' << endl;
  
  return 0;
}

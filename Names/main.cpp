//
//  main.cpp
//  Names
//
//  Created by Артем on 23.03.2020.
//  Copyright © 2020 Артем. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

class Person {
    private:
    struct YearName{
        int Year;
        string FirstName;
        string LastName;
    };
    vector<YearName> data;
    
public:
    Person(const string& first_name,
           const string& last_name,
           const int& year){
        YearName current_person = {year, first_name, last_name};
        data.push_back(current_person);
        
    }
    
    
  void ChangeFirstName(int year, const string& first_name) {
      for (auto& item : data){
          if (item.Year == year) {
              item.FirstName = first_name;
              return;
          }
      }
      YearName current_person;
      current_person.FirstName = first_name;
      current_person.Year = year;
      current_person.LastName = " ";
      data.push_back(current_person);
      sort(data.begin(), data.end(), [](struct YearName a, struct YearName b){
          return a.Year > b.Year;
      });
  }
  void ChangeLastName(int year, const string& last_name) {
      for (auto& item : data){
          if (item.Year == year) {
              item.LastName = last_name;
              return;
          }
      }
      YearName current_person;
      current_person.LastName = last_name;
      current_person.Year = year;
      current_person.FirstName = " ";
      data.push_back(current_person);
      sort(data.begin(), data.end(), [](struct YearName a, struct YearName b){
          return a.Year > b.Year;
      });
  }
    
    
    
  string GetFullName(int year) const {
      string first_name, last_name;
      string res;
      /*sort(data.begin(), data.end(), [](struct YearName a, struct YearName b){
          return a.Year > b.Year;
      });*/
      
      for (const auto& item : data){
          if (item.FirstName != " " && item.Year <= year){
              first_name = item.FirstName;
              break;
          }
          else{
              first_name = " ";
          }
      }
      
      for (const auto& item : data){
          if (item.LastName != " " && item.Year <= year){
              last_name = item.LastName;
              break;
          }
          else{
              last_name = " ";
          }
      }
      if (last_name != " " && first_name != " "){
          res = first_name + " " + last_name;
          return res;
      }
      else if (last_name != " " && first_name == " "){
          res = last_name + " with unknown first name";
          return res;
      }
      else if (first_name != " " && last_name == " "){
          res = first_name + " with unknown last name";
          return res;
      }
      else
          return "No person";
          //return "Incognito";;
      }
    
    
    
    string Names_Print(vector<string> name) const{
        string res;
        for (int i = 1; i < name.size(); i++){
            if (name[i] != name[i - 1]){
                res += name[i];
                if (i != name.size() - 1){
                    res += ", ";
                }
            }
        }
        if (res == ""){
            return name[0];
        }
        else{
            return name[0] + " (" + res + ")";
        }
    }
    
    
    
    
    string GetFullNameWithHistory(int year) const {
        /*sort(data.begin(), data.end(), [](struct YearName a, struct YearName b){
            return a.Year > b.Year;
        });*/
        vector<string> first_name, last_name;
        string res;
        
        for (const auto& item : data){
            if (item.FirstName != " " && item.Year <= year){
                first_name.push_back(item.FirstName);
            }
        }
        
        for (const auto& item : data){
            if (item.LastName != " " && item.Year <= year){
                last_name.push_back(item.LastName);
            }
        }
        
        if (first_name.size()== 0 && last_name.size() == 0){
            return "No person";
            //return "Incognito";
        }
        else if (last_name.size()== 0){
            return Names_Print(first_name) + " with unknown last name";
        }
        else if (first_name.size()== 0){
            return Names_Print(last_name) + " with unknown first name";
        }
        
        else{
            string res1 = Names_Print(first_name);
            string res2 = Names_Print(last_name);
            return res1 + " " +res2;
        }
    }
    
};




int main() {
  Person person("Polina", "Sergeeva", 1960);
  for (int year : {1959, 1960}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeFirstName(1965, "Appolinaria");
  person.ChangeLastName(1967, "Ivanova");
  for (int year : {1965, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }

  return 0;
}

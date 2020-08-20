//
//  main.cpp
//  Student_struct
//
//  Created by Артем on 03.04.2020.
//  Copyright © 2020 Артем. All rights reserved.
//

#include <vector>
#include <iostream>


using namespace std;



struct Student{
    string first_name;
    string last_name;
    int day;
    int month;
    int year;
};

vector<Student> students;

void CommandName(){
    int i;
    cin >> i;
    if (i <= students.size() && i > 0){
        cout << students[i - 1].first_name << " " << students[i-1].last_name << endl;
    }
    else{
        //cout << "bad request name"<< endl;
        cout << "bad request"<< endl;
    }
}

void CommandDate(){
    int i;
    cin >> i;
    if (i <= students.size() && i > 0){
        cout << students[i - 1].day << "." << students[i-1].month << "." << students[i-1].year <<endl;
    }
    else{
        //cout << "bad request date"<< endl;
        cout << "bad request"<< endl;
    }
}



void ReadAll (){
    int n_students;
    string new_first_name, new_last_name;
    int new_day, new_month, new_year;
    cin >> n_students;
    for (int i = 0; i < n_students; i ++){
        cin >> new_first_name >> new_last_name >> new_day >> new_month >> new_year;
        students.push_back({new_first_name, new_last_name, new_day, new_month, new_year});
    }
    int  n_commands;
    cin >> n_commands;
    for (int i = 0; i < n_commands; i++){
        string command;
        cin >> command;
        if (command == "name"){
            CommandName();
        }
        else if (command == "date"){
            CommandDate();
        }
        else{
            int n;
            cin >> n;
            //cout << "bad request no command " << endl;
            cout << "bad request" << endl;
        }
    }
    
}

void PrintAll (){
    for (const auto& item : students){
        cout << item.first_name << " " << item.last_name << " "<< item.day << "-" <<
        item.month << "-" << item.year << endl;
    }
}

int main(int argc, const char * argv[]) {
    ReadAll();
    //PrintAll();
    return 0;
}

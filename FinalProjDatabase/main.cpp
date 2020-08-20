//
//  main.cpp
//  FinalProjDatabase
//
//  Created by Артем on 07.04.2020.
//  Copyright © 2020 Артем. All rights reserved.
//

#include <iostream>
#include <vector>
#include <iomanip>
#include <sstream>
#include <set>
#include <map>
using namespace std;

class Date{
public:
    Date (){
        year = 0;
        month = 0;
        day = 0;
    }
    Date(int new_year, int new_month, int new_day){
        year = new_year;
        if (new_month < 1 || new_month > 12){
            string error = "Month value is invalid: " + to_string(new_month);
            throw invalid_argument(error);
        }
        month = new_month;
        if (new_day < 1 || new_day > 31){
            string error = "Day value is invalid: " + to_string(new_day);
            throw invalid_argument(error);
        }
        day = new_day;
    }
    int GetYear() const{
        return year;
    }
    int GetMonth() const{
        return month;
    }
    int GetDay() const{
        return day;
    }
private:
    int year;
    int month;
    int day;
};


ostream& operator<<(ostream& stream, const Date& date) {
    stream << setw(4) << setfill('0') << date.GetYear() <<"-"<< setw(2) << setfill('0') << date.GetMonth() << "-"<< setw(2) << setfill('0') << date.GetDay();
    return stream;
}
/*
void EnsureNextSymbolAndSkip(istream& stream) {
    if (stream.peek() != '-') {
        throw exception();
    }
    stream.ignore(1);
}*/

Date ParseDate(const string& s){
    stringstream stream(s);
    int year, day, month = 88;
    stream >> year;
    // fail -- ошибка при чтении, иначе при менправильном формате клал 0 в int
    if (stream.peek() != '-' || stream.fail()) {
        string error = "Wrong date format: " + s;
        throw invalid_argument(error);
    }
    stream.ignore(1);
    stream >> month;
    //cout << "MONTH: " << month << endl;
    if (stream.peek() != '-' || stream.fail()) {
        string error = "Wrong date format: " + s;
        throw invalid_argument(error);
    }
    stream.ignore(1);
    stream >> day;
    // eof -- проверка на то, что строка заканчивается после чтения day. eof возвращает true, если файл(строка) закончилась
    if (stream.fail() || !stream.eof()) {
        string error = "Wrong date format: " + s;
        throw invalid_argument(error);
    }
    //cout << "DAY: " << year;
    Date date = {year, month, day};
    return date;
}


bool operator<(const Date&  lhs, const Date& rhs) {
    int lhs_in_days = lhs.GetYear() * 12 * 31 + lhs.GetMonth() * 31 + lhs.GetDay();
    int rhs_in_days = rhs.GetYear() * 12 * 31 + rhs.GetMonth() * 31 + rhs.GetDay();
    return (lhs_in_days < rhs_in_days);
}


class Database{
    public:
    Database (){
        map<Date, set<string>> new_data;
        data = new_data;
    }
    
    
    void Add(const Date& new_date, const string& new_event){
        data[new_date].insert(new_event);
    }
        
    void Print(){
        for (const auto& item: data){
            for (const auto& event: data[item.first]){
                cout << item.first << " " << event << endl;
            }
        }
    }
    
    void DelOne(const Date& date, const string& event){
        if (data.count(date) > 0) {
            if (data.at(date).erase(event) == 0){
                cout << "Event not found" << endl;
            }
            else{
                cout << "Deleted successfully" << endl;
            }
        }
        else{
            cout << "Event not found" << endl;
        }
    }
    
    void DelAll(const Date& date){
        if (data.count(date) > 0){
            cout << "Deleted " << data.at(date).size() << " events" << endl;
            data.erase(date);
        }
        else {
            cout << "Deleted 0 events" << endl;
        }
    }
    
    void Find(const Date& date){
        if (data.count(date) > 0){
            for (const auto& item: data.at(date)){
                cout << item << endl;
            }
        }
    }
    
    
    private:
        map<Date, set<string>> data;
};

    



int main() {
    string line;
    Database db;
    while (getline(cin, line)) {
        stringstream ss(line);
        string command;
        ss >> command;
        try{
            if (command == "Print"){
                db.Print();
            }
            else if (command == "Add"){
                string new_date, new_event;
                Date parsed_date;
                ss >> new_date >> new_event;
                parsed_date = ParseDate(new_date);
                db.Add(parsed_date, new_event);
            }
            else if (command == "Del"){
                string del_date, del_event;
                Date parsed_date;
                ss >> del_date >> del_event;
                parsed_date = ParseDate(del_date);
                if (del_event == ""){
                    db.DelAll(parsed_date);
                }
                else{
                    db.DelOne(parsed_date, del_event);
                }
                
            }
            else if (command == "Find"){
                string find_date;
                Date parsed_date;
                ss >> find_date;
                parsed_date = ParseDate(find_date);
                db.Find(parsed_date);
            }
            else if (command == ""){
            }
            else{
                string error = "Unknown command: " + command;
                throw invalid_argument(error);
            }
        }catch (exception& ex){
            cout << ex.what() << endl;
        }
    }
    return 0;
}

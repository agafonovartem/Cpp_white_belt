//
//  main.cpp
//  Структура LectureTitle
//
//  Created by Артем on 31.03.2020.
//  Copyright © 2020 Артем. All rights reserved.
//

#include <iostream>

using namespace std;

struct Specialization{
    string value;
    explicit Specialization (string str){
        value = str;
    }
};

struct Course{
    string value;
    explicit Course (string str){
        value = str;
    }
};

struct Week{
    string value;
    explicit Week (string str){
        value = str;
    }
};


struct LectureTitle {
  string specialization;
  string course;
  string week;
    LectureTitle (Specialization specialization_val, Course course_val, Week week_val){
        specialization = specialization_val.value;
        course = course_val.value;
        week = week_val.value;
        
    }
};



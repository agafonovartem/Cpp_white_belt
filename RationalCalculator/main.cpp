//
//  main.cpp
//  RationalCalculator
//
//  Created by Артем on 05.04.2020.
//  Copyright © 2020 Артем. All rights reserved.
//



#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <exception>



using namespace std;

class Rational {
public:
    Rational() {
        p = 0;
        q = 1;
    }

    Rational(int numerator, int denominator) {
        
        
        if (denominator == 0){
            throw invalid_argument("The denominator is Zer0");
        }
        
        
        if (numerator < 0 && denominator < 0){
            numerator = - numerator;
            denominator = - denominator;
        }
        else if (denominator < 0){
            numerator = - numerator;
            denominator = - denominator;
        }
        else if (numerator == 0){
            denominator = 1;
        }
         
        
        //cout << numerator << " " << denominator << endl;
        int gsd = GSD(numerator, denominator);
        //cout <<"gsd: " <<gsd << endl;
        p = numerator/gsd;
        q = denominator/gsd;
    }

    int Numerator() const {
        return p;
    }

    int Denominator() const {
        return q;
    }

private:
    int p;
    int q;
    int GSD (int a = 0, int b = 0){
        int q = 0;
        int r = 0;
        
        q = a / b;
        r = a % b;
        while (r != 0) {
            a = b;
            b = r;
            q = a / b;
            r = a % b;
        }
        return abs(b);
    }
};

bool operator==(const Rational&  lhs, const Rational& rhs) {
    return (lhs.Numerator() == rhs.Numerator() && lhs.Denominator() == rhs.Denominator());
}



Rational operator+(const Rational&  lhs, const Rational& rhs) {
    int numerator = lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator();
    int denominator = lhs.Denominator() * rhs.Denominator();
    return Rational(numerator, denominator);
}

Rational operator-(const Rational&  lhs, const Rational& rhs) {
    int numerator = lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator();
    int denominator = lhs.Denominator() * rhs.Denominator();
    return Rational(numerator, denominator);
}

bool operator<(const Rational&  lhs, const Rational& rhs) {
    return ((lhs - rhs).Numerator() < 0);
}

bool operator>(const Rational&  lhs, const Rational& rhs) {
    return ((lhs - rhs).Numerator() > 0);
}

Rational operator*(const Rational&  lhs, const Rational& rhs) {
    int numerator = lhs.Numerator() *  rhs.Numerator();
    int denominator = lhs.Denominator() * rhs.Denominator();
    return Rational(numerator, denominator);
}



Rational operator/(const Rational&  lhs, const Rational& rhs) {
    if( rhs.Numerator() == 0){
        throw domain_error("Can't divide by Zer0");
    }
    int numerator = lhs.Numerator() *  rhs.Denominator();
    int denominator = lhs.Denominator() * rhs.Numerator();
    return Rational(numerator, denominator);
}

ostream& operator<<(ostream& stream, const Rational&  rational) {
    stream << rational.Numerator() << '/'<<  rational.Denominator();
    return stream;
}

istream& operator>>(istream& stream, Rational&  rational) {
    if (stream){
        int p = rational.Numerator() , q = rational.Denominator();
        stream >> p;
        stream.ignore(1);
        stream >> q;
        rational = Rational(p, q);
    }
    return stream;
}

void ParseEquation(){
    Rational first, second;
    char operation;
    try{
    cin >> first >> operation >> second;
    } catch (invalid_argument&){
        cout << "Invalid argument" << endl;
        exit(0);
    }
    if (operation == '+'){
        cout << first + second << endl;
    }
    else if (operation == '-'){
        cout << first - second << endl;
    }
    else if (operation == '*'){
        cout <<  first * second << endl;
    }
    else {
        try{
        cout <<  first / second << endl;
        } catch (domain_error&){
            cout <<  "Division by zero" << endl;
        }
    }
}


int main() {
    ParseEquation();
    return 0;
}



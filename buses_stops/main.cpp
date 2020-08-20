//
//  main.cpp
//  buses_stops
//
//  Created by Артем on 22.03.2020.
//  Copyright © 2020 Артем. All rights reserved.
//

#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;


int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    map<set<string>, int> stops_bus;
    int no = 1;
    for (int i=0; i < n; i++){
        int n_stops;
        cin >> n_stops;
        set<string> stops;
        for (int j = 0; j < n_stops; j++){
            string stop;
            cin >> stop;
            stops.insert(stop);
        }
        if (stops_bus.count(stops) > 0){
            cout << "Already exists for " << stops_bus[stops]<< endl;
        }
        else{
            stops_bus[stops] = no;
            cout << "New bus " << no << endl;
            no += 1;
        }
    }
    
}



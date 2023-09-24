#include <iostream>
#include <string>

#include "foo.h"

using namespace std;

void print_number(const string& str) {
    string number;
    
    for(char current : str) {
        if(isdigit(current)) {
            number += current;
        }
        else if(!number.empty()) {
            cout << number << endl;
            number.clear();
        }
    }
    if (!number.empty()) {
        cout << number << endl;
    }
}
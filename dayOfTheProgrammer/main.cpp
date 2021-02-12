#include <string>
#include <iostream>
#include <array>
#include <vector>

using namespace std;

bool is_bisect (int year) {
    if (year < 1918) {
        if (year % 4 == 0) {
            return true;
        }
    } else {
        if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0) ) {
            return true;
        }
    }
    return false;
}

string solve(int year){
    // Complete this function
    string date;
    if (year != 1918) {
        if (is_bisect(year)) {
            date = "12.09." + to_string(year);
        } else {
            date = "13.09." + to_string(year);
        }
        // apply julian/gregorian difference
    } else {
        date = "26.09.1918";
    }
    return date;
}

int main() {
    int year;
    cin >> year;
    string result = solve(year);
    cout << result << endl;
    return 0;
}



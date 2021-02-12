#include <string>
#include <sstream>
#include <iostream>
#include <array>
#include <vector>

using namespace std;

/*
s = 1 2 1 3 2 
d = 3 
m = 2

*/
int solve(int n, std::vector <int> s, int d, int m){
    // Complete this function
    int solutions = 0;
    int sum = 0;
    if (n < m) {
        return 0;
    }
    for (int i = 0; i < m; i++) {
        sum += s[i];
    }
    if (sum == d) {
        solutions = 1;
    }
    cout << "initial sum:" << sum << endl;
    cout << "solutions:" << solutions << endl;
    for (int i = m; i < n; i++) {
        cout << "-----------------------------------" << endl;
        cout << "previous  sum:" << sum << endl;
        sum -= s[i-m];
        sum += s[i];
        cout << "subtracting:" << s[i-m] << " at index " << i << endl;
        cout << "adding " << s[i] << endl;
        cout << "Next sum:" << sum << endl;
        if (sum == d) {
            solutions ++;
        }
    }
    return solutions;
}

int main() {
    int n;
    cout << "N:";
    cin >> n;
    std::vector<int> s(n);
    cout << "Ok, input " << n << " elements";
    for(int s_i = 0; s_i < n; s_i++){
       cin >> s[s_i];
    }
    int d;
    int m;
    cout << "d:";
    cin >> d;
    cout << "m:";
    cin >> m;
    int result = solve(n, s, d, m);
    cout << result << endl;
    return 0;
}



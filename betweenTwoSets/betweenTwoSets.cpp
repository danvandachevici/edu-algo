#include <string>
#include <sstream>
#include <iostream>
#include <array>
#include <vector>
using namespace std;

int getTotalX(vector <int> a, vector <int> b) {
    // Complete this function
    int an = a.size();
    int bn = b.size();
    int maxa = a[0];
    int minb = b[0];
    for (int i = 0; i < an; i++) {
        if (a[i] > maxa) {
            maxa = a[i];
        }
    }
    for (int i = 0; i < bn; i++) {
        if (b[i] < minb) {
            minb = b[i];
        }
    }
    vector <int> asol;
    for (int i = maxa; i <= minb; i++) {
        bool wrong = false;
        for (int j = 0; j < an; j++) {
            if (i % a[j] != 0) {
                wrong = true;
                break;
            }
        }
        if (!wrong) {
            cout << "Pushing possible solution:" << i << endl;
            asol.push_back(i);
        }
    }
    vector <int> solutions;
    for (int i = 0; i < asol.size(); i++) {
        bool wrong = false;
        for (int j = 0; j < bn; j++) {
            if (b[j] % asol[i] != 0) {
                wrong = true;
                break;
            }
        }
        if (!wrong) {
            cout << "Pushing definite solution:" << asol[i] << endl;
            solutions.push_back(asol[i]);
        }
    }
    cout << "Solutions:";
    for (int i = 0; i < solutions.size();i++) {
        cout << solutions[i] << " ";
    }
    cout << endl;
    return solutions.size();
    
}

int main() {
    int n;
    int m;
    cout << "N:";
    cin >> n;
    cout <<"M:";
    cin >> m;
    cout << endl << "insert " << n << " numbers: ";
    vector<int> a(n);
    for(int a_i = 0; a_i < n; a_i++){
       cin >> a[a_i];
    }
    cout << endl << "insert " << m << " numbers: ";
    vector<int> b(m);
    for(int b_i = 0; b_i < m; b_i++){
       cin >> b[b_i];
    }
    int total = getTotalX(a, b);
    cout << total << endl;
    return 0;
}



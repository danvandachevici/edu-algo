#include <iostream>
#include <array>
#include <vector>
using namespace std;

int divisibleSumPairs(int n, int k, vector <int> ar) {
    // Complete this function
    //
    int sol = 0;
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if ((ar[i] + ar[j]) % k == 0) {
                //cout << "Found solution:" << ar[i] << ' ' << ar[j] << " at indices [" << i << "][" << j << "]" << endl;
                sol ++;
            }
        }
    }
    return sol;
}

int main() {
    int n = 6;
    int k = 3;
    vector<int> ar;
    ar.push_back(1);
    ar.push_back(3);
    ar.push_back(2);
    ar.push_back(6);
    ar.push_back(1);
    ar.push_back(2);
    int result = divisibleSumPairs(n, k, ar);
    cout << result << endl;
    return 0;
}

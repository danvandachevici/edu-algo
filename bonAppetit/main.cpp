#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, k;
//    cout << "n: ";
    cin >> n;
//    cout << "k: ";
    cin >> k;
    vector<int> ar;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        ar.push_back(tmp);
    }
//    cout << "sum:";
    int sum;
    cin >> sum;
    int tmpsum = 0;
    for (int i = 0; i < n; i++) {
        tmpsum += ar[i];
    }
    tmpsum -= ar[k];
    tmpsum /= 2;
    if (tmpsum == sum) {
        cout << "Bon Appetit";
    } else {
        cout << sum - tmpsum;
    }
    
    return 0;
}



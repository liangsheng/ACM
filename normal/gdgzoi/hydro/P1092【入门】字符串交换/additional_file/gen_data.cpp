#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
typedef long long LL;

int main(int argc, char** argv) {
    registerGen(argc, argv, 1);
    int T = 20;
    vector<int> n = {4, 2, 5, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 10000, 10000, 10000, 10000, 10000, 10000};
    vector<vector<string>> a(T);
    a[0] = {"11101101", "00", "10001", "10"};
    a[1] = {"101010", "010101"};
    a[2] = {"0000", "11", "0", "00000000", "1"};
    a[3] = {"011", "0111", "01111"};
    a[4] = {"0", "0"};
    a[5] = {"11", "111"};
    a[6] = {"11111", "0000"};
    a[7] = {"10100110", "1001"};
    a[8] = {"0011", "11111111"};
    a[9] = {"000", "001000"};
    a[10] = {"111101", "1111111"};
    a[11] = {"10111010", "101"};
    a[12] = {"010011010", "0100"};
    a[13] = {"0100", "1"};

    for (int i = 14; i < T; i++) {
        for (int j = 0; j < n[i]; j++) {
            if (rnd.next(n[i]) == 0) a[i].push_back("0");
            else if (rnd.next(n[i]) == 1) a[i].push_back("1");
            else {
                string t;
                int sz = rnd.next(20) + 1;
                for (int k = 0; k < sz; k++) {
                    t.push_back(rnd.next(2) + '0');
                }
                a[i].push_back(t);
            }
        }
    }

    for (int t = 0; t < T; t++) {
        freopen(("./testdata/" + to_string(t + 1) + ".in").c_str(), "w", stdout);
        
        cout << n[t] << '\n';
        for (int i = 0; i < n[t]; i++) {
            cout << a[t][i] << '\n';
        }

        cout.clear();
    }

    fclose(stdout);
    return 0;
}
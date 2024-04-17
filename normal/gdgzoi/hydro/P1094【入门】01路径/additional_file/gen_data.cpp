#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
typedef long long LL;

int main(int argc, char** argv) {
    registerGen(argc, argv, 1);
    int T = 10;
    vector<int> n = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
    vector<int> m = {1, 2, 3, 4, 5, 1000, 10000, 10000, 10000, 10000};
    vector<vector<vector<string>>> a(T);
    
    for (int t = 0; t < 5; t++) {
        int sz = m[t] * 2;
        string s;
        for (int j = 0; j < (1 << sz); j++) {
            vector<string> b(2);
            string s;
            for (int k = 0; k < sz; k++) {
                s.push_back((j >> k & 1) + '0');
            }
            b[0] = s.substr(0, m[t]);
            b[1] = s.substr(m[t], m[t]);
            a[t].push_back(b);
        }
    }
    for (int t = 5; t < 10; t++) {
        for (int i = 0; i < 1; i++) {
            vector<string> b(2);
            for (int j = 0; j < m[t]; j++) {
                b[0].push_back(rnd.next(2) + '0');
                b[1].push_back(rnd.next(2) + '0');
            }
            a[t].push_back(b);
        }
    }

    for (int t = 0; t < T; t++) {
        freopen(("./testdata/" + to_string(t + 1) + ".in").c_str(), "w", stdout);
        
        cout << a[t].size() << '\n';
        for (int i = 0; i < a[t].size(); i++) {
            cout << a[t][i][0].size() << '\n';
            cout << a[t][i][0] << '\n';
            cout << a[t][i][1] << '\n';
        }

        cout.clear();
    }

    fclose(stdout);
    return 0;
}
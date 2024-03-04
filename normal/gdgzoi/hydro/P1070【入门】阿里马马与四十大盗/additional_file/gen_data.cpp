#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
typedef long long LL;

int main(int argc, char** argv) {
    registerGen(argc, argv, 1);
    int T = 10;
    vector<int> n = {10, 20, 50, 100, 1000, 10000, 10000, 10000, 100000, 200000};
    vector<int> m(T);
    vector<vector<int>> c(T);
    for (int i = 0; i < T; i++) {
        m[i] = rnd.next(n[i]) + n[i] / 2;
        LL now = 0;
        for (int j = 0; j < n[i]; j++) {
            int x = rnd.next(m[i] / 4) + 1;
            if (now + x < m[i]) c[i].push_back(x), now += x;
            else {
                // if (rnd.next(3) != 0) c[i].push_back(0), now = 0;
                // else c[i].push_back(x), now += x;
                c[i].push_back(0), now = 0;
            }
        }
        c[i][0] = 0, c[i][n[i] - 1] = 0;
    }

    for (int t = 0; t < T; t++) {
        freopen(("./testdata/" + to_string(t + 1) + ".in").c_str(), "w", stdout);
        
        cout << n[t] << ' ' << m[t] << '\n';
        for (int i = 0; i < n[t]; i++) {
            cout << c[t][i] << " \n"[i == n[t] - 1];
        }

        cout.clear();
    }

    fclose(stdout);
    return 0;
}
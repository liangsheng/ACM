#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
typedef long long LL;

int main(int argc, char** argv) {
    registerGen(argc, argv, 1);
    int T = 10;
    vector<int> n = {10, 100, 100, 100, 100, 10, 100, 100, 100, 100};
    vector<string> a(T), b(T);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < n[i]; j++) {
            a[i].push_back(rnd.next(2) + '0');
        }
        b[i] = a[i];
        for (int k = 1; k <= min(n[i], 100); k++) {
            vector<int> P;
            for (int j = 0; j < n[i]; j++) if (b[i][j] == '1') P.push_back(j);
            int p = P[rnd.next(P.size())];
            for (int j = 0; j < n[i]; j++) if (j != p) {
                if (b[i][j] == '0') b[i][j] = '1';
                else b[i][j] = '0';
            }
        }
    }

    for (int i = 5; i < T; i++) {
        a[i].push_back('1');
        for (int j = 1; j < n[i]; j++) {
            a[i].push_back(rnd.next(2) + '0');
        }
        b[i] = a[i];
        if (rnd.next(2) == 1) {
            for (int j = 1; j < n[i]; j++) {
                if (b[i][j] == '0') b[i][j] = '1';
                else b[i][j] = '0';
            }
        }
        for (int k = 1; k <= 1000; k++) {
            int x = rnd.next(n[i]), y = rnd.next(n[i]);
            swap(b[i][x], b[i][y]);
        }
    }

    for (int t = 0; t < T; t++) {
        freopen(("./testdata/" + to_string(t + 1) + ".in").c_str(), "w", stdout);
        cout << 1 << '\n' << n[t] << '\n' << a[t] << '\n' << b[t] << '\n'; 
        cout.clear();
    }

    fclose(stdout);
    return 0;
}
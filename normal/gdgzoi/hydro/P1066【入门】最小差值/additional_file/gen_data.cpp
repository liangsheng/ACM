#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
typedef long long LL;

int main(int argc, char** argv) {
    registerGen(argc, argv, 1);
    int T = 10;
    vector<int> n = {10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
    vector<int> k(T);
    vector<vector<int>> c(T);
    for (int i = 0; i < T; i++) {
        k[i] = rnd.next(n[i]) + 1;
        for (int j = 0; j < n[i]; j++) {
            c[i].push_back(rnd.next(n[i]) + 1);
        }
    }

    for (int t = 0; t < T; t++) {
        freopen(("./testdata/" + to_string(t + 1) + ".in").c_str(), "w", stdout);
        
        cout << n[t] << ' ' << k[t] << '\n';
        for (int i = 0; i < n[t]; i++) {
            cout << c[t][i] << " \n"[i == n[t] - 1];
        }

        cout.clear();
    }

    fclose(stdout);
    return 0;
}
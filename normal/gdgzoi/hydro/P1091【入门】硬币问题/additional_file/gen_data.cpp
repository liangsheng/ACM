#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
typedef long long LL;

int main(int argc, char** argv) {
    registerGen(argc, argv, 1);
    int T = 5;
    vector<int> n = {10, 100, 1000, 10000, 10000};
    vector<int> m = {10, 100, 1000, 1000000000, 1000000000};
    vector<vector<int>> a(T);

    for (int i = 0; i < T; i++) {
        for (int j = 0; j < n[i]; j++) {
            a[i].push_back(m[i] - j);
        }
    }

    a[4].clear();
    for (int j = 0; j < n[4]; j++) {
        a[4].push_back(rnd.next(m[4]) + 1);
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
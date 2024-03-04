#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
typedef long long LL;

int main(int argc, char** argv) {
    registerGen(argc, argv, 1);
    int T = 7;
    vector<int> n = {10, 20, 50, 100, 200, 500, 100000};
    vector<int> m = {10, 20, 50, 100, 200, 500, 1000};
    vector<vector<int>> a(T);
    for (int i = 0; i < T; i++) {
        m[i] = rnd.next(n[i]) + n[i] / 2;
        for (int j = 0; j < n[i] / 4; j++) {
            a[i].push_back(rnd.next(n[i] / 2) + 1);
        }
    }

    for (int t = 0; t < T; t++) {
        freopen(("./testdata/" + to_string(t + 1) + ".in").c_str(), "w", stdout);

        cout << n[t] / 4 << ' ' << m[t] << '\n';
        for (int i = 0; i < n[t] / 4; i++) {
            cout << a[t][i] << " \n"[i == n[t] / 4 - 1];
        }

        cout.clear();
    }

    fclose(stdout);
    return 0;
}
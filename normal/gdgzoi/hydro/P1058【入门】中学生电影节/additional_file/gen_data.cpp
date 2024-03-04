#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
typedef long long LL;

int main(int argc, char** argv) {
    registerGen(argc, argv, 1);
    int T = 5;
    vector<int> n = {10, 20, 30, 40, 50};
    vector<vector<int>> a(T), b(T);
    for (int i = 0; i < T; i++) {
        for (int j = 0; j < n[i]; j++) {
            int x = rnd.next(n[i]) + 1;
            int y = rnd.next(n[i]) + 1;
            while (y == x) y = rnd.next(n[i]) + 1;
            if (x > y) swap(x, y);
            a[i].push_back(x);
            b[i].push_back(y);
        }
    }

    for (int t = 0; t < T; t++) {
        freopen(("./testdata/" + to_string(t + 1) + ".in").c_str(), "w", stdout);

        cout << n[t] << '\n';
        for (int i = 0; i < n[t]; i++) {
            cout << a[t][i] << ' ' << b[t][i] << '\n';
        }

        cout.clear();
    }

    fclose(stdout);
    return 0;
}
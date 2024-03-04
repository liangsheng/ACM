#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
typedef long long LL;

int main(int argc, char** argv) {
    registerGen(argc, argv, 1);
    int T = 10;
    vector<int> n = {5, 10, 20, 50, 100, 100, 100, 100, 100, 100};
    vector<int> V(T);
    vector<vector<int>> v(T), w(T), p(T);

    for (int i = 0; i < T; i++) {
        V[i] = rnd.next(n[i]) + n[i];
        V[i] = min(V[i], 100);
        for (int j = 0; j < n[i]; j++) {
            v[i].push_back(rnd.next(min(10, n[i])) + 1);
            w[i].push_back(rnd.next(min(10, n[i])) + 1);
            if (j == 0) p[i].push_back(-1);
            else p[i].push_back(rnd.next(j) + 1);
        }
        rnd.next(10);
    }

    for (int t = 0; t < T; t++) {
        freopen(("./testdata/" + to_string(t + 1) + ".in").c_str(), "w", stdout);
        
        cout << n[t] << ' ' << V[t] << '\n';
        for (int i = 0; i < n[t]; i++) {
            cout << v[t][i] << ' ' << w[t][i] << ' ' << p[t][i] << '\n';
        }

        cout.clear();
    }

    fclose(stdout);
    return 0;
}
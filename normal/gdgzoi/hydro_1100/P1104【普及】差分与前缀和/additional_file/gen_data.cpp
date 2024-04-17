#include <bits/stdc++.h>
#include "testlib.h"
#define X first
#define Y second
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

int main(int argc, char** argv) {
    registerGen(argc, argv, 1);
    int T = 5;
    vector<int> n = {10, 100, 1000, 10000, 100000};
    vector<int> m = n;
    vector<vector<int>> a(T);
    vector<vector<tuple<int, int, int>>> g(T); 

    for (int t = 0; t < T; t++) {
        for (int i = 0; i < n[t]; i++) a[t].push_back(rnd.next(n[t]) + 1);
        for (int i = 0; i < m[t]; i++) {
            int l = rnd.next(n[t]) + 1;
            int r = rnd.next(n[t]) + 1;
            if (l > r) swap(l, r);
            int v = rnd.next(n[t]) + 1;
            g[t].push_back({l, r, v});
        }
    }

    for (int t = 0; t < T; t++) {
        freopen(("./testdata/" + to_string(t + 1) + ".in").c_str(), "w", stdout);
        
        cout << n[t] << ' ' << g[t].size() << '\n';
        for (int i = 0; i < n[t]; i++) cout << a[t][i] << " \n"[i == n[t] - 1];
        for (int i = 0; i < g[t].size(); i++) {
            auto& [l, r, v] = g[t][i];
            cout << l << ' ' << r << ' ' << v << '\n';
        }

        cout.clear();
    }

    fclose(stdout);
    return 0;
}
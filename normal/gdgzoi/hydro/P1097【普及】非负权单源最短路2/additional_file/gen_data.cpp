#include <bits/stdc++.h>
#include "testlib.h"
#define X first
#define Y second
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

int main(int argc, char** argv) {
    registerGen(argc, argv, 1);
    int T = 10;
    vector<int> n = {10, 100, 1000, 2000, 2500, 10000, 20000, 20000, 20000, 20000};
    vector<int> m = {100, 1000, 2000, 4000, 6000, 20000, 40000, 40000, 40000, 40000};
    vector<int> s = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    vector<int> e = n;
    vector<vector<tuple<int, int, int>>> g(T); 

    for (int t = 0; t < T; t++) {
        for (int i = 2; i <= n[t]; i++) {
            int u = i, v = rnd.next(u - 1) + 1;
            int w = rnd.next(min(n[t], 10000)) + 1;
            g[t].push_back({u, v, w});
        }
        while (g[t].size() < m[t]) {
            int u = rnd.next(min(n[t], 10000)) + 1;
            int v = rnd.next(min(n[t], 10000)) + 1;
            int w = rnd.next(min(n[t], 10000)) + 1;
            g[t].push_back({u, v, w});            
        }
    }

    for (int t = 0; t < T; t++) {
        freopen(("./testdata/" + to_string(t + 1) + ".in").c_str(), "w", stdout);
        
        cout << n[t] << ' ' << g[t].size() << ' ' << s[t] << ' ' << e[t] << '\n';
        for (int i = 0; i < g[t].size(); i++) {
            auto& [u, v, a] = g[t][i];
            cout << u << ' ' << v << ' ' << a << '\n';
        }

        cout.clear();
    }

    fclose(stdout);
    return 0;
}
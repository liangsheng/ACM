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
    vector<int> n = {10, 20, 50, 50, 100, 100, 200, 200, 500, 500};
    vector<int> m = n, k = n, q = n;
    vector<vector<tuple<int, int, int>>> g(T); 

    for (int t = 0; t < T; t++) {
        k[t] = rnd.next(n[t]) + 1;
        m[t] = (rnd.next(20) + 1) * n[t];
        q[t] = sqrt(n[t]);
        for (int i = 1; i <= n[t]; i++) {
            int j = min(n[t], i + q[t] - 1);
            for (int p = i; p < j; p++) {
                g[t].push_back({p, p + 1, (rnd.next(4) <= 2 ? 1 : -1) * rnd.next(n[t])});
            }
            g[t].push_back({j, i, (rnd.next(4) <= 2 ? 1 : -1) * rnd.next(n[t])});
            int u = min(i + q[t], n[t]), v = min(u + q[t] - 1, n[t]), d = v - u + 1;
            if (d > 0) {
                for (int p = i; p <= j; p++) {
                    g[t].push_back({p, rnd.next(d) + u, (rnd.next(4) <= 2 ? 1 : -1) * rnd.next(n[t])});
                }
            }
            i = j;
        }
        while (g[t].size() < m[t]) {
            int u = rnd.next(n[t]) + 1;
            int v = rnd.next(n[t]) + 1;
            int w = (rnd.next(4) <= 2 ? 1 : -1) * rnd.next(n[t]);
            g[t].push_back({u, v, w});
        }
    }

    for (int t = 0; t < T; t++) {
        freopen(("./testdata/" + to_string(t + 1) + ".in").c_str(), "w", stdout);
        
        cout << n[t] << ' ' << g[t].size() << ' ' << k[t] << '\n';
        for (int i = 0; i < g[t].size(); i++) {
            auto& [u, v, w] = g[t][i];
            cout << u << ' ' << v << ' ' << w << '\n';
        }

        cout.clear();
    }

    fclose(stdout);
    return 0;
}
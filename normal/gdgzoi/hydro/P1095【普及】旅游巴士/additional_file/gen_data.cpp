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
    vector<int> n = {10, 20, 50, 50, 100, 100, 1000, 1000, 10000, 10000};
    vector<int> a = n;
    vector<int> m = {20, 40, 100, 200, 200, 2000, 2000, 2000, 20000, 20000};
    vector<int> k = {5, 5, 10, 10, 50, 50, 60, 60, 100, 100};
    vector<vector<tuple<int, int, int>>> g(T); 

    for (int t = 0; t < T; t++) {
        k[t] = rnd.next(k[t] / 2) + k[t] / 2;
        for (int i = 1; i <= n[t]; i++) {
            int j = min(n[t], i + k[t] - 1);
            for (int p = i; p < j; p++) {
                g[t].push_back({p, p + 1, rnd.next(a[t])});
            }
            g[t].push_back({j, i, rnd.next(a[t])});
            int u = min(i + k[t], n[t]), v = min(u + k[t] - 1, n[t]), d = v - u + 1;
            if (d > 0) {
                for (int p = i; p <= j; p++) {
                    g[t].push_back({p, rnd.next(d) + u, rnd.next(a[t])});
                }
            }
            i = j;
        }
    }

    for (int t = 0; t < T; t++) {
        freopen(("./testdata/" + to_string(t + 1) + ".in").c_str(), "w", stdout);
        
        cout << n[t] << ' ' << m[t] << ' ' << k[t] << '\n';
        for (int i = 0; i < g[t].size(); i++) {
            auto& [u, v, a] = g[t][i];
            cout << u << ' ' << v << ' ' << a << '\n';
        }

        cout.clear();
    }

    fclose(stdout);
    return 0;
}
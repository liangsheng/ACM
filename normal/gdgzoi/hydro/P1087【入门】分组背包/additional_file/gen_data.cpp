#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
typedef long long LL;

int main(int argc, char** argv) {
    registerGen(argc, argv, 1);
    int T = 10;
    vector<int> n = {5, 10, 20, 50, 100, 100, 100, 100, 100, 100};
    vector<int> V(T);
    vector<vector<int>> s(T);
    vector<vector<vector<int>>> v(T), w(T);

    for (int i = 0; i < T; i++) {
        V[i] = rnd.next(n[i]) + n[i] / 2;
        V[i] = min(V[i], 100);
        v[i] = vector<vector<int>>(n[i]);
        w[i] = vector<vector<int>>(n[i]);
        for (int j = 0; j < n[i]; j++) {
            int ss = rnd.next(n[i]) + 1;
            s[i].push_back(ss);
            while (ss--) {
                v[i][j].push_back(rnd.next(min(10, n[i])) + 1);
                w[i][j].push_back(rnd.next(min(10, n[i])) + 1);
            }
        }
        rnd.next(10);
    }

    for (int t = 0; t < T; t++) {
        freopen(("./testdata/" + to_string(t + 1) + ".in").c_str(), "w", stdout);
        
        cout << n[t] << ' ' << V[t] << '\n';
        for (int i = 0; i < n[t]; i++) {
            cout << s[t][i] << '\n';
            for (int j = 0; j < s[t][i]; j++) {
                cout << v[t][i][j] << ' ' << w[t][i][j] << '\n';
            }
        }

        cout.clear();
    }

    fclose(stdout);
    return 0;
}
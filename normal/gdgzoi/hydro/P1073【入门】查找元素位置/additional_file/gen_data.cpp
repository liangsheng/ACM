#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
typedef long long LL;

int main(int argc, char** argv) {
    registerGen(argc, argv, 1);
    int T = 5;
    vector<int> n = {10, 20, 1000, 5000, 10000};
    vector<int> m(T);
    vector<vector<int>> c(T);
    for (int i = 0; i < T; i++) {
        for (int j = 0; j < n[i]; j++) {
            c[i].push_back(rnd.next(min(n[i], 100)) + 1);
        }
        sort(c[i].begin(), c[i].end());
        m[i] = c[i][rnd.next(n[i])];
    }
    m[2] = 1001;

    for (int t = 0; t < T; t++) {
        freopen(("./testdata/" + to_string(t + 1) + ".in").c_str(), "w", stdout);
        
        cout << m[t] << ' ' << n[t] << '\n';
        for (int i = 0; i < n[t]; i++) {
            cout << c[t][i] << " \n"[i == n[t] - 1];
        }

        cout.clear();
    }

    fclose(stdout);
    return 0;
}
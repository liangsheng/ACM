#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
typedef long long LL;

int main(int argc, char** argv) {
    registerGen(argc, argv, 1);
    int T = 10;
    vector<int> n = {5, 10, 20, 50, 100, 1000, 1000, 1000, 1000, 1000};
    vector<int> m(T);
    vector<vector<int>> v(T), w(T);

    for (int i = 0; i < T; i++) {
        m[i] = rnd.next(min(10, n[i]) * n[i] / 4) + n[i] / 2;
        for (int j = 0; j < n[i]; j++) {
            v[i].push_back(rnd.next(min(10, n[i])) + 1);
            w[i].push_back(rnd.next(min(10, n[i])) + 1);
        }
    }

    for (int t = 0; t < T; t++) {
        freopen(("./testdata/" + to_string(t + 1) + ".in").c_str(), "w", stdout);
        
        cout << n[t] << ' ' << m[t] << '\n';
        for (int i = 0; i < n[t]; i++) cout << v[t][i] << ' ' << w[t][i] << '\n';

        cout.clear();
    }

    fclose(stdout);
    return 0;
}
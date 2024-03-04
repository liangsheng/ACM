#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
typedef long long LL;

int main(int argc, char** argv) {
    registerGen(argc, argv, 1);
    int T = 10;
    vector<int> n = {3, 5, 10, 100, 1000, 10000, 10000, 10000, 10000, 10000};
    vector<int> k(T);
    vector<vector<int>> v(T), w(T);

    for (int i = 0; i < T; i++) {
        k[i] = rnd.next(n[i]) + 1;
        for (int j = 0; j < n[i]; j++) {
            v[i].push_back(rnd.next(n[i]) + 1);
            w[i].push_back(rnd.next(n[i]) + 1);
        }
    }

    for (int t = 0; t < T; t++) {
        freopen(("./testdata/" + to_string(t + 1) + ".in").c_str(), "w", stdout);
        
        cout << n[t] << ' ' << k[t] << '\n';
        for (int i = 0; i < n[t]; i++) cout << v[t][i] << " \n"[i == n[t] - 1];
        for (int i = 0; i < n[t]; i++) cout << w[t][i] << " \n"[i == n[t] - 1];

        cout.clear();
    }

    fclose(stdout);
    return 0;
}
#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
typedef long long LL;

int main(int argc, char** argv) {
    registerGen(argc, argv, 1);
    int T = 10;
    vector<int> n = {5, 10, 20, 50, 100, 1000, 10000, 100000, 100000, 100000};
    vector<LL> m(T);
    vector<vector<int>> a(T);

    for (int i = 0; i < T; i++) {
        LL sum = 0;
        for (int j = 0; j < n[i]; j++) {
            a[i].push_back(rnd.next(n[i]) + 1);
            sum += a[i][j];
        }
        m[i] = max(0LL, sum / 4 - rnd.next(n[i]));
    }

    for (int t = 0; t < T; t++) {
        freopen(("./testdata/" + to_string(t + 1) + ".in").c_str(), "w", stdout);
        
        cout << n[t] << ' ' << m[t] << '\n';
        for (int i = 0; i < n[t]; i++) cout << a[t][i] << " \n"[i == n[t] - 1];

        cout.clear();
    }

    fclose(stdout);
    return 0;
}
#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
typedef long long LL;

int main(int argc,char** argv) {
    registerGen(argc, argv, 1);
    int T = 5;
    vector<int> n = {10, 100, 1000, 10000, 100000};
    vector<vector<int>> a(T, vector<int>());
    vector<vector<int>> b(T, vector<int>(2, 0));
    for (int i = 0; i < T; i++) {
        LL sum = 0, t = 0;
        for (int j = 0; j < n[i]; j++) {
            int x = rnd.next(min(n[i], 10000)) + 1;
            a[i].push_back(x);
            sum += x;
            if (j <= n[i] / 2) t += x;
        }
        b[i][0] = min(t, sum - t);
        b[i][1] = max(t, sum - t);
    }

    for (int t = 0; t < T; t++) {
        freopen(("./testdata/" + to_string(t + 1) + ".in").c_str(), "w", stdout);
        cout << n[t] << '\n';
        for (int i = 0; i < n[t]; i++) {
            cout << a[t][i] << " \n"[i == n[t] - 1];
        } 
        cout << b[t][0] << ' ' << b[t][1] << '\n';
        cout.clear();
    }

    fclose(stdout);
    return 0;
}
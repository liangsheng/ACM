#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
typedef long long LL;

int main(int argc,char** argv) {
    registerGen(argc, argv, 1);
    int T = 10;
    vector<int> n = {5, 10, 100, 1000, 10000, 10000, 10000, 10000, 10000, 50000};
    vector<int> m = {10, 30, 300, 3000, 30000, 100000, 1000000, 10000000, 100000000, 1000000000};
    vector<vector<int>> a(T);
    for (int i = 0; i < T; i++) {
		for (int j = 0; j < n[i]; j++) a[i].push_back(rnd.next(m[i] - 1) + 1);
        sort(a[i].begin(), a[i].end());
        a[i].erase(unique(a[i].begin(), a[i].end()), a[i].end());
        n[i] = a[i].size();
    }

    for (int t = 0; t < T; t++) {
        freopen(("./testdata/" + to_string(t + 1) + ".in").c_str(), "w", stdout);

        cout << 1 << '\n';
        cout << n[t] << ' ' << m[t] << '\n';
        for (int i = 0; i < n[t]; i++) {
            cout << a[t][i] << " \n"[i == n[t] - 1];
        }

        cout.clear();
    }

    fclose(stdout);
    return 0;
}
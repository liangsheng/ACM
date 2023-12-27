#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
typedef long long LL;

int main(int argc,char** argv) {
    registerGen(argc, argv, 1);
    int T = 10;
    vector<int> n = {10, 20, 50, 100, 1000, 10000, 100000, 100000, 100000, 100000};
    vector<int> d(T);
    vector<vector<int>> v(T), a(T);
    for (int i = 0; i < T; i++) {
        d[i] = rnd.next(1, min(n[i], 100));
        for (int j = 1; j < n[i]; j++) v[i].push_back(rnd.next(1, n[i])); 
        for (int j = 1; j <= n[i]; j++) a[i].push_back(rnd.next(1, min(n[i], 100))); 
    }

    for (int t = 0; t < T; t++) {
        freopen(("./testdata/" + to_string(t + 1) + ".in").c_str(), "w", stdout);
        
        cout << n[t] << ' ' << d[t] << '\n';
        for (int i = 0; i < n[t] - 1; i++) {
            cout << v[t][i] << " \n"[i == n[t] - 2];
        }
        for (int i = 0; i < n[t]; i++) {
            cout << a[t][i] << " \n"[i == n[t] - 1];
        }
        cout.clear();
    }

    fclose(stdout);
    return 0;
}
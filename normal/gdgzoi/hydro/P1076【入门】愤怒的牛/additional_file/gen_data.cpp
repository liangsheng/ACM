#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
typedef long long LL;

int main(int argc, char** argv) {
    registerGen(argc, argv, 1);
    int T = 10;
    vector<int> n = {10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
    vector<int> L(T), m(T);
    vector<vector<int>> a(T);
    for (int i = 0; i < T; i++) {
        L[i] = rnd.next(n[i], n[i] * 100) + 2;
        m[i] = rnd.next(n[i]) + 1;
        vector<int> b(L[i] - 1);
        for (int j = 1; j <= L[i] - 1; j++) b[j - 1] = j;
        for (int j = 1; j <= L[i] - 1; j++) {
            int x = rnd.next(L[i] - 1), y = rnd.next(L[i] - 1);
            swap(b[x], b[y]);
        }
        for (int j = 0; j < n[i]; j++) {
            a[i].push_back(b[j]);
        }
    }

    for (int t = 0; t < T; t++) {
        freopen(("./testdata/" + to_string(t + 1) + ".in").c_str(), "w", stdout);
        
        cout << 1 << '\n';
        cout << L[t] << ' ' << n[t] << ' ' << m[t] << '\n';
        for (int i = 0; i < n[t]; i++) {
            cout << a[t][i] << " \n"[i == n[t] - 1];
        }

        cout.clear();
    }

    fclose(stdout);
    return 0;
}
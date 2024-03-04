#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
typedef long long LL;

int main(int argc, char** argv) {
    registerGen(argc, argv, 1);
    int T = 5;
    vector<int> n = {5, 10, 100, 100, 100};
    vector<int> m = {10, 10, 90, 90, 90};
    vector<vector<vector<int>>> a(T);

    for (int i = 0; i < T; i++) {
        vector<vector<int>> b(n[i]);
        for (int j = 0; j < n[i]; j++) {
            int sz = rnd.next(m[i]) + 4;
            for (int k = 0; k < sz; k++) {
                b[j].push_back(rnd.next(201) - 100);
            }
            a[i] = b;
        }
    }

    for (int t = 0; t < T; t++) {
        freopen(("./testdata/" + to_string(t + 1) + ".in").c_str(), "w", stdout);
        
        cout << n[t] << '\n';
        for (int i = 0; i < n[t]; i++) {
            int sz = a[t][i].size();
            cout << sz << '\n';
            for (int k = 0; k < sz; k++) cout << a[t][i][k] << " \n"[k == sz - 1];
        }

        cout.clear();
    }

    fclose(stdout);
    return 0;
}
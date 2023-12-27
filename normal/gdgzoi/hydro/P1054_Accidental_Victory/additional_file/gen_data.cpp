#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
typedef long long LL;

int main(int argc,char** argv) {
    registerGen(argc, argv, 1);
    int T = 5;
    vector<int> n = {10, 100, 1000, 10000, 100000};
    vector<vector<int>> a(T);
    for (int i = 0; i < T; i++) {
        for (int j = 0; j < n[i]; j++) {
            if (rnd.next(2) == 0) {
                a[i].push_back(rnd.next(1000000000) + 1);
            } else {
                a[i].push_back(rnd.next(2) + 1);
            }
        }
    }

    for (int t = 0; t < T; t++) {
        freopen(("./testdata/" + to_string(t + 1) + ".in").c_str(), "w", stdout);
        
        cout << 1 << '\n';
        cout << n[t] << '\n';
        for (int i = 0; i < n[t]; i++) {
            cout << a[t][i] << " \n"[i == n[t] - 1];
        }
        cout.clear();
    }

    fclose(stdout);
    return 0;
}
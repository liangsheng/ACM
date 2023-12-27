#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
typedef long long LL;

int main(int argc,char** argv) {
    registerGen(argc, argv, 1);
    int T = 5;
    vector<vector<int>> a(T);
    a[0] = {2, 1, 1, 3, 2};
    a[1] = {30, 10, 20};
    for (int i = 2; i < T; i++) {
        int n = rnd.next(1, 1000);
        for (int j = 0; j < n; j++) {
            int x = rnd.next(1, n);
            a[i].push_back(x);
        }
    }

    for (int t = 0; t < T; t++) {
        freopen(("./testdata/" + to_string(t + 1) + ".in").c_str(), "w", stdout);

        cout << a[t].size() << '\n';
        for (int i = 0; i < a[t].size(); i++) {
            cout << a[t][i] << " \n"[i == a[t].size() - 1];
        }

        cout.clear();
    }

    fclose(stdout);
    return 0;
}
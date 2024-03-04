#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
typedef long long LL;

int main(int argc, char** argv) {
    registerGen(argc, argv, 1);
    int T = 10;
    vector<int> n = {5, 10, 20, 50, 100, 1000, 10000, 100000, 100000, 100000};
    vector<vector<int>> h(T);

    for (int i = 0; i < T; i++) {
        for (int j = 0; j < n[i]; j++) {
            h[i].push_back(rnd.next(n[i]) + 1);
        }
    }

    for (int t = 0; t < T; t++) {
        freopen(("./testdata/" + to_string(t + 1) + ".in").c_str(), "w", stdout);
        
        cout << n[t] << '\n';
        for (int i = 0; i < n[t]; i++) cout << h[t][i] << " \n"[i == n[t] - 1];

        cout.clear();
    }

    fclose(stdout);
    return 0;
}
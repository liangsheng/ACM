#include <bits/stdc++.h>
#include "testlib.h"
#define X first
#define Y second
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

int main(int argc, char** argv) {
    registerGen(argc, argv, 1);
    int T = 5;
    vector<int> n = {10, 100, 1000, 10000, 100000};
    vector<int> m = {10, 10000000, 10000000, 10000000, 10000000};
    vector<vector<pair<int, int>>> a(T);

    for (int t = 0; t < T; t++) {
        
        for (int i = 0; i < n[t]; i++) {
            int opt = rnd.next(6) + 1;

        }
    }

    for (int t = 0; t < T; t++) {
        freopen(("./testdata/" + to_string(t + 1) + ".in").c_str(), "w", stdout);
        
        cout << n[t] << '\n';
        for (int i = 0; i < n[t]; i++) cout << a[t][i] << " \n"[i == n[t] - 1];

        cout.clear();
    }

    fclose(stdout);
    return 0;
}
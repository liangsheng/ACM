#include <bits/stdc++.h>
#include "testlib.h"
#define X first
#define Y second
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

int main(int argc, char** argv) {
    registerGen(argc, argv, 1);
    int T = 10, N = 10;
    vector<int> n = {5, 10, 20, 50, 100, 100, 100, 100, 100, 100};
    vector<vector<int>> a(T);
    vector<int> b(T);

    for (int t = 0; t < T; t++) {
        int sza = rnd.next(n[t]) + 1;
        a[t].push_back(rnd.next(9) + 1);
        for (int j = 1; j < sza; j++) {
            a[t].push_back(rnd.next(10));
        }
        b[t] = rnd.next(1000) + 1; 
    }

    for (int t = 0; t < T; t++) {
        freopen(("./testdata/" + to_string(t + 1) + ".in").c_str(), "w", stdout);
        
        for (int i = 0; i < (int) a[t].size(); i++) {
            cout << a[t][i];
        }
        cout << '\n' << b[t] << '\n';

        cout.clear();
    }

    fclose(stdout);
    return 0;
}
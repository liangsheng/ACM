#include <bits/stdc++.h>
#include "testlib.h"
#define X first
#define Y second
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

int main(int argc, char** argv) {
    registerGen(argc, argv, 1);
    int T = 10;
    vector<int> n = {5, 10, 20, 50, 100, 100, 100, 100, 100, 100};
    vector<int> m(T);

    for (int t = 0; t < T; t++) {
        n[t] = rnd.next(n[t]) + 1;
        m[t] = rnd.next(1000) + 1;
    }

    for (int t = 0; t < T; t++) {
        freopen(("./testdata/" + to_string(t + 1) + ".in").c_str(), "w", stdout);
        
        cout << n[t] << ' ' << m[t] << '\n';

        cout.clear();
    }

    fclose(stdout);
    return 0;
}
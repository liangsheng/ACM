#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
typedef long long LL;

int main(int argc,char** argv) {
    registerGen(argc, argv, 1);
    int T = 10, p = 0;
    vector<int> n(T);
    vector<int> m = {10, 20, 50, 100, 1000, 10000, 100000, 1000000, 10000000, 1000000000};
    for (int i = 0; i < T; i++) {
        n[i] = rnd.next(p, m[i] - 1) + 1;
        p = m[i];
    }
    n[T - 1] = 1000000000;

    for (int t = 0; t < T; t++) {
        freopen(("./testdata/" + to_string(t + 1) + ".in").c_str(), "w", stdout);
        
        cout << n[t] << '\n';

        cout.clear();
    }

    fclose(stdout);
    return 0;
}
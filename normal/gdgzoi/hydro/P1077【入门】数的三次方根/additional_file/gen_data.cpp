#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
typedef long long LL;

int main(int argc, char** argv) {
    registerGen(argc, argv, 1);
    int T = 10;
    vector<int> n = {10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
    for (int i = 0; i < T; i++) {
        n[i] = rnd.next(2001) - 1000;
    }

    for (int t = 0; t < T; t++) {
        freopen(("./testdata/" + to_string(t + 1) + ".in").c_str(), "w", stdout);
        
        cout << n[t] << '\n';

        cout.clear();
    }

    fclose(stdout);
    return 0;
}
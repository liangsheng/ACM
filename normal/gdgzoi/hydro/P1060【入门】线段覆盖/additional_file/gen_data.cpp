#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
typedef long long LL;

int main(int argc, char** argv) {
    registerGen(argc, argv, 1);
    int T = 5;
    vector<int> n = {10, 100, 1000, 10000, 100000};
    vector<string> a(T);
    for (int i = 0; i < T; i++) {
        for (int j = 0; j < n[i]; j++) {
            int x = rnd.next(3);
            if (x == 0) a[i].push_back('P');
            else if (x == 1) a[i].push_back('R');
            else a[i].push_back('S');
        }
    }

    for (int t = 0; t < T; t++) {
        freopen(("./testdata/" + to_string(t + 1) + ".in").c_str(), "w", stdout);

        cout << 1 << '\n';
        cout << n[t] << '\n';
        cout << a[t] << '\n';

        cout.clear();
    }

    fclose(stdout);
    return 0;
}
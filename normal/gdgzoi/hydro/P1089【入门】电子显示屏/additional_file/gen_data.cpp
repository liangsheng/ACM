#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
typedef long long LL;

int main(int argc, char** argv) {
    registerGen(argc, argv, 1);
    int T = 10;
    vector<int> n = {100, 100, 100, 100, 100, 100, 100, 100, 100, 100};
    vector<LL> m = {1000, 1000, 1000, 10000, 100000, 1000000, 100000000000000000LL, 100000000000000000LL, 100000000000000000LL, 100000000000000000LL};
    vector<vector<LL>> l(T), r(T);

    for (int i = 0; i < T; i++) {
        for (int j = 0; j < n[i]; j++) {
            if (rnd.next(2) == 0) {
                LL x = rnd.next(m[i]);
                LL y = x + rnd.next(10);
                l[i].push_back(x);
                r[i].push_back(y);
            } else {
                LL x = rnd.next(m[i]);
                LL y = rnd.next(m[i]);
                if (x > y) swap(x, y); 
                l[i].push_back(x);
                r[i].push_back(y);               
            }
        }
    }

    for (int t = 0; t < T; t++) {
        freopen(("./testdata/" + to_string(t + 1) + ".in").c_str(), "w", stdout);
        
        cout << n[t] << '\n';
        for (int i = 0; i < n[t]; i++) {
            cout << l[t][i] << ' ' << r[t][i] << '\n';
        }

        cout.clear();
    }

    fclose(stdout);
    return 0;
}
#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
typedef long long LL;

int main(int argc,char** argv) {
    registerGen(argc, argv, 1);
    int T = 10;
    vector<string> s(T);
    vector<int> a(T), b(T);
    s[0] = "*...*", a[0] = 1, b[0] = 1;
    s[1] = "*...*.", a[1] = 2, b[1] = 3;
    s[2] = ".*....**.*.", a[2] = 3, b[2] = 10;
    s[3] = "***", a[3] = 2, b[3] = 3;
    s[4] = "*........**.....*", a[4] = 10, b[4] = 2;
    for (int i = 5; i < T; i++) {
        int n = rnd.next(1, 20000);
        for (int j = 0; j < n; j++) {
            if (rnd.next(2) == 0) s[i].push_back('*');
            else s[i].push_back('.');
        }
        a[i] = rnd.next(1, 5000);
        b[i] = rnd.next(1, 5000);
    }

    for (int t = 0; t < T; t++) {
        freopen(("./testdata/" + to_string(t + 1) + ".in").c_str(), "w", stdout);

        cout << s[t].size() << ' ' << a[t] << ' ' << b[t] << '\n';
        cout << s[t] << '\n';

        cout.clear();
    }

    fclose(stdout);
    return 0;
}
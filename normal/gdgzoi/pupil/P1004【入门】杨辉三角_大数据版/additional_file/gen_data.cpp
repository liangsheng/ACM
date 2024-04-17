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
    vector<int> n = {5, 10, 20, 50, 100, 150, 200, 300, 300, 300};
    vector<int> m(T);
    
    for (int t = 0; t < 8; t++) m[t] = n[t] / 2;
    m[8] = rnd.next(n[8]) + 1;
    m[9] = rnd.next(n[9]) + 1;

    for (int t = 0; t < T; t++) {
        freopen(("./testdata/" + to_string(t + 1) + ".in").c_str(), "w", stdout);

        cout << n[t] << ' ' << m[t] << '\n';

        cout.clear();
    }

    fclose(stdout);
    return 0;
}
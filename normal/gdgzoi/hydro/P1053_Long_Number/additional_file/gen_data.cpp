#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
typedef long long LL;

int main(int argc,char** argv) {
    registerGen(argc, argv, 1);
    int T = 5;
    vector<int> n = {10, 100, 1000, 10000, 100000};
    vector<string> s(T);
    vector<vector<int>> a(T, vector<int>(9));
    for (int i = 0; i < T; i++) {
        for (int j = 0; j < n[i]; j++) {
            s[i].push_back(rnd.next(9) + 1 + '0');
        }
        for (int j = 0; j < 9; j++) {
            a[i][j] = rnd.next(9) + 1;
        }
    }

    for (int t = 0; t < T; t++) {
        freopen(("./testdata/" + to_string(t + 1) + ".in").c_str(), "w", stdout);
        
        cout << n[t] << '\n' << s[t] << '\n';
        for (int i = 0; i < 9; i++) {
            cout << a[t][i] << " \n"[i == 8];
        }
        cout.clear();
    }

    fclose(stdout);
    return 0;
}
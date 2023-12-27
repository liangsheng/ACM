#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
typedef long long LL;

int main(int argc,char** argv) {
    registerGen(argc, argv, 1);
    int T = 5;
    vector<int> n = {10, 100, 1000, 10000, 100000};
    vector<vector<string>> a(T);
    vector<vector<int>> b(T);
    vector<string> name;
    for (int j = 0; j < 10; j++) for (int k = 0; k < 10; k++) {
        string s;
        s.push_back('a' + j);
        s.push_back('a' + k);
        name.push_back(s);
    }
    for (int i = 0; i < T; i++) {
        for (int j = 0; j < n[i]; j++) {
            a[i].push_back(name[rnd.next(name.size())]);
            b[i].push_back(rnd.next(1000) + 1);
        }
    }

    for (int t = 0; t < T; t++) {
        freopen(("./testdata/" + to_string(t + 1) + ".in").c_str(), "w", stdout);
        
        cout << n[t] << '\n';
        for (int i = 0; i < n[t]; i++) {
            cout << a[t][i] << ' ' << b[t][i] << '\n';
        }

        cout.clear();
    }

    fclose(stdout);
    return 0;
}
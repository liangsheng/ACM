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
    vector<int> n = {5, 10, 20, 50, 100, 200, 500, 1000, 1000, 1000};
    vector<vector<int>> a(T), b(T);

    for (int t = 0; t < T; t++) {
        a[t].push_back(1);
        for (int i = 1; i < n[t]; i++) {
            a[t].push_back(rnd.next(2));
        }
    }

    for (int t = 0; t < T; t++) {
        freopen(("./testdata/" + to_string(t + 1) + ".in").c_str(), "w", stdout);
        
        for (int i = 0; i < n[t]; i++) cout << a[t][i];
        cout << '\n';
        cout.clear();
    }

    fclose(stdout);
    return 0;
}
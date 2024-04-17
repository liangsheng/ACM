#include <bits/stdc++.h>
#include "testlib.h"
#define X first
#define Y second
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

int main(int argc, char** argv) {
    registerGen(argc, argv, 1);
    int T = 10, N = 10;
    vector<int> n = {5, 10, 20, 50, 100, 100, 100, 100, 100, 100};
    vector<vector<string>> a(T, vector<string>(N)), b = a;

    for (int t = 0; t < T; t++) {
        for (int i = 0; i < N; i++) {
            int f = rnd.next(5);
            if (f == 0) a[t][i] = "0";
            else {
                if (f < 3) a[t][i].push_back('-');
                int sza = rnd.next(n[t]) + 1;
                a[t][i].push_back(rnd.next(9) + 1 + '0');
                for (int j = 1; j < sza; j++) {
                    a[t][i].push_back(rnd.next(10) + '0');
                }
            }

            f = rnd.next(5);
            if (f == 0) b[t][i] = "0";
            else {
                if (f < 3) b[t][i].push_back('-');
                int szb = rnd.next(n[t]) + 1;
                b[t][i].push_back(rnd.next(9) + 1 + '0');
                for (int j = 1; j < szb; j++) {
                    b[t][i].push_back(rnd.next(10) + '0');
                }
            }

            if (rnd.next(5) == 0) b[t][i] = a[t][i];
        }
    }

    for (int t = 0; t < T; t++) {
        freopen(("./testdata/" + to_string(t + 1) + ".in").c_str(), "w", stdout);
        
        cout << N << '\n';
        for (int i = 0; i < N; i++) cout << a[t][i] << ' ' << b[t][i] << '\n';

        cout.clear();
    }

    fclose(stdout);
    return 0;
}
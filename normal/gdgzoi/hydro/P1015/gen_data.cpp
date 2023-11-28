#include <bits/stdc++.h>
using namespace std;

int rand(int l, int r) {
    return rand() % (r - l + 1) + l;
}

int main() {
    srand(time(0));
    int T = 2;
    // vector<vector<int>> a(T, vector<int>(2, 0));
    // a[0][0] = 93, a[0][1] = 43;
    // a[1][0] = 97, a[1][1] = 27;
    // a[2][0] = 98, a[2][1] = 45;
    // a[3][0] = 26  , a[3][1] = 21;
    // a[4][0] = 43  , a[4][1] = 15;
    for (int t = 1; t <= T; t++) {
        freopen(("./in/" + to_string(t) + ".in").c_str(), "w", stdout);
        int n = 999999 + t - 1;
        cout << n << '\n';
        vector<int> a(n, 0);
        for (int i = 0; i < n; i++) a[i] = rand(100, 1000000);
        for (int i = 1; i <= n / 2 + 1; i++) a[i] = t * 2 + 1;
        for (int i = 0; i < n; i++) {
            int x = rand(0, n - 1);
            swap(a[i], a[x]);
        }
        for (int i = 0; i < n; i++) cout << a[i] << ' ';
        cout << endl;
    
        cout.clear();
    }
    fclose(stdout);
    return 0;
}
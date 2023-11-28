#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void gen_arr(int n, int l, int r) {
    for (int i = 0; i < n; i++) {
        int x = rand() % 10;
        cout << x;
        if (i != n - 1) cout << ' ';
        else cout << '\n';
    }
}

int main() {
    srand(time(0));
    int T = 10;
    vector<vector<LL>> a(10, vector<LL>(2, 0));
    a[0][0] = 55, a[0][1] = 8;
    a[1][0] = 10441959267565LL, a[1][1] = 262144LL;
    a[2][0] = 1, a[2][1] = 8;
    a[3][0] = 27, a[3][1] = 1;
    a[4][0] = 8169866510401LL, a[4][1] = 8192;
    a[5][0] = 6766125366781LL, a[5][1] =128;
    a[6][0] = 19006130119005LL, a[6][1] = 262144;
    a[7][0] = 1554141261601LL, a[7][1] = 2048;
    a[8][0] = 826589491921LL, a[8][1] = 4;
    a[9][0] = 9413656971292LL, a[9][1] = 1024;
    for (int t = 1; t <= T; t++) {
        freopen(("./in/" + to_string(t) + ".in").c_str(), "w", stdout);
        cout << a[t - 1][0] << ' ' << a[t - 1][1] << '\n';
        cout.clear();
    }
    fclose(stdout);
    return 0;
}
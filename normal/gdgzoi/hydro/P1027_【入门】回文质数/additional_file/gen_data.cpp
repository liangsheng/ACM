#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int rand(int l, int r) {
    return rand() % (r - l + 1) + l;
}

int main() {
    srand(time(0));
    int T = 5;
    vector<vector<LL>> a(T, vector<LL>(2, 0));
    for (int i = 0; i < T; i++) {
        a[i][0] = rand(1, 1000);
        a[i][1] = rand(1, 100000000);
        a[i][1] = a[i][1] + a[i][1];
    }
    a[0][0] = 5, a[0][1] = 1000;
    a[1][0] = 750, a[1][1] = 14000;
    a[2][0] = 5, a[2][1] = 1000000000;
    for (int t = 1; t <= T; t++) {
        freopen(("./testdata/" + to_string(t) + ".in").c_str(), "w", stdout);
        cout << a[t - 1][0] << " " << a[t - 1][1] << '\n';
        cout.clear();
    }
    fclose(stdout);
    return 0;
}
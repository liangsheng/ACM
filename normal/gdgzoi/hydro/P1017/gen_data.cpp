#include <bits/stdc++.h>
using namespace std;

int rand(int l, int r) {
    return rand() % (r - l + 1) + l;
}

int main() {
    srand(time(0));
    int T = 5;
    vector<vector<int>> a(T, vector<int>(2, 0));
    a[0][0] = 698680, a[0][1] = 765184;
    a[1][0] = 600832, a[1][1] = 935744;
    a[2][0] = 639600, a[2][1] = 2992;
    a[3][0] = 1000000  , a[3][1] = 80;
    a[4][0] = 100  , a[4][1] = 80;
    for (int t = 1; t <= T; t++) {
        freopen(("./in/" + to_string(t) + ".in").c_str(), "w", stdout);
        cout << a[t - 1][0] << '\n';
        cout.clear();
    }
    fclose(stdout);
    return 0;
}
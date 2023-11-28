#include <bits/stdc++.h>
using namespace std;

int rand(int l, int r) {
    return rand() % (r - l + 1) + l;
}

int main() {
    srand(time(0));
    int T = 4;
    vector<vector<int>> a(5, vector<int>(4, 0));
    a[0][0] = 218, a[0][1] = 765184;
    a[1][0] = 950, a[1][1] = 935744;
    a[2][0] = 60 , a[2][1] = 2992;
    a[3][0] = 6  , a[3][1] = 80;
    for (int t = 1; t <= T; t++) {
        freopen(("./in/" + to_string(t) + ".in").c_str(), "w", stdout);
        cout << a[t - 1][0] << ' ' << a[t - 1][1] << '\n';
        cout.clear();
    }
    fclose(stdout);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int rand(int l, int r) {
    return rand() % (r - l + 1) + l;
}

int main() {
    srand(time(0));
    int T = 5;
    vector<int> n = {10, 100, 1000, 10000, 100000};
    vector<vector<int>> a(T), b(T);
    vector<vector<pair<int, int>>> L(T);
    for (int i = 0; i < T; i++) {
        a[i] = vector<int>(n[i], 0);
        b[i] = vector<int>(n[i], 0);
        for (int j = 0; j < n[i]; j++) {
            a[i][j] = rand() % n[i] + 1;
            b[i][j] = rand() % n[i] + 1;
        }
        vector<int> c(n[i], 0);
        vector<int> d(n[i], 0);
        for (int j = 0; j < n[i]; j++) c[j] = j, d[j] = j;
        sort(c.begin(), c.end(), [&](const int& x, const int& y) {
            return a[i][x] > a[i][y];
        });
        sort(d.begin(), d.end(), [&](const int& x, const int& y) {
            return b[i][x] > b[i][y];
        });
        int maxl = min((LL) n[i] * n[i] - 50, 100000LL);
        int e = max((int) sqrt(maxl), 0);
        for (int j = 0; j < e; j++) for (int k = 0; k < e; k++) {
            L[i].push_back({c[j] + 1, d[k] + 1});
        }
        // for (int j = 0; j < n[i]; j++) cout << a[i][j] << ' ';
        // cout << '\n';
        // for (int j = 0; j < n[i]; j++) cout << c[j] + 1 << ' ';
        // cout << '\n';
        // for (int j = 0; j < n[i]; j++) cout << b[i][j] << ' ';
        // cout << '\n';
        // for (int j = 0; j < n[i]; j++) cout << d[j] + 1 << ' ';
        // cout << '\n';
    }

    for (int t = 1; t <= T; t++) {
        freopen(("./testdata/" + to_string(t) + ".in").c_str(), "w", stdout);
        cout << n[t - 1] << ' ' << n[t - 1] << ' ' << L[t - 1].size() << '\n';
        for (int i = 0; i < n[t - 1] - 1; i++) cout << a[t - 1][i] << ' ';
        cout << a[t - 1][n[t - 1] - 1] << endl;
        for (int i = 0; i < n[t - 1] - 1; i++) cout << b[t - 1][i] << ' ';
        cout << b[t - 1][n[t - 1] - 1] << endl;
        for (int i = 0; i < L[t - 1].size(); i++) cout << L[t - 1][i].first << ' ' << L[t - 1][i].second << '\n';
        cout.clear();
    }

    fclose(stdout);
    return 0;
}
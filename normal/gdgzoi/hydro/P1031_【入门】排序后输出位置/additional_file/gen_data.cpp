#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int rand(int l, int r) {
    return rand() % (r - l + 1) + l;
}

int main() {
    srand(time(0));
    int T = 5;
    vector<int> n = {10, 100, 1000, 10000, 100000, 100000, 100000, 100000};
    vector<vector<int>> a(T);
    for (int i = 0; i < T; i++) {
        a[i] = vector<int>(n[i], 0);
        for (int j = 0; j < n[i]; j++) a[i][j] = j + 1;
        for (int j = 0; j < n[i]; j++) {
            int p = rand() % n[i];
            swap(a[i][j], a[i][p]);
        }
    }

    for (int t = 1; t <= T; t++) {
        freopen(("./testdata/" + to_string(t) + ".in").c_str(), "w", stdout);
        cout << n[t - 1] << '\n';
        for (int i = 0; i < n[t - 1] - 1; i++) cout << a[t - 1][i] << ' ';
        cout << a[t - 1][n[t - 1] - 1] << endl;
        cout.clear();
    }
    fclose(stdout);
    return 0;
}
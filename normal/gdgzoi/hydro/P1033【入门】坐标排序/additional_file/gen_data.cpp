#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int rand(int l, int r) {
    return rand() % (r - l + 1) + l;
}

int main() {
    srand(time(0));
    int T = 5;
    vector<int> n = {10, 100, 1000, 10000, 10000};
    vector<vector<int>> a(T, vector<int>());
    vector<vector<int>> b(T, vector<int>());
    for (int i = 0; i < T; i++) {
        for (int j = 0; j < n[i]; j++) {
            int x = rand(1, min(n[i], 100));
            int y = rand(1, min(n[i], 100));
            a[i].push_back(x);
            b[i].push_back(y);
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
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<pair<int, int>> a;
    for (int i = 0; i < 24; i++) for (int j = 0; j < 60; j++) {
        int A = i / 10, B = i % 10, C = j / 10, D = j % 10;
        if ((10 * A + C < 24) && (10 * B + D < 60)) a.push_back({i, j});
    }
    int n, m;
    while (cin >> n >> m) {
        int id = lower_bound(a.begin(), a.end(), make_pair(n, m)) - a.begin();
        if (id < a.size()) cout << a[id].first << ' ' << a[id].second << '\n';
        else cout << "0 0" << '\n';
    }
    return 0;
}
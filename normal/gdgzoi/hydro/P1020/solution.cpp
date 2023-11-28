#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    while (cin >> n) {
        vector<int> b(n);
        vector<vector<int>> a(2);
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            a[b[i] % 2].push_back(b[i]);
        }
        sort(a[0].begin(), a[0].end());
        sort(a[1].begin(), a[1].end());
        vector<int> e(2, 0);
        for (int i = 0; i < n; i++) cout << a[b[i] % 2][e[b[i] % 2]++] << ' ';
        cout << '\n';
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        if (n == 2) {
            cout << "2 1" << '\n';
            continue;
        }
        if (n == 3) {
            cout << "-1" << '\n';
            continue;
        }
        vector<int> a(n + 1);
        a[1] = n - 1, a[2] = n;
        for (int i = 3; i <= n; i++) a[i] = i - 2;
        for (int i = 1; i < n; i++) cout << a[i] << ' ';
        cout << a[n] << '\n';
    }
    return 0;
}
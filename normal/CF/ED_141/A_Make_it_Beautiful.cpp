#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        int t = a[n - 1];
        for (int i = n - 1; i >= 1; i--) a[i] = a[i - 1];
        a[0] = t;
        if (a[0] == a[1]) cout << "NO" << '\n';
        else {
            cout << "YES" << '\n';
            for (int i = 0; i < n - 1; i++) cout << a[i] << ' ';
            cout << a[n - 1] << '\n';
        }
    }
    return 0;
}
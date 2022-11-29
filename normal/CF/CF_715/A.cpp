#include <bits/stdc++.h>
using namespace std;

const int N = 2005;

int T, n;
int a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i< n; i++) cin >> a[i];
        sort(a, a + n, [](const int& x, const int& y) {
            return x % 2 < y % 2;
        });
        for (int i = 0; i < n - 1; i++) cout << a[i] << ' ';
        cout << a[n - 1] << '\n';
    }
    return 0;
}
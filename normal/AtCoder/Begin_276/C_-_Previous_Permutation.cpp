#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, p, q;
    while (cin >> n) {
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = n; i > 1; i--) if (a[i - 1] > a[i]) {
            p = i - 1;
            break;
        }
        for (int i = n; i > p; i--) if (a[i] < a[p]) {
            q = i;
            break;
        }
        swap(a[p], a[q]);
        sort(a.begin() + p + 1, a.end(), greater<int>());
        for (int i = 1; i < n; i++) cout << a[i] << ' ';
        cout << a[n] << '\n';
    }
    return 0;
}
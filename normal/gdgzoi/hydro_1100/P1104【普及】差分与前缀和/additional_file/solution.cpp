#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    // 这两句是为了让 cin 更快
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m, l, r, x;
	cin >> n >> m;

    vector<LL> a(n + 2, 0);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = n; i >= 1; i--) a[i] = a[i] - a[i - 1];  // 差分

    while (m--) {
        cin >> l >> r >> x;
        a[l] += x, a[r + 1] -= x;
    }
    for (int i = 1; i <= n; i++) a[i] = a[i] + a[i - 1];  // 前缀和
    for (int i = 1; i <= n; i++) cout << a[i] << " \n"[i == n];
    return 0;
}
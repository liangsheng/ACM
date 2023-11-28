#include <bits/stdc++.h>
using namespace std;

int T, n, m;
vector<int> a;

bool gao() {
    int f = 1;
    for (int i = 1, j = n; i <= j; i++, j--) if (a[i] != a[j]) {
        f = 0;
        break;
    }
    if (f) return 1;
    if (n == m) return f;
    if (m % 2 || n % 2) return 1;
    int ans = 0;
    for (int i = 1, j = n; i <= j; i++, j--) {
        ans = (ans + abs(a[i] - a[j])) % 2;
    }
    return ans == 0;
}

int main() {
	cin >> T;
	while (T--) {
        cin >> n >> m;
        a = vector<int>(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        cout << (gao() ? "YES" : "NO") << '\n';
	}
	return 0;
}
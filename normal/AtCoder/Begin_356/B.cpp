#include <bits/stdc++.h>
using namespace std;

int main() {
    // 下面 2 句话是为了让 cin 更快，不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, x, ok = 1;
    cin >> n >> m;
    vector<int> a(m);
    for (int i = 0; i < m; i++) cin >> a[i];
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        cin >> x;
        a[j] -= x;
    }
    for (int i = 0; i < m; i++) if (a[i] > 0) {
        ok = 0;
        break;
    }
    cout << (ok ? "Yes" : "No") << '\n';
    return 0;
}
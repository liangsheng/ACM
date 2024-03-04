#include <bits/stdc++.h>
using namespace std;

int hao(vector<int> a, int n, int m) {
    sort(a.begin(), a.end());
    int ans = a[n - 1] - a[0];
    for (int i = 0; i < n - 1; i++) {
        int l = a[0] + m, r = a[i] + m;
        int u = a[i + 1] - m, v = a[n - 1] - m;
        ans = min(ans, max(r, v) - min(l, u));
    }
    return ans;
}

int main() {
    // 下面 2 句话是为了让 cin, cout 更快, 不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    while (cin >> n >> m) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        cout << hao(a, n, m) << '\n';
    } 
    return 0;
}
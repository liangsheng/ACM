#include <bits/stdc++.h>
using namespace std;

int main() {
    // 下面 2 句话是为了让 cin, cout 更快, 并不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    auto gao = [&](int mid) {
        int p = 0, pre = a[0];
        for (int i = 2; i <= m; i++) {
            while (p < n && a[p] - pre < mid) p++;
            if (p >= n) return false; 
            pre = a[p];
        }
        return true;
    };
    int l = 1, r = a[n - 1] - a[0], mid;
    while (l != r) {
        mid = (l + r) / 2 + 1;
        if (gao(mid)) l = mid;
        else r = mid - 1;
    }
    cout << l << '\n';
    return 0;
}
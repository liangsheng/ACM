#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    // 下面 2 句话是为了让 cin 更快，不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int m = a[n - 1];
    vector<int> h(m + 1);
    int p = 0;
    for (int i = 1; i <= m; i++) {
        while (a[p] <= i && p + 1 < n) p++;
        if (a[p] > i) h[i] = p;
        else h[i] = n;
    }
    LL ans = 0;
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 0; j < i; j++) {
            int k = a[i] / a[j], r = a[i] / k;
            int id = min(h[r], i) - 1;
            ans += (LL) k * (id - j + 1);
            j = id;
        }
    }
    cout << ans << '\n';
    return 0;
}

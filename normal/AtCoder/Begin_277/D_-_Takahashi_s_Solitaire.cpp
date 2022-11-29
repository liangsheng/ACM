#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    LL sum = 0;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i], sum += a[i];
    sort(a.begin(), a.end());
    // for (int i = 0; i < n; i++) cout << a[i] << ' ';
    // cout << '\n';
    LL ans = 0, tmp;
    for (int i = 0; i < n; i++) {
        tmp = a[i];
        while (i + 1 < n && (a[i + 1] == a[i] || a[i + 1] == a[i] + 1)) tmp += a[++i];
        // cout << "i= " << i << ", a[i]= " << a[i] << ", tmp= " << tmp << '\n';
        ans = max(ans, tmp);
    }
    if (a[0] == 0 && a[n - 1] == m - 1) {
        int i = 0;
        tmp = a[i];
        while (i + 1 < n && (a[i + 1] == a[i] || a[i + 1] == a[i] + 1)) tmp += a[++i];
        if (i < n - 1) {
            i = n - 1;
            tmp += a[i];
            while (i - 1 >= 0 && (a[i - 1] == a[i] || a[i - 1] + 1 == a[i])) tmp += a[--i];
        }
        ans = max(ans, tmp);
    }
    cout << sum - ans << '\n';
    return 0;
}
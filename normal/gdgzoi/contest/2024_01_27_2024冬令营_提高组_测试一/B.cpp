#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n + 2, 0);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt += max(a[i] - a[i - 1], 0);
    }
    vector<vector<int>> ans(cnt, vector<int>(2, 0));
    int l = 0, r = 0;
    for (int i = 1; i <= n + 1; i++) {
        if (a[i] > a[i - 1]) {
            for (int j = 1; j <= a[i] - a[i - 1]; j++) ans[l++][0] = i; 
        } else {
            for (int j = 1; j <= a[i - 1] - a[i]; j++) ans[r++][1] = i - 1; 
        }
    }
    cout << cnt << '\n';
    for (int i = 0; i < cnt; i++) cout << ans[i][0] << ' ' << ans[i][1] << '\n';
    return 0;
}

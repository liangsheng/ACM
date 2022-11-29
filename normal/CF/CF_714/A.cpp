#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int T, n, k;

void gao() {
    if (k == 0) {
        for (int i = 1; i < n; i++) cout << i << ' ';
        cout << n << '\n';
        return ;
    }
    if (n < 2 * k + 1) {
        puts("-1");
        return ;
    }

    int l = 2, r = n - 2;
    vector<int> ans;
    ans.push_back(n - 1);
    ans.push_back(n), ans.push_back(1);
    for (int i = 2; i <= k; i++) {
        ans.push_back(r--);
        ans.push_back(l++);
    }
    for (int i = l; i <= r; i++) ans.push_back(i);
    for (int i = 0; i < n - 1; i++) cout << ans[i] << ' ';
    cout << ans[n - 1] << '\n';
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> n >> k;
        gao();
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int D = 60;

int n;
vector<int> a(2, 0);
vector<LL> ans;

void gao(int p) {
    if (n == 2 || p == D + 1) {
        LL t = 0;
        for (int i = 0; i < n; i++) t |= (1LL << a[i]);
        ans.push_back(t);
        return ;
    }
    gao(p + 1);
    if (n < 2) {
        a[n++] = p;
        gao(p + 1);
        n--;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    n = 0;
    gao(0);
    sort(ans.begin(), ans.end());
    // for (int i = 0; i < ans.size(); i++) cout << ans[i] << '\n';
    // cout << ans.size() << '\n';
    int T;
    LL m;
    cin >> T;
    while (T--) {
        cin >> m;
        int i = lower_bound(ans.begin(), ans.end(), m) - ans.begin();
        // cout << "i= " << i << " " << ans[i] << ' ' << m << '\n';
        if (i >= 0 && i < ans.size() && ans[i] == m) cout << ans[i + 1] << '\n';
        else cout << "No,Commander" << '\n';
    }
    return 0;
}
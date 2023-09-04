#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    while (cin >> n) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        vector<int> b = a;
        sort(b.begin(), b.end(), greater<int>());
        
        m = n;
        vector<int> ans;
        for (int k = 0; k < m; k++) {
            int p = -1;
            for (int i = 0; i < n; i++) if (a[i] == b[k]) {
                p = i;
                break;
            }
            ans.push_back(p);
            for (int i = p; i < n - 1; i++) a[i] = a[i + 1];
            n--;
            reverse(a.begin(), a.begin() + n);
        }
        int res = (m + 1) * m / 2;
        cout << res << '\n';
        vector<string> c = {"A B", "B A"};
        vector<string> d = {"A C", "B C"};
        for (int i = 0; i < m; i++) {
            // cout << "i= " << i << ", ans[i]= " << ans[i] << '\n';
            int k = i & 1;
            for (int j = 0; j < ans[i]; j++) cout << c[k] << '\n';
            cout << d[k] << '\n';
            for (int j = 0; j < m - i - 1 - ans[i]; j++) cout << c[k] << '\n';
        }
    }
    return 0;
}
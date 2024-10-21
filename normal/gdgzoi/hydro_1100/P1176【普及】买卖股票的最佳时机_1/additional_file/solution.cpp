#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& p) {
    int n = p.size();
    vector<int> f(n);
    f[n - 1] = p[n - 1];
    for (int i = n - 2; i >= 0; i--) f[i] = max(p[i], f[i + 1]);
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        ans = max(ans, max(0, f[i + 1] - p[i]));
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    cout << maxProfit(p) << '\n';

    return 0;
}
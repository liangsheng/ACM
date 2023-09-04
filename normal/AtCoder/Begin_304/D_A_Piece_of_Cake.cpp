#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int w, h, n, A, B;
    while (cin >> w >> h >> n) {
        vector<int> x(n), y(n);
        for (int i = 0; i < n; i++) cin >> x[i] >> y[i];

        cin >> A;
        vector<int> a(A + 2, 0);
        for (int i = 1; i <= A; i++) cin >> a[i];
        a[A + 1] = w;

        cin >> B;
        vector<int> b(B + 2, 0);
        for (int i = 1; i <= B; i++) cin >> b[i];
        b[B + 1] = h;

        map<pii, int> q;
        for (int i = 0; i < n; i++) {
            int u = upper_bound(a.begin(), a.end(), x[i]) - a.begin();
            int v = upper_bound(b.begin(), b.end(), y[i]) - b.begin();
            q[{u, v}]++;
        }
        int mini = n, maxi = 0;
        for (auto it : q) mini = min(mini, it.second), maxi = max(maxi, it.second);
        if (q.size() < (LL) (A + 1) * (B + 1)) mini = 0;
        cout << mini << ' ' << maxi << '\n';
    }
    return 0;
}
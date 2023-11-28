#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MOD = 998244353;

vector<int> mp;
vector<int> p;

// jingly code
// https://codeforces.com/contest/1766/submission/184952734
void init(int N) {
    mp = vector<int>(N + 1, 0);
    p = vector<int>();
    for (int i = 2; i <= N; i++) {
        if (mp[i] == 0) mp[i] = i, p.push_back(i);
        for (int t : p) {
            if (i * t > N) break;
            mp[i * t] = t;
            if (i % t == 0) break;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    init(10000);
    int m = p.size();

    int n, w;
    while (cin >> n >> w) {
        vector<int> a(n + 1);
        for (int i = 0; i < n; i++) cin >> a[i];
        a[n] = w;

        vector<vector<int>> cnt(n + 1, vector<int>(m));
        for (int i = 0; i <= n; i++) {
            int x = a[i];
            for (int j = 0; j < m; j++) {
                while (x % p[j] == 0) cnt[i][j]++, x /= p[j];
            }
        }
        for (int j = 0; j < m; j++) {
            while (cnt[n][j] > 0) {
                int p = 0;
                for (int i = 1; i < n; i++) if (cnt[i][j] < cnt[p][j]) p = i;
                cnt[p][j]++;
                cnt[n][j]--;
            }
        }

        LL ans = 1;
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
            ans = (LL) ans * (cnt[i][j] + 1) % MOD;
        }
        cout << ans << '\n';
    }
    return 0;
}
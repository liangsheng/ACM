#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 10000;

int e;
vector<int> mp(N + 1, 0);
vector<int> p;

// jingly code
// https://codeforces.com/contest/1766/submission/184952734
void init() {
    for (int i = 2; i <= N; i++) {
        if (mp[i] == 0) mp[i] = i, p.push_back(i);
        for (int t : p) {
            if (i * t > N) break;
            mp[i * t] = t;
            if (i % t == 0) break;
        }
    }
    e = p.size();
}

int T, n;
vector<LL> a;

bool gao() {
    vector<set<int>> q(e, set<int>());
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) {
        if (a[i] == a[j]) return 0;
        LL d = a[j] - a[i];
        for (int k = 0; k < e; k++) {
            if (d % p[k]) continue;
            q[k].insert(a[i] % p[k]);
            // cout << "k= " << p[k] << ' ' << q[k].size() << '\n';
            if (q[k].size() == p[k]) return 0;
        }
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    cin >> T;
    while (T--) {
        cin >> n;
        a = vector<LL>(n, 0);
        for (int i = 0; i < n; i++) cin >> a[i];
        cout << (gao() ? "YES" : "NO") << '\n';
    }
    return 0;
}
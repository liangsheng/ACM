#include <bits/stdc++.h>
using namespace std;

const int N = 1000000;

vector<int> mp(N + 1, 0);
vector<int> p;

void init() {
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
    cin.tie(0);
    int T, n, m;
    init();
    cin >> T;
    while (T--) {
        cin >> n >> m;
        vector<int> a(n, 0);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
        n = a.size();
        if (n == 1 || m == 2) {
            cout << 0 << '\n';
            continue;
        }
        int d = a[0];
        for (int i = 1; i < n; i++) d = __gcd(d, a[i]);
        if (d > 1) {
            cout << 1 << '\n' << d << '\n';
            continue;
        }
        int e = p.size();
        set<int> s;
        for (int i = 0; i < n; i++) {
            int x = a[i];
            while (x != 1) {
                s.insert(mp[x]);
                x /= mp[x];
            }
        }
        int id = -1;
        for (int i = 0; i < e && p[i] <= m; i++) if (!s.count(p[i])) {
            id = i;
            break;
        }
        if (id != -1) cout << 1 << ' ' << p[id] << '\n';
        else cout << 2 << '\n' << 2 << ' ' << 3 << '\n';
    }
    return 0;
}
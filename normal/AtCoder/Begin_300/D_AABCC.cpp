#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

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
    init();
    LL n;
    while (cin >> n) {
        LL d = LL(sqrt(n)), ans = 0;
        for (LL i = 6; i <= d; i++) {
            LL u, v, j = i;
            if (mp[j] == j) continue;
            u = mp[j], j /= mp[j];
            if (mp[j] != j) continue;
            v = mp[j];
            if (u > v) swap(u, v);
            int L = lower_bound(p.begin(), p.end(), u) - p.begin() + 1;
            int R = lower_bound(p.begin(), p.end(), v) - p.begin() - 1;
            if (L > R) continue;
            LL c = n / (u * u * v * v); 
            int x = upper_bound(p.begin(), p.end(), c) - p.begin() - 1;
            // cout << "i= " << i << ' ' << u << ' ' << v << ' ' << c << ' ' << L << ' ' << R << ' ' << c << '\n';
            if (x >= L) ans += min(x, R) - L + 1;
        }
        cout << ans << '\n';
    }
    return 0;
}
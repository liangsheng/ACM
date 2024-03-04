#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
 
int main() {
    // 下面 2 句话是为了让 cin 更快，不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, t;
    cin >> n >> t;
    vector<pii> a(t + 1);
    for (int i = 1; i <= t; i++) cin >> a[i].X >> a[i].Y;
    vector<LL> f(n + 1, 0);
    map<LL, int> q;
    q[0] = n;
    for (int i = 1; i <= t; i++) {
        auto [x, y] = a[i];
        LL p = f[x];
        f[x] += y;
        q[p]--;
        if (q[p] == 0) q.erase(p);
        q[f[x]]++;
        cout << q.size() << '\n';
    }
    return 0;
}
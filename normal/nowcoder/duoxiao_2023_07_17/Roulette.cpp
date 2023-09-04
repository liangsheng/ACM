#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

const int MOD = 998244353, M = 499122177;

int n, m;
map<pii, int> q;

int gao(int i, int j) {
    if (i >= n + m) return 1;
    if (q.count({i, j})) return q[{i, j}];
    LL t = gao(i + j, 1);
    if (i - j >= j * 2) t += gao(i - j, j * 2);
    t = t * M % MOD;
    q[{i, j}] = t;
    return t;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n >> m) {
        q.clear();
        cout << gao(n, 1) << '\n';
    }
    return 0;
}
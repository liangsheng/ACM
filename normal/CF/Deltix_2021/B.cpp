#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 100005;
const LL INF = ~0ULL >> 2;

int T, n;
bool a[N], b[N];

LL cal(bool a[N], bool b[N]) {
    vector<int> u, v;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 0) u.push_back(i);
        if (b[i] == 0) v.push_back(i);
    }
    LL ans = 0;
    for (int i = 0; i < u.size(); i++)  ans += abs(u[i] - v[i]);
    return ans;
}

LL gao() {
    int sum = accumulate(a + 1, a + n + 1, 0);
    LL ans = INF, tmp;
    if (n % 2 == 0) {
        if (sum * 2 != n) return -1;
        for (int i = 1; i <= n; i++) b[i] = i % 2;
        tmp = cal(a, b);
        ans = min(ans, tmp);
        for (int i = 1; i <= n; i++) b[i] = (i + 1) % 2;
        tmp = cal(a, b);
        ans = min(ans, tmp);
        return ans;
    } else {
        if (sum * 2 == n + 1) {
            for (int i = 1; i <= n; i++) b[i] = i % 2;
            tmp = cal(a, b);
            ans = min(ans, tmp);
            return ans;  
        } else if (sum * 2 == n - 1) {
            for (int i = 1; i <= n; i++) b[i] = (i + 1) % 2;
            tmp = cal(a, b);
            ans = min(ans, tmp);
            return ans;
        } else return -1;
    }
    return 0;
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int x;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> x;
            a[i] = x & 1;
        }
        cout << gao() << '\n';
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<int> gao(int x) {
    vector<int> ans;
    for (int i = 1; (LL) i * i <= x; i++) {
        if (x % i) continue;
        ans.push_back(i);
        if (i * i != x) ans.push_back(x / i);
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, a, b, x, y;
    cin >> T;
    while (T--) {
        cin >> a >> b;
        if (a >= b) {
            cout << a - b << '\n';
            continue;
        }
        if (b % a == 0) {
            cout << 0 << '\n';
            continue;
        }
        int ans = a - b % a;
        for (int i = 1; i <= 100000; i++) {
            int d = a + i, tmp;
            if (b % d == 0) tmp = i;
            else tmp = i + d - b % d;
            if (tmp < ans) ans = tmp, x = i, y = tmp - i;
        }
        cout << "x= " << x << " y= " << y << '\n';
        for (int i = 0; i <= 1; i++) {
            int c = b + i;
            vector<int> d = gao(c);
            int tmp = *lower_bound(d.begin(), d.end(), a) - a + i;
            ans = min(ans, tmp);
        }
        cout << ans << '\n';
    }
    return 0;
}

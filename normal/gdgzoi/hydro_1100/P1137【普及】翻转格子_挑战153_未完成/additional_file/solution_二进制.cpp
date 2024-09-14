#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> c(n);
    for (int i = 0; i < n; i++) cin >> c[i];

    int na = n / 2;
    set<LL> a;
    for (int st = 0; st < (1 << na); st++) {
        long long s = 0;
        for (int i = 0; i < na; i++) if ((st >> i) & 1) s += c[i];
        a.insert(s);
    }

    int nb = n - na;
    set<LL> b;
    for (int st = 0; st < (1 << nb); st++) {
        long long s = 0;
        for (int i = 0; i < nb; i++) if ((st >> i) & 1) s += c[na + i];
        b.insert(s);
    }

    // cout << "a= " << '\n';
    // for (LL x: a) cout << x << ' ';
    // cout << '\n';

    // cout << "b= " << '\n';
    // for (LL x: b) cout << x << ' ';
    // cout << '\n';

    bool ok = false;
    for (LL x: a) if (b.count(k - x)) {
        ok = true;
        break;
    }
    cout << (ok ? "Yes" : "No") << '\n';
    return 0;
}

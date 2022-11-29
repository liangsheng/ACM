#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while (cin >> n) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        int sum = accumulate(a.begin(), a.end(), 0);
        int p = 0;
        set<pair<int, int>> s;
        for (int i = 0; i < n; i++) {
            if (a[i] == 0) p++;
            else p--;
            s.insert(make_pair(p, i));
        }
        int L = n, R = -n, d = 0;
        for (int i = 0; i < n; i++) {
            int mini = s.begin()->first - d, maxi = s.rbegin()->first - d;
            if (mini < L) L = mini;
            if (maxi > R) R = maxi;
            if (a[i] == 0) d++;
            else d--;
            s.erase(make_pair(d, i));
            // cout << "i= " << i << " mini= " << mini << " maxi= " << maxi << " d= " << d << '\n';
        }
        if (R < 0 || L > 0) cout << R - L + 2 << '\n';
        else cout << R - L + 1 << '\n';
    }
    return 0;
}
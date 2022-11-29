#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 5005;

int n;
LL ans;
string s;

LL gao(char ch) {
    vector<int> a;
    for (int i = 0; i < n; i++) if (s[i] == ch) a.push_back(i);
    int m = a.size();
    LL tmp = 0;
    for (int k = 0; k < m; k++) {
        int l, r;
        if (k == 0) l = 0;
        else l = a[k - 1] + 1;
        if (k == m - 1) r = n - 1;
        else r = a[k + 1] - 1;
        if (l <= a[k] - 2) tmp += a[k] - 2 - l + 1;
        if (r >= a[k] + 2) tmp += r - (a[k] + 2) + 1;
        if (l < a[k] && r > a[k]) tmp += ((LL) a[k] - l) * (r - a[k]);
    }
    return tmp;
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    while (cin >> n) {
        cin >> s;
        ans = 0;
        ans += gao('G');
        ans += gao('H');
        cout << ans << '\n';
    }
    return 0;
}
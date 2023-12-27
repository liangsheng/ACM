#include <bits/stdc++.h>
using namespace std;

double gao(int n, int m, vector<int>& a) {
    a[0] = 0, a[n + 1] = m;
    int l = 0, r = n + 1, vl = 1, vr = 1;
    double ans = 0, lt = 0, rt = 0;
    while (l + 1 < r) {
        double x = lt + 1.0 * (a[l + 1] - a[l]) / vl;
        double y = rt + 1.0 * (a[r] - a[r - 1]) / vr;
        if (x < y) lt = x, vl++, l++;
        else rt = y, vr++, r--;
    }
    double dis = a[r] - a[l];
    if (lt < rt) dis -= (rt - lt) * vl, ans = rt;
    else dis -= (lt - rt) * vr, ans = lt;
    ans += dis / (vl + vr);
    return ans;
}

double hao(int n, int m, vector<int>& a) {
    int vl = 1, vr = 1, pl = 1, pr = n;
    double l = 0, r = m, tim = 0;
    while (pl <= pr) {
        double x = 1.0 * (a[pl] - l) / vl;
        double y = 1.0 * (r - a[pr]) / vr;
        if (x < y) {
            l = a[pl], vl++, pl++;
            r -= vr * x;
            tim += x;
        } else {
            r = a[pr], vr++, pr--;
            l += y * vl;
            tim += y;
        }
    }
    tim += (r - l) / (vl + vr);
    return tim;
}

int main() {
    int T, n, m;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        vector<int> a(n + 2);
        for (int i = 1; i <= n; i++) cin >> a[i];
        // double ans = gao(n, m, a);
        double ans = hao(n, m, a);
        cout << fixed << setprecision(12) << ans << '\n';
    }
    return 0;
}
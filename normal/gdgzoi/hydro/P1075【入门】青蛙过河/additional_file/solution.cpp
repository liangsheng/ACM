#include <bits/stdc++.h>
using namespace std;

const int N = 500005;

int L, n, m;
int a[N];

bool ok(int mid) {
    int now = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] - now > mid) return false;
        while (i + 1 < n && a[i + 1] - now <= mid) i++;
        cnt++, now = a[i];
    }
    return cnt <= m;
};

int main() {
    // 下面 2 句话是为了让 cin, cout 更快, 不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while (T--) {
        cin >> L >> n >> m;
        for (int i = 0; i < n; i++) cin >> a[i];
        a[n++] = L;
        sort(a, a + n);

        int l = 1, r = L, mid;
        while (l != r) {
            mid = (l + r) / 2;
            if (ok(mid)) r = mid;
            else l = mid + 1;
        }
        cout << l << '\n';
    }
    return 0;
}
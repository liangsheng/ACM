#include <bits/stdc++.h>
#define lowbit(x) ((-x) & (x))
using namespace std;

int T, n;
vector<int> a, b, c;

void update(int p, int v) {
    for (; p > 0; p -= lowbit(p)) c[p] += v;
}

int query(int p) {
    int ans = 0;
    for (; p <= n; p += lowbit(p)) ans += c[p];
    return ans;
}

void init() {
    c = vector<int>(n + 1, 0);
    for (int i = 1; i <= n; i++) if (a[i] == i) update(i, 1);
}

int gao() {
    int ans = 0;
    init();
    for (int i = 1; i <= n; i++) {
        if (b[i] == i) continue;
        int t = query(i + 2);
        if (i + 1 <= n && a[i] == i + 1 && a[i + 1] == i && t == n - i - 1) return ans;
        if (i + 1 <= n && a[i] == i + 1 && a[i + 1] == b[i] && t == n - i - 2) return ans + 1;
        if (i + 1 <= n && a[i + 1] == i && a[i] == b[i + 1] && t == n - i - 2) return ans + 1;
        int x = b[i];
        b[a[i]] = x, b[i] = i;
        swap(a[i], a[x]);
        update(i, 1);
        if (a[x] == x) update(x, 1);
        ans++;
        // cout << "i= " << i << '\n';
        // for (int j = 1; j <= n; j++) cout << a[j] << ' ';
        // cout << '\n';
    }
    return ans + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> n;
        a = vector<int>(n + 1), b = a;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            b[a[i]] = i;
        }
        cout << gao() << '\n';
    }
    return 0;
}
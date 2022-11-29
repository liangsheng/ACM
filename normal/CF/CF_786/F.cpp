#include <bits/stdc++.h>
#define lowbit(x) (x & (-x))
using namespace std;

int e;
int b[1000005];

void init(int E) {
    e = E;
    for (int i = 1; i <= e; i++) b[i] = 0;
}

void update(int p, int v) {
    for (; p <= e; p += lowbit(p)) b[p] += v;
}

int add(int p) {
    int ans = 0;
    for (; p > 0; p -= lowbit(p)) ans += b[p];
    return ans;
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int n, m, q, x, y, id;
    while (cin >> n >> m >> q) {
        vector<string> g(n);
        for (int i = 0; i < n; i++) cin >> g[i];
        
        int cnt = 0;
        vector<int> a(n * m, 0);
        init(n * m);
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
            id = j * n + i + 1;
            if (g[i][j] == '*') {
                a[id] = 1;
                cnt++;
                update(id, 1);
            }
        }
        while (q--) {
            cin >> x >> y;
            cout << "x= " << x << " y= " << y << '\n';
            x--, y--;
            id = y * n + x + 1;
            cout << "id= " << id << '\n';
            if (a[id]) {
                a[id] = 0, cnt--;
                update(id, -1);
            } else {
                a[id] = 1, cnt++;
                update(id, 1);
            }
            int tmp = add(cnt);
            // cout << "cnt= " << cnt << " tmp= " << tmp << '\n';
            cout << cnt - tmp << '\n';
        }
    }
    return 0;
}
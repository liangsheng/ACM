#include <bits/stdc++.h>
#define repe(i, u) for (int i = head[u]; i != -1; i = nxt[i])
using namespace std;

const int N = 100005;

/*------------------------- 并查集 begin -------------------*/
int f[N], p[N];

void init(int n) {
    for (int i = 1; i <= n; i++) f[i] = i, p[i] = 0;
}

int find(int x) {
    if (f[x] == x) return f[x];
    int fa = find(f[x]);
    p[x] ^= p[f[x]];
    return f[x] = fa;
}
/*------------------------- 并查集 end ---------------------*/

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    
    int c, t, n, m, x, y;
    string s;
    cin >> c >> t;
    while (t--) {
        cin >> n >> m;
        int T = n + 1, F = -T, U = 0;
        vector<int> from(n + 1);
        for (int i = 1; i <= n; i++) from[i] = i;  // i 的最终值来自 from[i] 的原值
        for (int i = 1; i <= m; i++) {
            cin >> s;
            if (s == "+") {
                cin >> x >> y;
                from[x] = from[y];
            } else if (s == "-") {
                cin >> x >> y;
                from[x] = -from[y];
            } else if (s == "T") {
                cin >> x;
                from[x] = T;
            } else if (s == "F") {
                cin >> x;
                from[x] = F;
            } else if (s == "U") {
                cin >> x;
                from[x] = U;
            }
        }

        // for (int i = 1; i <= n; i++) cout << "i= " << i << ", from[i]= " << from[i] << '\n';
        vector<int> is_u(n + 1, -1);
        for (int i = 1; i <= n; i++) {
            if (from[i] == -i || from[i] == U) is_u[i] = 1;
            else if (from[i] == T || from[i] == F) is_u[i] = 0;
        }
        
        init(n);  // 使用并查集前一定要 init(); !!
        for (int i = 1; i <= n; i++) if (is_u[i] == -1) {
            int x = i, y = from[i], ay = abs(y);
            int fx = find(x), fy = find(ay);
            // cout << "x= " << x << ", fx= " << fx << ", y= " << y << ", fy= " << fy << '\n';
            if (fx == fy) {
                // cout << "same, p[x]= " << p[x] << ", p[ay]= " << p[ay] << '\n';
                if (p[x] == p[ay] && y > 0) continue;  // 没有矛盾
                if (p[x] != p[ay] && y < 0) continue;  // 没有矛盾
                f[fx] = U;                            // 有矛盾, 直接指向 U
            } else {
                f[fx] = fy;
                p[fx] = p[x] ^ p[ay] ^ (y < 0);
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int fi = find(i);
            if (fi == U || (is_u[fi] == 1)) ans++;
        }
        cout << ans << '\n';
    }
    return 0; 
}
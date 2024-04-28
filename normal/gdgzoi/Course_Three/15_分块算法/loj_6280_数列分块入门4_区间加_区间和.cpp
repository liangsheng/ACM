#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

/*
 * loj_6280: https://loj.ac/p/6280
 * 区间更新, 区间求和, 分块
 */
const int N = 50005, M = 250;

LL a[N];    // 原数组
LL b[M];    // 块里的数都要加上的数
LL s[M];    // 块里的数的和
int id[N];  // 块号

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, opt, l, r, c;
    cin >> n;
    LL d = sqrt(n);
    for (int i = 0; i < n; i++) id[i] = i / d, cin >> a[i], s[id[i]] += a[i];  // 块内求和
    for (int t = 0; t < n; t++) {
        cin >> opt >> l >> r >> c;
        l--, r--;  // 从 0 开始编号, 左闭右闭 [l, r]
        if (opt == 0) {
            if (id[l] == id[r]) {
                for (int i = l; i <= r; i++) a[i] += c, s[id[i]] += c;
            } else {
                for (int i = l; id[i] == id[l]; i++) a[i] += c, s[id[i]] += c;  // 左边多余的部分
                for (int i = r; id[i] == id[r]; i--) a[i] += c, s[id[i]] += c;  // 右边多余的部分
                for (int i = id[l] + 1; i < id[r]; i++) s[i] += d * c, b[i] += c;
            }
        } else {
            LL ans = 0;
            if (id[l] == id[r]) {
                for (int i = l; i <= r; i++) ans += a[i] + b[id[i]];
            } else {
                for (int i = l; id[i] == id[l]; i++) ans += a[i] + b[id[i]];  // 左边多余的部分
                for (int i = r; id[i] == id[r]; i--) ans += a[i] + b[id[i]];  // 右边多余的部分
                for (int i = id[l] + 1; i < id[r]; i++) ans += s[i];
            }
            cout << ans % (c + 1) << '\n';
        }
    }
    return 0;
}
// https://atcoder.jp/contests/abc348/submissions/52093801
#include <bits/stdc++.h>
using namespace std;

const int N = 2005, M = 1005;

int a[N][N];

int main() {
    // 下面 2 句话是为了让 cin 更快，不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> a[i][j];

    // bitset 默认都是 0
    bitset<N> g[N];  // g[i][j] 表示 第 i 行和第 j 行相同的索引数
    bitset<N> h[M];  // h[i][j] == 1 表示数 i 出现在第 j 行
    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= 999; i++) h[i] = 0;
        for (int i = 1; i <= n; i++) h[a[i][j]][i] = 1;   // a[i][j] 在第 i 行出现
        for (int i = 1; i <= n; i++) g[i] ^= h[a[i][j]];  // 所有和第 i 行有相同数的行
    }
    int ans = 0;
    // g[i].count() 记录和第 i 行相同的数的个数是基数的行
    for (int i = 1; i <= n; i++) ans += g[i].count();
    if (m % 2) ans -= n;  // 如果 m 是奇数, 每一行和自己本身也是相似的
    cout << ans / 2 << '\n';
    return 0;
}
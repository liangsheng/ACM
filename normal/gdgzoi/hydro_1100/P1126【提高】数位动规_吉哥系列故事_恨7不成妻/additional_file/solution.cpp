#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MOD = 998244353;

// s[i][0][j][k]: 前 i 位数, 和 x 相等, 数字和 %7 是 j, 数 %7 是 k 的数的和
// s[i][1][j][k]: 前 i 位数, 比 x 小  , 数字和 %7 是 j, 数 %7 是 k 的数的和
int s[20][2][7][7];

// f 存的是数的平方和
int f[20][2][7][7];

// c 存的是数的个数
int c[20][2][7][7];

void add(int& x, int y) {
    x = ((LL) x + y) % MOD;
}

// 统计 0 到 x 与 7 无关的数的平方和
int cal(LL x) {
    // cout << "x= " << x << '\n';
    vector<int> a;
    while (x != 0) a.push_back(x % 10), x /= 10;
    int n = a.size();

    memset(s, 0, sizeof(s));
    memset(f, 0, sizeof(f));
    memset(c, 0, sizeof(c));
    c[0][0][0][0] = 1;
    for (int i = 0; i < n; i++) for (int ls = 0; ls < 2; ls++) {
        for (int j = 0; j < 7; j++) for (int k = 0; k < 7; k++) { 
            // printf("i= %d, %d, %d, %d, %d\n", i, ls, j, k, c[i][ls][j][k]);

            // ls = 1, 表示前面已经小了, 那么这一位 0 到 9 都可以
            // ls = 0, 表示前面相等, 那么这一位只能 0 到 a[n - i]
            int lim = (ls ? 9 : a[n - 1 - i]);
            for (int d = 0; d <= lim; d++) {
                if (d == 7) continue;  // 不能包含 7
                int u = (j + d) % 7, v = (k * 10 + d) % 7;

                // 先更新个数 c
                add(c[i + 1][ls | (d < lim)][u][v], c[i][ls][j][k]);

                // 再更新和 dp
                int t = ((LL) s[i][ls][j][k] * 10 + (LL) c[i][ls][j][k] * d) % MOD;
                add(s[i + 1][ls | (d < lim)][u][v], t);

                // 最后更新平方和 
                // (10x + d)^2 = 100x^2 + 20xd + d^2
                t = ((LL) 100 * f[i][ls][j][k] + (LL) 20 * s[i][ls][j][k] * d + (LL) c[i][ls][j][k] * d * d) % MOD;
                add(f[i + 1][ls | (d < lim)][u][v], t);
            }
        }
    }
    int ans = 0;
    for (int j = 1; j < 7; j++) for (int k = 1; k < 7; k++) add(ans, f[n][1][j][k]);
    return ans;
}

int main() {
    // 下面 2 句话是为了让 cin 更快，不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    LL L, R;
    cin >> L >> R;
    LL a = cal(R + 1), b = cal(L);
    cout << (a - b + MOD) % MOD << '\n';
    return 0;
}

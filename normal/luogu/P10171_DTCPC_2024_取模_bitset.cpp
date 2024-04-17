#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

/**
 * luogu_P10171: https://www.luogu.com.cn/problem/P10171
 * 题意: 给一个数组 a, 和一个范围 [l, r], 问 [l, r] 中有多少个数 k, 满足 a_i % k 互不相同
 * 
 * 样例:
 * [l, r] = [1, 3], a = [11, 7, 6]
 * 在 [1, 3] 中只要 3 满足条件, 11 % 3 = 2, 7 % 3 = 1, 6 % 3 = 0
 * 1 <= a.size() <= 5 * 10^4
 * 0 < a_i <= 4 * 10^5
 * 1 <= l <= r <= 10^9
 *
 * 答案: 可以先求有多少 k 使得 a_i % k 中有相同, 其实就是 (a_i - a_j) % k == 0
 * 所有可以先求出 a_i - a_j 的所有可能值, 再求这些值的约数
 * 求 a_i - a_j 的所有可能值可以用 ntt
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, l, r, maxi = 0;
    cin >> n >> l >> r;
    vector<int> A(n);
    for (int i = 0; i < n; i++) cin >> A[i], maxi = max(maxi, A[i]);

    bool ok = true;
    bitset<400001> a, b;
    for (int i = 0; i < n; i++) {
        if (b[A[i]]) {
            ok = false;
            break;
        }
        b[A[i]] = 1;
    }
    if (!ok) {
        cout << 0 << '\n';
        return 0;
    }
    for (int i = 0; i < n; i++) a |= (b >> A[i]);

    vector<int> f(maxi + 1, 0);
    for (int i = 1; i <= maxi; i++) {
        if (a[i] > 0) f[i] = 1;
    }
    f[1] = 1;
    for (int i = 2; i <= maxi; i++) if (!f[i]) {
        for (int j = i; j <= maxi; j += i) if (f[j]) {
            f[i] = 1;
            break;
        }
    }
    int ans = r - l + 1;
    for (int x = l; x <= min(maxi, r); x++) ans -= f[x];
    cout << ans << '\n';
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

/*------------------------------------------- 欧拉筛计算约数个数, 约数和 begin --------------------------*/
// 欧拉筛, 线性筛
// 筛法: https://oiwiki.org/math/number-theory/sieve/
// 欧拉筛: https://www.bilibili.com/video/BV1H8411E7hn/?share_source=copy_web&vd_source=037e882c0cdcb03fb30079bba610dae3
// 约数和: https://zhuanlan.zhihu.com/p/588074333
struct Euler {
    int n, m;
    vector<int> mp, p;           // 欧拉筛相关
    vector<int> c, d, num, sum;  // 约数个数, 约数和相关
    vector<int> phi;             // phi[i] 表示小于 i 且和 i 互质的数的个数

    // 假设 i = p1^a1 * p2^a2, (p1 < p2)
    // num[i] = (a1 + 1) * (a2 + 1)
    // sum[i] = (p1^0 + p1^1 + ... + p1^a1) * (p2^0 + p2^1 + ... + p2^a2)
    // c[i] = a1
    // d[i] = p2^a2 的约数和
    Euler(int n_) {
        n = n_;
        mp.assign(n + 1, 0);   // mp[i] 表示 i 的最小质因子
        p.clear();             // 存储质数

        // 约数个数, num[12] = 4, [1, 2, 3, 4, 6, 12]
        num.assign(n + 1, 0);

        // 约数和, sum[12] = 1 + 2 + 3 + 4 + 6 + 12 = 28
        sum.assign(n + 1, 0);  

        // c[i] 表示 i 的最小质因子的指数, c[12] = 2, 12 = 2^2 * 3
        // 12 = 2^2 * 3, 12 的最小质因子是 2, 2 的指数是 2, 所以 c[12] = 2
        c.assign(n + 1, 0);

        // d[i] 表示 i 除掉所有的最小质因子后的约数和, 
        // 12 = 2^2 * 3, 12 的最小质因子是 2, 把 2 全部除掉后是 3, 所以 d[12] = sum[3] = 4
        d.assign(n + 1, 0);

        // phi[i] 表示小于 i 且和 i 互质的数的个数
        // 10 以内和 10 互质的数有 [1, 3, 7, 9], 所以 phi[10] = 4
        phi.assign(n + 1, 0);

        num[1] = 1, sum[1] = 1;
        for (int i = 2; i <= n; i++) {
            if (!mp[i]) {
                p.push_back(i), m++;
                mp[i] = i;       // 质数的最小质因子是自己
                c[i] = 1;        // 质数的最小质因子的质数是 1
                d[i] = 1;        // 质数的最小质因子就是自己, 除掉自己后是 1
                num[i] = 2;      // 质数只有 2 个约数
                sum[i] = i + 1;  // 质数的约数和是 i + 1
                phi[i] = i - 1;  // 1 到 i - 1 都和 i 互质
            }
            for (int j = 0; j < (int) p.size() && i * p[j] <= n; j++) {
                int k = p[j];
                mp[i * k] = k;
                if (i % p[j] == 0) {
                    // i 里面有 p[j] 的情况
                    c[i * k] = c[i] + 1;
                    num[i * k] = num[i] / (c[i] + 1) * (c[i * k] + 1);
                    d[i * k] = d[i];
                    sum[i * k] = sum[i] * k + d[i];
                    phi[i * k] = phi[i] * k;
                    break;
                } else {
                    // i 里面没有 p[j] 的情况
                    c[i * k] = 1;
                    num[i * k] = num[i] * 2;
                    d[i * k] = sum[i];
                    sum[i * k] = sum[i] * (k + 1);
                    phi[i * k] = phi[i] * (k - 1);
                }
            }
        }
    }
};
/*------------------------------------------- 欧拉筛计算约数个数, 约数和 end ----------------------------*/

int main() {
    // 这两句用来加速 cin 和 cout, 比赛时一定要写!!! 
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    // 线性筛法求 10^6 以内的所有质数, 所有数的约数个数, 约数和, 欧拉函数
    Euler ans(1000000);

    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        cout << ans.num[n] << ' ' << ans.sum[n] << ' ' << ans.phi[n] << '\n';
    }
    return 0;
}
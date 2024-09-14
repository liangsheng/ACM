#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

/*------------------------------------------- 欧拉筛计算约数个数, 约数和 begin --------------------------*/
// 欧拉筛, 线性筛
// oiwiki: https://oiwiki.org/math/number-theory/sieve/
// 欧拉筛: https://www.bilibili.com/video/BV1H8411E7hn/?share_source=copy_web&vd_source=037e882c0cdcb03fb30079bba610dae3
// 约数和: https://zhuanlan.zhihu.com/p/588074333
// 洛谷题单: https://www.luogu.com.cn/training/579340#information
struct EulerSieveFactor {
    int n, m;
    vector<int> mp, p;           // 欧拉筛相关
    vector<int> c, d, num, sum;  // 约数个数, 约数和相关
    // vector<int> phi, mu;         // 欧拉函数, 莫比乌斯函数

    // 假设 i = p1^a1 * p2^a2, (p1 < p2)
    // num[i] = (a1 + 1) * (a2 + 1)
    // sum[i] = (p1^0 + p1^1 + ... + p1^a1) * (p2^0 + p2^1 + ... + p2^a2)
    // c[i] = a1
    // d[i] = p2^a2 的约数和
    EulerSieveFactor(int n_) {
        n = n_;
        mp.assign(n + 1, 0);   // mp[i] 表示 i 的最小质因子
        m = 0, p.clear();      // 存储质数
        num.assign(n + 1, 0);  // 约数个数, num[12] = 4, [1, 2, 3, 4, 6, 12]
        sum.assign(n + 1, 0);  // 约数和, sum[12] = 1 + 2 + 3 + 4 + 6 + 12 = 28
        c.assign(n + 1, 0);    // i 的最小质因子的指数, c[12] = 2, 12 = 2^2 * 3
        d.assign(n + 1, 0);    // i 删除所有的最小质因子后的约数和, d[12] = sum[3] = 4

        num[1] = 1, sum[1] = 1;
        for (int i = 2; i <= n; i++) {
            if (!mp[i]) {
                p.push_back(i), m++;
                mp[i] = i;       // 质数的最小质因子是自己
                c[i] = 1;        // 质数的最小质因子的质数是 1
                num[i] = 2;      // 质数只有 2 个约数
                sum[i] = i + 1;  // 质数的约数和是 i + 1
            }
            for (int j = 0; j < m && i * p[j] <= n; j++) {
                int k = p[j];
                mp[i * k] = k;
                if (i % p[j] == 0) {
                    c[i * k] = c[i] + 1;
                    num[i * k] = num[i] / (c[i] + 1) * (c[i * k] + 1);
                    d[i * k] = d[i];
                    sum[i * k] = sum[i] * k + d[i];
                    break;
                } else {
                    c[i * k] = 1;
                    num[i * k] = num[i] * 2;
                    d[i * k] = sum[i];
                    sum[i * k] = sum[i] * (k + 1);
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

    EulerSieveFactor ans(12);
    cout << ans.num[12] << ' ' << ans.sum[12] << '\n';
    return 0;
}
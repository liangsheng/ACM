#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

/*------------------------------------------- 埃氏筛 begin ----------------------------------------------*/
// oiwiki: https://oiwiki.org/math/number-theory/sieve/

// 返回不少过 n 以内的质数, 时间复杂度 O(n * loglog(n))
vector<int> eratosthenes(int n) {
    // is_p[i] = true, 表示 i 是质数
    vector<bool> is_p(n + 1, true);

    // 只需要筛到 sqrt(n) 就行, 因为某个数是合数, 就必然会有小于等于 sqrt(n) 的因数
    for(int i = 2; i * i <= n; i++) if (is_p[i]) {

        // 比 i * i 小的数都被筛过了
        for (int j = i * i; j <= n; j += i) is_p[j] = false;
    }

    // 将 is_p[i] 是 true 的返回
    vector<int> p;
    for (int i = 2; i <= n; i++) if (is_p[i]) p.push_back(i);
    return p;
}

/*------------------------------------------- 埃氏筛 end -------------------------------------------------*/

/*------------------------------------------- 欧拉筛 begin ----------------------------------------------*/
// oiwiki: https://oiwiki.org/math/number-theory/sieve/

// 返回不少过 n 以内的质数, 时间复杂度 O(n)
// 在 n = 10^7 时更快
vector<int> euler(int n) {
    // is_p[i] = true, 表示 i 是质数
    vector<bool> is_p(n + 1, true);
    vector<int> p;

    for (int i = 2; i <= n; i++) {
        if (is_p[i]) p.push_back(i);
        for (int j = 0; j < (int) p.size() && i * p[j] <= n; j++) {
            is_p[i * p[j]] = false;

            // 说明 p[j] 是 i 的约数
            // 没有必要再往后枚举比 p[j] 大的质数了, 保证每个合数都被最小的质因子筛掉
            if (i % p[j] == 0) break;
        }
    }
    return p;
}

/*------------------------------------------- 欧拉筛 end -------------------------------------------------*/

int main() {
    // 这两句用来加速 cin 和 cout, 比赛时一定要写!!! 
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, q, k;
    cin >> n >> q;

    // 3.55s
    // vector<int> p = eratosthenes(n);
    // while (q--) {
    //     cin >> k;
    //     cout << p[k - 1] << '\n';
    // }

    // 3.71s
    vector<int> p = euler(n);
    while (q--) {
        cin >> k;
        cout << p[k - 1] << '\n';
    }
    return 0;
}
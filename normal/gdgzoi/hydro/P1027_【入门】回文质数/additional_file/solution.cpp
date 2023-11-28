#include <bits/stdc++.h>
using namespace std;

const int N = 100005, MAX = 1000000000;

int e;     // 所有回文数的个数
int p[N];  // 用来存储所有的回文数
bool f[N];  // 判断是否是质数

bool is_prim(int x) {
    // 只需要判断到 sqrt(x) 就行了
    for (int i = 2; i * i <= x; i++) {
        // 找到 x 的一个约数 i, 那么 x 就不是素数
        if (x % i == 0) {
            // 找到一个约数, 就可以提前返回了
            return false;
        }
    }
    return true;
}

// 获取一个数的翻转
// 比如: get_inv(123) 返回 321
int get_inv(int x) {
    int ans = 0;
    while (x != 0) {
        ans = ans * 10 + x % 10;
        x /= 10;
    }
    return ans;
}

// 产生所有的回文数(奇数)
void gen_palindromes() {
    // // 1 位回文数
    // for (int i = 0; i < 10; i++) {
    //     // 只需要奇数, 因为大于 2 的偶数不可能是质数
    //     if (i % 2) a[e++] = i;
    // }

    // // 2 位回文数
    // for (int i = 1; i <= 9; i++) {
    //     int d = i * 10 + i;
    //     if (d % 2) a[e++] = d;
    // }

    // // 3 位回文数
    // for (int i = 1; i <= 9; i++) {
    //     for (int j = 0; j <= 9; j++) {
    //         int d = i * 100 + j * 10 + i;
    //         if (d % 2) a[e++] = d;
    //     }
    // } 

    // // 4 位回文数
    // for (int i = 1; i <= 9; i++) {
    //     for (int j = 0; j <= 9; j++) {
    //         int d = i * 1000 + j * 100 + j * 10 + i;
    //         if (d % 2) a[e++] = d;
    //     }
    // } 

    // // 5 位回文数
    // for (int i = 1; i <= 9; i++) {
    //     for (int j = 0; j <= 9; j++) {
    //         for (int k = 0; k <= 9; k++) {
    //             int d = i * 10000 + j * 1000 + k * 100 + j * 10 + i;
    //             if (d % 2) a[e++] = d;
    //         }
    //     }
    // } 

    // // 6 位回文数
    // for (int i = 1; i <= 9; i++) {
    //     for (int j = 0; j <= 9; j++) {
    //         for (int k = 0; k <= 9; k++) {
    //             int d = i * 10000 + j * 1000 + k * 100 + j * 10 + i;
    //             if (d % 2) a[e++] = d;
    //         }
    //     }
    // } 

    e = 0;
    for (int i = 0; i <= 99999; i++) {
        int inv_i = get_inv(i);

        long long d = 1, k = i;
        while (k != 0) k /= 10, d *= 10;
        
        // 把 i 和 inv_i 组合起来
        long long t = i * d + inv_i;
        // 只需要奇数, 因为大于 2 的偶数不可能是质数
        if (t % 2 && t < MAX) p[e++] = t;

        // 在 i 和 inv_i 中间放 1 个数
        for (int j = 0; j < 10; j++) {
            t = i * d * 10 + j * d + inv_i;
            if (t % 2 && t < MAX) p[e++] = t;
        }
    }
    sort(p, p + e);

    // 判断数组 p 里面的数是否是质数
    for (int i = 0; i < e; i++) {
        f[i] = is_prim(p[i]);
    }
}

int main() {
    gen_palindromes();

    int a, b;
    cin >> a >> b;
    for (int i = 0; i < e; i++) {
        if (p[i] >= a && p[i] <= b && f[i]) cout << p[i] << '\n';
    }
    return 0;
}
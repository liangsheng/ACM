#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

/********************** 快读快写 begin ***************************/
inline int read() { 
    char c = getchar(); int x = 0, f = 1;
    while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
    while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}

inline void write(int x) {
	 if (x == 0) {
        putchar('0'); 
        return;
     }
     if (x < 0) putchar('-'), x =- x;
     if (x > 9) write(x / 10);
     putchar(x % 10 + '0');
}
/********************** 快读快写 end ***************************/

/********************** ntt begin ***************************/

// 998244353 的一个原根为 3 且 998244353 - 1 = 2 ^ 23 * 119
// 3 在模 998244353 意义下的逆元为 332748118
const int P = 998244353, g = 3, gi = 332748118;

// r 存储交换的位置, w 存储提前计算的原根
vector<int> r, w;

int power(int x, int y) {
    int res = 1;
    while (y) {
        if (y & 1) res = (LL) res * x % P;
        x = (LL) x * x % P; y >>= 1;
    } 
    return res;
}

int init(int N) {
    int n = 1, lg = 0;
    while (n < N) n *= 2, lg++;
    r = vector<int>(n, 0);
    for (int i = 0; i < n; i++) {
        r[i] = (r[i >> 1] >> 1) | ((i & 1) << (lg - 1));
    }

    // n 次原根 v = g ^ ((p - 1) / n)
    int v = power(g, (P >> lg));
    w = vector<int>(n, 0);
    w[n >> 1] = 1;
    for (int i = (n >> 1) + 1; i < n; i++) w[i]= (LL) w[i - 1] * v % P;
    for (int i = (n >> 1) - 1; i >= 1; i--) w[i] = w[i << 1];
    return n;
}

/**
 *  flag = 1  是 DFT
 *  flag = -1 是 IDFT
 */
void ntt(int *a, int n, int flag) {
    for (int i = 0; i < n; i++)  {
        if (r[i] < i) swap(a[i], a[r[i]]);
    }
    for (int i = 1; i < n; i <<= 1) {
        for (int j = 0; j < n; j += (i << 1)) {
            for (int k = 0; k < i; k++) {
                int x = a[j + k], y = (LL) w[i + k] * a[i + j + k] % P;
                a[j + k] = (x + y) % P;
                a[i + j + k] = (x - y + P) % P;
            }
        }
    }
    if (flag == -1) {
        reverse(a + 1, a + n);
        int v = P - (P - 1) / n;
        for (int i = 0; i < n; i++) a[i] = (LL) a[i] * v % P;
    }
}

/********************** ntt end *****************************/

/**
 * 题意：输入两个正整数, 输出两个数的积, 整数位数在 100 左右
 * Sample Input:
 * 36
 * 3
 * Sample Output:
 * 108
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t;
    cin >> s >> t;

    int n = s.size(), m = t.size();
    

    // 初始化 fft
    // 比如多项式的乘积是 p(x) = p0 + p1x + p2x^2 + p3x^3 + p4^4
    // p(x) 需要 5 个点来确定
    // 这里传入 5, 返回 8
    int len = init(n + m - 1);

    // 注意: 输入的多项式一定要是从低位到高位
    vector<int> a(len, 0), b(len, 0);
    for (int i = 0; i < n; i++) a[n - 1 - i] = s[i] - '0'; 
    for (int i = 0; i < m; i++) b[m - 1 - i] = t[i] - '0';

    // a.data() 返回一个指向内存数组的直接指针
    ntt(a.data(), len, 1);
    ntt(b.data(), len, 1);

    // 点值相乘
    for (int i = 0; i < len; i++) a[i] = (LL) a[i] * b[i] % P;

    // 点值转系数
    ntt(a.data(), len, -1);

    int d = 0;
    vector<int> ans;
    for (int i = 0; i < n + m - 1; i++) {
        ans.push_back((a[i] + d) % 10);
        d = (a[i] + d) / 10;
    }
    while (d != 0) ans.push_back(d % 10), d /= 10;

    int p = -1;
    for (int i = ans.size() - 1; i >= 0; i--) if (ans[i] != 0) {
        p = i;
        break;
    }
    if (p == -1) cout << 0 << '\n';
    else {
        for (int i = p; i > 0; i--) cout << ans[i];
        cout << ans[0] << '\n';
    }
    return 0;
}

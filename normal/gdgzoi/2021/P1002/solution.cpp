#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
 
/********************** fft begin ***************************/
 
const double PI = acos(-1.0);
 
struct Complex {
    double x, y;
 
    Complex(double _x = 0.0, double _y = 0.0) {
        x = _x;
        y = _y;
    }
 
    Complex operator-(const Complex &b) const {
        return Complex(x - b.x, y - b.y);
    }
 
    Complex operator+(const Complex &b) const {
        return Complex(x + b.x, y + b.y);
    }
 
    Complex operator*(const Complex &b) const {
        return Complex(x * b.x - y * b.y, x * b.y + y * b.x);
    }
};
 
// r 存储交换的位置, w 存储体检计算的单位复根
vector<int> r;
vector<Complex> w;
 
int power(int x, int y, int P) {
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
 
    w = vector<Complex>(n);
    w[n >> 1] = Complex(1, 0);
    Complex v(cos(2 * PI / n), sin(2 * PI / n));
    for (int i = (n >> 1) + 1; i < n; i++) w[i] = w[i - 1] * v;
    for (int i = (n >> 1) - 1; i >= 1; i--) w[i] = w[i << 1]; 
    return n;
}
 
/**
 *  flag = 1  是 DFT
 *  flag = -1 是 IDFT
 */
void fft(Complex *a, int n, int flag) {
    for (int i = 0; i < n; i++)  {
        if (r[i] < i) swap(a[i], a[r[i]]);
    }
    for (int i = 1; i < n; i <<= 1) {
        for (int j = 0; j < n; j += (i << 1)) {
            for (int k = 0; k < i; k++) {
                Complex x = a[j + k], y = w[i + k] * a[i + j + k];
                a[j + k] = x + y;
                a[i + j + k] = x - y;
            }
        }
    }
    if (flag == -1) {
        reverse(a + 1, a + n);
        for (int i = 0; i < n; i++) a[i].x /= n;
    }
}
 
/********************** fft end *****************************/
 
/********************** 计算质数 p 的原根 begin **************/
/**
 * 计算素数 p 的原根
 * 原根往往不大（一般不会超过 300）, 可以枚举判断, 判断过程
 * 1、对于枚举的 g, 枚举 p - 1 的所有质因子 p_i
 * 2、如果所有的 p_i, g ^ ((p - 1) / p_i) = 1(mod p) 都不成立
 * 3、那么 g 就是原根
 */
int gao(int p) {
    if (p == 2) return 2;
    int x = p - 1;
 
    // 1、首先计算出 p 的所有质因子 p_i
    vector<int> pi;
    for (int i = 2; i * i <= x; i++) if (x % i == 0) {
        pi.push_back(i);
        while (x % i == 0) x /= i;
    }
    if (x != 1) pi.push_back(x);
 
    // 2、枚举 g
    // 如果所有的 p_i, g ^ ((p - 1) / p_i) = 1(mod p) 都不成立, 则 g 是元根
    for (int g = 2; g < p; g++) {
        bool f = true;
        for (int p_i : pi) if (power(g, (p - 1) / p_i, p) == 1) {
            f = false;
            break;
        }
        if (f) return g;
    }
    return -1;
}
/********************** 计算质数 p 的原根 end ****************/
 
/**
 * 题意: 求 n 个整数, 两两之间的乘积, 模质数 m 的余数为 k (0 <= k < m) 的有多少个
 * 输入: 第一行为数据组数, 每组数据第一行 n, m, 接下来一行 n 个数(n <= 3*10^5, m 是质数)
 * Sample Input
 * 2
 * 4 5
 * 2 0 1 7
 * 4 2
 * 2 0 1 6
 * Sample Output
 * 3
 * 0
 * 2
 * 0
 * 1
 * 6
 * 0
 */
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
     
    int T, n, m, x;
    cin >> T;
    while (T--) {
        cin >> n >> m;
 
        // 将输入转换成 % m 的余数计数
        vector<int> a(m);
        for (int i = 0; i < n; i++) {
            cin >> x;
            a[x % m]++;
        }
 
        // 求 m 的原根
        // [g^0, g^1, g^2, ..., g^(m-2)] 对应 [1, 2, ..., m-1] 
        int g = gao(m);
 
        // 比如 m = 5, g = 2, 那么
        // d = [1, 2, 4, 3] 记录的是 [2^0, 2^1, 2^2, 2^3] % 5 的值
        vector<int> d(m - 1, 1);
        for (int i = 1; i <= m - 2; i++) d[i] = d[i - 1] * g % m;
 
        // b = [a[d[0]], a[d[1]], a[d[2]], a[d[3]]]
        // b = [a[1], a[2], a[4], a[3]]
        // b = [1, 2, 0, 0]
        int len = init(2 * m - 1);
        vector<Complex> b(len, Complex(0, 0));
        for (int i = 0; i < m - 1; i++) b[i].x = a[d[i]];
 
        // 对 b 做 ntt
        fft(b.data(), len, 1);
        for (int i = 0; i < len; i++) b[i] = b[i] * b[i];
        fft(b.data(), len, -1);
 
        vector<LL> ans(m, 0);
        for (int i = 0; i < len; i++) ans[d[i % (m - 1)]] += (LL) (b[i].x + 0.5);
 
        // 减去自己乘自己的情况(0 除外)
        for (int i = 1; i < m; i++) ans[(LL) i * i % m] -= a[i];
        for (int i = 1; i < m; i++) ans[i] /= 2;
 
        // 加上 0 乘 其他余数的情况
        ans[0] += (LL) a[0] * (a[0] - 1) / 2;
        for (int i = 1; i < m; i++) ans[0] += (LL) a[0] * a[i];
 
        for (int i = 0; i < m; i++) cout << ans[i] << '\n';
    }
    return 0;
}
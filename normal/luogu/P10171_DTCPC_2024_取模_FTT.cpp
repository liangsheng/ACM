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

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int n, l, r, maxi = 0;
    cin >> n >> l >> r;
    vector<int> A(n);
    for (int i = 0; i < n; i++) cin >> A[i], maxi = max(maxi, A[i]);
    
    int len = init(3 * maxi), ok = 1;
    vector<Complex> a(len, Complex(0, 0)), b(len, Complex(0, 0));
    for (int i = 0; i < n; i++) {
        if (a[maxi + A[i]].x > 0) {
            ok = 0;
            break;
        }
        a[maxi + A[i]].x = 1;
        b[maxi - A[i]].x = 1;
    }
    if (!ok) {
        cout << 0 << '\n';
        return 0;
    }

    // a.data() 返回一个指向内存数组的直接指针
    fft(a.data(), len, 1);
    fft(b.data(), len, 1);

    // 点值相乘
    for (int i = 0; i < len; i++) a[i] = a[i] * b[i];

    // 点值转系数
    fft(a.data(), len, -1);

    vector<int> f(maxi + 1, 0);
    for (int i = 1; i <= maxi; i++) {
        if ((int) (a[i + 2 * maxi].x + 0.5) > 0) f[i] = 1;
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
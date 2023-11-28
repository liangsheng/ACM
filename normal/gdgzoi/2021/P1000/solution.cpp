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

/**
 * 题意：第一行两个整数 n, m
 * 接下来一行 n + 1 个数字, 从低到高表示 f(x) 的系数
 * 接下来一行 m + 1 个数字, 从低到高表示 g(x) 的系数
 * 输出一行 n + m + 1 个数字, 从低位到高位表示 f(x) * g(x) 的系数
 * Sample Input:
 * 1 2
 * 1 2
 * 1 2 1
 * Sample Output:
 * 1 4 5 2
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, x, y;
    n = read(), m = read();

    // 初始化 fft
    // 比如多项式的乘积是 p(x) = p0 + p1x + p2x^2 + p3x^3 + p4^4
    // p(x) 需要 5 个点来确定
    // 这里传入 5, 返回 8
    int len = init(n + m + 1);

    // 注意: 输入的多项式一定要是从低位到高位
    vector<Complex> a(len, Complex(0, 0)), b(len, Complex(0, 0));
    for (int i = 0; i <= n; i++) {
        x = read();
        a[i].x = x;
    }
    for (int i = 0; i <= m; i++) {
        y = read();
        b[i].x = y;
    }

    // a.data() 返回一个指向内存数组的直接指针
    fft(a.data(), len, 1);
    fft(b.data(), len, 1);

    // 点值相乘
    for (int i = 0; i < len; i++) a[i] = a[i] * b[i];

    // 点值转系数
    fft(a.data(), len, -1);

    for (int i = 0; i < n + m; i++) printf("%d ", (int) (a[i].x + 0.5));
    printf("%d\n", (int) (a[n + m].x + 0.5));

    return 0;
}
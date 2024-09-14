#include <bits/stdc++.h>
using namespace std;

/*--------------------------------- jiangly 大整数取模 Mint begin ----------------------------------*/
// 来自: https://blog.csdn.net/qq_17175035/article/details/128720590
// 来自: https://github.com/beiyouwuyanzu/cf_code_jiangly/blob/main/497/497E-E-SubsequencesReturn.cpp

using i64 = long long;
template<class T>
constexpr T power(T a, i64 b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}

template<int P>
struct MInt {
    int x;
    constexpr MInt() : x{} {}
    constexpr MInt(i64 x) : x{norm(x % P)} {}
    
    constexpr int norm(int x) const {
        if (x < 0) {
            x += P;
        }
        if (x >= P) {
            x -= P;
        }
        return x;
    }
    constexpr int val() const {
        return x;
    }
    explicit constexpr operator int() const {
        return x;
    }
    constexpr MInt operator-() const {
        MInt res;
        res.x = norm(P - x);
        return res;
    }
    constexpr MInt inv() const {
        assert(x != 0);
        return power(*this, P - 2);
    }
    constexpr MInt &operator*=(MInt rhs) {
        x = 1LL * x * rhs.x % P;
        return *this;
    }
    constexpr MInt &operator+=(MInt rhs) {
        x = norm(x + rhs.x);
        return *this;
    }
    constexpr MInt &operator-=(MInt rhs) {
        x = norm(x - rhs.x);
        return *this;
    }
    constexpr MInt &operator/=(MInt rhs) {
        return *this *= rhs.inv();
    }
    friend constexpr MInt operator*(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res *= rhs;
        return res;
    }
    friend constexpr MInt operator+(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res += rhs;
        return res;
    }
    friend constexpr MInt operator-(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res -= rhs;
        return res;
    }
    friend constexpr MInt operator/(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res /= rhs;
        return res;
    }
    friend constexpr std::istream &operator>>(std::istream &is, MInt &a) {
        i64 v;
        is >> v;
        a = MInt(v);
        return is;
    }
    friend constexpr std::ostream &operator<<(std::ostream &os, const MInt &a) {
        return os << a.val();
    }
    friend constexpr bool operator==(MInt lhs, MInt rhs) {
        return lhs.val() == rhs.val();
    }
    friend constexpr bool operator!=(MInt lhs, MInt rhs) {
        return lhs.val() != rhs.val();
    }
};
 
template<int V, int P>
constexpr MInt<P> CInv = MInt<P>(V).inv();
 
// constexpr int P = 998244353;
constexpr int P = 1000000007;
using Z = MInt<P>;

/*--------------------------------- jiangly 大整数取模 Mint end ------------------------------------*/

/*--------------------------------- 矩阵快速幂 begin------------------------------------------------*/
// 来自: https://github.com/beiyouwuyanzu/cf_code_jiangly/blob/main/497/497E-E-SubsequencesReturn.cpp
// 来自: https://github.com/beiyouwuyanzu/cf_code_jiangly/blob/main/1743/1743F-F-IntersectionandUnion.cpp

template<typename T>
struct Matrix {
    // const 表示不变
    // static 表示静态变量, 也就是说所有 Matrix 类型的变量都公用变量 a
    // 因为申明 array 需要指定长度, 所以这里需要用 const static 
    const static int n = 2;

    // array 不支持变长, 在申明的时候要指定类型和长度
    // 这句话相当于: T a[n][n];
    array<array<T, n>, n> mat;

    Matrix(T x = 0) {
        // 初始化全为 0, 对角线为 x
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) mat[i][j] = 0;
        for (int i = 0; i < n; i++) mat[i][i] = x;
    }

    // 矩阵乘法
    Matrix operator*(const Matrix& b) {
        Matrix c(0);
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) c.mat[i][j] += mat[i][k] * b.mat[k][j];
        }
        return c;
    }

    // 矩阵快速幂
    Matrix operator^(i64 cnt) {
        Matrix ans(1), c = *this;
        while (cnt) {
            if (cnt & 1) ans = ans * c;
            c = c * c;
            cnt >>= 1;
        }
        return ans;
    }

    // friend Matrix operator*(const Matrix& a, const Matrix& b) {
    //     Matrix c;
    //     for (int i = 0; i < a.n; i++) for (int j = 0; j < a.n; j++) {
    //         for (int k = 0; k < a.n; k++) c.mat[i][j] += a.mat[i][k] * b.mat[k][j];
    //     }
    // }

    void print() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) cout << mat[i][j] << ' ';
            cout << '\n';
        }
    }
};
/*--------------------------------- 矩阵快速幂 end --------------------------------------------------*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 n;
    cin >> n;
    if (n <= 2) cout << 1 << '\n';
    else {
        Matrix<Z> a;
        a.mat[0][0] = 0, a.mat[0][1] = 1;
        a.mat[1][0] = 1, a.mat[1][1] = 1;
        Matrix<Z> ans = a ^ (n - 2);
        Z res = ans.mat[0][1] + ans.mat[1][1];
        cout << res.val() << '\n';
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

/*--------------------------------- 矩阵快速幂 begin------------------------------------------------*/
// 来自: https://github.com/beiyouwuyanzu/cf_code_jiangly/blob/main/497/497E-E-SubsequencesReturn.cpp
// 来自: https://github.com/beiyouwuyanzu/cf_code_jiangly/blob/main/1743/1743F-F-IntersectionandUnion.cpp

using i64 = long long;
const int P = 1000000007;

template<typename T, int P>
struct Matrix {
    int n;
    vector<vector<T>> mat;

    Matrix(int n_, T x = 0): n(n_) {
        // 初始化全为 0, 对角线为 x
        mat.assign(n, vector<T>(n, 0));
        for (int i = 0; i < n; i++) mat[i][i] = x;
    }

    // 矩阵乘法
    Matrix operator*(const Matrix& b) {
        Matrix c(n, 0);
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) for (int k = 0; k < n; k++) {
            c.mat[i][j] = (c.mat[i][j] + (i64) mat[i][k] * b.mat[k][j] % P) % P;
        }
        return c;
    }

    // 矩阵快速幂
    Matrix operator^(i64 cnt) {
        Matrix ans(n, 1), c = *this;
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
using M = Matrix<int, P>;
/*--------------------------------- 矩阵快速幂 end --------------------------------------------------*/

/*--------------------------------- 快速幂 begin ----------------------------------------------------*/
template<typename T>
T power(T x, T y, T P = 1000000007) {
    T ans = 1;
    while (y) {
        if (y & 1) ans = (i64) ans * x % P;
        x = (i64) x * x % P;
        y >>= 1;
    }
    return ans;
}

/*--------------------------------- 快速幂 end ------------------------------------------------------*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 n, f1, f2, f3, c;
    cin >> n >> f1 >> f2 >> f3 >> c;

    // [f1, f2, f3] * a = [f2, f3, f4]
    // 次方取模, 指数要 % (P - 1), 不是 % P
    // power(x, y) % p = power(x, y % (p - 1)) % p
    // 因为 power(x, p - 1) % p == 1
    Matrix<i64, P - 1> a(3, 0);
    a.mat = {
        {0, 0, 1},
        {1, 0, 1},
        {0, 1, 1},
    };
    a = a ^ (n - 3);

    // 计算 f1, f2, f3 的指数
    i64 fn1 = power(f1, a.mat[0][2]);
    i64 fn2 = power(f2, a.mat[1][2]);
    i64 fn3 = power(f3, a.mat[2][2]);
    i64 ans = fn1 * fn2 % P * fn3 % P;
    // cout << "fn1= " << a.mat[0][2] << ", fn2= " << a.mat[1][2] << ", fn3= " << a.mat[2][2] << '\n';

    // 计算 c 的指数
    // f4c = f1c + f2c + f3c + 2
    // f5c = f2c + f3c + f4c + 4
    // [f1c, f2c, f3c, 2, 2] * b = [f2c, f3c, f4c, 4, 2]
    // [0, 0, 0, 2, 2] * b = [0, 0, 2, 4, 2]
    Matrix<i64, P - 1> b(5, 0);
    b.mat = {
        {0, 0, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {0, 1, 1, 0, 0},
        {0, 0, 1, 1, 0},
        {0, 0, 0, 1, 1},
    };
    b = b ^ (n - 3);
    i64 cnt = (2 * b.mat[3][2] + 2 * b.mat[4][2]) % (P - 1);
    i64 res = power(c, cnt);
    // cout << "cnt= " << cnt << '\n';
    cout << ans * res % P << '\n';

    return 0;
}
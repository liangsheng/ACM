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

    int n, b, k, x;
    cin >> n >> b >> k >> x;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) cin >> a[i];

    M c(x, 0);
    for (int i = 0; i < x; i++) for (int j = 0; j < n; j++) {
        int d = (10 * i + a[j]) % x;
        c.mat[i][d]++;
    }
    c = c ^ b;
    cout << c.mat[0][k] << '\n';

    return 0;
}
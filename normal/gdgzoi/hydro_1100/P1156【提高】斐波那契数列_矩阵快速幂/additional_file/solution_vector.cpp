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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 n;
    cin >> n;
    if (n <= 2) cout << 1 << '\n';
    else {
        M a(2, 0);
        a.mat = {
            {0, 1},
            {1, 1}
        };
        a = a ^ (n - 2);
        int res = (a.mat[0][1] + a.mat[1][1]) % P;
        cout << res << '\n';
    }
    return 0;
}
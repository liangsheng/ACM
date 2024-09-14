#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

/*--------------------------------- 矩阵快速幂 begin------------------------------------------------*/
// 来自: https://www.luogu.com.cn/article/87ooh5ay

using i64 = long long;
const int P = 1000000007;

template<typename T>
struct Matrix {
    int n;
    vector<vector<T>> mat;

    // n_ 是矩阵大小, x 是对角线初值
    Matrix(int n_, T x) {
        n = n_;
        mat.assign(n, vector<T>(n, 0));
        for (int i = 0; i < n; i++) mat[i][i] = x;
    }

    Matrix operator*(const Matrix& b) {
        Matrix ans(n, 0);
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) for (int k = 0; k < n; k++) {
            ans.mat[i][j] = (ans.mat[i][j] + (i64) mat[i][k] * b.mat[k][j]) % P;
        }
        return ans;
    }
};

// n >= 1
template<typename T>
T power(T x, i64 n) {
    T ans = x; n -= 1;
    for (; n > 0; n >>= 1, x = x * x) if (n & 1) ans = ans * x;
    return ans;
}
/*--------------------------------- 矩阵快速幂 end --------------------------------------------------*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 n;
    cin >> n;
    if (n <= 2) cout << 1 << '\n';
    else {
        // f1 = 1, f2 = 2
        // fn = 2f(n-2) + 3f(n-1) + 4n
        // [f2, f3, 16, 4] = [f1, f2, 12, 4] * a
        Matrix<int> a(4, 0);
        a.mat = {
            {0, 2, 0, 0},
            {1, 3, 0, 0},
            {0, 1, 1, 0},
            {0, 0, 1, 1}
        };
        a = power(a, n - 2);
        // [fn-1, fn, 4*(n+1), 4] = [f1, f2, 12, 4] * a
        // cout << a.mat[1][0] << ", " << a.mat[1][1] << ", " << a.mat[2][1] << '\n';
        i64 fn = ((i64) a.mat[0][1] + a.mat[1][1] + (i64) 12 * a.mat[2][1] + (i64) 4 * a.mat[3][1]) % P;
        cout << fn << '\n';
    }
    return 0;
}
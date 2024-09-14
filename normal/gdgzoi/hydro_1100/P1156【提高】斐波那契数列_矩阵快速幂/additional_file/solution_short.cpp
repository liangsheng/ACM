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
        // [f2, f3] = [f1, f2] * a
        Matrix<int> a(2, 0);
        a.mat = {
            {0, 1},
            {1, 1}
        };
        a = power(a, n - 2);
        // [fn-1, fn] = [1, 1] * a
        i64 fn = (a.mat[0][1] + a.mat[1][1]) % P;
        cout << fn << '\n';
    }
    return 0;
}
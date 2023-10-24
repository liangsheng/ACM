#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MOD = 998244353;

int n, m;
//vector<vector<int> > a; 
//vector<int> s;
//vector<vector<vector<int> > > f;
//vector<vector<int> > g;
int a[105][2005], s[105], f[105][2005][205], g[105][105];

void add(int &x, int y) {
    x = ((LL) x + y) % MOD;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	while (cin >> n >> m) {
//        a = vector<vector<int> >(n + 1, vector<int>(m + 1, 0));
		for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> a[i][j];

//        s = vector<int>(n + 1, 0);
        memset(s, 0, sizeof(s));
        for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
            s[i] = ((LL) s[i] + a[i][j]) % MOD;
        }

//        g = vector<vector<int> >(n + 1, vector<int>(n + 1, 0));
        memset(g, 0, sizeof(g));
        g[0][0] = 1;
        for (int i = 1; i <= n; i++) for (int j = 0; j <= n; j++) {
            g[i][j] = g[i - 1][j];
			if (j > 0) add(g[i][j], (LL) g[i - 1][j - 1] * s[i] % MOD);
        }
        int tol = 0;
        for (int i = 1; i <= n; i++) tol = ((LL) tol + g[n][i]) % MOD;

//        f = vector<vector<vector<vector<int> > > >(n + 1, vector<vector<vector<int> > >(m + 1, vector<vector<int> >(n + 1, vector<int>(n + 1, 0))));
//		for (int j = 1; j <= m; j++) f[0][j][0][0] = 1;
//        for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
//            for (int k = 0; k <= i; k++) for (int h = 0; h <= i; h++) {
//                f[i][j][k][h] = f[i - 1][j][k][h];
//                if (k > 0) add(f[i][j][k][h], (LL) a[i][j] * f[i - 1][j][k - 1][h] % MOD);
//                if (h > 0) add(f[i][j][k][h], (LL) (s[i] - a[i][j]) * f[i - 1][j][k][h - 1] % MOD);
////                if (i == 2 && j == 1 && k == 1 && h == 1) cout << f[i][j][k][h] << ' ' << f[i - 1][j][k - 1][h] << ' ' << f[i - 1][j][k][h - 1] << '\n';
////                if (i == 3 && j == 1 && k == 2 && h == 1) cout << f[i - 1][j][k - 1][h] << ' ' << f[i - 1][j][k][h - 1] << '\n';
////                if (f[i][j][k][h] != 0) {
////                    cout << "i= " << i << ' ' << j << ' ' << k << ' ' << h << ' ' << f[i][j][k][h] << '\n';
////                }
//            }
//        }

//		f = vector<vector<vector<int> > >(n + 1, vector<vector<int> >(m + 1, vector<int>(2 * n + 1, 0)));
		memset(f, 0, sizeof(f));
		for (int j = 1; j <= m; j++) f[0][j][0 + n] = 1;
		for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) for (int k = -i + n; k <= i + n; k++) {
			f[i][j][k] = f[i - 1][j][k];
			if (k - 1 >= 0) add(f[i][j][k], (LL) a[i][j] * f[i - 1][j][k - 1] % MOD);
			if (k + 1 <= 2 * n) add(f[i][j][k], (LL) (s[i] - a[i][j]) * f[i - 1][j][k + 1] % MOD);
//            if (f[i][j][k] != 0) {
//                cout << "i= " << i << ' ' << j << ' ' << k - n << ' ' << f[i][j][k] << '\n';
//            }
		}

        int tmp = 0;
        for (int j = 1; j <= m; j++) for (int k = 1 + n; k <= n + n; k++) add(tmp, f[n][j][k]);
//        cout << "tol= " << tol << ", tmp= " << tmp << '\n';
        int ans = (((LL) tol - tmp) % MOD + MOD) % MOD;
        cout << ans << '\n';
    }	
	return 0;
} 

//4 2
//1 1
//1 0
//1 1
//1 1
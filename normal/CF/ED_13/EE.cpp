#include <bits/stdc++.h>

#define sc(x) cout << #x" = " << x << endl, system("pause")
#define sc2(x, y) cout << #x" = " << x << " " << #y" = " << y << endl, system("pause")
#define sc3(x, y, z) cout << #x" = " << x << " " << #y" = " << y << " " << #z" = " << z << endl, system("pause")
#define sc4(x, y, z, w) cout << #x" = " << x << " " << #y" = " << y << " " << #z" = " << z << " " << #w" = " << w << endl, system("pause")


using namespace std;
typedef long long LL;
const int N = 18;
int n;
int cnt[1 << N];
double p[N][N];
double f[N][1 << N];

int main() {
    cin >> n;
    for (int i = 0 ; i < n; ++ i) {
        for (int j = 0 ; j < n ; ++ j) {
            cin >> p[i][j];
        }
    }
    for (int i = 1 ; i < 1 << n ; ++ i) {
        cnt[i] = cnt[i & (i - 1)] + 1;
    }

    //f[i][j]表示ivan想在i状态中且j第一个出站时能取得最的大胜率
    f[0][1] = 1;
    for (int i = 1 ; i < 1 << n ; ++ i) {
        if (cnt[i] < 2) continue;
        for (int j = 0 ; j < n ; ++ j) {

            if (!(i >> j & 1)) continue;

            for (int k = 0 ; k < n ; ++ k) {

                if (j != k && (i >> k & 1)) {
                    f[j][i] = max(f[j][i] , p[j][k] * f[j][i ^ (1 << k)] + p[k][j] * f[k][i ^ (1 << j)]);
                }
            }
            sc3(i, j, f[j][i]);
        }
        //f[i] /= cnt;
    }
    double res = 0;
    for (int i = 0 ; i < n ; ++ i) {
        res = max(res , f[i][(1 << n) - 1]);
    }
    printf("%.12f\n" , res);
}

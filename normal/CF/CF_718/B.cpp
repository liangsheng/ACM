#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 105;

int T, n, m;
int b[N][N], a[N][N];
int L[N], R[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) cin >> b[i][j];
            sort(b[i] + 1, b[i] + m + 1);
        }
        for (int i = 1; i <= n; i++) L[i] = 1, R[i] = m;
        for (int j = 1; j <= m; j++) {
            int p = -1;
            for (int i = 1; i <= n; i++) {
                if (p == -1 || b[i][L[i]] < b[p][L[p]]) p = i;
            }
            a[p][j] = b[p][L[p]];
            for (int i = 1; i <= n; i++) {
                if (i == p) L[p]++;
                else a[i][j] = b[i][R[i]], R[i]--;
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < m; j++) cout << a[i][j] << ' ';
            cout << a[i][m] << '\n';
        }
    }
    return 0;
}
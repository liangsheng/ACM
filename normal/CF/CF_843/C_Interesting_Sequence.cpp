#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int D = 61;

LL T, n, x;

void gao() {
    vector<int> a(D, 0), b(D, 0);
    for (int i = 0; i < D; i++) {
        a[D - 1 - i] = n >> i & 1;
        b[D - 1 - i] = x >> i & 1;
    }
    int p = 0;
    for (int i = 0; i < D; i++) {
        if (a[i] == 0 && b[i] == 1) {
            cout << "-1" << '\n';
            return ;
        }
        if (a[i] == 1 && b[i] == 0) {
            p = i;
            break;
        }
    }
    // cout << "n= " << n << ", x= " << x << ", p= " << p << '\n';
    for (int i = p + 1; i < D; i++) if (b[i] == 1) {
        cout << "-1" << '\n';
        return ;
    }
    if (a[p - 1] == 1) {
        cout << "-1" << '\n';
        return ;
    }
    a[p - 1] = 1;
    for (int j = p; j < D; j++) a[j] = 0;
    LL ans = 0;
    for (int i = 0; i < D; i++) ans = ans * 2 + a[i];
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> n >> x;
        if (n < x) cout << "-1" << '\n';
        else if (n == x) cout << n << '\n';
        else gao();
    }
    return 0;
}
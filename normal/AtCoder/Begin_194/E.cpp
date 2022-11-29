#include <bits/stdc++.h>
using namespace std;

const int N = 1500005;

int n, m;
int a[N];
int f[N];

int gao() {
    int ans ;
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= m; i++) f[a[i]]++;
    for (int i = 0; i <= n; i++) if (f[i] == 0) {
        ans = i;
        break;
    }
    for (int i = 2; i + m - 1 <= n; i++) {
        f[a[i - 1]]--, f[a[i + m - 1]]++;
        if (f[a[i - 1]] == 0 && a[i - 1] < ans) ans = a[i - 1];
    }
    return ans;
}

int main() {
    while (cin >> n >> m) {
        for (int i = 1; i <= n; i++) cin >> a[i];
        cout << gao() << '\n';
    }
    return 0;
}
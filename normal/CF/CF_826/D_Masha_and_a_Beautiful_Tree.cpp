#include <bits/stdc++.h>
using namespace std;

const int N = 262144, D = 18;

int T, n;
int a[N + 5];

int gao() {
    if (n == 1) return 0;
    int ans = 0;
    for (int i = 1; i <= n; i += 2) {
        if (a[i] > a[i + 1]) ans++, swap(a[i], a[i + 1]);
        if (!(a[i] % 2 == 1 && a[i] + 1 == a[i + 1])) return -1;
        a[(i + 1) / 2] = a[i + 1] / 2;
    }
    n = n / 2;
    int tmp = gao();
    if (tmp == -1) return -1; 
    return ans + tmp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        cout << gao() << '\n';
    }
    return 0;
}
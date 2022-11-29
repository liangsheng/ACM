#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int T, n, d;
int a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> n >> d;
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n);
        if (a[n - 1] <= d || (a[0] + a[1] <= d)) puts("YES");
        else puts("NO");
    }
    return 0;
}
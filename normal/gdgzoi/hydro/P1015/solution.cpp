#include <bits/stdc++.h>
using namespace std;

int a[1000001];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    int ans = a[0], cnt = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] == ans) cnt++;
        else if (--cnt < 0) ans = a[i], cnt = 1;
    }
    cout << ans << '\n';
    return 0;
}
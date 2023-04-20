#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N = 5000000;
    vector<bool> f(N + 1, 0);
    vector<int> p;
    for (int i = 2; i <= N; i++) {
        if (f[i]) continue;
        p.push_back(i);
        for (long long j = (long long) i * i; j <= N; j += i) f[j] = 1;
    }
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        if (f[a[0]]) cout << "Farmer Nhoj" << '\n';
        else cout << "Farmer John" << '\n';
    }
    return 0;
}
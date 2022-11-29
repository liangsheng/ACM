#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 200005, MOD = 1000000007;

int T, n;
int a[N];
map<int, int> q;

int gao() {
    int mini = q.begin()->first, m = q.begin()->second;
    if (m < 2) return 0;
    for (int i = 0; i < n; i++) {
        if ((a[i] & mini) != mini) return 0;
    }

    int ans = (LL) m * (m - 1) % MOD;
    for (int i = n - 2; i >= 1; i--) ans = (LL) ans * i % MOD;
    return ans;
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> n;
        q.clear();
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            q[a[i]]++;
        }
        cout << gao() << '\n';
    }
    return 0;
}
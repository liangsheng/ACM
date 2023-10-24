#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        map<int, int> q;
        for (int i = 2; (LL) i * i <= n; i++) {
            while (n % i == 0) q[i]++, n /= i;
            if (q.size() > 1) break;
        }
        if (n != 1) q[n]++;
        cout << (q.size() > 1 ? "Yes" : "No") << '\n';
    }
    return 0;
}
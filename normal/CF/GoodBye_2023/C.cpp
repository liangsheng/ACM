#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T, n, x;
    cin >> T;
    while (T--) {
        cin >> n;

        LL sum = 0, cnt = 0;
        for (int i = 1; i <= n; i++) {
            cin >> x;
            cnt += x % 2;
            sum += x;
            cout << sum - cnt / 3 - (i > 1 && cnt % 3 == 1);
            cout << " \n"[i == n];
        }
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n) {
        int now = 1;
        vector<int> ans;
        ans.push_back(1);
        for (int i = 2; i < n - 1; i++) {
            if (__gcd(i, n) == 1) ans.push_back(i), now = (LL) now * i % n;
        }
        if (n > 2 && (LL) now * (n - 1) % n == 1) ans.push_back(n - 1);
        cout << ans.size() << '\n';
        for (int i = 0; i < ans.size() - 1; i++) cout << ans[i] << ' ';
        cout << ans[ans.size() - 1] << '\n';
    }
    return 0;
}
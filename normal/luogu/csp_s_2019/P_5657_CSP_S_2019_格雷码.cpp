#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    LL n, k;
    while (cin >> n >> k) {
        vector<int> ans(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            LL d = 1LL << i;
            if (k <= d) ans[i] = 0;
            else ans[i] = 1, k -= d;
        }
        for (int i)
    }
    return 0;
}
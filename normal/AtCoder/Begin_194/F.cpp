#include <bits/stdc++.h>
using namespace std;

const int N = 200005, M = 17, MOD = 1000000007;

int n, k;
string s;
int a[N];

int gao() {
    if (k > n) return 0;
    for (int i = 0; i < n; i++) {
        if (s[i] >= '0' && s[i] <= '9') a[i + 1] = s[i] - '0';
        else a[i + 1] = s[i] - 'A' + 10;
    }
    memset(dp, 0, sizeof(dp));
    dp[1][1] = a[1] - 1;
    for (int i = 2; i <= n; i++) {

    }
}

int main() {
    while (cin >> s >> k) {
        n = s.size();
        cout << gao() << '\n';
    }
    return 0;
}
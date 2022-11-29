#include <bits/stdc++.h>
using namespace std;

int n, k;
string s;

int gao() {
    for (int t = 1; t <= n; t++) {
        if (n % t) continue;
        int tmp = 0;
        for (int i = 0; i < t; i++) {
            vector<int> c(26, 0);
            for (int j = i; j < n; j += t) c[s[j] - 'a']++;
            tmp += n / t - *max_element(c.begin(), c.end());
        }
        if (tmp <= k) return t;
    }
    return n;
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    while (cin >> n >> k) {
        cin >> s;
        cout << gao() << '\n';
    }
    return 0;
}
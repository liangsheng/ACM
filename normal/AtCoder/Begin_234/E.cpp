#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

set<LL> ans;

void put(string a) {
    // cout << a << '\n';
    if (a[0] == '0') return ;
    LL tmp = 0;
    for (char ch : a) tmp = tmp * 10 + ch - '0';
    ans.insert(tmp);
}

void init() {
    for (int i = 0; i < 100; i++) ans.insert(i);
    for (int d = 3; d <= 10; d++) {
        for (int k = 0; k < 10; k++) {
            for (int i = 0; i + (d - 1) * k < 10; i++) {
                string ans;
                for (int j = 0; j < d; j++) {
                    ans.push_back('0' + i + j * k);
                }
                put(ans);
                reverse(ans.begin(), ans.end());
                put(ans);
            }
        }
    }
    for (int d = 11; d <= 18; d++) {
        for (int i = 1; i < 10; i++) {
            string ans;
            for (int j = 0; j < d; j++) ans.push_back('0' + i);
            // cout << "hello " << ans << '\n';
            put(ans);
        }
    }
    ans.insert(1111111111111111111LL);
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    init();
    // cout << ans.size() << '\n';
    // for (LL x : ans) cout << x << '\n';
    LL n;
    while (cin >> n) cout << *ans.lower_bound(n) << '\n';
    return 0;
}
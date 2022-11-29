#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void init(int n) {
    vector<bool> f(n + 1, 0);
    vector<int> p;
    for (int i = 2; i <= n; i++) {
        if (f[i]) continue;
        p.push_back(i);
        for (LL j = (LL) i * i; j <= n; j += i) f[j] = 1;
    }
    cout << p.size() << '\n';
}

int main() {
    init(200000);
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int T, n;
    string s;
    cin >> T;
    while (T--) {
    }
    return 0;
}
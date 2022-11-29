#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 10000000;

int T;
int c, d, x;
bool f[N + 5];
vector<int> p;

int gao() {
    vector<int> h = {1};
    if (x != 1) h.push_back(x);
    for (int i = 2; (LL) i * i <= x; i++) {
        if (x % i) continue;
        h.push_back(i);
        if (x / i != i) h.push_back(x / i);
    }
    
    int ans = 0;
    for (auto v: h) {
        int u = x / v + d;
        // cout << "u= " << u << ' ' << v << ' ' << h.size() << '\n';
        if (u % c) continue;
        u /= c;
        if (u == 1) {
            ans += 1;
            continue;
        }
        int t = 1;
        for (int i = 2; (LL) i * i <= u; i++) {
            if (u % i) continue;
            t *= 2;
            while (u % i == 0) u /= i;
        }
        if (u != 1) t *=2 ;
        ans += t;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> c >> d >> x;
        cout << gao() << '\n';
    }
    return 0;
}
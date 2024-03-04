#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
 
int main() {
    // 下面 2 句话是为了让 cin 更快，不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    LL n;
    cin >> n;
    vector<LL> a;
    LL l = 1, r = 1000000, mid;
    while (l != r) {
        mid = (l + r) / 2 + 1;
        if (mid * mid * mid <= n) l = mid;
        else r = mid - 1;
    }

    auto gao = [&](LL t) {
        LL m = t, x = 0;
        while (m != 0) {
            x = x * 10 + m % 10;
            m /= 10;
        }
        return x == t;

    };
    for (LL i = l; i >= 1; i--) {
        LL t = i * i * i;
        if (gao(t)) {
            cout << t << '\n';
            break;
        }
    }
    return 0;
}
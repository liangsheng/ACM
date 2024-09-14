#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    // 下面 2 句话是为了让 cin 更快，不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    LL n;
    cin >> n;
    
    map<LL, LL> q;
    q[1] = 0;
    function<LL(LL)> gao = [&](LL x) {
        if (q.count(x)) return q[x];
        return q[x] = x + gao(x / 2) + gao((x + 1) / 2);
    };
    cout << gao(n) << '\n';
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int INF = numeric_limits<int>::max() / 2;

int main() {
    // 下面 2 句话是为了让 cin 更快，不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q, c, x;
    cin >> n >> q;
    vector<int> f(n + 1, 0);
    while (q--) {
        cin >> c >> x;
        if (c == 1) f[x] = 1;
        else {
            for (int i = x; i <= n; i++) if (!f[i]) {
                cout << i << '\n';
                break;
            }
        }
    }
    return 0;
}
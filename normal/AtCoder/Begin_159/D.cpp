#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 200005;

int n;
int a[N];
map<int, int> q;

int main() {
    LL ans, tmp;
    while (~scanf("%d", &n)) {
        q.clear();
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            q[a[i]]++;
        }
        ans = 0;
        for (auto &t: q) ans += (LL) t.second * (t.second - 1) / 2;
        for (int i = 0; i < n; i++) cout << ans - q[a[i]] + 1 << '\n';
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int D = 30, INF = 1000000000;

vector<int> a;
vector<int> b = {2, 3, 5, 7};

void dfs(int p, LL now) {
    if (p == 4) {
        a.push_back(now);
        return ;
    }
    while (now <= INF) {
        dfs(p + 1, now);
        now *= b[p];
    }
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    dfs(0, 1);
    sort(a.begin(), a.end());
    int l, r;
    cin >> l >> r;
    int y = upper_bound(a.begin(), a.end(), r) - a.begin() - 1;
    int x = lower_bound(a.begin(), a.end(), l) - a.begin() - 1;
    cout << y - x << '\n';
    return 0;
}
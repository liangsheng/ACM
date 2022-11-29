#include <bits/stdc++.h>
using namespace std;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int n, m, x;
    while (~scanf("%d %d", &n, &m)) {
        multiset<int> a;
        vector<int> ans;
        for (int i = 1; i <= n; i++) {
            cin >> x;
            a.insert(x);
            if (i < m) continue;
            if (i == m) {
                ans.push_back(*a.begin());
                continue;
            }
            a.erase(a.begin());
            ans.push_back(*a.begin());
        }
        for (int x : ans) printf("%d\n", x);
    }
    return 0;
}
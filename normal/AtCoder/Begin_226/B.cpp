#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int n, len, x;
    while (cin >> n) {
        set<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            cin >> len;
            vector<int> a;
            for (int j = 0; j < len; j++) {
                cin >> x;
                a.push_back(x);
            }
            ans.insert(a);
        }
        cout << ans.size() << '\n';
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int INF = ~0U >> 2;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int n;
    while (cin >> n) {
        vector<int> a(n);
        set<int> s;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (s.count(a[i])) a[i] = INF;
            else s.insert(a[i]);
        }
        sort(a.begin(), a.end());
        int now = 1, m = n;
        for (int i = 0; i < m; now++) {
            if (a[i] == now) {
                i++;
                continue;
            }
            if (m - 2 >= i) m -= 2;
            else break;
        }
        cout << now - 1 << '\n';
    }
    return 0;
}
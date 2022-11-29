#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    while (cin >> n >> m) {
        int x, now = 0, flag = 1;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) {
            // cout << "i= " << i << ' ' << now << '\n';
            x = a[i];
            if (x == 1) {
                if (now + 2 <= m) now += 2;
            } else {
                if (now + 3 <= m) now += 3;
                else if (now + 2 <= m) now += 2;
                else {
                    flag = 0;
                    break;
                }
            }
        }
        cout << (flag ? "Yes" : "No") << '\n';
    }
    return 0;
}
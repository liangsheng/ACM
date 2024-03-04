#include <bits/stdc++.h>
using namespace std;

int main() {
    // 下面 2 是为了让 cin, cout 更快, 不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    while (cin >> n  >> m) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        int cnt = 0;
        for (int i = 0; i < n && m > 0; i++) {
            if (a[i] <= m) m -= a[i], cnt++; 
        }
        cout << cnt << '\n';
    }
   return 0;
}
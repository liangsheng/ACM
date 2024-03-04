#include <bits/stdc++.h>
using namespace std;
 
int main() {
    // 下面 2 句话是为了让 cin 更快，不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        vector<int> a(n);
        for (int& x: a) cin >> x;
        sort(a.begin(), a.end());
        cout << a[n - 1] - a[0] + a[n - 1] - a[1] + a[n - 2] - a[1] + a[n - 2] - a[0] << '\n';
    }
    return 0;
}
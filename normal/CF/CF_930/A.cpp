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
        int ans = 1;
        while (ans <= n) ans *= 2;
        cout << ans / 2 << '\n';
    }
    return 0;
}
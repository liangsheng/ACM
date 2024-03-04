#include <bits/stdc++.h>
using namespace std;
 
int main() {
    // 下面 2 句话是为了让 cin 更快，不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, ans = 0, tmp = 500005;
    int n0 = 0, n1 = 0, y0 = 0, y1 = 0;
    string s;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        vector<int> c(2, 0);
        for (char ch : s) c[ch - '0']++;
        ans += min(c[0], c[1]);
        tmp = min(tmp, abs(c[0] - c[1]));
        if (c[0] >= c[1]) y0 = 1;
        if (c[1] >= c[0]) y1 = 1;
        if (c[0] > 0 && c[0] < c[1]) n0 = 1;
        if (c[1] > 0 && c[1] < c[0]) n1 = 1;  
    }
    if ((n0 & !y0) || (n1 & !y1)) cout << ans + tmp << '\n';
    else cout << ans << '\n';
    return 0;
}
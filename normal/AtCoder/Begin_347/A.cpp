#include <bits/stdc++.h>
using namespace std;
 
int main() {
    // 下面 2 句话是为了让 cin 更快，不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k, x;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x % k == 0) cout << x / k << ' ';
    }
    cout << '\n';
    return 0;
}
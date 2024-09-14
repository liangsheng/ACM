#include <bits/stdc++.h>
using namespace std;

int main() {
    // 下面 2 句话是为了让 cin 更快，不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, l, r;
    cin >> n >> l >> r;
    for (int i = 1; i < l; i++) cout << i << ' ';
    for (int i = r; i >= l; i--) cout << i << ' ';
    for (int i = r + 1; i <= n; i++) cout << i << ' ';
    cout << '\n';
    return 0;
}
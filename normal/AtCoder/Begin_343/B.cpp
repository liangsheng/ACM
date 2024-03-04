#include <bits/stdc++.h>
using namespace std;
 
int main() {
    // 下面 2 句话是为了让 cin 更快，不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> x;
            if (x == 1) cout << j + 1 << ' ';
        }
        cout << '\n';
    }
    return 0;
}
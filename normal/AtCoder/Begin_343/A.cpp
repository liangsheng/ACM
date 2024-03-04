#include <bits/stdc++.h>
using namespace std;
 
int main() {
    // 下面 2 句话是为了让 cin 更快，不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b;
    cin >> a >> b;
    for (int i = 0; i <= 9; i++) if (i != a + b) {
        cout << i << '\n';
        break;
    }
    return 0;
}
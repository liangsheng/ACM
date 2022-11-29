#include <bits/stdc++.h>
using namespace std;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int T;
    string a, b;
    cin >> T;
    while (T--) {
        cin >> a >> b;
        int cnt = 0;
        for (int i = 0; i < b.size(); i++) cnt += (b[i] == 'a');
        if (b == "a") cout << 1 << '\n';
        else if (cnt == 0) cout << (1LL << a.size()) << '\n';
        else cout << -1 << '\n';
    }
    return 0;
}
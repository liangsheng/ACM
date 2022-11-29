#include <bits/stdc++.h>
using namespace std;

int T, n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> n >> m;
        if (m > (n + 1) / 2) {
            cout << "-1" << '\n';
            continue;
        }
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                for (int j = 0; j < n; j++) {
                    if (j == i && j / 2 < m) cout << "R";
                    else cout << ".";
                }
                cout << '\n';
            } else {
                for (int j = 0; j < n; j++) cout << ".";
                cout << "\n";
            }
        }
    }
    return 0;
}
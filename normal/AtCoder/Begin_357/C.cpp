#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> len = {1, 3, 9, 27, 81, 243, 729};
    bool s[7][800][800];
    s[0][0][0] = 1;
    for (int k = 1, d = 3; k <= 6; k++, d *= 3) {
        int t = d / 3;
        for (int i = 0; i < d; i += t) for (int j = 0; j < d; j += t) {
            for (int u = i; u < i + t; u++) for (int v = j; v < j + t; v++) {
                s[k][u][v] = s[k - 1][u - i][v - j];
            }
        }
        for (int u = t; u < t + t; u++) for (int v = t; v < t + t; v++) {
            s[k][u][v] = 0;
        }
    }
    int n;
    cin >> n;
    for (int i = 0; i < len[n]; i++) {
        for (int j = 0; j < len[n]; j++) cout << (s[n][i][j] ? '#' : '.');
        cout << '\n';
    }
    return 0;
}
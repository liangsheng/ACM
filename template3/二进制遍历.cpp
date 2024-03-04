#include <bits/stdc++.h>
using namespace std;

int main () {
    int n = 28, m = 5;

    auto gao = [&](int x) {
        cout << x << ' ';
        for (int i = m - 1; i >= 0; i--) cout << (x >> i & 1);
        cout << '\n';
    };

    while (cin >> n >> m) {

        int cnt = 0;
        for (int i = n; i != 0; i = i & (i - 1)) gao(i), cnt++;
        cout << "cnt= " << cnt << '\n';

        cnt = 0;
        for (int i = n; i != 0; i = n & (i - 1)) gao(i), cnt++;
        cout << "cnt= " << cnt << '\n';
    }
    return 0;
}
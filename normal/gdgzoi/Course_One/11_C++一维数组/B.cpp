#include <bits/stdc++.h>
using namespace std;

int main() {
    int cnt[10];
    for (int i = 0; i < 10; i++) cnt[i] = 0;
    int l, r;
    while (cin >> l >> r) {
        for (int i = l; i <= r; i++) {
            int x = i;
            if (x == 0) cnt[0]++;
            else {
                while (x != 0) cnt[x % 10]++, x /= 10;
            }
        }
        for (int i = 0; i < 9; i++) cout << cnt[i] << ' ';
        cout << cnt[9] << '\n';
    }
    return 0;
}
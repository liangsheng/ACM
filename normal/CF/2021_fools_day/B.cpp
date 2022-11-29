#include <bits/stdc++.h>
using namespace std;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int x;
    while (cin >> x) {
        while (x > 9) {
            int y = 0;
            while (x != 0) {
                y += x % 10;
                x /= 10;
            }
            x = y;
        }
        cout << x << '\n';
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    LL n, x, y;
    while (cin >> n) {
        LL sum = 0;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }
        cin >> x >> y;
        LL p = 0, now = 0;
        for (int i = 0; i < n; i++) {
            now += a[i];
            if (now >= x && now <= y && sum - now >= x && sum - now <= y) {
                p = i + 2;
                break;
            }
        }
        cout << p << '\n';
    }
    return 0;
}
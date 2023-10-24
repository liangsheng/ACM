#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, now;
    while (cin >> n) {
        now = 0;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i] >> b[i];
            now += b[i] * 100 / a[i];
        }
        cin >> m;
        if (now >= m) cout << "Already Au." << '\n';
        else {
            for (int i = 0; i < n; i++) {
                if (now + (a[i] - b[i]) * 100 / a[i] < m) cout << "NaN" << '\n';
                else {
                    int tmp = now, d = 100 / a[i];
                    for (int j = 1; j <= a[i] - b[i]; j++) {
                        tmp += d;
                        if (tmp >= m) {
                            cout << j << '\n';
                            break;
                        }
                    }
                }
            }
        }
    }
    return 0;
}
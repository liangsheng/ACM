#include <bits/stdc++.h>
using namespace std;

const int INF = ~0U >> 2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while (cin >> n) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        vector<int> d;
        for (int i = 1; (long long) i * i <= a[0]; i++) {
            if (a[0] % i) continue;
            d.push_back(i);
            if (a[0] / i != i) d.push_back(a[0] / i);
        }
        int cnt = INF;
        for (int x : d) {
            int flag = 1, tmp = 0;
            for (int i = 0; i < n; i++) {
                int y = a[i];
                if (y % x) {
                    flag = 0;
                    break;
                }
                int t = y / x;
                while (t != 1) {
                    if (t % 2 == 0) t /= 2, tmp++;
                    else if (t % 3 == 0) t /= 3, tmp++;
                    else break;
                }
                if (t != 1) {
                    flag = 0;
                    break;
                }
            }
            if (flag) cnt = min(cnt, tmp);
        }
        if (cnt == INF) cnt = -1;
        cout << cnt << '\n';
    }
    return 0;
}
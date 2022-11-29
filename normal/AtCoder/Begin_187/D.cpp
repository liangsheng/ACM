#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 200005;

int n;
vector<pair<int, int> > a;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int x, y;
    while (cin >> n) {
        a.clear();
        for (int i = 0; i < n; i++) {
            cin >> x >> y;
            a.push_back({x, y});
        }
        sort(a.begin(), a.end(), [](const pair<int, int> &u, const pair<int, int> &v) {
            return 2LL * u.first + u.second > 2LL * v.first + v.second;
        });
        
        vector<LL> h(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) h[i] = h[i + 1] + a[i].first;

        int ans = -1;
        LL now = 0;
        for (int i = 0; i < n; i++) {
            now += a[i].first + a[i].second;
            if (now > h[i + 1]) {
                ans = i;
                break;
            }
        }
        cout << ans + 1 << '\n';
    }
    return 0;
}
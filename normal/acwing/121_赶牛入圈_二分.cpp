#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
typedef pair<int, int> pii;

const int N = 505, INF = 10000;

int c, n;
pii a[N];

bool ok(int i, int d) {
    for (int k = 0; k < 2; k++) {
        vector<int> x;
        int l = a[i].Y - d + 1, r = a[i].Y;
        if (k) l = a[i].Y, r = a[i].Y + d - 1;
        for (int j = 0; j < n; j++) {
            if (a[j].Y >= l && a[j].Y <= r) x.push_back(a[j].X);
        }
        // for (int j : x) cout << j << ' ';
        // cout << '\n';
        for (int j = 0; j + c <= x.size(); j++) {
            if (x[j + c - 1] - x[j] + 1 <= d) return true;
        } 
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> c >> n) {
        for (int i = 0; i < n; i++) cin >> a[i].X >> a[i].Y;
    
        int ans = INF;
        for (int k = 0; k < 2; k++) {
            if (k) {
                for (int i = 0; i < n; i++) swap(a[i].X, a[i].Y);
            }
            // 按 x 排序
            sort(a, a + n);
            for (int i = 0; i < n; i++) {
                int l = 1, r = INF, mid;
                while (l != r) {
                    int mid = (l + r) / 2;
                    // cout << "mid= " << mid << " " << ok(i, mid) << '\n';
                    if (ok(i, mid)) r = mid;
                    else l = mid + 1;
                }
                ans = min(ans, l);
                // cout << "k= " << k << ", i= " << i << ", ans= " << ans << '\n';
            }  
        }    
        cout << ans << '\n'; 
    }
    return 0;
}
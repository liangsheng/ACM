#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;  // 表示代码里需要写 pair<int, int> 时, 可以用 pii 代替
 
int main() {
    // 下面 2 是为了让 cin, cout 更快, 不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    while (cin >> n) {

        vector<pii> a(n);
        for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
        
        // 按结束时间从小到大排序
        sort(a.begin(), a.end(), [&](const pii& x, const pii& y) {
            return x.second < y.second;
        });

        int cnt = 1, p = a[0].second;
        for (int i = 1; i < n; i++) if (a[i].first >= p) {
            cnt++;
            p = a[i].second;
        }
        cout << cnt << '\n';
    }
    return 0;
}
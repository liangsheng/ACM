#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;  // typedef 是指 pair<int, int> 在下面的代码中可以简写成 pii

int main() {
    int n;
    cin >> n;
    vector<pii> a(n);
    for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
    sort(a.begin(), a.end(), [&](const pii& p, const pii& q) {
        if (p.first != q.first) return p.first < q.first;
        return p.second < q.second;
    });
    for (int i = 0; i < n; i++) cout << a[i].first << ' ' << a[i].second << '\n';
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    // 这两句话是为了让 cin 和 cout 操作更快
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; i++) cin >> h[i];

    vector<int> b;
    for (int i = 0; i < n; i++) {
        // 找到第一个不小于 h[i] 的数, 用来拦截 h[i]
        auto it = lower_bound(b.begin(), b.end(), h[i]);
        
        // 如果找不到就新建一个拦截系统
        if (it == b.end()) b.push_back(h[i]);
        else *it = h[i];
    }
    cout << b.size() << '\n';
    return 0;
}
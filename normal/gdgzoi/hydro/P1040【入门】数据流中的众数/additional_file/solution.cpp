#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x, cnt = 0;
    cin >> n;
    map<int, int> q;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        cin >> x;
        q[x]++;
        if (q[x] > cnt) {
            cnt = q[x];
            ans.clear();
            ans.push_back(x);
        } else if (q[x] == cnt) {
            ans.push_back(x);
        }
        cout << ans.size() << ' ' << cnt << '\n';
    }
    return 0;
}
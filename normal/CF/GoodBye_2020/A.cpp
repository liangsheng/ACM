#include <bits/stdc++.h>

using namespace std;

const int N = 55;

int T, n;
vector<int> a(N);
set<int> ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];

        ans.clear();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) ans.insert(a[j] - a[i]);
        }
        cout << ans.size() << '\n';
    }
    return 0;
}
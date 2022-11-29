#include <bits/stdc++.h>
using namespace std;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        int mini = *min_element(a.begin(), a.end());
        if (a[0] > mini) {
            cout << "NO" << '\n';
            continue;
        }
        bool flag = 1;
        for (int i = 1; i < n; i++) if (a[i] % a[0]) {
            flag = 0;
            break;
        }
        if (flag) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}
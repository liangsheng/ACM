#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    while (cin >> n) {
        vector<int> a(n, 0), b(n, 0);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        int maxi = *max_element(a.begin(), a.end());
        int mini = *min_element(b.begin(), b.end());
        if (mini >= maxi) cout << mini - maxi + 1 << '\n';
        else puts("0");
    }
    return 0;
}
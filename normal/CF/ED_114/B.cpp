#include <bits/stdc++.h>
using namespace std;

int T, a[3], m;

int main() {
    cin >> T;
    while (T--) {
        cin >> a[0] >> a[1] >> a[2] >> m;
        int maxi = a[0] + a[1] + a[2] - 3;
        sort(a, a + 3);
        int mini = 0, d = a[2] - a[0] - a[1];
        if (d > 1) mini = d - 1;
        if (m >= mini && m <= maxi) cout << "YES" << '\n';
        else cout << "NO" << '\n';        
    }
}

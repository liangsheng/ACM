#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, n, k;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        vector<int> a;
        if (k == 1) for (int i = 1; i <= n; i++) a.push_back(i);
        else {
            int L = 0, R = n + 1;
            while (L < R) {
                for (int i = R - 1; i > max(R - k, L); i--) a.push_back(i);
                R = a[a.size() - 1];
                for (int i = L + 1; i < min(L + k, R); i++) a.push_back(i);
                L = a[a.size() - 1];
            }
        }
        for (int i = 0; i < n - 1; i++) cout << a[i] << ' ';
        cout << a[n - 1] << '\n';
    }
    return 0;
}
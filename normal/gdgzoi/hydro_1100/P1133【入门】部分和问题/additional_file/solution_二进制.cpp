#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    auto ok = [&]() {
        for (int st = 1; st < (1 << n); st++) {
            long long s = 0;
            for (int i = 0; i < n; i++) if ((st >> i) & 1) s += a[i];
            if (s == k) return true;
        }
        return false;
    };
    cout << (ok() ? "Yes" : "No") << '\n';
    return 0;
}

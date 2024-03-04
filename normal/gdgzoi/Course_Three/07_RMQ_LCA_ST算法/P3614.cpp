#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int n;
    while (cin >> n) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        
        LL sum = accumulate(a.begin(), a.end(), 0LL);
        int p = sum / n, q = sum % n;
        vector<int> b(n, p);
        for (int i = 0; i < q; i++) b[i]++;

        LL ans = 0;
        sort(a.begin(), a.end(), greater<int>());
        for (int i = 0; i < n; i++) ans += abs(a[i] - b[i]);
        cout << ans / 2 << '\n';
    }
    return 0; 
}
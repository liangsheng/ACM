#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        vector<int> a(n + 1);

        int maxi = 0, now = 0, c = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i] == 1) {
                c++;
                if (now == maxi) maxi++, now = maxi;
                else now++;
            } else {
                if (c == 0) continue;
                if (c % 2) now = (c + 1) / 2;
                else now = c / 2 + 1;
            }
        }
        cout << maxi << '\n';
    }
    return 0;
}
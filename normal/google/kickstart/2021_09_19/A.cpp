#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 500005, INF = N;

int T, n;
string s;
int L[N], R[N];

int main() {
    // ios:sync_with_stdio(false);
    // cin.tie(0);
    int cas = 0, p;
    cin >> T;
    while (T--) {
        cin >> n;
        cin >> s;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') L[i] = N;
            else {
                L[i] = 0, p = i;
                break;
            }
        }
        for (int i = p + 1; i < n; i++) {
            if (s[i] == '1') L[i] = 0;
            else L[i] = L[i - 1] + 1;
        }
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') R[i] = N;
            else {
                R[i] = 0, p = i;
                break;
            }
        }
        for (int i = p - 1; i >= 0; i--) {
            if (s[i] == '1') R[i] = 0;
            else R[i] = R[i + 1] + 1;
        }
        LL ans = 0;
        for (int i = 0; i < n; i++) ans += min(L[i], R[i]);
        cout << "Case #" << ++cas << ": " << ans << '\n';
    }
    return 0;
}
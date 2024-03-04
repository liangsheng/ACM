#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
typedef long long LL;
typedef pair<string, int> psi;

int main() {
    // 下面 2 句是为了让 cin, cout 更快, 不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n) {
        vector<psi> s(n);
        vector<LL> a(n, 0), b(n, 0), d(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> s[i].X, s[i].Y = i;
            b[i] = 0;
            for (int j = 0; j < s[i].X.size(); j++) {
                if (s[i].X[j] == 'X') b[i]++;
                else {
                    a[i] += b[i] * (s[i].X[j] - '0');
                    d[i] += s[i].X[j] - '0';
                }
            } 
        }

        sort(s.begin(), s.end(), [&](const psi& u, const psi& v) {
            int p = u.Y, q = v.Y;
            return b[p] * d[q] > b[q] * d[p];
        });

        LL ans = 0, c = 0;
        for (int i = 0; i < n; i++) for (char ch : s[i].X) {
            if (ch == 'X') c++;
            else ans += c * (ch - '0');
        }
        cout << ans << '\n';
    }
    return 0;
}
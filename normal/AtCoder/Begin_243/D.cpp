#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL INF = 1000000000000000000LL;

LL n, x;
string s;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    while (cin >> n >> x) {
        cin >> s;
        int cnt = 0;
        for (char ch : s) {
            if (cnt > 0) {
                if (ch == 'U') cnt--;
                else cnt++;
            } else {
                if (ch == 'U') x = x / 2;
                else {
                    if (x * 2 > INF) cnt++;
                    else if (ch == 'L') x = x * 2;
                    else x = x * 2 + 1;
                }
            }
        }
        cout << x << '\n';
    }
    return 0;
}
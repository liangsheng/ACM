#include <bits/stdc++.h>

using namespace std;

const int N = 25;

int T;
string a, b;

int gcd(int x, int y) {
    return x % y ? gcd(y, x % y) : y;
}

string gao() {
    int n = a.size(), m = b.size();
    int sz = n * m / gcd(n, m);
    string ans, res;
    for (int i = 0; i < sz / n; i++) ans += a;
    for (int i = 0; i < sz / m; i++) res += b;
    if (ans == res) return ans;
    return "-1";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> a >> b;
        cout << gao() << '\n';
    }
    return 0;
}
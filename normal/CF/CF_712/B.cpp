#include <bits/stdc++.h>
using namespace std;

const int N = 300005;

int T, n;
string a, b;

bool gao() {
    int c[2] = {0, 0}, f = 0;
    for (int i = 0; i < n; i++) c[a[i] - '0']++;
    for (int i = n - 1; i >= 0; i--) {
        int x = (a[i] - '0') ^ f;
        if (b[i] - '0' == x) {
            c[x]--;
            continue;
        }
        if (c[0] != c[1]) return 0;
        swap(c[0], c[1]);
        f ^= 1;
        c[b[i] - '0']--;
    }
    return 1;
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> n;
        cin >> a >> b;
        puts(gao() ? "YES" : "NO");
    }
    return 0;
}

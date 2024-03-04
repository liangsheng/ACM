#include <bits/stdc++.h>
using namespace std;
typedef long long LL; 

const int D = 60;

LL T, MOD, A, B;

int gao(LL A, LL B) {
    if (A < B) return 0;
    int c = 0, tmp = 1, e = 0, d = 0;
    while (A != 0) {
        int a = (A & 1), b = (B & 1), t;
        A >>= 1, B >>= 1;
        if (b) {
            if (a != d) return 0;
            t = 1, d = 1;
        } else {
            if (d && a) t = 0, d = 0;
            else if (d && !a) t = -1, d = 1;
            else if (!d && a) t = -1, d = 0;
            else if (!d && !a) t = 0, d = 0;
        }
        if (t == -1) c = tmp, e++;
        tmp = (LL) tmp * 2 % MOD;
    }
    for (int i = 1; i < e; i++) c = (LL) c * 2 % MOD;
    return c;
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    cin >> T >> MOD;
    while (T--) {
        cin >> A >> B;
        cout << gao(A, B) << '\n';
    }
    return 0;
}

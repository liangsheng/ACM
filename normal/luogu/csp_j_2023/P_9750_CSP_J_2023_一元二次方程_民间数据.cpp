#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int INF = ~0U >> 2;

int gcd(int x, int y) {
    return x % y == 0 ? y : gcd(y, x % y);
}

void gao(int p, int q) {
    if (p == 0) cout << 0;
    else if (p % q == 0) cout << p / q;
    else {
        int f = 1;
        if (p * q < 0) f = 0;
        p = abs(p), q = abs(q);
        int d = gcd(p, q);
        if (f) cout << p / d << '/' << q / d;
        else cout << '-' << p / d << '/' << q / d;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T, m, a, b, c;
    srand(time(0));
    while (cin >> T >> m) while (T--) {
        cin >> a >> b >> c;
        // a = rand() % (2 * m + 1) - m;
        // b = rand() % (2 * m + 1) - m;
        // b = 0;
        // c = rand() % (2 * m + 1) - m;
        // cout << a << ' ' << b << ' ' << c << '\n';
        if (a < 0) a = -a, b = -b, c = -c;
        int delta = b * b - 4 * a * c;
        if (delta < 0) {
            cout << "NO" << '\n';
            continue;
        }
        int d = sqrt(delta);
        double x = max((-b + sqrt(b * b - 4 * a * c)) / (2 * a), (-b - sqrt(b * b - 4 * a * c)) / (2 * a));
        // cout << x << ' ';
        if (d * d == delta) {
            int p = d - b, q = 2 * a;
            gao(p, q);
            cout << '\n';
        } else {
            int p = -b, q = 2 * a;
            if (b != 0) gao(p, q), cout << '+';
            int h = 1;
            for (int i = 2; i * i <= delta; i++) if (delta % (i * i) == 0) h = i;
            if (h != 1) d = delta / h / h;
            else d = delta;
            if (h % (2 * a) == 0) {
                if (h / (2 * a) == 1) cout << "sqrt(" << d << ")";
                else cout << h / (2 * a) << "*sqrt(" << d << ")";
            } else {
                // cout << "\n" << h << ' ' << d << ' ' << delta << '\n';
                // cout << -b << ' ' << 2 * a << ' ' << h << ' ' << d << '\n';
                int g = gcd(h, 2 * a);
                h /= g;
                if (h != 1) cout << h << "*";
                cout << "sqrt(" << d << ")" << "/" << 2 * a / g; 
            }
            cout << '\n';
        }
    }
    return 0;
}

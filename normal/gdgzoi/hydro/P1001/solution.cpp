#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    string op;
    while (cin >> a >> op >> b) {
        if (op == "+") {
            cout << a + b << endl;
        } else if (op == "-") {
            cout << a - b << endl;
        } else if (op == "*") {
            cout << (long long) a * b << endl;
        } else if (op == "/") {
            cout << a / b << endl;
        } else if (op == "%") {
            cout << a % b << endl;
        } else if (op == "//") {
            double ans = a * 1.0 / b;
            cout << fixed << setprecision(2) << ans << endl;
        }
    }
    return 0;
}
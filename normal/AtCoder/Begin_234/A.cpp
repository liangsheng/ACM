#include <bits/stdc++.h>
using namespace std;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    auto f = [](int x) {
        return x * x + 2 * x + 3;
    };
    auto g = [&](int x) {
        return f(f(f(x) + x) + f(f(x)));
    };
    int t;
    while (cin >> t) cout << g(t) << '\n';
    return 0;
}
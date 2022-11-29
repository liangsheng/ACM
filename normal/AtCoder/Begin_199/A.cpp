#include <bits/stdc++.h>
using namespace std;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int a, b, c;
    while (cin >> a >> b >> c) {
        puts(a * a + b * b < c * c ? "Yes" : "No");
    }
    return 0;
}
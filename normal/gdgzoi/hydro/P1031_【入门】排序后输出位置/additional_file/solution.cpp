#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int main() {
    int n;
    int a[N];
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    int b[N];
    for (int i = 1; i <= n; i++) b[i] = i;
    sort(b + 1, b + n + 1, [&](const int& x, const int& y) {
        return a[x] < a[y];
    });
    for (int i = 1; i <= n - 1; i++) cout << b[i] << ' ';
    cout << b[n] << '\n';
    return 0;
}
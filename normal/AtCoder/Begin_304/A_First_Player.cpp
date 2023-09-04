#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while (cin >> n) {
        vector<string> a(n);
        vector<int> b(n);
        int p = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i] >> b[i];
            if (b[i] < b[p]) p = i;
        }
        for (int i = p, j = 0; j < n; j++) cout << a[(i + j) % n] << '\n';
    }
    return 0;
}
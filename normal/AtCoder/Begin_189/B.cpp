#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int n, m;
int a[N], b[N];

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    int p, sum;
    while (cin >> n >> m) {
        sum = 0, p = -1;
        for (int i = 0; i < n; i++) {
            cin >> a[i] >> b[i];
            sum += a[i] * b[i];
            if (sum > m * 100 && p == -1) p = i + 1; 
        }
        cout << p << '\n';
    }
    return 0;
}
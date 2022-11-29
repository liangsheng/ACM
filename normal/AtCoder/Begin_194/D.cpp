#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n;
double dp[N];

double gao(int m) {
    if (dp[m] != -1.0) return dp[m];
    if (m == n) return dp[m] = 0.0;
    return dp[m] = n * 1.0 / (n - m) + gao(m + 1);
}

int main() {
    while (cin >> n) {
        for (int i = 1; i <= n; i++) dp[i] = -1.0;
        printf("%.6f\n", gao(1));
    }
    return 0;
}
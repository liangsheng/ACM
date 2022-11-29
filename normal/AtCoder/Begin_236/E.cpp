#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 16;
const LL INF = ~0ULL >> 2;

int n ;
int a[N];
LL dp[1 << 16];

int main() {
    while (~scanf("%d", &n)) {
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        for (int i = 0; i < (1 << n); i++) dp[i] = INF;
        dp[0] = 0;
        for (int i = 0; i < n; i++) for (int j = 0; j < (1 << n); j++) {
            if (dp[j] == INF) continue;
            dp[j] = min(dp[j], )
        }
    }
    return 0;
}
#include <bits/stdc++.h>
#define ll long long
#define INF 1e18
using namespace std;
int main() {
    ll t;
    scanf("%lld", &t);
    while (t --) {
        ll n, ans = 0;
        scanf("%lld", &n);
        vector <ll> a(n + 1);
        for (int i = 1; i <= n; i ++)
            scanf("%lld", &a[i]);
        if (n == 1) {
            printf("%lld\n", max(0LL, a[1]));
            continue;
        }
        for (int i = n; i >= 1; i --) {
            if (i % 2 == 0 && a[i] >= 0) {
                int sum = a[i];
                // <- i
                while (i - 1 > 0 && abs(a[i - 1] + a[i]) != abs(a[i - 1]) + abs(a[i])) {
                    i --;
                    sum += max(0LL, a[i]);
                }
                if (i > 1) ans += sum;
                else ans += sum - min(a[2], -a[1]);
            }
            if (i % 2 == 1 && a[i] >= 0)
                ans += a[i];
        }
        printf("%lld\n", ans);
    }
    return 0;
}
/*
求有多少个子串的hash值为n
f(x,b) = x0bk-1 + x1bk-2 + ... + xk-2b + xk-1
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>

#define pause cout << " press any key to continue...",  cin >> chh
#define file_r(x) freopen(x,  "r",  stdin)
#define file_w(x) freopen(x,  "w",  stdout)

using namespace std;
int chh;

typedef long long LL;

const LL N = 10005;

LL T, b, p, n;
LL x[N], sum[N], B[N];
char s[N];
map<LL, LL> q;

int main() {
    LL i, j, len, ans, t;
    scanf("%lld", &T);
    while (T--) {
        getchar();
        gets(s);
        scanf("%lld %lld %lld", &b, &p, &n);
        len = strlen(s);
        for (i = 0; i < len; i++) x[i] = int(s[i]);
        B[len] = 1LL, sum[len] = 0;
        q.clear();
        for (i = len - 1; i >= 0; i--) {
            sum[i] = (x[i] * B[i + 1] % p + sum[i + 1]) % p;
            B[i] = B[i + 1] * b % p;
            q[sum[i]]++;
        }
        ans = 0;
        if (q.find(n) != q.end()) ans += q[n];
        for (i = len - 1; i > 0; i--) {
            t = (n * B[i] % p + sum[i]) % p;
            q[sum[i]]--;
            if (q.find(t) != q.end()) ans += q[t];
        }
        printf("%lld\n", ans);
    }
    return 0;
}

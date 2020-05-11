/*
定义k-回文串如下：(1)任何串(包括空串)都是0-回文; 
(2)一个长度为n的回文串，若它的前n/2个字符和后n/2个字符都是(k-1)-回文，
则它是k-回文。现给定一个串（长度不超过5,000,000），
设它的每个前缀分别是x-回文，
求所有这些x值的和。
比如abacaba，
”a”是1-回文，
”aba”是2-回文，
”abacaba”是3-回文，故输出6。
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define pause cout << " press any key to continue...",  cin >> chh
#define file_r(x) freopen(x,  "r",  stdin)
#define file_w(x) freopen(x,  "w",  stdout)

using namespace std;
int chh;

typedef long long LL;

const int N = 10000005, M = 5000005;

int n, m;
int fail[N], d[M];
char s[M], str[N];

int main() {
    int i, k, p;
    LL ans;
    scanf("%s", s);
    n = strlen(s);
    m = n * 2 + 1;
    copy(s, s + n, str);
    str[n] = '#';
    for (i = n + 1; i < m; i++) str[i] = s[2 * n - i];
    str[m] = 0;
    fill(fail, fail + m, -1);
    for (i = 1; str[i]; ++i) {
        for (k = fail[i - 1]; k >= 0 && str[i] != str[k + 1]; k = fail[k]);
        if (str[k + 1] == str[i]) fail[i] = k + 1;
    }
    fill(d, d + n, 0);
    p = fail[m - 1];
    while (p != -1) d[p] = 1, p = fail[p];
    ans = 0;
    for (i = 1; i <= n; i++) {
        if (d[i - 1]) d[i - 1] = d[i / 2 - 1] + 1;
        ans += d[i - 1];
    }
    printf("%lld\n", ans);
    return 0;
}

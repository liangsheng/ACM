#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cassert>

#define pause cout << " press any key to continue...",  cin >> chh
#define file_r(x) freopen(x,  "r",  stdin)
#define file_w(x) freopen(x,  "w",  stdout)

using namespace std;
int chh;

typedef long long LL;

const int P = 100005;

int T, cnt;
LL n1[P], n2[P];
char s[P], t[P];

/*==================================================*\
| KMP 匹配算法 O(M+N)
| CALL: res=kmp(str, pat); 原串为str; 模式为pat(长为P);
\*==================================================*/
int fail[P];
void kmp(char* str, char* pat, LL num[]) {
    int i, j, k, len;
    memset(fail, -1, sizeof(fail));
    for (i = 1; pat[i]; ++i) {
        for (k = fail[i - 1]; k >= 0 && pat[i] != pat[k + 1]; k = fail[k]);
        if (pat[k + 1] == pat[i]) fail[i] = k + 1;
    }
    i = j = 0, len = strlen(pat);
    while (str[i]) { // By Fandywang
        if (pat[j] == str[i]) {
            num[j]++;
            ++i, ++j;
            if (j == len) j = fail[j - 1] + 1;
        }
        else if (j == 0) ++i;//第一个字符匹配失败,从str下个字符开始
        else j = fail[j - 1] + 1;
    }
}

int main() {
    int i, j, lt, ls;
    LL ans;
    scanf("%d", &T);
    while (T--) {
        scanf("%s %s", s, t);
        ls = strlen(s), lt = strlen(t);
        fill(n1, n1 + lt + 1, 0);
        fill(n2, n2 + lt + 1, 0);
        kmp(s, t, n1);
        for (i = lt - 1; i >= 0; i--)
            if (fail[i] != -1) n1[fail[i]] += n1[i];
        for (i = 0; i <= (lt - 1) / 2; i++) swap(t[i], t[lt - 1 - i]);
        for (i = 0; i <= (ls - 1) / 2; i++) swap(s[i], s[ls - 1 - i]);
        kmp(s, t, n2);
        for (i = lt - 1; i >= 0; i--)
            if (fail[i] != -1) n2[fail[i]] += n2[i];
        ans = 0;
        for (i = 0; i < lt - 1; i++) ans += n1[i] * n2[lt- 2 - i];
        printf("%lld\n", ans);
    }
    return 0;
}

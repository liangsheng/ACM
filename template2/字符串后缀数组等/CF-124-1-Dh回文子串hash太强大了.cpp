/*
给你一个整数m 和一个字符串s
输出一个字符串，使得这个字符串的字典序大于s（且是最小的字典序）且满足不存在长度大于等于m的回文子串
利用回文串的性质，只要修改当前某个字符后，前m个字符 和 前m+1个字符不为回文串，那么就可以继续构造，构造完后绝对不会产生大于m的回文子串
可以反证，如果构造完后（即字符串已经不存在长度为m或m+1的回文子串）存在大于等于m的回文子串，那么肯定会出现  在某个位置往前m或m+1（考虑奇偶）的子串是回文串  的情况，所以矛盾
另外，判断回文用的是哈希，比较简便。
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

const int N = 400005, P = 100000007;

int n, m;
int p[N], l[N], r[N];
char s[N], ans[N];

bool ok(int i, int x) {
    if (++i < x) return 1;
    return (l[i] - l[i - x]) != ((r[i] - r[i - x] * p[x]) * p[i - x]);
}

bool dfs(int i, bool f) {
    if (i == n) {
        puts(ans);
        return 1;
    }
    for (ans[i] = (f ? s[i] : 'a'); ans[i] <= 'z'; ans[i]++) {
        l[i + 1] = l[i] + ans[i] * p[i];
        r[i + 1] = r[i] * P + ans[i];
        if (ok(i, m) && ok(i, m + 1) && dfs(i + 1, f && (ans[i] == s[i]))) return 1;
    }
    return 0;
}

int main() {
    int i, j;
    p[0] = 1;
    for (i = 1; i < N; i++) p[i] = p[i - 1] * P;
    while (~scanf("%d", &m)) {
        scanf("%s", s);
        n = strlen(s);
        for (i = n - 1; i >= 0 && s[i] == 'z'; i--) s[i] = 'a';
        if (i < 0) {
            puts("Impossible");
            continue;
        }
        s[i]++;
        if (!dfs(0, 1)) puts("Impossible");
    }
    return 0;
}

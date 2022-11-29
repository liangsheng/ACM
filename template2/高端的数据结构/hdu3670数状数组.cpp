/*
题意是给以一串短整数，然后有一连串的操作，分别为1.把所有的整数都加上某一个值，如果大于2^16-1就取模。2.查询有多少个数满足二进制的第t位为1。这个题目还是有一点难度的，不过我原来在某大神的blog上看过这个题目的分析，所以马上就回忆起来了，做法也很清晰：对与加法操作，只需要另外记录下来就行了。对于查询操作，开16个树状树组，然后对于每一个整数，把它的二进制划分16次分别放到16个树状数组中，比如对于11是1011，我把1放到第0个树状数组里，11放到第1个树状数组里，011放到第2个，1011放到第3个，01011放到第4个，依此类推。然后对于每个询问t,只要找第t个树状数组中，满足2^t<=(x+d)mod 2^(t+1)<2^t+1的数的个数，这个方程可以解出两个区间来，然后区间求和，就是树转数组的强项了
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cassert>

#define pause cout << " press any key to continue...", cin >> chh
#define file_r(x) freopen(x, "r", stdin)
#define file_w(x) freopen(x, "w", stdout)
#define lowbit(x) ((x) & (-(x)))
#define two(i) (1LL << (i))

using namespace std;
int chh;

typedef long long LL;

const LL N = 1 << 16, M = 16;

LL n;
LL a[M][N + 5];

void add(LL i, LL x) {
    if (x < 1 || x > N) return;
    while (x <= N) {
        a[i][x]++;
        x += lowbit(x);
    }
}

LL cal(int i, int x) {
    LL res = 0;
    if (x < 1 || x > N) return 0;
    while (x > 0) {
        res += a[i][x];
        x -= lowbit(x);
    }
    return res;
}

int main() {
    LL i, j, inc, x, d, cas = 0, res, l, r;
    char ch;
    while (scanf("%lld", &n) != EOF) {
        if (n == -1) break;
        for (i = 0; i < M; i++)
            for (j = 1; j <= N; j++) a[i][j] = 0;
        for (i = 1; i <= n; i++) {
            scanf("%lld", &x);
            for (j = 0; j < M; j++) add(j, ((two(j + 1) - 1) & x) + 1);
        }
        inc = 0, res = 0;
        while (1) {
            scanf("%c", &ch);
            while (ch != 'Q' && ch != 'C' && ch != 'E') scanf("%c", &ch);
            if (ch == 'E') break;
            scanf("%lld", &x);
            if (ch == 'C') {
                inc = (inc + x) % N;
            } else {
                d = inc & (two(x + 1) - 1);
                l = two(x) - d + 1, r = two(x + 1) - d;
                res += cal(x, r) - cal(x, l - 1);
                l = two(x + 1) + two(x) - d + 1, r = N;
                if (l <= r) res += cal(x, r) - cal(x, l - 1);
            }
        }
        printf("Case %lld: %lld\n", ++cas, res);
    }
    return 0;
}

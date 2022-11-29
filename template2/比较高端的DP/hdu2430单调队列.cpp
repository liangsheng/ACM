#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define pause cout << " press any key to continue...", cin >> ch
#define file_r(x) freopen(x, "r", stdin)
#define file_w(x) freopen(x, "w", stdout)
using namespace std;
int ch;

typedef long long LL;

const int N = 1000005;

int T, n, p, k;
int r[N], cnt[N], odr[N], q[N];
LL s[N];

int main()
{
    int i, j, x, head, tail, id, cur, cas = 0;
    LL ans;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d%d", &n, &p, &k);
        s[0] = 0, ans = -1;
        memset(cnt, 0, sizeof(cnt));
        for (i = 1; i <= n; i++)
        {
            scanf("%d", &x);
            s[i] = s[i - 1] + (LL) x;
            r[i] = (int) (s[i] % p);
            cnt[r[i]]++;
            if (r[i] <= k) ans = max(ans, s[i]);
        }
        for (i = 1; i < p; i++) cnt[i] += cnt[i - 1];
        for (i = 1; i <= n; i++) odr[cnt[r[i]]--] = i;
        head = tail = 0, id = 1;
        for (i = 1; i <= n; i++)
        {
            cur = odr[i];   //这个忘记写，一直用i，WA了好几次
            while (head != tail && r[q[head]] < r[cur]) head++;
            while (id <= n && r[odr[id]] - r[cur] <= k)
            {
                while (head != tail && q[tail - 1] <= odr[id]) tail--;
                q[tail++] = odr[id];
                id++;
            }
            if (head !=tail)
            {
                if (q[head] != cur) ans = max(ans, s[q[head]] - s[cur]);
                else if (head + 1 != tail) ans = max(ans, s[q[head + 1]] - s[cur]);
            }
        }
        if (ans == -1) printf("Case %d: %d\n", ++cas, -1);
        else printf("Case %d: %lld\n", ++cas, ans / p);
    }
    return 0;
}

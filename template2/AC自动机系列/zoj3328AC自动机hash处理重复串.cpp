#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define LEN 100005
#define INF 999999
using namespace std;

const int N = LEN;
const int NODE = (LEN * 6);
const int CH = 26;

int end;
int chd[NODE][CH];
int work[NODE], fail[NODE], pre[NODE], hash[N], q[NODE];

int n;
char s[N], ch[10];
int f[NODE];
int cnt[N], cnt2[N], pos[N], len[N];

void init()
{
    int i;
    end = 1;
    memset(chd[0], -1, sizeof(chd[0]));
    work[0] = 0;
}

void add(char* str, int val)
{
    int i, id, p = 0;
    for (i = 0; str[i]; i++)
    {
        id = str[i] - 'a';
        if (chd[p][id] == -1)
        {
            memset(chd[end], -1, sizeof(chd[end]));
            work[end] = 0;
            chd[p][id] = end++;
        }
        p = chd[p][id];
    }
    if (work[p] == 0) work[p] = val;
    hash[val] = work[p];                //处理相同的串
}

void build()
{
    int i, j, p, v, head, tail;
    fail[0] = head = tail = 0;
    for (i = 0; i < CH; i++)
    {
        if (chd[0][i] != -1)
        {
            fail[chd[0][i]] = 0;
            q[tail++] = chd[0][i];
        }
        else chd[0][i] = 0;
    }
    while (head != tail)
    {
        p = q[head++];
        for (i = 0; i < CH; i++)
        {
            v = chd[p][i];
            if (v != -1)
            {
                fail[v] = chd[fail[p]][i];
                q[tail++] = v;
            }
            else chd[p][i] = chd[fail[p]][i];
        }
    }
}

int solve()
{
    int i, j, t, p = 0;
    memset(cnt, 0, sizeof(cnt));
    memset(cnt2, 0, sizeof(cnt2));
    memset(pos, -1, sizeof(pos));
    for (i = 0; i < end; i++)
    {
        pre[i] = 0;
        for (j = fail[i]; j; j = fail[j])
            if (work[j] != 0)
            {
                pre[i] = j;
                break;
            }
    }
    //cout << hash[2], system("pause");
    for (i = 0; s[i]; i++)
    {
        p = chd[p][s[i] - 'a'];
        for (j = p; j; j = fail[j])
        {
            if (work[j] == 0) continue;
            //cout << i << " " << j, system("pause");
            t = work[j];
            cnt[t]++;
            //cout << t << " " << cnt[t], system("pause");
            if (i - pos[t] >= len[t])
            {
                cnt2[t]++;
                pos[t] = i;
            }
        }
    }
    for (i = 1; i <= n; i++)
    {
        if (f[i]) printf("%d\n", cnt2[hash[i]]);
        else printf("%d\n", cnt[hash[i]]);
    }
    printf("\n");
    return 1;
}

int main()
{
    int i, j, cas = 0;
    while (scanf("%s", s) != EOF)
    {
        printf("Case %d\n", ++cas);
        scanf("%d", &n);
        init();
        for (i = 1; i <= n; i++)
        {
            scanf("%d%s", &f[i], ch);
            len[i] = strlen(ch);
            add(ch, i);
        }
        build();
        solve();
    }
    system("pause");
    return 0;
}

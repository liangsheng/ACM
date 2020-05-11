#include <iostream>
#include <cstdio>
#include <cstring>
#define N 1005
#define inf (1 << 30)
using namespace std;

struct Help
{
    int l;
    char c;  
};
       
int T, m, n;
int g[505][505], v[505], match[505];
Help myp[2005][2005];

int find(int x)
{
    int i, t;
    for (i = 1; i <= m; i++)
    {
        if (g[x][i] != 0 && v[i] == 0)
        {
            v[i] = 1;
            if (match[i] == -1 || find(match[i]))  
            {
                match[i] = x;
                return 1;         
            }       
        }
    }
    return 0;
}

int main()
{
    int i, j, x, y, ans;
    string ss;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &n, &m);
        memset(g, 0, sizeof(g));
        memset(myp, -1, sizeof(myp));
        memset(match, -1, sizeof(match));
        for (i = 1; i <= n; i++)
        {
            scanf("%d%d", &x, &y);
            cin >> ss;
            for (j = 0; j < ss.size(); j++)
            {
                myp[x][y].c = ss[j];
                myp[x++][y].l = i;
            }
        }
        for (i = 1; i <= m; i++)
        {
            scanf("%d%d", &x, &y);
            cin >> ss;
            for (j = 0; j < ss.size(); j++)
            {
                if (myp[x][y].l != -1 && ss[j] != myp[x][y].c)
                    g[myp[x][y].l][i] = 1;
                y++;
            }
        }   
        ans = 0;
        for (i = 1; i <= n; i++)
        {
            memset(v, 0, sizeof(v));
            if (find(i)) ans++;
        }
        printf("%d\n", n + m - ans);    
    }
    system("pause");
    return 0;
}

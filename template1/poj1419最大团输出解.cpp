#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int MAX=110;

bool map[MAX][MAX];   //图
int bestx[MAX]; //当前最优解
int x[MAX];  //当前解
int bestn; //当前最大顶点数
int cn;  //当前顶点数
int n, m;  //点数  边数

int dfs(int i)
{
    int j;
    if (i > n)
    {
        for (j = 1; j <= n; j++)
            bestx[j] = x[j];
        bestn = cn;   //cn的值是递增的
        return 1;
    }
    int flag = 1;
    for(j = 1; j < i; j++)
        if(x[j] == 1 && !map[j][i])
        {
            flag=0;
            break;
        }
    if (flag)
    {
        x[i] = 1;
        cn++;
        dfs(i + 1);
        cn--;
    }
    if (cn + n - i > bestn)   //剪枝，保证递增
    {
        x[i] = 0;
        dfs(i + 1);
    }
    return 1;
}

int main()
{
    int cases, i, j, u, v;
    scanf("%d",&cases);
    while (cases--)
    {
        scanf("%d%d",&n, &m);
        memset(map, 0, sizeof(map));
        for (i = 1; i <= m; i++)
        {
            scanf("%d%d",&u, &v);
            map[u][v] = map[v][u] = 1;
        }
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                if (i != j) map[i][j] =! map[i][j];
        bestn = cn = 0;
        memset(x, 0, sizeof(x));
        memset(bestx, 0, sizeof(bestx));
        dfs(1);  //从第一个点开始染色
        printf("%d\n", bestn);
        for (i = 1; i <= n; i++)
            if (bestx[i]) printf("%d ",i);
        printf("\n");
    }
    return 0;
}

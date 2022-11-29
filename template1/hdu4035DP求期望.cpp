/**
    dp求期望的题。
    题意：
    有n个房间，由n-1条隧道连通起来，实际上就形成了一棵树，
    从结点1出发，开始走，在每个结点i都有3种可能：
        1.被杀死，回到结点1处（概率为ki）
        2.找到出口，走出迷宫 （概率为ei）
        3.和该点相连有m条边，随机走一条
    求：走出迷宫所要走的边数的期望值。

    设 E[i]表示在结点i处，要走出迷宫所要走的边数的期望。E[1]即为所求。

    叶子结点：
    E[i] = ki*E[1] + ei*0 + (1-ki-ei)*(E[father[i]] + 1);
         = ki*E[1] + (1-ki-ei)*E[father[i]] + (1-ki-ei);

    非叶子结点：（m为与结点相连的边数）
    E[i] = ki*E[1] + ei*0 + (1-ki-ei)/m*( E[father[i]]+1 + ∑( E[child[i]]+1 ) );
         = ki*E[1] + (1-ki-ei)/m*E[father[i]] + (1-ki-ei)/m*∑(E[child[i]]) + (1-ki-ei);

    设对每个结点：E[i] = Ai*E[1] + Bi*E[father[i]] + Ci;

    对于非叶子结点i，设j为i的孩子结点，则
    ∑(E[child[i]]) = ∑E[j]
                   = ∑(Aj*E[1] + Bj*E[father[j]] + Cj)
                   = ∑(Aj*E[1] + Bj*E[i] + Cj)
    带入上面的式子得
    (1 - (1-ki-ei)/m*∑Bj)*E[i] = (ki+(1-ki-ei)/m*∑Aj)*E[1] + (1-ki-ei)/m*E[father[i]] + (1-ki-ei) + (1-ki-ei)/m*∑Cj;
    由此可得
    Ai =        (ki+(1-ki-ei)/m*∑Aj)   / (1 - (1-ki-ei)/m*∑Bj);
    Bi =        (1-ki-ei)/m            / (1 - (1-ki-ei)/m*∑Bj);
    Ci = ( (1-ki-ei)+(1-ki-ei)/m*∑Cj ) / (1 - (1-ki-ei)/m*∑Bj);

    对于叶子结点
    Ai = ki;
    Bi = 1 - ki - ei;
    Ci = 1 - ki - ei;

    从叶子结点开始，直到算出 A1,B1,C1;

    E[1] = A1*E[1] + B1*0 + C1;
    所以
    E[1] = C1 / (1 - A1);
    若 A1趋近于1则无解...
**/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <fstream>
#define inf (1 << 30)
#define mod 1000000007
#define N 10005
const double eps = 1e-12;
const double pi = acos(-1.0);
using namespace std;

struct NODE
{
    int u, v;
    int next;
};

int T, n, e;
int head[N], size[N];
double ki[N], ei[N], A[N], B[N], C[N], dp[N];
NODE edge[N * 2];

int add_edge(int u, int v)
{
    size[u]++;
    edge[e].u = u, edge[e].v = v;
    edge[e].next = head[u], head[u] = e++;
    return 1;
}

int DFS(int t, int p)
{
    int i, v;
    double tmp = 0.0;
    if (size[t] == 1 && p != -1)
    {
        A[t] = ki[t];
        B[t] = 1.0 - ki[t] - ei[t];
        C[t] = 1.0 - ki[t] - ei[t];
        //cout << t << " " << A[t] << " " << B[t] << " " << C[t], system("pause");
        return 1;
    }
    A[t] = ki[t];
    B[t] = (1.0 - ki[t] - ei[t]) / size[t];
    C[t] = 1.0 - ki[t] - ei[t];
    for (i = head[t]; i != -1; i = edge[i].next)
    {
        v = edge[i].v;
        if (v == p) continue;
        if (DFS(v, t) == 0) return 0;
        //if (t == 2) cout << size[t], system("pause");
        A[t] += B[t] * A[v];
        C[t] += B[t] * C[v];
        tmp += B[t] * B[v];
    }
    //if (t == 2) cout << B[t] / (1.0 - tmp), system("pause");
    if (fabs(tmp - 1.0) < eps) return 0;
    A[t] /= 1.0 - tmp;
    B[t] /= 1.0 - tmp;
    C[t] /= 1.0 - tmp;
    //cout << t << " " << A[t] << " " << B[t] << " " << C[t], system("pause");
    return 1;
}

int main()
{
    int i, j, h, x, y;
    scanf("%d", &T);
    for (h = 1; h <= T; h++)
    {
        scanf("%d", &n);
        e = 0;
        memset(head, -1, sizeof(head));
        memset(size, 0, sizeof(size));
        for (i = 1; i < n; i++)
        {
            scanf("%d%d", &x, &y);
            add_edge(x, y), add_edge(y, x);
        }
        for (i = 1; i <= n; i++)
        {
            scanf("%lf%lf", &ki[i], &ei[i]);
            ki[i] /= 100.0, ei[i] /= 100.0;
        }
        printf("Case %d: ", h);
        if (DFS(1, -1) && fabs(A[1] - 1.0) > eps) printf("%lf\n", C[1] / (1.0 - A[1]));
        else printf("impossible\n");
    }
    system("pause");
    return 0;
}

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
#define N 205
#define file_r(x) freopen(x, "r", stdin)
#define file_w(x) freopen(x, "w", stdout)
using namespace std;

struct NODE
{
    int v, next;
};

int T, cnt, e;
char input[10001];
int head[N], vis[N];
NODE edge[N * N];
map<string, int> q;

int init()
{
    e = cnt = 0;
    memset(head, -1, sizeof(head));
    q.clear();
    return 1;
}

int add_edge(int u, int v)
{
    edge[e].v = v;
    edge[e].next = head[u];
    head[u] = e++;
    return 1;
}

int bfs(int p1, int p2)
{
    int i, u, v;
    if (p1 == p2) return 1;
    memset(vis, 0, sizeof(vis));
    queue<int> bfs;
    bfs.push(p1), vis[p1] = 1;
    while (!bfs.empty())
    {
        u = bfs.front();
        bfs.pop();
        for (i = head[u]; i != -1; i = edge[i].next)
        {
            v = edge[i].v;
            if (vis[v] == 1) continue;
            if (v == p2) return 1;
            vis[v] = 1;
            bfs.push(v);
        }
    }
    return 0;
}

char ask(int p1, int p2)
{
    if (bfs(p1, p2)) return 'Y';
    return 'M';
}

int main()
{
    int i, size, cas = 0, f, p1, p2;
    char end;
    char a[20], b[20], verb[20];
    scanf("%d", &T);
    getchar();
    while (T--)
    {
        init();
        printf("Case #%d:\n", ++cas);
        while (1)
        {
            fgets(input, 10000, stdin);
            size = strlen(input);
            while (input[size - 1] < 32) size--;
            end = input[size - 1];
            if(end == '!') break;
            input[size - 1] = 0;
            int u = 0, x, y, ws = 0;
            for (; input[u]!=' '; u++);
            for (i=0; input[i]; i++) if(input[i] == ' ') ws++;
            if (end == '.')
            {
                if (input[u + 1] != 'w')
                {
                    sscanf(input, "%s %s %s", a, verb, b);
                    strcat(a, "n");
                    strcat(b, verb[0]=='a' ? "n" : "v");
                }
                else
                {
                    sscanf(input, "%*s %*s %*s %s %s %s", a, verb, b);
                    strcat(a, "v");
                    strcat(b, verb[0]=='a' ? "n" : "v");
                }
            }
            else
            {
                if(ws == 2)
                {
                    sscanf(input, "%s %s %s", verb, a, b);
                    strcat(a, "n");
                    strcat(b, verb[0]=='a' ? "n" : "v");
                }
                else
                {
                    sscanf(input, "%s %*s %*s %*s %s %s", verb, a, b);
                    strcat(a, "v");
                    strcat(b, verb[0]=='a' ? "n" : "v");
                }
            }
            if(q.find(a) == q.end()) x = q[a] = ++cnt;
            else x = q[a];
            if(q.find(b) == q.end()) y = q[b] = ++cnt;
            else y = q[b];
            if(end == '.') add_edge(x, y);
            else printf("%c", ask(x, y));
        }
        printf("\n");
    }
    return 0;
}

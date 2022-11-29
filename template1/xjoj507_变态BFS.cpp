#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#define W 105
#define H 105
using namespace std;

int w, h, t;
int mp[H * W][5], c[3], visit[H * W], ans[2][H * W], e[3];

int BFS(int u, int cnt)
{
    int i, front, v;
    queue <int> q;
    memset(visit, 0, sizeof(visit));
    ans[cnt][u] = 0;
    visit[u] = 1;
    q.push(u);
    while (! q.empty())
    {
        front = q.front();
        //cout << "front=" << front;
        //system("pause");
        for (i = 1; i <= mp[front][0]; i++)
        {   
            if (visit[mp[front][i]]) continue;
            v = mp[front][i];
            ans[cnt][v] = ans[cnt][front] + 1;
            visit[v] = 1;
            q.push(v);
            if (v == e[1] || v == e[2]) return ans[cnt][v];
        }
        q.pop();  
    }
    return 1;
}

int main()
{
    int i, j, size, u, v, x, y, maxi;
    string s;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &h, &w);
        memset(mp, 0, sizeof(mp));
        memset(c, 0, sizeof(c));
        memset(e, 0, sizeof(e));
        memset(ans, 0, sizeof(ans));
        getline(cin, s);
        for (i = 1; i <= h * 2 + 1; i++)
        {
            getline(cin, s);
            size = s.size();
            if (i == 1)
            {
                for (j = 1; j < 2 * w; j += 2)
                    if (s[j] != '-') e[0]++, e[e[0]] = (j + 1) / 2;
                continue;
            }
            if (i == 2 * h + 1)
            {
               for (j = 1; j < 2 * w; j += 2)
                   if (s[j] != '-') e[0]++, e[e[0]] = (h - 1) * w + (j + 1) / 2;   
               continue;
            }
            if (i % 2)
            {
                for (j = 1; j < 2 * w; j += 2)
                {
                    if (s[j] == '-') continue;
                    u = i / 2, v = (j + 1) / 2;
                    x = (u - 1) * w + v, y = u * w + v;
                    mp[x][0]++, mp[y][0]++;
                    mp[x][mp[x][0]] = y, mp[y][mp[y][0]] = x;
                    if (s[j] == '#')
                    {
                        e[++e[0]] = x;
                        e[++e[0]] = y;     
                    }
                }  
            }
            if (i % 2 == 0)
            {
                if (s[0] != '|') e[0]++, e[e[0]] = (i / 2 - 1) * w + 1;
                if (s[2 * w] != '|') e[0]++, e[e[0]] = (i / 2 - 1) * w + w;
                for (j = 1; j <= 2 * w - 1; j += 2)
                {
                    if (s[j] == '*')
                    {
                        c[++c[0]] = ((i / 2) - 1) * w + j / 2 + 1;
                        break;     
                    }
                }
                for (j = 2; j <= 2 * (w - 1); j += 2)
                {
                    if (s[j] == '|') continue;
                    u = i / 2, v = j / 2;
                    x = (u - 1) * w + v, y = x + 1;                
                    mp[x][0]++, mp[y][0]++;
                    mp[x][mp[x][0]] = y, mp[y][mp[y][0]] = x;                
                    if (s[j] == '#')
                    {
                        e[++e[0]] = x;
                        e[++e[0]] = y;     
                    }                
                }  
            }
        }
        if (e[0] == 1) e[e[0] + 1] = h * w + 1;
        maxi = BFS(c[1], 0) + 1;
        //cout << e[1] << " " << e[2];
        //system("pause");
        /*for (i = 1; i <= h * w; i++)
            ans[0][i] = ans[0][i] < ans[1][i] ? ans[0][i] : ans[1][i];
        maxi = 0;
        for (i = 1; i <= h * w; i++)
        maxi = max(maxi, ans[0][i]);*/ 
        printf("%d\n", maxi); 
    }  
    system("pause");
    return 0;
}

#include <iostream>
#include <cstdio>
#include <cstring>
#define N 2505
using namespace std;

struct NODE
{
    int x1, x2, y1, y2;
    int col;   
};
       
int n, m, c, len, s;
int a[N];
NODE r[200005];

int add(NODE temp)
{
    r[s + len] = temp;
    len++;
    return 1;
}

int pop()
{
    if (len == 1) s = 0, len = 0;
    else s++, len--;
    return 1;
}

int deal(NODE t)
{
    int i, vs = s, vlen = len;
    NODE temp, old;
    for (i = vs; i < vs + vlen; i++)
    {   
        pop();
        if (t.x1 > r[i].x2 || t.x2 < r[i].x1) 
        {
            add(r[i]);
            continue;
        }
        if (t.y1 > r[i].y2 || t.y2 < r[i].y1) 
        {
            add(r[i]);
            continue;
        }        
        old = r[i];
        if (t.x1 <= old.x1 && t.y1 <= old.y1 && t.x2 >= old.x2 && t.y2 >= old.y2) continue;
        if (old.x1 < t.x1)
        {
            temp = old;
            temp.x2 = t.x1 - 1;
            add(temp); 
            old.x1 = t.x1;
            //cout << temp.x1 << " " << temp.y1 << " " << temp.x2 << " " << temp.y2; system("pause");    
        }
        if (old.x2 > t.x2)
        {
            temp = old;
            temp.x1 = t.x2 + 1;
            add(temp);
            old.x2 = t.x2;
            //cout << temp.x1 << " " << temp.y1 << " " << temp.x2 << " " << temp.y2; system("pause");        
        }
        if (old.y1 < t.y1)
        {
            temp = old;
            temp.y2 = t.y1 - 1;
            add(temp);
            old.y1 = t.y1;
            //cout << temp.x1 << " " << temp.y1 << " " << temp.x2 << " " << temp.y2; system("pause");          
        }
        if (old.y2 > t.y2)
        {
            temp = old;
            temp.y1 = t.y2 + 1;
            add(temp);
            old.y2 = t.y2; 
            //cout << temp.x1 << " " << temp.y1 << " " << temp.x2 << " " << temp.y2; system("pause");        
        }
    }
    return 1;
}

int main()
{
    int i, j;
    NODE t;
    scanf("%d%d%d", &n, &m, &c);
    memset(a, 0, sizeof(a));
    memset(r, 0, sizeof(r));
    len = 0;
    s = 0;
    t.x1 = 1, t.y1 = 1, t.x2 = n, t.y2 = m, t.col = 1;
    add(t);
    for (i = 1; i <= c; i++)
    {
        scanf("%d%d%d%d%d", &t.x1, &t.y1, &t.x2, &t.y2, &t.col);
        t.x1++;
        t.y1++;
        deal(t);
        add(t);
    }
    for (i = s; i < s + len; i++)
    {
        //cout << i << " " << r[i].x1 << " " << r[i].y1 << " " << r[i].x2 << " " << r[i].y2 << " " << r[i].col;
        //system("pause");
        a[r[i].col] += (r[i].x2 - r[i].x1 + 1) * (r[i].y2 - r[i].y1 + 1);
    }
    for (i = 1; i <= 2500; i++)
    {
        if (a[i] != 0)
            printf("%d %d\n", i, a[i]);
    }
    system("pause");
    return 0;
}

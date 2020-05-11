#include <stdio.h>   
#include <stdlib.h>   
#include <vector>   
using namespace std;   
const int MaxN = 10001;   
const int INF = 0x7fffffff/2 - 1;   
typedef struct {    int dis , vex;  } ElemType;   
typedef struct {    int vex , dis;  }   Edge;   
typedef vector < Edge > VE;   
VE edge[MaxN];   
bool cmp(ElemType e1 , ElemType e2)   
{   
    return e1.dis < e2.dis;   
}   
class Heap   
{   
public:   
    Heap()      {n = 0;}   
    int min(int _a , int _b)    {   
        return a[_a].dis < a[_b].dis ? _a : _b;   
    }   
   void push(ElemType e)   {   
        for (i = ++ n;i > 1 && cmp(e , a[i >> 1]);i >>= 1)   {   
            a[i] = a[i >> 1];   
        }   
        a[i] = e;   
   }   
   void pop()  {   
        ElemType e = a[n];   
       for (i = 2;i < n;i <<= 1)  {   
           if (i < n - 1)   {   
               i = min(i , i + 1);   
            }   
            if (cmp(e , a[i])) break;   
            a[i >> 1] = a[i];   
        }   
        a[i >> 1] = a[n --];   
    }   
    ElemType top()  {   
        return a[1];   
    }   
    bool empty()    {   
        return !n;   
    }   
private:   
    ElemType a[MaxN];   
    int n , i;   
};   
void dijkstra(int nvex , int st)   
{   
    Heap h;   
    Edge e;   
    ElemType  tmp;   
    int dis[ MaxN ] , i , now;   
    bool visited[ MaxN ] = {0};   
       
    tmp.dis = 0;   
    tmp.vex = st;   
    h.push(tmp);   
    for (i = 0;i < nvex;i ++)    dis[ i ] = INF;   
    dis[ st ] = 0;   
    while (!h.empty())  {   
        tmp = h.top();h.pop();   
        now = tmp.vex;   
        if (!visited[ now ])    {   
            visited[ now ] = true;   
            for (i = 0;i < (int)edge[ now ].size();i ++) {   
                e = edge[ now ][ i ];   
                if (!visited[ e.vex ] && dis[ now ] + e.dis < dis[ e.vex ])  {   
                    tmp.dis = dis[ tmp.vex = e.vex ] = dis[ now ] + e.dis;   
                    h.push(tmp);   
                }   
            }   
        }   
    }   
    for (i = 0;i < nvex;i ++)    {   
        if (dis[ i ] == INF)    {   
            printf("-1 ");   
        }   else    {   
            printf("%d " , dis[ i ]);   
        }   
    }   
}   
void __test()   
{   
    Edge e;   
    int n , m , i , a , b , c;   
       
    scanf("%d%d" , &n , &m);   
    for (i = 0;i < n;i ++)   {   
        edge[i].clear();   
    }   
    for (i = 0;i < m;i ++)   {   
        scanf("%d%d%d" , &a , &b , &e.dis);   
        e.vex = b;edge[a].push_back(e);   
        e.vex = a;edge[b].push_back(e);   
    }   
    scanf("%d" , &a);   
    dijkstra(n , a);   
}   
int main()   
{   
    __test();   
}   

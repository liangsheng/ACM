#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#define mod 1000000007
#define N 1000005
#define inf (1 << 30)
const double eps = 1e-12;
const double pi = acos(-1.0);
using namespace std;

struct Point
{
    int id, v;
    Point() {}
    Point(int X, int Y): id(X), v(Y) {}
};

struct Line
{
    int sp, i, le;
    Point p[N];
    Line() {}
    void init()
    {
        sp = -1;
        i = le = 0;
    }

    bool insert(Point P)
    {
        while (sp > i && p[sp].v < P.v) sp--;
        if (sp == i && p[i].v < P.v) p[i] = P;
        else  p[++sp] = P;
        return true;
    }

    bool pop()
    {
        if (sp == -1) return false;
        le++;
        return true;
    }

    bool solve()
    {
        if (sp == -1) printf("-1\n");
        else
        {
            while (i <= sp && p[i].id <= le) i++;
            if (i > sp)
            {
                i = 0, sp = -1;
                printf("-1\n");
                return true;
            }
            printf("%d\n", p[i].v);
        }
        return true;
    }
} line;

int T;

int main()
{
    int i, v, t;
    char cmd[10];
    scanf("%d", &T);
    while (T--)
    {
        line.init();
        t = 0;
        while (scanf("%s", cmd))
        {
            if (cmd[0] == 'S') continue;
            if (cmd[0] == 'E') break;
            if (cmd[0] == 'C')
            {
                t++;
                scanf("%s%d", cmd, &v);
                line.insert(Point(t, v));
                //line.out();
            }
            else if (cmd[0] == 'Q')
            {
                //line.out();
                //cout << "()()(" << endl;
                line.solve();
            }
            else if (cmd[0] == 'G') line.pop(); //line.out();
        }
    }
    system("pause");
    return 0;
}

#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;
#define size 50000
#define eps 1e-8
#define sqr(x) ((double)(x) * (x))

int Left[size], Right[size], Up[size], up_rank[size];
int X[size], Y[size], R[size];
int t, n;
double mid;

set<int> mytree;
typedef set<int>::iterator it;

bool cmp_left(const int &a, const int &b){return (X[a] - R[a] < X[b] - R[b]);}
bool cmp_right(const int &a, const int &b){return (X[a] + R[a] < X[b] + R[b]);}
bool cmp_up(const int &a, const int &b){if (Y[a] == Y[b]) return X[a] < X[b]; else return Y[a] < Y[b];}

bool collid(int a, int b)
{
    a = Up[a];
    b = Up[b];
    return (sqr(X[a] - X[b]) + sqr(Y[a] - Y[b]) - sqr(R[a] + R[b] + mid + mid) <= 0);
}

bool insert(int &id)
{
    it i = mytree.insert(id).first;
    if (i != mytree.begin())
    {
        if (collid(id, *--i))
            return false;
        ++i;
    }
    if (++i != mytree.end())
    {
        if (collid(id, *i))
            return false;
    }
    return true;
}

bool judge()
{
    mytree.clear();
    int l = 0, r = 0;
    while(l < n || r < n)
    {
        if (r == n||l != n && (X[Right[r]] + R[Right[r]] + mid) - (X[Left[l]] - R[Left[l]] - mid) >= 0)
        {
            if (!insert(up_rank[Left[l++]])) return true;
        }
        else mytree.erase(up_rank[Right[r++]]);
    }
    return false;
}

double jeogia()
{
    for(int i = 0; i < n; i++)
        Left[i] = Right[i] = Up[i] = i;
    sort(Left, Left + n, cmp_left);
    sort(Right, Right + n, cmp_right);
    sort(Up, Up + n, cmp_up);
    for(int i = 0; i < n; i++)
        up_rank[Up[i]] = i;
    double s = 0, t = sqrt(sqr(X[0] - X[1]) + sqr(Y[0] - Y[1])) - R[0] - R[1];
    while(t - s >= eps)
    {
        mid = (s + t) * 0.5; //mid 为各个圆需要加上的半径长度
        if (judge()) t = mid;//是否有圆相交
        else s = mid;
    }
    return t + s;
}

int main()
{
    scanf("%d", &t);
    while(t-- && scanf("%d", &n))
    {
        for(int i = 0; i < n; i++)
            scanf("%d%d%d", &X[i], &Y[i], &R[i]);
        printf("%.6f\n", jeogia());
    }
    return 0;
}

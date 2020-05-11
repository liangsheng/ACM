#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 20005
#define INF 999999
using namespace std;

struct Node
{
    int w, h;
};

bool operator < (Node p1, Node p2)
{
    if (p1.w != p2.w) return p1.w > p2.w;
    return p2.h > p1.h;
}

int T, n;
int b[N];
Node a[N];

//lower_bound()第一个大于等于val的数的下标
int get_gef(int *a, int p1, int p2, int val)  //great, equals, first
{
    int l = p1, r = p2, mid;
    while (l < r)
    {
        mid = (l + r) >> 1;
        if (a[mid] >= val) r = mid;
        else l = mid + 1;
    }
    if (a[r] < val) return r + 1;
    return r;
}

//upper_bound()第一个大于val的数的下标
int get_gf(int *a, int p1, int p2, int val)
{
    int l = p1, r = p2, mid;
    while (l < r)
    {
        mid = (l + r) >> 1;
        if (a[mid] > val) r = mid;
        else l = mid + 1;
    }
    if (a[r] <= val) return r + 1;
    return r;
}

int main()
{
    int i, j, len, mid, t;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        for (i = 0; i < n; i++) scanf("%d%d", &a[i].w, &a[i].h);
        sort(a, a + n);
        memset(b, 0, sizeof(b));
        b[1] = a[0].h;
        len = 1;
        for (i = 1; i < n; i++)
        {
            //第一个大于val的下标
            //t = upper_bound(b + 1, b + len + 1, a[i].h) - b;
            t = get_gf(b, 1, len, a[i].h);
            if (t == len + 1) b[++len] = a[i].h;
            else b[t] = a[i].h;
        }
        printf("%d\n", len);
    }
    system("pause");
    return 0;
}

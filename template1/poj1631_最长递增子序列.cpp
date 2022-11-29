#include <iostream>
#include <cstdio>
#include <cstring>
#define N 40005
using namespace std;

int T, n;
int a[N], c[N];

int find(int len, int x)
{
    int left = 1, right = len, mid;
    while (left <= right)
    {
        mid = (left + right) >> 1;
        if (x >= c[mid]) left = mid + 1; //×î³¤µÝÔö:x > c[mid] 
        else right = mid - 1;  
    }
    return left;
}

int main()
{
    int i, len, t;
    scanf("%d", &T);    
    while (T--)
    {
        scanf("%d", &n); 
        memset(c, -1, sizeof(c));
        for (i = 1; i <= n; i++)
            scanf("%d", &a[i]);  
        c[1] = a[1];
        len = 1;
        for (i = 2; i <= n; i++)
        {
            t = find(len, a[i]);
            c[t] = a[i];
            if (t > len) len = t;
        } 
        printf("%d\n", len);  
    }
    system("pause");
    return 0;
}

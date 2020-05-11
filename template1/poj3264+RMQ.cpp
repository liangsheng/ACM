# include <iostream>
# include <cstdio>
# include <cmath>
# define N 50005
# define Q 200005
# define DEP 20
using namespace std;

int n, m;
int a[N], s_max[DEP][N], s_min[DEP][N];

int RMQ_Init()
{
     int i, j, t, m;    
     m = floor(log(double(n)) / log(2.0));       
     for (j = t = 1; j <= m; j++, t *= 2)    
     {        
         for(i = 0; i < n - t; i++) s_min[j][i] = min(s_min[j - 1][i], s_min[j - 1][i + t]);        
         for(i = n - t; i < n; i++) s_min[j][i] = s_min[j - 1][i];    
     }
     for (j = t = 1; j <= m; j++, t *= 2)
     {
         for (i = 0; i < n - t; i++) s_max[j][i] = max(s_max[j - 1][i], s_max[j - 1][i + t]);
         for (i = n - t; i < n; i++) s_max[j][i] = s_max[j - 1][i];
     }    
     return 1;
}

int RMQ_Query(int i, int j)
{
     int x1, x2;
     if(i == j) return 0;    
     if (j < i) j += i, i = j - i, j -= i;    
     int m = floor(log(double(j - i)) / log(2.0));    
     x1 = min(s_min[m][i], s_min[m][j - (1 << m) + 1]); 
     x2 = max(s_max[m][i], s_max[m][j - (1 <<m ) + 1]);
     return x2 - x1;   
}

int main()
{
    int i, j, x, y, ans;
    scanf("%d%d", &n, &m);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &s_max[0][i]);
        s_min[0][i] = s_max[0][i];
    }
    RMQ_Init();
    for (i = 1; i <= m; i++)
    {
        scanf("%d%d", &x , &y);
        ans = RMQ_Query(x - 1, y - 1);
        printf("%d\n", ans);
    }
    system("pause");
    return 0;
}

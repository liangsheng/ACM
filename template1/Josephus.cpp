# include <iostream>
# include <cstdio>
using namespace std;

int main()
{
    int n, k, m;
    while( scanf("%d%d%d", &n, &k, &m), n || k || m )
    {
        int i, d, s=0;
        for( i=2; i <= n; ++i ) s = (s+k)%i;
        k = k%n; if( k == 0 ) k=n;
        d = (s+1) + (m-k);
        if( d >= 1 && d <= n ) 
        printf("%d\n", d);
        else 
        if( d < 1 ) 
        printf("%d\n", n+d);
        else 
        if( d > n ) 
        printf("%d\n", d%n);
    }
    system("pause");
    return 0;
}

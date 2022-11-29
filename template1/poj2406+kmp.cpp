# include <iostream>
# include <cstdio>
# include <cstring>
# define N 1000010
using namespace std;

char s[N]; 
int fail[N];

int main()
{
    int i,k,n;
    char a[2]=".";
    while (scanf("%s",&s)!=EOF)
    {
         if (strcmp(a,s)==0) break;
         n=strlen(s);
         memset(fail,-1,sizeof(fail));
         for (i=1;s[i];++i)
         {
             for (k=fail[i-1];k>=0&&s[i]!=s[k+1];k=fail[k]);
             if (s[k+1]==s[i]) fail[i]=k+1;
         }
         if (n%(n-fail[n-1]-1)==0)
         printf("%d\n",n/(n-fail[n-1]-1));
         else
         printf("1\n"); 
    }
    system("pause");
    return 0;
}

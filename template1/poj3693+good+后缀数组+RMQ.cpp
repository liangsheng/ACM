#include <iostream>
#include <cmath>
using namespace std;
const int MAX_LEN = 100001;
const int MAX_DEP = 20;
int wa[MAX_LEN], wb[MAX_LEN], wv[MAX_LEN], wd[MAX_LEN], Height[MAX_LEN], sa[MAX_LEN], rank[MAX_LEN];
int s[MAX_DEP][MAX_LEN];
int n;

inline bool IsEqual(int *r, int a, int b, int l)
{    
     return (r[a] == r[b] && r[a + l] == r[b + l]);
}

void da(int *r, int m = 27)
{    
     int i, j, p, *x = wa, *y = wb, *t;
     memset(wd, 0, sizeof(wd));    
     for (i = 0; i < n; i++) wd[x[i] = r[i]]++; x[n] = y[n] = 0;    
     for (i = 1; i < m; i++) wd[i] += wd[i - 1];    
     for (i = n - 1; i >= 0; i--) sa[--wd[x[i]]] = i;    
     for (p = 1, j = 1; p <= n; m = p, j *= 2)    
     {        
         for(p = 0, i = n - j; i < n; i++) y[p++] = i;        
         for(i = 0; i < n; i++)if(sa[i] >= j)y[p++] = sa[i] - j;       
         for(i = 0; i < n; i++) wv[i] = x[y[i]];        
         memset(wd, 0, sizeof(wd));        
         for(i = 0; i < n; i++) wd[wv[i]]++;        
         for(i = 1; i < m; i++) wd[i] += wd[i - 1];        
         for(i = n - 1; i >= 0; i--) sa[--wd[wv[i]]] = y[i];        
         for(t = x, x = y, y = t, i = 1, p = 2,x[sa[0]] = 1; i < n; i++)            
         x[sa[i]] = IsEqual(y, sa[i-1], sa[i], j) ? p - 1 : p++;    
     }
}

void CalHeight(int *r)
{    
     int i, j, k;    
     for (i = 0; i < n; i++)rank[sa[i]] = i;    
     for (i = 0, Height[0] = k = 0; i < n; Height[rank[i++]] = k)        
     for (k?k--:0, j=(rank[i]>0)?sa[rank[i]-1]:0; rank[i]>0&&r[i+k]==r[j+k]; k++);
}

void RMQInit()
{    
     int i, j, t, m;    
     m = floor(log(double(n)) / log(2.0));    
     for(i = 0; i < n; i++) s[0][i] = Height[i];    
     for (j = t = 1; j <= m; j++, t *= 2)    
     {        
         for(i = 0; i < n - t; i++)s[j][i] = min(s[j-1][i], s[j-1][i + t]);        
         for(i = n - t; i < n; i++)s[j][i] = s[j-1][i];    
     }
}

int RMQQuery(int i, int j)
{    
     if(i == j) return n - sa[i];    
     if (j < i) j += i, i = j - i, j -= i;    
     int m = floor(log(double(j - i)) / log(2.0));    
     return min(s[m][i + 1], s[m][j - (1 << m) + 1]);
}

int main()
{    
     char str[MAX_LEN];    
     int r[MAX_LEN];    
     int i, j, k, s, maxn, len, l, sp, t, tsp, iter = 0;    
     while(scanf("%s", str) && str[0] != '#')    
     {        
         n = strlen(str), maxn = 0, iter++;        
         memset(r, 0, sizeof(r));        
         for (i = 0; i < n; i++)r[i] = str[i] - 'a' + 1;        
         da(r);        
         CalHeight(r); 
         for (i = 0; i < n; i++) cout << Height[i] << " "; system("pause");       
         RMQInit();        
         for (i = 1; i <= n / 2; i++)            
         for (j = i; j < n; j += i)            
         {                
             len = RMQQuery(rank[j - i], rank[j]);                
             tsp = (len || rank[j - i] < rank[j]) ? j - i : j;                
             cout << len << " " << tsp; system("pause");
             for (k = j - i - 1, s = 0; k >= 0 && k > (j - 2 * i) && r[k] == r[k + i];k--)                   
             if(++s == (i-(len%i)))tsp = k;                    
             else if(rank[tsp] > rank[k])tsp = k;                            
             l = (s + len)/i + 1;                
             if(l > maxn) maxn = l, sp = tsp, t = i;                
             else if(l == maxn && rank[sp] > rank[tsp])maxn = l, sp = tsp, t = i;            
             cout << "sgsgsgs"; system("pause");
         }        
         printf("Case %d: ", iter);        
         for (i = 0; i < maxn * t; i++)
         printf("%c", str[sp + i]);        
         printf("\n");    
     }
     system("pause");    
     return 0;
}

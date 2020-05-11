#include <iostream>
#include <cstdio>
#include <cmath>
#define M 55
#define inf (1 << 30)
const int head = 0;
const int V = M * M;
const double eps = 1e-7;
using namespace std;

int T, n, m, Limit, size, ans, t;
int R[V], L[V], U[V], D[V], C[V], RR[V], visit[M];
int S[V], H[V];
int mc[26][3], g[26][3][26][3], neb[M];

int Remove(int c)
{
    int i;//Ö»É¾³ı¸ÃÁĞ
    if (H[RR[c]] == c) H[RR[c]] = R[c];
    for (i = D[c]; i != c; i = D[i])
    {
		if (H[RR[i]] == i) H[RR[i]] = R[i];
		L[R[i]] = L[i], R[L[i]] = R[i];
	}
    return 1;
}

int Resume(int c)
{
    int i;
    if (H[RR[c]] == R[c]) H[RR[c]] = c;
    for (i = U[c]; i != c; i = U[i])
    {		
		L[R[i]] = R[L[i]] = i;
		if (H[RR[i]] == R[i]) H[RR[i]] = i; 
	}	
    return 1;
}

int Remove2(int r)
{
	int i;
	U[D[r]] = U[r], D[U[r]] = D[r], S[C[r]]--;
	for (i = R[r]; i != r; i = R[i])
		U[D[i]] = U[i], D[U[i]] = D[i], S[C[i]]--;
	return 1;
}

int Resume2(int r)
{
	int i;
	U[D[r]] = D[U[r]] = r, S[C[r]]++;
	for (i = R[r]; i != r; i = R[i])
	    U[D[i]] = D[U[i]] = i, S[C[r]]++;
	return 1;
}

int h()
{
    int r = 0, i, j, k;
    int hash[M];
    memset(hash, 0, sizeof(hash));
    for (i = R[head]; i !=head; i = R[i])
    {
        if (!hash[i])
        { 
            r++;
            hash[i] = 1;
            for (j = D[i]; j != i ;j =D[j])
                for (k = R[j]; k != j; k = R[k]) hash[C[k]] = 1;
        }
    }
    return r;
}

int Dance(int k)
{
    int i, j, min, c;
    if (k + h() >= ans) return 0;
    if (R[head] == head) 
    {
		if (k < ans) ans = k;
        return 1;        
    }    
    for (i = R[head], c = 0, min = M; i != head; i = R[i])
        if (S[i] < min) min = S[i], c = i;
    for (i = D[c]; i != c; i = D[i])
    {
        //visit[RR[i]] = 1;
		Remove(i);
        for (j = R[i]; j != i; j = R[j])  Remove(j);
        if (neb[RR[i]] != -1) Remove2(H[neb[RR[i]]]);
        Dance(k + 1);
        if (neb[RR[i]] != -1) Resume2(H[neb[RR[i]]]);
		for (j = L[i]; j != i; j = L[j]) Resume(j);
        Resume(i);
        //visit[RR[i]] = 0;
    }
    return 1;
}

int Link(int r, int c)
{
	S[c]++, C[size] = c, RR[size] = r;
    U[size] = U[c], D[U[c]] = size;
    D[size] = c, U[c] = size;
    if (H[r] == -1) L[size] = R[size] = H[r] = size;
    else
    {
        L[size] = L[H[r]], R[L[H[r]]] = size;
        R[size] = H[r], L[H[r]] = size;
    }
    size++;
    return 1;
}

int Build_map()
{
	int i, j, ii, jj;
	memset(visit, 0, sizeof(visit));
	memset(H, -1, sizeof(H));
	Limit = n;
    for (i = 0; i <= t; i++)
    {
        S[i] = 0, U[i] = D[i] = i;
        R[i] = i + 1, L[i + 1] = i;
    }
    R[t] = 0;
    size = t + 1;
    ans = Limit;
    for (i = 1; i <= t; i++)
    {
		for (j= 1; j <= 2; j++)
		{
			if (mc[i][j] == -1) continue;
			g[i][j][i][j] = 1;
			if (neb[mc[i][j]] != -1)
			   g[i][j][i][j + neb[mc[i][j]] - mc[i][j]] = 1;
		}
	}
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= 2; j++)
		{
			if (mc[i][j] == -1) continue;
			for (ii = 1; ii <= n; ii++)
			{
				for (jj = 1; jj <= 2; jj++)
				{
					if (g[i][j][ii][jj] == 1)
						Link(mc[i][j], mc[ii][jj]);
				}
			}
		}
	}
	return 1;
}

int main()
{
    int i, j, k, mm, x, y, cas = 0;
    scanf("%d", &T);
    while (T--)
    {
        cas++;
	    scanf("%d", &n);
	    memset(mc, -1, sizeof(mc));
	    memset(g, -1, sizeof(g));
	    memset(neb, -1, sizeof(neb));
	    t = 0;
        for (i = 1; i <= n; i++)
        {
            scanf("%d", &m);
            for (j = 1; j <= m; j++)
            {
                t++;
                mc[i][j] = t;
                if (m == 1) neb[t] = -1;
                else neb[t] = (j == 1 ? t + 1 : t - 1);
				scanf("%d", &mm);
                for (k = 1; k <= mm; k++)
                {
                    scanf("%d%d", &x, &y);
                    g[i][j][x + 1][y + 1] = 1;
				}
            }
        }
        Build_map();
        Dance(0);
        printf("Case %d: %d\n", cas, ans);
    }
    system("pause");
    return 0; 
} 

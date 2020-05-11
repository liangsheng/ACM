#include <iostream>
#include <cstdio>
#include <cmath>
#define M 55
const int head = 0;
const int V = M * M;
const double eps = 1e-7;
using namespace std;

struct Point
{
    double x, y;   
};

int T, n, m, Limit, size;
int R[V], L[V], U[V], D[V], C[V];
int S[V], H[V];
Point radar[M];
Point city[M];

double dis(Point p1, Point p2)
{
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);  
}

int Remove(int c)
{
	int i;//Ö»É¾³ı¸ÃÁĞ
	for (i = D[c]; i != c; i = D[i])
		L[R[i]] = L[i], R[L[i]] = R[i];
	return 1;
}

int Resume(int c)
{
	int i;
	for (i = U[c]; i != c; i = U[i])
		L[R[i]] = R[L[i]] = i;
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
			for (j  =D[i]; j !=i ;j =D[j])
				for (k = R[j] ;k !=j ;k = R[k]) hash[C[k]] = 1;
		}
	}
	return r;
}

int Dance(int k)
{
	int i, j, min, c;
	if (k + h() > Limit) return 0;
	if (R[head] == head) return 1;	
	for (i  =R[head], c = 0, min = M; i != head; i = R[i])
		if (S[i]<min) min = S[i], c = i;	
	for (i = D[c]; i != c; i = D[i])
    {
		Remove(i);
		for (j = R[i]; j != i; j = R[j]) Remove(j);
		if (Dance(k+1)) return 1;
		for (j = L[i]; j != i; j = L[j]) Resume(j);
		Resume(i);
	}
	return 0;
}

int Link(int r, int c)
{
	S[c]++, C[size] = c;
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

int solve(double rr)
{
    int i, j;
    for (i = 0; i <= n; i++)
    {
        S[i] = 0, U[i] = D[i] = i;
        R[i] = i + 1, L[i + 1] = i;
    }
    R[n] = 0, size = n + 1;
    memset(H, -1, sizeof(H));
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
            if (dis(radar[i], city[j]) <= rr) Link(i, j + 1);
    }
    for (i = 1; i <= n; i++)
        if (S[i] == 0) return 0;
    return Dance(0);
}

int main()
{
    int i, j;
    double up, low, mid;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d%d", &n, &m, &Limit);
        for (i = 0; i < n; i++)
            scanf("%lf%lf", &city[i].x, &city[i].y);
        for (j = 0; j < m; j++)
            scanf("%lf%lf", &radar[j].x, &radar[j].y);
        low = 0.000001, up = 1416.0;
        while (low + eps < up)
        {
            mid = (low + up) * 0.5;
            if (solve(mid * mid)) up = mid;
            else low = mid;  
        }  
        printf("%lf\n", up);
    }
    system("pause");
    return 0; 
} 

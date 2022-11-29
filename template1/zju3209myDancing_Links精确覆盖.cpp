#include <iostream>
#include <cstdio>
#include <cstring> 
#define M 910          //矩阵列数 
#define N 510          //矩阵行数 
const int V = N * M;   //最大节点数 
const int head = 0;    //最终hed节点 
using namespace std;

int T, n, m, p;
int ans, size;
int U[V], D[V], L[V], R[V] ,C[V];  //C指向该列head节点 
int S[M], H[M];   //S表示该列的大小 H用来帮助构造横向双向环状链表 

int Remove(int c)
{
	int i, j;
	L[R[c]] = L[c], R[L[c]] = R[c];
	for (i = D[c]; i != c; i = D[i])
    {
		for( j = R[i]; j != i; j=R[j])
        {
			S[C[j]]--;
			U[D[j]] = U[j];
			D[U[j]] = D[j];
		}
	}
	return 1;
}

int Resume(int c)
{
	int i, j;
	for(i = U[c]; i != c; i = U[i])
    {
		for(j = L[i]; j != i; j = L[j])
        {
			S[C[j]]++;
			U[D[j]] = D[U[j]] = j;
		}
	}
	L[R[c]] = R[L[c]] = c;
	return 1;
}

int Dance(int k)
{
	int min, i, j, c;
	if(R[head] == head)
    {
		if(k < ans) ans = k;
		return 1;
	}
	for(min = M, c = 0, i = R[head]; i != head; i = R[i])
		if(S[i] < min) min = S[i], c = i;
	Remove(c);
	for(i = D[c]; i != c; i = D[i])      //枚举可选的每一行 
    {
		for(j = R[i]; j != i; j = R[j]) Remove(C[j]);
		Dance(k+1);
		for(j = L[i]; j != i; j = L[j]) Resume(C[j]);
	}
    Resume(c);
    return 1;
}

int Link(int r, int c)
{
    S[c]++, C[size] = c;
	U[size] = U[c], D[U[c]] = size;
	D[size] = c, U[c] = size;  
	if(H[r] == -1)  L[size] = R[size] = H[r] = size;
	else
    {
		L[size] = L[H[r]], R[L[H[r]]] = size;
		R[size] = H[r], L[H[r]] = size;
	}
    size++;  
    return 1;    
}

int main()
{
    int i, j, x0, x1, y0, y1, x, y;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d%d", &n, &m, &p);
        m = n * m;    //矩阵的列 
        n = m / n;    //矩阵的行
        for (i = 0; i <= m; i++)
        {
            S[i] = 0, U[i] = D[i] = i;
            L[i + 1] = i, R[i] = i + 1;
        } 
        R[m] = 0, size = m + 1;
        memset(H, -1, sizeof(H));
        for (i = 0; i < p; i++)
        {
            scanf("%d%d%d%d", &x0, &y0, &x1, &y1);
            for (x = x0; x < x1; x++)
            {
                for (y = y0 + 1; y <= y1; y++) 
                    Link(i, x * n + y);      //行号, 列号 
            }
        }
        ans = M;
        Dance(0);
        printf("%d\n", ans == M ? -1 : ans);
    }
    system("pause");
    return 0; 
} 

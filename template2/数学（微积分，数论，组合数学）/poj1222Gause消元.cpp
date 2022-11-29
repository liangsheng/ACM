#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define pause cout << " press any key to continue...", cin >> ch
#define file_r(x) freopen(x, "r", stdin)
#define file_w(x) freopen(x, "w", stdout)

using namespace std;
int ch;

const int N = 35;

int T, n;
int ans[N];
int a[5][6], id[5][6], matrix[N][N];
int dir[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};

void gause() {
    int i, j, k, a, b, sum, row = 0, col = 0;
    while (row < n && col < n) {
        for (i = row, j = -1; i < n; i++)
            if (matrix[i][col] != 0) {
                j = i;
                break;
            }
        for (i = col; i <= n; i++) swap(matrix[row][i], matrix[j][i]);
        a = matrix[row][col];
        for (i = row + 1; i < n; i++) {
            b = matrix[i][col];
            for (j = col; j <= n; j++)
                matrix[i][j] = (matrix[i][j] * a - matrix[row][j] * b) % 2;   //%2是对于该题的特殊
        }
        row++, col++;
    }
    i = row - 1, j = n - 1;
    while (i >= 0) {
        sum = 0;
        for (k = j + 1; k < n; k++)
            sum += matrix[i][k] * ans[k];
        ans[j] = (matrix[i][n] - sum) / matrix[i][j];
        ans[j] %= 2;     //%2是对于该题的特殊
        i--, j--;
    }
}

void solve()
{
    int i,j,k;
    int row,col,sum,a,b;
    row = 0; col = 0;
    while(row < n && col < n)
    {
        for(i = row,j = -1; i < n; i++)
            if(matrix[i][col] != 0)
            {
                j = i; break;
            }
		//第i次循环消解第i个未知数，因为可能在第i个表达式中第i个未知数的系数是0
		//则无法利用该行的此位消解下面行的改为，则需要找出一行是非0的，然后交换当
		//前行和该行,这样再进行消解
        for(i = col; i <= n; i++)
        {
            k = matrix[row][i];
            matrix[row][i] = matrix[j][i];
            matrix[j][i] = k;
        }
		//进行对第row个未知数的消解
        a = matrix[row][col];
        for(i = row+1; i < n; i++)
        {
            b = matrix[i][col];
            for(j = col; j <= n; j++)
                matrix[i][j] = (matrix[i][j]*a-matrix[row][j]*b)%2;
        }
        row++; col++;
    }
    i = row-1; j = n-1;
	//计算每个未知数
	//从后往前，每次把xi的值记录在ans[i]中，
	//那么当计算xk时，先求出xk后面的值的和，然后将结果减去这个和
	//然后xk的系数除以这个差结果
	//最后将这个结果存到ans[k]中，完毕！
    while(i >= 0)
    {
        sum = 0;
        for(k = j+1; k < n; k++)
            sum = sum + matrix[i][k]*ans[k];
        ans[j] = (matrix[i][n] - sum)/matrix[i][j];
        ans[j] %= 2;
        i--; j--;
    }
    for(i = 0; i < n; i++) ans[i] = (ans[i] + 2) % 2;
}

int main() {
    int i, j, k, u, v, e, x, y, cas = 0;
    scanf("%d", &T);
    while (T--) {
        e = 0;
        memset(matrix, 0, sizeof(matrix));
        n = 30;
        for (i = 0; i < 5; i++)
            for (j = 0; j < 6; j++) {
                scanf("%d", &a[i][j]);
                id[i][j] = e++;
                matrix[e - 1][n] = a[i][j];
            }
        for (i = 0; i < 5; i++)
            for (j = 0; j < 6; j++) {
                u = id[i][j];
                matrix[u][u] = 1;
                for (k = 0; k < 4; k++) {
                    x = i + dir[k][0], y = j + dir[k][1];
                    if (x < 0 || x >= 5 || y < 0 || y >= 6) continue;
                    v = id[x][y];
                    matrix[u][v] = 1;
                }
            }
        printf("PUZZLE #%d\n", ++cas);
        gause();
        for (i = 0; i < n; i++) ans[i] = (ans[i] + 2) % 2;
        for (i = 0; i < 5; i++)
            for (j = 0; j < 6; j++) {
                printf("%d", ans[i * 6 + j]);
                if (j == 5) printf("\n");
                else printf(" ");
            }
    }
    return 0;
}

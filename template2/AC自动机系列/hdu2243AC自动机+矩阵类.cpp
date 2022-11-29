#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define N 105
#define M 15
#define mod 100000
using namespace std;

typedef unsigned __int64 ULL;

struct Mat
{
    int size;
    int mat[N][N];

    void e()
    {
        int i, j;
        memset(mat, 0, sizeof(mat));
        for(i = 0; i < size; i++) mat[i][i] = 1;
    }

    void clr()
    {
        int i, j;
        memset(mat, 0, sizeof(mat));
    }

    void print()
    {
        int i, j;
        for (i = 0; i < size; i++)
        {
            for (j = 0; j < size; j++)
                printf("%d ", mat[i][j]);
            printf("\n");
        }
    }

    Mat operator = (Mat b)
    {
        int i, j;
        size = b.size;
        for (i = 0; i < size; i++)
            for (j = 0; j < size; j++)
                mat[i][j] = b.mat[i][j];
    }

    Mat operator + (Mat b)
    {
        int i, j;
        Mat c;
        c.size = size;
        c.clr();
        for (i = 0; i < size; i++)
            for (j = 0; j < size; j++)
                c.mat[i][j] = mat[i][j] + b.mat[i][j];
        return c;
    }

    Mat operator * (Mat b)
    {
        int i, j, k;
        Mat c;
        c.size = size;
        c.clr();
        for (i = 0; i < size; i++)
        {
            for (k = 0; k < size; k++)
            {
                if (mat[i][k]==0) continue;
                for (j = 0; j < size; j++)
                {
                    if( b.mat[k][j] == 0) continue;
                    c.mat[i][j] += mat[i][k] * b.mat[k][j];
                }
            }
        }
        return c;
    }

    Mat operator ^ (int p)          //二分求幂
    {
        int i, j;
        Mat ret, a;
        ret.size = size;
        ret.e();
        a = *this;
        while (p)
        {
            if (p & 1) ret = ret * a;
            a = a * a;
            p >>= 1;
        }
        return ret;
    }

    Mat operator - (Mat b)
    {
        int i, j;
        Mat c;
        c.size = size;
        c.clr();
        for (i = 0; i < N; i++)
        {
            for (j = 0; j < N; j++)
                c.mat[i][j] = mat[i][j] - b.mat[i][j];
        }
        return c;
    }
};

int main()
{
    int i, j, sum = 0;
    Mat a, c;
    a.size = 6;
    a.clr();
    a.mat[0][0] = 3, a.mat[0][1] = 1;
    c = a ^ 3;
    for (i = 0; i < c.size; i++) sum += c.mat[0][i];
    printf("ans= %d\n", sum);
    system("pause");
    return 0;
}

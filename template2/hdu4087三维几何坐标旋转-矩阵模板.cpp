#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <vector>
#define inf 99999999
#define eps 1e-10
#define pi acos(-1.0)
#define MAXN 1010
#define N 4
#define M (1 << 10)
#define file_r(x) freopen(x, "r", stdin)
#define file_w(x) freopen(x, "w", stdout)
using namespace std;

struct Matrix
{
    double arr[N][N];
    void init_E()
    {
        memset(arr, 0, sizeof(arr));
        for(int i = 0; i < N; i++) arr[i][i] = 1.0;
    }

    void clear()
    {
        memset(arr, 0, sizeof(arr));
    }

    Matrix operator * (const Matrix &A) const
    {
        Matrix res;
        res.clear();
        for(int k = 0; k < N; k++)
            for(int i = 0; i < N; i++)
                for(int j = 0; j < N; j++)
                    res.arr[i][j] += arr[i][k] * A.arr[k][j];
        return res;
    }
    void output()
    {
        for(int i = 0 ; i < N; i++)
        {
            for(int j = 0 ; j < N; j++)
            {
                printf("%0.2f ",arr[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
};

Matrix mpow(Matrix A, int p)
{
    Matrix res;
    res.init_E();
    while(p)
    {
        if (p & 1) res = res * A;
        A = A * A;
        p >>= 1;
    }
    return res;
}

struct Operation
{
    int oprid;
    int k;
    Matrix mat;
};

struct Point
{
    double x, y, z;
    void input()
    {
        scanf("%lf%lf%lf", &x, &y, &z);
    }

    void output()
    {
        printf("%lf %lf %lf\n", x, y, z);
    }
} p[MAXN];

int n, matchend;
char buff[MAXN], buf[100];;
vector<Operation> opr;

bool init()
{
    double tx, ty, tz;
    double a, b, c;
    double x, y, z, ang;
    if (matchend == -1) return false;
    Operation tmp;
    tmp.mat.init_E();
    scanf("%s", buff);
    if (buff[0] == 'r' && buff[1] == 'o')
    {
        tmp.oprid = 0;
        scanf("%lf%lf%lf%lf", &x, &y, &z, &ang);
        ang = ang / 180.0 * pi;
        double len = sqrt(x * x + y * y + z * z);
        x /= len;
        y /= len;
        z /= len;
        tmp.mat.arr[3][3] = 1.0;
        tmp.mat.arr[0][0] = x * x + (1 - x * x) * cos(ang);
        tmp.mat.arr[0][1] = x * y * (1 - cos(ang)) - z * sin(ang);
        tmp.mat.arr[0][2] = x * z * (1 - cos(ang)) + y * sin(ang);
        tmp.mat.arr[1][0] = y * x * (1 - cos(ang)) + z * sin(ang);
        tmp.mat.arr[1][1] = y * y + (1 - y * y) * cos(ang);
        tmp.mat.arr[1][2] = y * z * (1 - cos(ang)) - x * sin(ang);
        tmp.mat.arr[2][0] = z * x * (1 - cos(ang)) - y * sin(ang);
        tmp.mat.arr[2][1] = z * y * (1 - cos(ang)) + x * sin(ang);
        tmp.mat.arr[2][2] = z * z + (1 - z * z) * cos(ang);
    }
    if (buff[0] == 't')
    {
        tmp.oprid = 1;
        scanf("%lf%lf%lf", &tx, &ty, &tz);
        tmp.mat.arr[0][3] = tx;
        tmp.mat.arr[1][3] = ty;
        tmp.mat.arr[2][3] = tz;
    }
    if (buff[0] == 's')
    {
        tmp.oprid = 2;
        scanf("%lf%lf%lf", &a, &b, &c);
        tmp.mat.arr[0][0] = a;
        tmp.mat.arr[1][1] = b;
        tmp.mat.arr[2][2] = c;
    }
    if (buff[0] == 'r' && buff[1] == 'e')
    {
        matchend++;
        tmp.oprid = 3;
        scanf("%d",&tmp.k);
    }
    if (buff[0] == 'e')
    {
        matchend--;
        tmp.oprid = 4;
    }
    opr.push_back(tmp);
    return true;
}

Matrix solve(int l, int r)
{
    int i, j, f, sum;
    Matrix res;
    res.init_E();
    if (l > r) return res;
    if (opr[l].oprid == 3)
    {
        f = 0, sum = opr[l].k;
        for (i = l + 1; l <= r; i++)
        {
            if (opr[i].oprid == 3) f++;
            else if (opr[i].oprid == 4) f--;
            if (f == -1) break;
        }
        res = solve(i + 1, r) * mpow(solve(l + 1, i - 1), sum);
    }
    else res = solve(l + 1, r) * opr[l].mat;
    return res;
}

inline void output(const double &x)
{
    sprintf(buf, "%.2f", x);
    if (strcmp(buf, "-0.00") == 0) printf("0.00");
    else printf("%s", buf);
}
int main()
{
    int i, j;
    while (scanf("%d", &n) != EOF && n)
    {
        opr.clear();
        matchend = 0;
        while (init());
        for(int i = 0 ; i < n; i++) p[i].input();
        Matrix res = solve(0, opr.size() - 1);
        for(int i = 0 ; i < n; i++)
        {
            double x = res.arr[0][0] * p[i].x + res.arr[0][1] * p[i].y + res.arr[0][2] * p[i].z + res.arr[0][3];
            double y = res.arr[1][0] * p[i].x + res.arr[1][1] * p[i].y + res.arr[1][2] * p[i].z + res.arr[1][3];
            double z = res.arr[2][0] * p[i].x + res.arr[2][1] * p[i].y + res.arr[2][2] * p[i].z + res.arr[2][3];
            output(x), printf(" ");
            output(y), printf(" ");
            output(z), printf("\n");
        }
        printf("\n");
    }
    system("pause");
    return 0;
}

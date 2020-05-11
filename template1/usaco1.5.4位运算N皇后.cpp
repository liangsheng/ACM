/*
ID : ls_02221
PROG : checker
LANG : C++
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <fstream>
using namespace std;

ifstream fin("checker.in");
ofstream fout("checker.out");

int n, upperlim, sum = 0, a[14], k = 0, t = 0;

int test(int row, int ld, int rd)
{
    int i, j, pos, p;
    if (row != upperlim)
    {
        pos = upperlim & (~(row | ld | rd));
        while (pos != 0)
        {
            p = pos & (-pos);
            pos = pos - p;
            a[++k] = p;
            test(row + p, (ld + p) << 1, (rd + p) >> 1);  
            k--;
        }
        return 1;    
    }
    sum++;
    t++;
    if (t > 3) return 1;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if ((1 << (j - 1)) & a[i])
            {
                if (i == n) /*printf("%d\n", j);*/ fout << j << endl;
                else  /*printf("%d ", j);*/ fout << j << " ";
                break;   
            }
        }
    }
    return 1;
}

int main()
{
    int i; 
    //scanf("%d", &n);
    fin >> n;
    upperlim = (1 << n) - 1;
    test(0, 0, 0);
    //printf("%d\n", sum);
    fout << sum << endl;
    //system("pause");
    return 0;
}

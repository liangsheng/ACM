#include <iostream>
#include <cstdio>
#include <cstring>
#define N 505
using namespace std;

int f[N][N];

int main()
{
    int i, j, len1, len2;
    string s1, s2;
    while (cin >> s1 >> s2)
    {
        len1 = s1.size();
        len2 = s2.size();
        memset(f, 0, sizeof(f));
        for (i = 1; i <= len1; i++)
        {
            for (j = 1; j <= len2; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                    f[i][j] = f[i - 1][j - 1] + 1;
                else
                    f[i][j] = f[i - 1][j] > f[i][j - 1] ? f[i - 1][j] : f[i][j - 1];
            }
        } 
        printf("%d\n", f[len1][len2]); 
    }
    system("pause");
    return 0; 
} 

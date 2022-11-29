#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#define inf (1 << 30)
#define mod 1000000007
#define N 3010
const double eps = 1e-12;
const double pi = acos(-1.0);
using namespace std;

int T, n1, n2;
char s1[N], s2[N], stmp[N];

int change(char *s, int l, int r)
{
    if (r < l) return 1;
    int i, j, k, cnt0 = 0, cnt1 = 0;
    int ll = l, rl = l;
    vector<string> vs;
    for (i = l; i <= r; i++)
    {
        if (s[i] == '0') cnt0++;
        if (s[i] == '1') cnt1++;
        rl = i;
        if (cnt0 == cnt1)
        {
            change(s, ll + 1, rl - 1);
            for (j = ll; j <= rl; j++)
                stmp[j - ll] = s[j];
            stmp[j - ll] = 0;
            vs.push_back(stmp);
            ll = rl + 1;
            rl = rl + 1;
            cnt0 = cnt1;
        }
    }
    sort(vs.begin(), vs.end());
    i = l;
    for (k = 0; k < vs.size(); k++)
        for (j = 0; j < vs[k].size(); j++) s[i++] = vs[k][j];
    vs.clear();
    return 1;
}

int main()
{
    int i, j;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%s%s", s1, s2);
        n1 = strlen(s1);
        n2 = strlen(s2);
        change(s1, 0, n1 - 1);
        change(s2, 0, n2 - 1);
        if (strcmp(s1, s2) == 0) printf("same\n");
        else printf("different\n");
    }
    system("pause");
    return 0;
}

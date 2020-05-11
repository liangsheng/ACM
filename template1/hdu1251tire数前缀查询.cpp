#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#define inf (1 << 30)
#define mod 1000000007
#define N 20
const double eps = 1e-12;
const double pi = acos(-1.0);
using namespace std;

struct tire
{
    int date;
    struct tire* son[26];
}*root;

int insert(string s, struct tire *p)
{
    int i, j;
    struct tire *rot = p;
    for (i = 0; i < s.size(); i++)
    {
        if (rot -> son[s[i] - 'a'] == NULL)
        {
            tire *t = new tire;
            t -> date = 1;
            for (j = 0; j < 26; j++) t -> son[j] = NULL;
            rot -> son[s[i] - 'a'] = t;
            rot = rot -> son[s[i] - 'a'];
            continue;
        }
        rot = rot -> son[s[i] - 'a'];
        rot -> date++;
    }
    return 1;
}

int search(string s, struct tire *p)
{
    int i, j;
    struct tire *rot = p;
    for (i = 0; i < s.size(); i++)
    {
        if (rot -> son[s[i] - 'a'] == NULL) return 0;
        rot = rot -> son[s[i] - 'a'];
    }
    return rot -> date;
}

int main()
{
    int i, j;
    string s;
    root = new tire;
    root -> date = 0;
    for (i = 0; i < 26; i++) root -> son[i] = NULL;
    while (getline(cin, s) && s != "\0") insert(s, root);
    while (cin >> s) printf("%d\n", search(s, root));
    system("pause");
    return 0;
}

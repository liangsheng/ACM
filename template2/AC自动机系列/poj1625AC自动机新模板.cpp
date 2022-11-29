#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct node
{
    int index;
    node *fail;
    node *next[50];
    int count;
} trie[1000];

int total;
node *root;

node *q[1000];
int head, tail;

char word[100];

struct num
{
    int number[101];
    int len;
};

num dp[100][100];

void add(num a, num &t)
{
    int i;
    for (i=0; i<a.len && i<t.len; i++)
        t.number[i] += a.number[i];
    if (a.len>t.len)
    {
        for (i=t.len; i<a.len; i++)
        {
            t.number[i] = a.number[i];
        }
        t.len = a.len;
    }
    for (i=1; i<t.len; i++)
    {
        t.number[i] += t.number[i-1]/10;
        t.number[i-1] %= 10;
    }
    while (t.number[t.len-1]>10)
    {
        t.number[t.len] = t.number[t.len-1]/10;
        t.number[t.len-1] %= 10;
        t.len++;
    }
}

int rank[300];
int ct;

int n,m,p;

inline node *new_node()
{
    node *p = &trie[total];
    p -> index = total;
    p -> count = 0;
    p -> fail = NULL;
    int i;
    for (i = 0; i < n; i++)
        p -> next[i] = NULL;
    total++;
    return p;
}

void insert(char *s)
{
    node *p = root;
    int index;
    int i = 0;
    while (s[i] != '\0')
    {
        index = rank[s[i]];
        if (p -> next[index] == NULL)
            p -> next[index] = new_node();
        p = p -> next[index];
        i++;
    }
    p -> count++;
}

void build_ac_automation()
{
    int i;
    node *temp;
    head = tail = 0;
    root -> fail = root;
    for (i = 0; i < n; i++)
    {
        if (root -> next[i] != NULL)
        {
            root -> next[i] -> fail = root;
            q[tail++] = root -> next[i];
        }
        else root -> next[i] = root;
    }
    while (head != tail)
    {
        temp = q[head++];
        for (i = 0; i < n; i++)
        {
            if (temp -> next[i] != NULL)
            {
                temp -> next[i] -> fail = temp -> fail -> next[i];
                if (temp -> next[i] -> fail -> count != 0)
                    temp -> next[i] -> count = 1;
                q[tail++] = temp -> next[i];
            }
            else temp -> next[i] = temp -> fail -> next[i];
        }
    }
}

num solve()
{
    int i,j,k;
    int index;
    for (i=0; i<=m; i++)
    {
        for (j=0; j<=total; j++)
        {
            dp[i][j].len = 1;
        }
    }
    dp[0][0].len = 1;
    dp[0][0].number[0] = 1;
    for (i=1; i<=m; i++)
    {
        for (j=0; j<total; j++)
        {
            if (trie[j].count==0)
            {
                for (k=0; k<n; k++)
                {
                    if (trie[j].next[k]->count==0)
                    {
                        index = trie[j].next[k]->index;
                        add(dp[i-1][j], dp[i][index]);
                    }
                }
            }
        }
    }
    num sum;
    sum.len = 1;
    sum.number[0] = 0;
    for (i=0; i<total; i++)
    {
        if (trie[i].count==0)
        {
            add(dp[m][i], sum);
        }
    }
    return sum;
}

int main()
{
    int i;
    scanf("%d %d %d", &n, &m, &p);
    scanf("%s", word);
    for (i=0,ct=0; word[i]!='\0'; i++)
    {
        rank[word[i]] = ct;
        ct++;
    }
    total = 0;
    root = new_node();
    for (i=0; i<p; i++)
    {
        scanf("%s", word);
        insert(word);
    }
    build_ac_automation();
    num t = solve();
    for (i=t.len-1; i>=0; i--)
        printf("%d", t.number[i]);
    printf("\n");
    return 0;
}

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#define inf (1 << 30)
#define mod 1000000007
#define N 510
#define M 50005
const double eps = 1e-12;
const double pi = acos(-1.0);
using namespace std;

const int kind = 26;
struct node
{
    node *fail;       //失败指针
    node *next[kind]; //Tire每个节点的26个子节点（最多26个字母）
    int count;        //是否为该单词的最后一个节点
    node()
    {
        //构造函数初始化
        fail=NULL;
        count=0;
        memset(next,NULL,sizeof(next));
    }
} *root;

int T, n;
char keyword[55], str[1000001];

int init()
{
    root = new node;
    return 1;
}

int insert(char *str, node *root)
{
    node *p = root;
    int i = 0, index;
    while (str[i])
    {
        index = str[i] - 'a';
        if (p -> next[index] == NULL) p -> next[index] = new node();
        p = p -> next[index];
        i++;
    }
    p -> count++;
    return 1;
}

int build_ac_automation(node *root)
{
    int i;
    queue<node*> q;
    root -> fail = NULL;
    q.push(root);
    while (! q.empty())
    {
        node *temp = q.front();
        q.pop();
        node *p = NULL;
        for (i = 0; i < kind; i++)
        {
            if (temp -> next[i] != NULL)
            {
                if (temp == root) temp -> next[i] -> fail = root;
                else
                {
                    p = temp -> fail;
                    while (p != NULL)
                    {
                        if (p -> next[i] != NULL)
                        {
                            temp -> next[i] -> fail = p -> next[i];
                            break;
                        }
                        p = p -> fail;
                    }
                    if (p == NULL) temp -> next[i] -> fail = root;
                }
                q.push(temp -> next[i]);
            }
        }
    }
    return 1;
}

int query(node *root)
{
    int i = 0, cnt = 0, index, len = strlen(str);
    node *p = root;
    while (str[i])
    {
        index = str[i] - 'a';
        while (p -> next[index] == NULL && p != root) p = p -> fail;
        p = p -> next[index];
        p = (p == NULL) ? root : p;
        node *temp = p;
        while (temp != root && temp -> count != -1)
        {
            cnt += temp -> count;
            temp -> count = -1;
            temp = temp -> fail;
        }
        i++;
    }
    return cnt;
}

int main()
{
    int i, j;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        init();
        for (i = 1; i <= n; i++)
        {
            scanf("%s", keyword);
            insert(keyword, root);
        }
        build_ac_automation(root);
        scanf("%s", str);
        printf("%d\n", query(root));
    }
    system("pause");
    return 0;
}

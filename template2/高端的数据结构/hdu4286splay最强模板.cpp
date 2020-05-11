/*
 * Problem: NOI2005 sequence
 * Author: Guo Jiabao
 * Time: 2009.5.30 14:19
 * State: Solved
 * Memo: 伸展树
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
using namespace std;
const int MAXN=2850003,MAXL=500001,INF=1001;
struct SplayTree {
    struct SplayNode {
        SplayNode *c[2],*f;
        int value,size,sum,maxsum,mls,mrs;
        bool rev,same;
    }*root,*null,*lb,*rb,SS[MAXN];
    int SC;
    SplayNode * NewNode(int value,SplayNode *f) {
        SplayNode *e=SS+ ++SC;
        e->value=value;
        e->size=1;
        e->f=f;
        e->sum=e->maxsum=e->mls=e->mrs=value;
        e->same=e->rev=false;
        e->c[0]=e->c[1]=null;
        return e;
    }
    inline int max(int a,int b) {
        return a>b?a:b;
    }
    void update(SplayNode *p) {
        if (p==null) return;
        p->size = p->c[0]->size + p->c[1]->size + 1;
        p->sum = p->c[0]->sum + p->c[1]->sum + p->value;
        p->mls = p->c[0]->mls;
        p->mls = max( p->mls , p->c[0]->sum + p->value);
        p->mls = max( p->mls , p->c[0]->sum + p->value + p->c[1]->mls );
        p->mrs = p->c[1]->mrs;
        p->mrs = max( p->mrs , p->c[1]->sum + p->value);
        p->mrs = max( p->mrs , p->c[1]->sum + p->value + p->c[0]->mrs );
        p->maxsum = p->value;
        p->maxsum = max( p->maxsum , p->c[0]->maxsum );
        p->maxsum = max( p->maxsum , p->c[1]->maxsum );
        p->maxsum = max( p->maxsum , p->c[0]->mrs + p->value );
        p->maxsum = max( p->maxsum , p->c[1]->mls + p->value );
        p->maxsum = max( p->maxsum , p->c[0]->mrs + p->c[1]->mls + p->value );
    }
    void pushdown(SplayNode *p) {
        if (p==null) return;
        if (p->rev) {
            p->rev=false;
            SplayNode *q=p->c[0];
            p->c[0]=p->c[1];
            p->c[1]=q;
            p->c[0]->rev = !p->c[0]->rev;
            p->c[1]->rev = !p->c[1]->rev;
            int t=p->mls;
            p->mls=p->mrs;
            p->mrs=t;
        }
        if (p->same) {
            p->same=false;
            p->c[0]->same=p->c[1]->same=true;
            p->c[0]->value=p->c[1]->value=p->value;
            p->sum = p->maxsum = p->mls = p->mrs = p->value * p->size;
            if (p->value < 0)
                p->maxsum = p->mls = p->mrs = p->value;
        }
    }
    void rotate(SplayNode *x,int o) { //Zig o=0 Zag o=1
        SplayNode *y=x->f;
        pushdown(x->c[0]);
        pushdown(x->c[1]);
        pushdown(y->c[!o]);
        y->c[o] = x->c[!o];
        y->c[o]->f=y;
        x->f = y->f;
        if (y->f->c[0]==y)
            y->f->c[0]=x;
        else
            y->f->c[1]=x;
        y->f=x;
        x->c[!o]=y;
        update(y);
        update(x);
        if (root==y) root=x;
    }
    void splay(SplayNode *x,SplayNode *y) {
        pushdown(x);
        while (x->f!=y) {
            if (x->f->f==y) {
                if (x->f->c[0]==x)
                    rotate(x,0);
                else
                    rotate(x,1);
            } else if (x->f->f->c[0] == x->f) {
                if (x->f->c[0]==x)
                    rotate(x->f,0),rotate(x,0);
                else
                    rotate(x,1),rotate(x,0);
            } else {
                if (x->f->c[1]==x)
                    rotate(x->f,1),rotate(x,1);
                else
                    rotate(x,0),rotate(x,1);
            }
        }
    }
    void select(int k,SplayNode *y) {
        SplayNode *x=root;
        pushdown(x);
        for (; k != x->c[0]->size + 1;) {
            if (k <= x->c[0]->size)
                x=x->c[0];
            else {
                k-=x->c[0]->size + 1;
                x=x->c[1];
            }
            pushdown(x);
        }
        splay(x,y);
    }
    void Insert(int pos,int tot,int *C) {
        SplayNode *z,*t;
        z=t=NewNode(C[1],null);
        for (int i=2; i<=tot; i++)
            z=z->c[1]=NewNode(C[i],z);
        select(pos+1,null);
        select(pos+2,root);
        root->c[1]->c[0] = t;
        t->f=root->c[1];
        splay(z,null);
    }
    void Delete(int pos,int tot) {
        select(pos,null);
        select(pos+tot+1,root);
        root->c[1]->c[0] = null;
        splay(root->c[1],null);
    }
    void MakeSame(int pos,int tot,int value) {
        select(pos,null);
        select(pos+tot+1,root);
        root->c[1]->c[0]->same=true;
        root->c[1]->c[0]->value=value;
        splay(root->c[1]->c[0],null);
    }
    void Reverse(int pos,int tot) {
        select(pos,null);
        select(pos+tot+1,root);
        root->c[1]->c[0]->rev=!root->c[1]->c[0]->rev;
        splay(root->c[1]->c[0],null);
    }
    int GetSum(int pos,int tot) {
        select(pos,null);
        select(pos+tot+1,root);
        pushdown(root->c[1]->c[0]);
        return root->c[1]->c[0]->sum;
    }
    int MaxSum() {
        pushdown(root);
        update(root);
        return root->maxsum;
    }
    void init() {
        SC=-1;
        null=0;
        null=NewNode(-INF,0);
        null->size=0;
        lb=root=NewNode(-INF,null);
        rb=root->c[1]=NewNode(-INF,root);
        null->sum = lb->sum = rb->sum=0;
        update(root);
    }
} Splay;
int N,M,C[MAXL],pos,i,j,A;
char Ctrl[20];
int main() {
    freopen("seq2005.in","r",stdin);
    freopen("seq2005.out","w",stdout);
    Splay.init();
    scanf("%d%d",&N,&M);
    for (i=1; i<=N; i++)
        scanf("%d",&C[i]);
    Splay.Insert(0,N,C);
    for (i=1; i<=M; i++) {
        scanf("%s",Ctrl);
        switch (Ctrl[0]) {
        case 'I':
            scanf("%d%d",&pos,&N);
            for (j=1; j<=N; j++)
                scanf("%d",&C[j]);
            Splay.Insert(pos,N,C);
            break;
        case 'D':
            scanf("%d%d",&pos,&N);
            Splay.Delete(pos,N);
            break;
        case 'R':
            scanf("%d%d",&pos,&N);
            Splay.Reverse(pos,N);
            break;
        case 'G':
            scanf("%d%d",&pos,&N);
            A=Splay.GetSum(pos,N);
            printf("%d\n",A);
            break;
        case 'M':
            if (Ctrl[2]=='K') {
                scanf("%d%d%d",&pos,&N,&C[0]);
                Splay.MakeSame(pos,N,C[0]);
            } else
                printf("%d\n",Splay.MaxSum());
            break;
        }
    }
    return 0;
}

/*
维护数列

【问题描述】

请写一个程序，要求维护一个数列，支持以下 6 种操作：（请注意，格式栏 中的下划线‘ _ ’表示实际输入文件中的空格）
操作编号 	输入文件中的格式

说明

1.  插入
INSERT_posi_tot_c1_c2_…_ctot
在当前数列的第 posi 个数字后插入 tot个数字：c1, c2, …, ctot；若在数列首插入，则 posi 为 0

2.  删除
DELETE_posi_tot从当前数列的第 posi 个数字开始连续删除 tot 个数字

3.  修改
MAKE-SAME_posi_tot_c将当前数列的第 posi 个数字开始的连续 tot 个数字统一修改为 c

4.  翻转
REVERSE_posi_tot
取出从当前数列的第 posi 个数字开始的 tot 个数字，翻转后放入原来的位置

5.  求和
GET-SUM_posi_tot计算从当前数列开始的第 posi 个数字开始的 tot 个数字的和并输出

6.  求和最大的子列
MAX-SUM
求出当前数列中和最大的一段子列，并输出最大和

【输入格式】

输入文件的第 1 行包含两个数 N 和 M，N 表示初始时数列中数的个数，M表示要进行的操作数目。

第 2 行包含 N 个数字，描述初始时的数列。

以下 M 行，每行一条命令，格式参见问题描述中的表格。

【输出格式】

对于输入数据中的 GET-SUM 和 MAX-SUM 操作，向输出文件依次打印结果，每个答案（数字）占一行。

【输入样例】

9 8
2 -6 3 5 1 -5 -3 6 3
GET-SUM 5 4
MAX-SUM INSERT 8 3 -5 7 2
DELETE 12 1
MAKE-SAME 3 3 2
REVERSE 3 6
GET-SUM 5 4
MAX-SUM

【输出样例】

-1
10
1
10

【样例说明】

初始时，我们拥有数列 2 -6 3 5 1 -5 -3 6 3

执行操作 GET-SUM 5 4，表示求出数列中从第 5 个数开始连续 4 个数字之和，1+(-5)+(-3)+6 = -1：

2     -6     3      5      1     -5    -3     6      3

执行操作 MAX-SUM，表示要求求出当前数列中最大的一段和，应为 3+5+1+(-5)+(-3)+6+3 = 10：

2     -6     3      5      1     -5    -3     6      3

执行操作 INSERT 8 3 -5 7 2，即在数列中第 8 个数字后插入-5 7 2，

2     -6     3      5      1     -5    -3     6     -5     7      2      3

执行操作 DELETE 12 1，表示删除第 12 个数字，即最后一个：

2     -6     3      5      1     -5    -3     6     -5     7      2

执行操作 MAKE-SAME 3 3 2，表示从第 3 个数开始的 3 个数字，统一修改为 2：

2	-6	3	5	1	-5	-3	6	-5	7	2

改为

2	-6	2	2	2	-5	-3	6	-5	7	2

执行操作 REVERSE 3 6，表示取出数列中从第 3 个数开始的连续 6 个数：

2           -6            2             2             2           -5            -3            6            -5            7            2

如上所示的灰色部分 2 2 2 -5 -3 6，翻转后得到 6 -3 -5 2 2 2，并放回原来位置：

2     -6     6     -3     -5     2      2      2     -5     7      2

最后执行 GET-SUM 5 4 和 MAX-SUM，不难得到答案 1 和 10。

2            -6            6            -3            -5           2             2            2             -5           7             2
*/

//http://www.byvoid.com/blog/noi-2005-sequence/

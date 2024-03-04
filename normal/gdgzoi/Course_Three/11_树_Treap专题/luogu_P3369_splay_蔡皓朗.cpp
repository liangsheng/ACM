// http://gdgzoi.com/showsource.php?id=616493
#include<bits/stdc++.h>
using namespace std;
 
const int N = 1e5 + 10;
int n, rt, sum;
struct Splay{
    int fa, val, sz, son[2];//0 left, 1 right
} spy[N];
 
bool direction(int x, int fa){return spy[fa].son[1] == x;}
 
void update(int u){spy[u].sz = spy[spy[u].son[0]].sz + spy[spy[u].son[1]].sz + 1;}
 
void rebuild(int x, int fa, int d){//d 是左边 or 右边的标记 
    spy[fa].son[d] = x, spy[x].fa = fa;
}
 
void rotate(int x){
    int fa = spy[x].fa, g = spy[fa].fa;
    int d = direction(x, fa);//右旋回 0 左旋回 1 
    rebuild(spy[x].son[d ^ 1], fa, d);//什么旋处理什么儿子
    rebuild(x, g, direction(fa, g));
    rebuild(fa, x, d ^ 1);//更换 x 和 fa 的父子关系
    update(fa), update(x);
}
 
void newnode(int &u, int val, int fa){
    u = ++sum;
    spy[sum].fa = fa, spy[sum].val = val, spy[sum].sz = 1;
}
 
void splay(int x, int v){//把 x 转到 y 的儿子 
    if(!v)  rt = x;
    while(spy[x].fa != v){
        int f = spy[x].fa, g = spy[f].fa;
        if(g != v)  direction(f, g) ^ direction(x, f) ? rotate(x) : rotate(f);
        //原本要分四种情况，但因为 rotate 合二为一，所以有的情况在 rotate 里讨论了
        rotate(x);//最后一次都是旋转 x
    }
}
 
void insert(int &u, int fa, int val){
    if(!u)  newnode(u, val, fa), splay(u, 0);
    else if(val < spy[u].val)    insert(spy[u].son[0], u, val);
    else    insert(spy[u].son[1], u, val);
}
 
void delnode(int u){
    splay(u, 0);
    if(!spy[rt].son[1]) rt = spy[u].son[0], spy[rt].fa = 0;//转完发现没有右儿子，直接把根定为左儿子
    else{
        int nxt = spy[u].son[1];
        while(spy[nxt].son[0])  nxt = spy[nxt].son[0];//找后继 
        splay(nxt, u);
        rebuild(spy[u].son[0], nxt, 0);
        rt = nxt, spy[nxt].fa = 0;
        update(rt);
    }
}
 
void del(int val, int u = rt){
    if(spy[u].val == val)   delnode(u);
    else if(spy[u].val > val)    del(val, spy[u].son[0]);
    else    del(val, spy[u].son[1]);
}
 
int rnk(int x){
    int u = rt, rk = 1, v = 0;
    while(u){
        if(x <= spy[u].val)    v = u, u = spy[u].son[0];
        else    rk += spy[spy[u].son[0]].sz + 1, u = spy[u].son[1];
    }
    if(v)   splay(v, 0);
    return rk;
}
 
int query(int rk){
    int u = rt;
    while(u){
        if(spy[spy[u].son[0]].sz + 1 == rk){
            splay(u, 0);
            break;
        }else if(spy[spy[u].son[0]].sz >= rk)    u = spy[u].son[0];
        else    rk -= spy[spy[u].son[0]].sz + 1, u = spy[u].son[1];
    }
    return spy[u].val;
}
 
int main(){
    scanf("%d", &n);
    int op, x;
    while(n--){
        scanf("%d%d", &op, &x);
        if(op == 1) insert(rt, 0, x);
        else if(op == 2)    del(x);
        else if(op == 3)    printf("%d\n", rnk(x));
        else if(op == 4)    printf("%d\n", query(x));
        else if(op == 5)    printf("%d\n", query(rnk(x) - 1));
        else if(op == 6)    printf("%d\n", query(rnk(x + 1)));
    }
    return 0;
}
/**************************************************************
    Problem: 2085
    User: 2021gzezcz10
    Language: C++
    Result: Accepted
    Time:64 ms
    Memory:3976 kb
****************************************************************/

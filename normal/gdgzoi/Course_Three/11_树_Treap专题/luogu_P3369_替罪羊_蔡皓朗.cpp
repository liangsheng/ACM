// http://gdgzoi.com/showsource.php?id=616482
#include<bits/stdc++.h>
using namespace std;
 
const int N = 1e5 + 10;
const double alpha = 0.75;
struct spgoat{
    int val, cnt, sz, cntsz, fa, son[2];//sz：节点个数；cntsz:一共有多少个数（包含重复） 
    bool isdel;
} spt[N];
int n, sum, tot, len, rt;
int cur[N], a[N];
 
void update(int u){
    spt[u].cntsz = spt[spt[u].son[0]].cntsz + spt[spt[u].son[1]].cntsz + 1;
    spt[u].sz = spt[spt[u].son[0]].sz + spt[spt[u].son[1]].sz + 1;
}
 
void newnode(int x){spt[x].son[0] = spt[x].son[1] = 0, spt[x].sz = spt[x].cntsz = 1;}//新建节点 
 
bool check(int x){return (double)spt[x].sz * alpha > (double)max(spt[spt[x].son[0]].sz, spt[spt[x].son[1]].sz);}//检查是否平衡 
 
void Traversal(int x){//中序遍历拍扁子树，根据BST的性质，遍历完后元素是递减的
    if(!x)  return;
    Traversal(spt[x].son[0]);//中序遍历先遍历该节点的左子树
    if(!spt[x].isdel)   cur[++tot] = x;//如果该节点没被删掉，拍扁！ 
    else    a[++len] = x;//否则加入储存空节点的数组，方便动态开点 
    Traversal(spt[x].son[1]);//最后遍历右子树 
}
 
void setup(int l, int r, int &x){//重构树 
    int mid = (l + r) >> 1;
    x = cur[mid];
    if(l == r){//如果这是叶节点 
        newnode(x);//重置该节点 
        return;
    }
    if(l < mid)  setup(l, mid - 1, spt[x].son[0]);//如果左边还有数，说明它有左子树，重构左子树
    else    spt[x].son[0] = 0;//否则左子树为空 
    setup(mid + 1, r, spt[x].son[1]);//重构右子树 
    update(x);//更新 x 的两个 sz 
}
 
void rebuild(int &x){
    tot = 0, Traversal(x);//拍扁成数组 
    if(tot) setup(1, tot, x);//重建成完全二叉树 
    else    x = 0;//特判子树为空 
}
 
void is_balance(int x, int val){
    int d = val > spt[x].val;
    while(spt[x].son[d]){
        if(!check(spt[x].son[d])){
            rebuild(spt[x].son[d]);
            return;
        }
        x = spt[x].son[d], d = val > spt[x].val;
    }
}
 
void insert(int &x, int val){
    if(!x){
        x = a[len--], spt[x].val = val, spt[x].isdel = 0;
        newnode(x);
        return;
    }
    ++spt[x].sz, ++spt[x].cntsz;
    if(val < spt[x].val) insert(spt[x].son[0], val);
    else    insert(spt[x].son[1], val);
}
 
void del(int &x, int rk){
    if(!spt[x].isdel && spt[spt[x].son[0]].sz + 1 == rk){//如果当前查到的数没被删掉且刚好等于查询排名 
        spt[x].isdel = 1, --spt[x].sz;//标记删掉这个数，将子树大小-- 
        return ;
    }
    --spt[x].sz;
    if(spt[spt[x].son[0]].sz + !spt[x].isdel >= rk)  del(spt[x].son[0], rk);
    else    del(spt[x].son[1], rk - !spt[x].isdel - spt[spt[x].son[0]].sz);//递归不解释 
}
 
int rnk(int v){
    int x = rt, rk = 1;
    while(x){
        if(spt[x].val >= v)  x = spt[x].son[0];
        else    rk += spt[spt[x].son[0]].sz + !spt[x].isdel, x = spt[x].son[1];
    }
    return rk;
}
 
int query(int rk){
    int x = rt;
    while(x){
        if(!spt[x].isdel && spt[spt[x].son[0]].sz + 1 == rk)    return spt[x].val;
        else if(spt[spt[x].son[0]].sz >= rk) x = spt[x].son[0];
        else    rk -= !spt[x].isdel + spt[spt[x].son[0]].sz, x = spt[x].son[1];
    }
}
 
void Delete(int v){
    del(rt, rnk(v));
    if((double)spt[rt].cntsz * alpha > (double)spt[rt].sz)   rebuild(rt);
}
 
int main(){
    scanf("%d", &n);
    len = 0;
    for(int i=N-1;i;i--)    a[++len] = i;
    while(n--){
        int op, x, rt1;
        scanf("%d%d", &op, &x);
        if(op == 1) rt1 = rt, insert(rt, x), is_balance(rt1, x);
        else if(op == 2)    Delete(x);
        else if(op == 3)    printf("%d\n", rnk(x));
        else if(op == 4)    printf("%d\n", query(x));
        else if(op == 5)    printf("%d\n", query(rnk(x) - 1));
        else if(op == 6)    printf("%d\n", query(rnk(x + 1)));
    }
}
/**************************************************************
    Problem: 2085
    User: 2021gzezcz10
    Language: C++
    Result: Accepted
    Time:76 ms
    Memory:5928 kb
****************************************************************/

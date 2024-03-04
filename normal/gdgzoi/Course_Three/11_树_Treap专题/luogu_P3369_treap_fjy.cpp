// http://gdgzoi.com/showsource.php?id=599452
// created time : 2021-12-24 13:18:54
// writer : fjy
#include <bits/stdc++.h>
#define _rep(i_,a_,b_) for(int i_ = a_;i_ <= b_;++i_)
int in(void) { int x; scanf("%d",&x); return x; }
typedef long long ll;
using namespace std;
mt19937 engine(114514);
const int kN = 100005,inf = 0x7fffffff;
#define lc(id) pool[id].ch[0]
#define rc(id) pool[id].ch[1]
struct node {
    int ch[2],val,siz,cnt;
    unsigned int key;
} pool[kN]; int cnt,root,kase;
int require(int value) { pool[++cnt] = node{0,0,value,1,1,(unsigned)(engine())}; return cnt; } 
void pushup(int id) { pool[id].siz = pool[lc(id)].siz + pool[rc(id)].siz + pool[id].cnt; }
void rotate(int &id,int d) {
    int tmp = pool[id].ch[d ^ 1];
    pool[id].ch[d^1] = pool[tmp].ch[d];
    pool[tmp].ch[d] = id; pushup(id);
    pushup(id = tmp);
}
void insert(int &id,int v) {
    if(!id) { id = require(v); return; }
    if(v == pool[id].val) ++pool[id].cnt;
    else {
        int ch = v < pool[id].val ? 0 : 1;
        insert(pool[id].ch[ch],v);
        if(pool[pool[id].ch[ch]].key < pool[id].key) rotate(id,ch ^ 1);
    }
    pushup(id); 
}
void remove(int &id,int v) {
    if(!id) return;
    if(v == pool[id].val) {
        if(pool[id].cnt > 1) { --pool[id].cnt; pushup(id); return; }
        if(lc(id) || rc(id)) {
            if(lc(id) && (!rc(id) || pool[lc(id)].key < pool[rc(id)].key)) rotate(id,1),remove(rc(id),v);
            else rotate(id,0),remove(lc(id),v);
            pushup(id);
        } else id = 0;
    } else {
        if(v < pool[id].val) remove(lc(id),v); else remove(rc(id),v);
        pushup(id);
    }
}
int query_rank(int &id,int v) {
    if(!id) return 0;
    if(pool[id].val < v) return pool[lc(id)].siz + pool[id].cnt + query_rank(rc(id),v);
    else return query_rank(lc(id),v);
}
int kth(int &id,int v) {
    if(v <= pool[lc(id)].siz) return kth(lc(id),v);
    else if(pool[lc(id)].siz + pool[id].cnt < v) return kth(rc(id),v - pool[lc(id)].siz - pool[id].cnt);
    else return pool[id].val; 
}
int pre(int v) {
    int id = root,ans;
    while(id) {
        if(pool[id].val < v) ans = pool[id].val,id = rc(id);
        else id = lc(id);
    }
    return ans;
}
int nxt(int v) {
    int id = root,ans;
    while(id) {
        if(pool[id].val > v) ans = pool[id].val,id = lc(id);
        else id = rc(id);
    }
    return ans;
}
void flatten(int x) { if(!x) return; flatten(lc(x)); printf("%d ",pool[x].val); flatten(rc(x)); }
int main() {
    int n = in();
    while(n--) {
        int opt = in(),x = in();
        if(opt == 1) insert(root,x);
        else if(opt == 2) remove(root,x);
        else if(opt == 3) printf("%d\n",query_rank(root,x) + 1);
        else if(opt == 4) printf("%d\n",kth(root,x));
        else if(opt == 5) printf("%d\n",pre(x));
        else printf("%d\n",nxt(x));
        // if(opt == 1 || opt == 2) flatten(root); putchar('\n');
    }
    return 0;
}
/**************************************************************
    Problem: 2085
    User: 2021qtdq6013
    Language: C++
    Result: Accepted
    Time:56 ms
    Memory:4372 kb
****************************************************************/

// http://gdgzoi.com/showsource.php?id=620745
// created time : 2021-12-28 19:29:46
// writer : fjy
#include <bits/stdc++.h>
#define _rep(i_,a_,b_) for(int i_ = a_;i_ <= b_;++i_)
int in(void) { int x; scanf("%d",&x); return x; }
typedef long long ll;
using namespace std;
const int kN = 100005;
namespace Splay {
    int ch[kN][2],val[kN],cnt[kN],siz[kN],fa[kN],root,ncnt;
    int get(int x) { return ch[fa[x]][1] == x; }
    void pushup(int x) { siz[x] = siz[ch[x][0]] + siz[ch[x][1]] + cnt[x]; }
    void rotate(int x) {
        int y = fa[x],z = fa[y],k = get(x),w = ch[x][k ^ 1];
        ch[y][k] = w; fa[w] = y; 
        ch[z][get(y)] = x; fa[x] = z;
        ch[x][k^1] = y; fa[y] = x;
        pushup(y); pushup(x);
    }
    void splay(int x,int goal = 0) {
        while(fa[x] != goal) {
            int y = fa[x],z = fa[y];
            if(z != goal) rotate(get(x) == get(y) ? y : x);
            rotate(x);
        }
        if(!goal) root = x;
    }
    void insert(int x) {
        int cur = root,p = 0;
        while(cur && val[cur] != x) p = cur,cur = ch[cur][x > val[cur]];
        if(cur) ++cnt[cur];
        else {
            cur = ++ncnt;
            if(p) ch[p][x > val[p]] = cur;
            ch[cur][0] = ch[cur][1] = 0,fa[cur] = p,val[cur] = x,cnt[cur] = siz[cur] = 1;
        }
        splay(cur);
    }
    int kth(int k) {
        int cur = root;
        while(true) {
            if(ch[cur][0] && k <= siz[ch[cur][0]]) cur = ch[cur][0];
            else if(k > siz[ch[cur][0]] + cnt[cur]) k -= siz[ch[cur][0]] + cnt[cur],cur = ch[cur][1];
            else { splay(cur); return cur; }
        } 
    }
    // 返回最靠近 x 的节点, 如果存在 x, 则 val[root] = x; 否则返回 x 的前驱或者后继
    void find(int x) {
        if(!root) return;
        int cur = root; while(val[cur] != x && ch[cur][x > val[cur]]) cur = ch[cur][x > val[cur]];
        splay(cur);
    }
    // 这个可能有问题, 树为空的时候, 查询某个数的排名
    // int rank(int x) { find(x); return siz[ch[root][0]] + 1; }

    // 这个是正确的
    int rank(int x) { find(x); return siz[ch[root][0]] + (val[root] < x) + 1; }

    int pre(int x) {
        find(x); if(val[root] < x) return root;
        int cur = ch[root][0]; while(ch[cur][1]) cur = ch[cur][1];
        splay(cur); return cur;
    }
    int suc(int x) {
        find(x); if(val[root] > x) return root;
        int cur = ch[root][1]; while(ch[cur][0]) cur = ch[cur][0];
        splay(cur); return cur;
    }
    void remove(int x) {
        int lst = pre(x),nxt = suc(x);
        splay(lst); splay(nxt,lst);
        int to_del = ch[nxt][0];
        if(cnt[to_del] > 1) { --cnt[to_del]; splay(to_del); }
        // else ch[nxt][0] = 0;  // 这里可能有问题, nxt 的左儿子的 cnt 有修改, 但这里没有更新
        else { ch[nxt][0] = 0; splay(nxt); }
    }
    void flatten(int rt) {
        if(!rt) return;
        flatten(ch[rt][0]);
        printf("(val=%d cnt=%d siz=%d)\n",val[rt],cnt[rt],siz[rt]);
        flatten(ch[rt][1]);
    }
}
int main() {
    Splay::insert(0x7fffffff); Splay::insert(0x80000000);
    int n = in();
    while(n--) {
        int op = in(),x = in();
        if(op == 1) Splay::insert(x);
        else if(op == 2) Splay::remove(x);
        else if(op == 3) printf("%d\n",Splay::rank(x) - 1);
        else if(op == 4) printf("%d\n",Splay::val[Splay::kth(x + 1)]);
        else if(op == 5) printf("%d\n",Splay::val[Splay::pre(x)]);
        else if(op == 6) printf("%d\n",Splay::val[Splay::suc(x)]);
        // Splay::flatten(Splay::root); puts("");
    }
    return 0;
}
/**************************************************************
    Problem: 2085
    User: 2021qtdq6013
    Language: C++
    Result: Accepted
    Time:72 ms
    Memory:4368 kb
****************************************************************/

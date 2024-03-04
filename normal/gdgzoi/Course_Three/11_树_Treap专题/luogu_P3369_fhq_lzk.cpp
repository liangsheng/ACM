// http://gdgzoi.com/showsource.php?id=980741
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int cnt,root,ans,n;
struct node{
    int ls,rs,val,siz;
    int pri;
}s[N];
int add(int x){
    ++cnt;
    s[cnt].val=x;
    s[cnt].ls=s[cnt].rs=0;
    s[cnt].siz=1;s[cnt].pri=rand();
    return cnt;
}
void pushup(int k){s[k].siz=s[s[k].ls].siz+s[s[k].rs].siz+1;}
void split(int k,int x,int &l,int &r){
    if(!k){l=r=0;return;}
    if(s[k].val<=x){
        l=k;split(s[l].rs,x,s[l].rs,r);
        pushup(l);
    }else{
        r=k;split(s[r].ls,x,l,s[r].ls);
        pushup(r);
    }
}
int merge(int x,int y){
    if(!x||!y)return x+y;
    if(s[x].pri>s[y].pri){
        s[x].rs=merge(s[x].rs,y);
        pushup(x);return x;
    }else{
        s[y].ls=merge(x,s[y].ls);
        pushup(y);return y;
    }
}
int l,r,p;
int kth(int k,int x){
    if(s[s[k].ls].siz+1==x)return k;
    if(s[s[k].ls].siz+1>=x)return kth(s[k].ls,x);
    return kth(s[k].rs,x-s[s[k].ls].siz-1);
}
int pre(int x){
    split(root,x-1,l,r);
    ans=kth(l,s[l].siz);
    root=merge(l,r);
    return ans;
}
int suf(int x){
    split(root,x,l,r);
    ans=kth(r,1);
    root=merge(l,r);
    return ans;
}
int rk(int x){
    split(root,x-1,l,r);
    ans=s[l].siz+1;
    root=merge(l,r);
    return ans;
}
void insert(int x){
    split(root,x,l,r);
    root=merge(merge(l,add(x)),r);
}
void del(int x){
    split(root,x,l,r);
    split(l,x-1,l,p);
    root=merge(merge(l,merge(s[p].ls,s[p].rs)),r);
}
void print(int k, int fa) {
    if (!k) return;
    print(s[k].ls, k);
    cout << "k= " << k << ", val= " << s[k].val << ", siz= " << s[k].siz << ", fa = " << fa << '\n';
    print(s[k].rs, k);
}
int main(){
    srand(time(NULL));
    scanf("%d",&n);
    while(n--){
        int op,x;
        scanf("%d%d",&op,&x);
        if(op==1)insert(x);
        if(op==2)del(x);
        if(op==3)printf("%d\n",rk(x));
        if(op==4)printf("%d\n",s[kth(root,x)].val);
        if(op==5)printf("%d\n",s[pre(x)].val);
        if(op==6)printf("%d\n",s[suf(x)].val);
        // print(root, -1);
    }
    return 0;
}
/**************************************************************
    Problem: 2085
    User: 2022qtgzsz12
    Language: C++
    Result: Accepted
    Time:48 ms
    Memory:21556 kb
****************************************************************/

#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,a[N],ans;
struct node{
    int ls,rs,val,siz,pri;
}s[N];
int cnt,root;
void pushup(int k){s[k].siz=s[s[k].ls].siz+s[s[k].rs].siz+1;}
int add(int x){
    s[++cnt]=node{0,0,x,1,rand()};
    return cnt;
}
void split(int k,int x,int &l,int &r){
    if(!k){l=r=0;return;}
    if(s[k].val<=x){
        l=k;split(s[k].rs,x,s[k].rs,r);
    }else{
        r=k;split(s[k].ls,x,l,s[k].ls);
    }pushup(k);
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
int kth(int k,int x){
    int ll=s[s[k].ls].siz;
    if(ll+1==x)return s[k].val;
    if(ll>=x)return kth(s[k].ls,x);
    return kth(s[k].rs,x-ll-1);
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        int l,r;
        split(root,a[i],l,r);
        int x=-2e9,y=2e9;
        if(l)x=kth(l,s[l].siz);
        if(r)y=kth(r,1);
        root=merge(merge(l,add(a[i])),r);
        if(i==1)continue;
        ans+=min(a[i]-x,y-a[i]);
    }
    cout<<ans+a[1]<<endl;
    return 0;
}

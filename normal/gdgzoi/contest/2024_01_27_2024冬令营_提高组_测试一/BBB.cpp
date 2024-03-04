#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+5;
ll a[N],f[N];
struct ccc{
    int pri,siz,ls,rs,val,mi,tag;
}s[N];
int cnt,root;
int add(int x){
    s[++cnt]=ccc{rand(),1,0,0,x,x,0};
    return cnt;
}
struct node{
    int l,r;
}ans[N];
int n,t[N];
void pushup(int k){
    s[k].siz=s[s[k].ls].siz+s[s[k].rs].siz+1;
    s[k].mi=min(s[s[k].ls].mi,min(s[s[k].rs].mi,s[k].val));
}
void due(int k,int z){
    if(!k)return;s[k].val+=z;
    s[k].mi+=z;s[k].tag+=z;
}
void pushdown(int k){
    if(!s[k].tag)return;
    due(s[k].ls,s[k].tag);
    due(s[k].rs,s[k].tag);
    s[k].tag=0;
}
void split(int k,int x,int &l,int &r){
    if(!k){l=r=0;return;}
    pushdown(k);int lsiz=s[s[k].ls].siz;
    if(lsiz+1<=x){
        l=k;split(s[k].rs,x-lsiz-1,s[k].rs,r);
    }else{
        r=k;split(s[k].ls,x,l,s[k].ls);
    }pushup(k);
}
int merge(int x,int y){
    if(!x||!y)return x+y;
    pushdown(x);pushdown(y);
    if(s[x].pri>s[y].pri){
        s[x].rs=merge(s[x].rs,y);
        pushup(x);return x;
    }else{
        s[y].ls=merge(x,s[y].ls);
        pushup(y);return y;
    }
}
int find(int k){
    pushdown(k);
    int w=s[s[k].ls].mi;
    if(s[k].ls!=0&&w==0)return find(s[k].ls);
    else if(s[k].val==0)return k;
    else return find(s[k].rs);
}
/*void inorder(int k){
    if(!k)return;pushdown(k);
    inorder(s[k].ls);
    cout<<k<<' '<<s[k].mi<<" "<<s[k].ls<<" "<<s[k].rs<<" "<<s[k].val<<endl;
    inorder(s[k].rs);
}*/
int main(){
    scanf("%d",&n);s[0].mi=2e9;
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++){
        if(a[i]<=a[i-1])f[i]=f[i-1],t[i]=0;
        else f[i]=f[i-1]+(a[i]-a[i-1]),t[i]=a[i]-a[i-1];
    }
    printf("%lld\n",f[n]);
    int now=0;
    for(int i=1;i<=n;i++)root=merge(root,add(a[i]));
    for(int i=1;i<=n;i++){
        if(i==n){
            for(int j=1;j<=t[i];j++)
            printf("%d %d\n",i,i);
            break;
        }
        for(int j=1;j<=t[i];j++){
            int l,r,p;
            split(root,i,l,r);int k;
            if(s[r].mi!=0)k=n;
            else k=find(r)-1;
            //inorder(r);cout<<endl;
            printf("%d %d\n",i,k);
            root=merge(l,r);
            split(root,k,l,r);
            split(l,i-1,l,p);
            due(p,-1);
            root=merge(merge(l,p),r);
            //inorder(root);cout<<endl;
        }
    }
    return 0;
}
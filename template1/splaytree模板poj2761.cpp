# include <iostream>
# include <Cstdio>
# include <algorithm>
# define N 200000
# define M 100000
using namespace std;

struct node
{
    int key;
    int l,r,f,num;   
};

struct ASK
{
    int s,t,kth;
    int id,res;   
};

class SplayTree
{
public:
    node p[N];
    int root,size,tsize;
    SplayTree()
    {
        size=0;
        root=0;
        tsize=0; 
        p[0].num=0;      
    } 
    
    void rot_l(int x)
    {
        int y=p[x].f;
        p[y].r=p[x].l;
        p[y].num=p[p[y].l].num+p[p[x].l].num+1;
        p[x].num=p[p[x].r].num+p[y].num+1;
        if (p[x].l!=0)
        p[p[x].l].f=y;
        p[x].f=p[y].f;
        p[x].l=y;
        if (p[y].f!=0)
        {
            if (p[p[y].f].l==y)
            p[p[y].f].l=x;
            else
            p[p[y].f].r=x;          
        }
        p[y].f=x;
    }
    
    void rot_r(int x)
    {
        int y=p[x].f;
        p[y].l=p[x].r;
        p[y].num=p[p[y].r].num+p[p[x].r].num+1;
        p[x].num=p[p[x].l].num+p[y].num+1;
        if (p[x].r!=0)
        p[p[x].r].f=y;
        p[x].f=p[y].f;
        p[x].r=y;
        if (p[y].f!=0)
        {
            if (p[p[y].f].l==y)
            p[p[y].f].l=x;
            else
            p[p[y].f].r=x;           
        } 
        p[y].f=x;
    }
    
    void splay(int x)
    {
        int y;
        while (p[x].f!=0)
        {
            y=p[x].f;
            if (p[y].f==0)
            {
                if (p[y].l==x)
                rot_r(x);
                else
                rot_l(x);
                break;          
            } 
            if (p[y].l==x)
            {
                if (p[p[y].f].l==y)
                {
                    rot_r(y);
                    rot_r(x);               
                }
                else
                {
                    rot_r(x);
                    rot_l(x);
                }          
            }
            if (p[y].r==x)
            {
                if (p[p[y].f].r==y)
                {
                    rot_l(y);
                    rot_l(x);                
                }          
                else
                {
                    rot_l(x);
                    rot_r(x);
                }
            }
        }
        root=x; 
    }
    
    int search(int x,int key)
    {
        while (x!=0&&p[x].key!=key)
        {
            if (key<p[x].key)
            x=p[x].l;
            else
            x=p[x].r;  
        }
        if (x==0)
        return -1;
        return x;
    }
    
    void insert(int x,int key)
    {
        if (root==0)
        {
            root=size=tsize=1;
            p[1].f=0;
            p[1].num=1;
            p[1].l=p[1].r=0;
            p[1].key=key;
            return;        
        }
        int pre;
        while (x!=0)
        {
            pre=x;
            if (key<p[x].key)
            x=p[x].l;
            else
            x=p[x].r;  
        }
        x=++tsize;
        p[x].f=pre;
        p[x].key=key;
        p[x].num=1;
        p[pre].num++;
        if (key<p[pre].key)
        p[pre].l=x;
        else
        p[pre].r=x;           
        splay(x);           
    }
    
    void unio(int a,int b)
    {
        int i=a,j=b;
        while (p[i].r!=0)
        i=p[i].r;
        splay(i);
        p[i].r=b;
        p[i].num=p[p[i].l].num+p[p[i].r].num+1;
        p[b].f=i; 
    }
    
    void remove(int key)
    {
        int x=search(root,key);
        if (x==-1)
        return;
        splay(x);
        if (p[x].l==0&&p[x].r==0)
        {
            root=size=0;
            return;                     
        } 
        if (p[x].l==0)
        {
            root=p[x].r;
            size--;
            p[p[x].r].f=0;
            return;          
        }
        if (p[x].r==0)
        {
            root=p[x].l;
            size--;
            p[p[x].l].f=0;
            return;          
        }
        int l=p[x].l,r=p[x].r;
        p[l].f=0;
        p[r].f=0;
        unio(l,r);
        size--;
    }
    
    int find(int k,int kth)
    {
        while (1)
        {
            if (kth==p[p[k].l].num+1) break;
            if (kth<p[p[k].l].num+1) k=p[k].l;
            else
            {              
                kth=kth-p[p[k].l].num-1;
                k=p[k].r;
            }
        }
        return p[k].key;        
    }
    
    void print(int k)
    {
         if (k==0) return;
         if (p[k].l!=0)
         print(p[k].l);
         printf("%d\n",p[k].key);
         if (p[k].r!=0)
         print(p[k].r);
    }     
};

int cmp1(ASK req1,ASK req2)
{
    return req1.s<req2.s;
}

int cmp2(ASK req1,ASK req2)
{
    return req1.id<req2.id;
}

int n,m,dog[N];
ASK req[M];
SplayTree T;
           
int main()
{
    int i,j;
    scanf("%d%d",&n,&m);
    for (i=1;i<=n;i++)
    scanf("%d",&dog[i]);
    for (i=1;i<=m;i++)
    {
        scanf("%d%d%d",&req[i].s,&req[i].t,&req[i].kth);
        req[i].id=i;
        req[i].res=0;
    }   
    sort(req+1,req+m+1,cmp1);
    for (i=req[1].s;i<=req[1].t;i++)
    T.insert(T.root,dog[i]);
    req[1].res=T.find(T.root,req[1].kth);
    for (i=2;i<=m;i++)
    {
        for(j=req[i-1].s;(j<req[i].s)&&(j<=req[i-1].t);j++)
        T.remove(dog[j]);
        for(j=req[i].t;j>=req[i].s&&j>req[i-1].t;j--)
        T.insert(T.root,dog[j]);
        req[i].res=T.find(T.root,req[i].kth);
    }  
    sort(req+1,req+m+1,cmp2);
    for (i=1;i<=m;i++)
    printf("%d\n",req[i].res); 
    system("pause");
    return 1;
}

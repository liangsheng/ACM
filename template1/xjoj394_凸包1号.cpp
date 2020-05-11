# include <iostream>
# include <cstdio>
# include <algorithm>
# include <cmath> 
using namespace std;
struct mypoint
{
    double x,y;   
};
mypoint a[10001],stack[10001];
int n,top;
double dis(mypoint p1,mypoint p2)
{
     double ans=(p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y);
     return sqrt(ans);  
}
double judge(mypoint p1,mypoint p2,mypoint p0)
{   //cout<<p1.x<<" "<<p1.y<<" "<<p2.x<<" "<<p2.y<<" "<<p0.x<<" "<<p0.y;system("pause");
    mypoint t1,t2;
    t1.x=p1.x-p0.x;
    t1.y=p1.y-p0.y;
    t2.x=p2.x-p0.x;
    t2.y=p2.y-p0.y;
    double r=t1.x*t2.y-t1.y*t2.x;
    //if (p0.x==7&&p0.y==8){
    //cout<<t1.x<<" "<<t1.y<<" "<<t2.x<<" "<<t2.y<<" "<<r;system("pause");}
    return r;
}
int cmp(mypoint p1,mypoint p2)
{
    double ans=judge(p1,p2,a[1]);
    if (ans>0) 
    return 1;
    if (ans==0&&dis(p1,a[1])<dis(p2,a[1]))
    return 1;
    return 0;
}
int graham()
{//cout<<"ww"<<" "<<judge(a[4],a[1],a[2]);system("pause");
    double m;
    int i;
    top=2;
    stack[1]=a[1];
    stack[2]=a[2];
    for (i=3;i<=n;i++)
    {
        top++;
        stack[top]=a[i];//cout<<"24423423";
        m=judge(stack[top],stack[top-2],stack[top-1]);//cout<<"m="<<m;system("pause");
        while (m<0)
        {
             stack[top-1]=stack[top];
             top--;
             //cout<<"xy"<<" "<<stack[top-1].x<<" "<<stack[top-1].y;system("pause");
             m=judge(stack[top],stack[top-2],stack[top-1]);
             //cout<<"top="<<top<<" "<<"m="<<m;system("pause");
        }
        //cout<<"top="<<top;system("pause");
    } 
}
int cout_ans()
{//cout<<top;system("pause");
    double ans=0.0;
    int i;
    for (i=1;i<top;i++)
    ans+=dis(stack[i],stack[i+1]);
    ans+=dis(a[1],stack[top]);
    printf("%.2lf\n",ans);
    return 1;
}
int main()
{
    int i,k;
    double mx=999999.0,my=999999.0;
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        scanf("%lf %lf",&a[i].x,&a[i].y);
        if (a[i].x<mx||(a[i].x==mx&&a[i].y<my))
        {
           mx=a[i].x;
           my=a[i].y;
           k=i;           
        }
    }
    swap(a[1],a[k]);
    sort(a+2,a+n+1,cmp);
    //for (i=1;i<=n;i++)
    //cout<<i<<" "<<a[i].x<<" "<<a[i].y<<endl;
    //system("pause");
    graham();
    cout_ans();
    system("pause");
    return 1;
}

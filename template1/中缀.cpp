# include <iostream>
# include <cstdio>
# include <cstring>
# include <vector>
# include <stack>
# include <map>
using namespace std;

struct NODE
{
    int tag; //0:nothing,1:int,2:operator
    int v;   
};
       
int come_in[9],come_out[9],is_right;       
string s;
vector<NODE> que,ans;
map<char,int> turn;

int power(int x,int y)
{
    int i,ans=1;
    for (i=1;i<=y;i++)
    ans*=x;
    return ans;
}

int init()
{
    come_in[1]=0,come_out[1]=0;
    come_in[2]=6,come_out[2]=1;
    come_in[3]=4,come_out[3]=5;
    come_in[4]=4,come_out[4]=5;
    come_in[5]=4,come_out[5]=5;
    come_in[6]=2,come_out[6]=3;
    come_in[7]=2,come_out[7]=3;
    come_in[8]=1,come_out[8]=6;
    turn['#']=1,turn['(']=2;
    turn['*']=3,turn['/']=4;
    turn['%']=5,turn['+']=6;
    turn['-']=7,turn[')']=8;
    return 1;
}

int my_scanf()
{
    int i,j,p,t,temp,size;
    NODE now;
    cin>>s;
    size=s.size();
    que.clear();
    for (i=0;i<size;i++)
    {
        if (s[i]>='0'&&s[i]<='9')
        {
           p=i;
           while (s[i+1]>='0'&&s[i+1]<='9') i++;
           temp=power(10,i-p);
           t=0;
           for (j=p;j<=i;j++)
           {
               t+=temp*(s[j]-48);
               temp/=10;
           }
           now.tag=1;
           now.v=t;
           que.push_back(now);                      
        }
        if (s[i]<'0'||s[i]>'9')
        {
           now.tag=2;
           now.v=turn[s[i]];
           que.push_back(now);                    
        }
    }   
    size=que.size();
    for (i=0;i<size;i++)    //deal with the '-'
    if (que[i].tag==2&&que[i].v==7)
    if (i-1==-1||(que[i-1].tag==2&&que[i-1].v!=8))
    {
       que[i].tag=0;
       que[i+1].v=-que[i+1].v;                          
    }
    return 1;
}

int have_a_chang()
{
    int i,top,size=que.size();
    NODE temp;
    stack<int> q;
    ans.clear();
    top=1;
    temp.tag=2;
    q.push(top); 
    for (i=0;i<size;i++)
    {
        if (que[i].tag==0)
        continue;
        if (que[i].tag==1)
        {
           ans.push_back(que[i]);
           continue;               
        }
        top=q.top();
        if (come_in[que[i].v]>come_out[top])
        {
           q.push(que[i].v);
           continue;                                 
        }
        while (come_out[top]>come_in[que[i].v]&&top!=1)
        {
            temp.v=top;
            ans.push_back(temp);
            q.pop(); 
            top=q.top(); 
        }
        if (que[i].v==8) 
        q.pop();
        else
        q.push(que[i].v);
    }
    while (!q.empty())
    {
        temp.v=q.top();
        if (temp.v!=1)
        ans.push_back(temp);
        q.pop();  
    }
    return 1;
}

int get_ans()
{
    int i,t1,t2,size=ans.size();
    stack<int> q;
    is_right=1;
    for (i=0;i<size;i++)
    {
        if (ans[i].tag==1)
        {
           q.push(ans[i].v);
           continue;              
        }
        if (ans[i].tag==2)
        {
           if (!q.empty())
           t2=q.top(),q.pop();
           else
           {
               is_right=0;
               return -1;
           }
           if (!q.empty())
           t1=q.top(),q.pop();
           else
           {
               is_right=0;
               return -1;
           }
           if (ans[i].v==3) q.push(t1*t2);
           if (ans[i].v==4) 
           {
              if (t2==0)
              {
                 is_right=0;
                 return -1;       
              }
              q.push(t1/t2);             
           }               
           if (ans[i].v==5)
           {
              if (t2==0)
              {
                 is_right=0;
                 return -1;       
              }
              q.push(t1%t2);            
           } 
           if (ans[i].v==6) q.push(t1+t2);
           if (ans[i].v==7) q.push(t1-t2);      
        }
    }
    
    return q.top();
}

int main()
{
    int ans;
    init();
    my_scanf();
    have_a_chang();
    ans=get_ans();
    if (is_right)
    printf("%d\n",ans);
    else
    printf("ERROR\n");
    system("pause");
    return 1;
}

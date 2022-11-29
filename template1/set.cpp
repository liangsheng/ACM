# include <iostream>
# include <cstdio>
# include <set>
using namespace std;
int main(){int y;
set<int> q;
for (int i=1;i<=4;i++)
{cin>>y;q.insert(y);}
if (q.find(4)!=q.end())
q.erase(4);
if (q.find(4)!=q.end())
cout<<1;
set<int>::iterator ii;
int i=0;
for (ii=q.begin();ii!=q.end();++ii,++i)
{
    if ((*ii)==3) break;
}
cout<<i;
system("pause");
return 1;    
}

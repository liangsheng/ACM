# include <iostream>  
# include <cstdio>
# include <set>   

using namespace std; 
  
struct stu{   
    int x,y;      
};   

class stu1:greater<stu>   
{   
      public:   
      bool operator () (stu b1,stu b2) const
      {   
        return b1.x<b2.x;   
      }   
}; 
  
int main()   
{   
    set<stu,stu1> a;   
    for(int i=0;i<3;i++)
    {   
        stu d;   
        cin>>d.x>>d.y;   
        a.insert(d);   
    }   
    set<stu,stu1 >::iterator l;   
    for(l=a.begin();l!=a.end();l++) 
    cout<<l->x<<" "<<l->y<<endl;      
    system("pause");
    return 1;
} 

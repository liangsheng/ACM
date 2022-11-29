#include <bits/stdc++.h>

#define file_r(x) freopen(x,  "r",  stdin)
#define file_w(x) freopen(x,  "w",  stdout)

using namespace std;

int t,n;
int m[10005];

int main()
{
    int i,j,k,t1,t2,t3,ti,ni,re1,re2,b;
    long long l1,l2,l3,l4;
//    file_r("B-large-practice.in");
//    file_w("B-large-practice2.out");
    cin>>t;
    for (ti = 1; ti != t + 1; ++ti) {
        cin>>n>>b;
        for (ni = 0; ni != n; ++ni) {
            cin>>m[ni];
        }
        if (n >= b) {
            cout<<"Case #"<<ti<<": "<<b<<endl;
            continue;
        }
        l1 = 0;
        l2 = 1000000000;
        l2 *= 100001;
        while (l1 < l2 - 1) {
            l3 = (l1 + l2) / 2;
            l4 = 0;
            for (i = 0;i != n; ++i) {
                l4 += l3 / m[i];
                ++l4;
            }
            if (l4 >= b) {
               l2 = l3;
            } else {
               l1 = l3;
            }
        }
        //cout<<l2<<endl;
        l4 = 0;
        for (i = 0; i != n; ++i) {
            l4 += l1 / m[i];
            ++l4;
        }
        l4 = b - l4;
        l3 = 0;
        for (i = 0; i != n; ++i) {
            if (l2 % m[i] == 0) {
               ++l3;
               if (l3 == l4) {
                  cout<<"Case #"<<ti<<": "<<i+1<<endl;
                  break;
               }
            }
        }
    }
    return 0;
}

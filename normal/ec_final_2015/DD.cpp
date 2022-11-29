#include<cstring>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    //freopen("a.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    for(int cas = 1; cas <= t; cas++){
        double a, b, ans = 0.01;
        scanf("%lf%lf", &a, &b);
        double aa = a, bb = b;
        while(b < 1){
            b *= 10;
        }
        while(b >= 10){
            b /= 10;
        }
        //cout << cnt1 << endl << cnt2 << endl;
        if(b == 1 && bb*2 != a) ans = 0.02;
        printf("Case #%d: %.2f\n", cas, ans);

    }
    return 0;
}

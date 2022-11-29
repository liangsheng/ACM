#include <iostream>
#include <fstream>
#define file_r(x) freopen(x,  "r",  stdin)
#define file_w(x) freopen(x,  "w",  stdout)
using namespace std;
int problems[100000+100];
int main()
{
    file_r("in.in");
    file_w("out2.out");
    int t, n;
    cin>>t;
    for(int c = 1; c <= t; c++){
        cin>>n;
        for(int i =  0; i < n; i++)
            cin>>problems[i];
        int cnt = 0, ans = 1, last = problems[0];
        for(int i = 1; i < n; i++){
            int tmp = problems[i] - last;
            if(tmp <= 0){
                cnt += (4 - ans);
                ans = 1;
                last = problems[i];
            }
            else if(tmp <= 10){
                ans++;
                last = problems[i];
                if(ans == 4 && i == n-1)
                    break;
                if(ans == 4 && i < n-1){
                    ans = 1;
                    last = problems[++i];
                }
            }
            else if(tmp <= 20){
                if(ans == 1){
                    cnt++;
                    ans += 2;
                    last = problems[i];
                }
                else if(ans == 2){
                    cnt++;
                    if(i == n-1){
                        ans = 4;
                        break;
                    }
                    else{
                        ans = 1;
                        last = problems[++i];
                    }
                }
                else if(ans == 3){
                    cnt++;
                    ans = 1;
                    last = problems[i];
                }
            }
            else if(tmp <= 30){
                if(ans == 1){
                    cnt += 2;
                    if(i == n-1){
                        ans = 4;
                        break;
                    }
                    else{
                        ans = 1;
                        last = problems[++i];
                    }
                }
                else{
                    cnt += (4 - ans);
                    ans = 1;
                    last = problems[i];
                }
            }
            else{
                cnt += (4 - ans);
                ans = 1;
                last = problems[i];
            }
        }
        cnt += (4 - ans);
        cout<<"Case #"<<c<<": "<<cnt<<endl;
    }
    return 0;
}

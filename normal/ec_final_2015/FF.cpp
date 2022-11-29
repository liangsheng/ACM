#include<cstring>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
const int mod = 1000000007;
long long dp[1000005];  //dp[i]表示考虑到第i个蚂蚁
long long poww[1000005]; //2^n
long long a1[1000005];  //蚂蚁重量前缀和
long long a2[1000005];  //dp[]的前缀和
long long m[1000005];

void init(){
    poww[0] = 1;
    a1[0] = 0;
    for(int i = 1; i < 1000005; i++){
        poww[i] = (poww[i-1]<<1)%mod;
        poww[i] %= mod;
    }
    for(int i = 1; i < 1000005; i++){
        a1[i] = a1[i-1]+i;
    }
    m[0] = 0;
    for(long long i = 1; i < 1000005; i++){
        long long tmp = m[i-1];
        long long tmp2 = i*(i+1);
        while(2*tmp*(tmp+1) < tmp2) tmp++;
        m[i] = tmp;
    }
}

int main(){
    freopen("in.txt", "r", stdin);
    freopen("out2.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    init();
    int n, k, cas = 0;
    for(cas = 1; cas <= t; cas++){
    //for (n = 1; n <= 10; n++) for (k = 1; k <= n; k++) {
        memset(a2, 0, sizeof(a2));
        scanf("%d%d", &n, &k);
        printf("Case #%d: ", cas);
        if(n == 1 && k == 1){
            cout << "2" << endl;
            continue;
        }
        memset(dp, 0, sizeof(dp));
        for(long long i = k; i <= n; i++){
            if(i == k){
                long long sum = k;
                for(int j = k-1; j >= 1; j--){
                    if(sum > a1[j]){
                        dp[k] = poww[j+1];
                        break;
                    }
                    sum += j;
                }
                a2[i] = dp[i];
            }else{
                if(m[i] >= k)
                    dp[i] = ((a2[i-1]-a2[m[i]-1])%mod+mod)%mod;
                else
                    dp[i] = a2[i-1];
                a2[i] = (a2[i-1]+dp[i])%mod;
            }

        }
        printf("%lld\n", dp[n]);

    }
    return 0;
}

/* ***********************************************
Author        :kuangbin
Created Time  :2015/6/13 19:07:57
File Name     :F:\ACM\2015ACM\BestCoder\BC44\B.cpp
************************************************ */

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

const long long MOD = 998244353;
int bit[30];

int a[100010];
long long ans ;

struct Trie{
    int next[30*50010][2];
    int num[30*50010];
    int root,tot;
    int newnode(){
        num[tot] = 0;
        next[tot][0] = next[tot][1] = -1;
        tot++;
        return tot-1;
    }
    void init(){
        tot = 0;
        root = newnode();
    }
    void insert(int val){
        int now = root;
        for(int i = 0;i < 30;i++){
            int id;
            if(val&bit[i])id = 1;
            else id = 0;
            if(next[now][id^1] != -1){
                ans += (long long)bit[i]*num[next[now][id^1]]%MOD;
                ans %= MOD;
            }
            if(next[now][id] == -1)
                next[now][id] = newnode();
            now = next[now][id];
            num[now]++;
        }
    }
}tree;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    bit[0] = 1;
    for(int i = 1;i < 30;i++)
        bit[i] = 2*bit[i-1];
    int T;
    int iCase = 0;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        ans = 0;
        tree.init();
        for(int i = 0;i < n;i++){
            scanf("%d",&a[i]);
            tree.insert(a[i]);
        }
        ans = ans*2%MOD;
        iCase++;
        printf("Case #%d: %I64d\n",iCase,ans);
    }
    return 0;
}

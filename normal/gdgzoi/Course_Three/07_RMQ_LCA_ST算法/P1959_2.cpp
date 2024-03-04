#include<bits/stdc++.h>
#define ll long long
using namespace std;
 
const int N = 20 + 5;
int n, ans, a[N];
ll sta[N];
unordered_map<int, unordered_set<ll> > mp;
unordered_map<ll, bool> vis;
 
void dfs(int k, int lim, ll state, int sum){
    if(k == lim + 1){
        if(lim == (n >> 1))
            mp[sum].insert(state);
        else{
            for(auto v: mp[-sum]){
                if(!vis[v + state])
                    vis[v + state] = 1, ++ans;
            }
        }
        return ;
    }
    dfs(k + 1, lim, state + sta[k], sum + a[k]);
    dfs(k + 1, lim, state + sta[k], sum - a[k]);
    dfs(k + 1, lim, state, sum);
}
 
int main(){
    scanf("%d", &n);
    sta[1] = 1;
    for(int i=1;i<=n;i++)
        scanf("%d", &a[i]);
    for(int i=2;i<=n;i++)
        sta[i] = sta[i - 1] << 1;
    dfs(1, n / 2, 0, 0);
    dfs(n / 2 + 1, n, 0, 0);
    printf("%d\n", ans - 1);
    return 0;
}

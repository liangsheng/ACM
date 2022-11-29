#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
 
const int MOD = 998'244'353;
 
int main(){
  unordered_map<ll, ll> MEMO;
  auto f = [&](auto self, ll X) -> ll {
    if(MEMO.count(X)) return MEMO[X];
    auto& res = MEMO[X];
    if(X <= 4) return (res = X);
    ll X1 = X / 2;
    ll X2 = (X + 1) / 2;
    return (res = self(self, X1) * self(self, X2) % MOD);
  };
  
  ll X;
  cin >> X;
  cout << f(f, X) << endl;
}
#include "bits/stdc++.h"
using namespace std;

#define int long long int
#define double long double
#define endl '\n'

const int MOD = 1000000007;

void solve(){
    // Observations:
    // 1. All 2nd type moves can be made at the end
    // 2. Answer cannot be more than N
    // 3. In any prefix decrement move, we use less than N moves.
    // 4. If j<i and A[j]<A[i], A[i] will never be 0 using type 1 moves
    // 5. Hence type 1 moves can be used only on prefix minimum elemnts.
    // 6. Its optimal to make the suffixes of the prefix 0.
    int n;
    cin>>n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin>>a[i];
    }
    vector<int> _min;
    _min.push_back(a[0]);
    for (int i = 1; i < n; i++) {
        if (a[i]<=_min.back()){
            _min.push_back(a[i]);
        }
    }
    int ans = n;
    reverse(_min.begin(),_min.end());
    for (int i = 0; i < _min.size(); i++) {
        // use n-1-i type2 and _min[i] type1 moves
        ans = min(ans, n-i-1+_min[i]);
    }
    cout<<ans<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t=1;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}
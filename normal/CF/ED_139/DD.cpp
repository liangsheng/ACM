#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
 
constexpr int N = 1E7;
 
int mp[N + 1];
std::vector<int> primes;
 
void solve() {
    int x, y;
    std::cin >> x >> y;
    
    int d = y - x;
    if (d == 1) {
        std::cout << -1 << "\n";
        return;
    }
    
    int ans = 1E9;
    while (d > 1) {
        int p = mp[d];
        d /= p;
        ans = std::min(ans, (p - x % p) % p);
    }
    
    std::cout << ans << "\n";
}
 
int main() {
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    
    int cnt = 0;
    for (int i = 2; i <= N; i++) {
        cout << "i:" << i;
        if (!mp[i]) {
            mp[i] = i;
            cnt++;
            cout << " " << i;
            primes.push_back(i);
        }
        
        for (auto p : primes) {
            if (i * p > N) break;
            mp[i * p] = p;
            cnt++;
            cout << " " << i * p;
            if (i % p == 0) break;
        }
        cout << '\n';
        if (i == 100)
         break;
    }
    cout << N << '\n' << cnt << '\n';
    
    int t;
    std::cin >> t;
    
    while (t--) solve();
    
    return 0;
}
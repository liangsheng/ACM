#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int H, W;
    std::cin >> H >> W;
    
    std::vector<std::set<int>> r(H), c(W);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            r[i].insert(j);
            c[j].insert(i);
        }
    }
    
    int Q;
    std::cin >> Q;
    
    int ans = H * W;
    while (Q--) {
        int x, y;
        std::cin >> x >> y;
        x--;
        y--;
        
        if (r[x].contains(y)) {
            ans--;
            r[x].erase(y);
            c[y].erase(x);
        } else {
            auto it = r[x].lower_bound(y);
            if (it != r[x].begin()) {
                int b = *std::prev(it);
                ans--;
                r[x].erase(b);
                c[b].erase(x);
            }
            if (it != r[x].end()) {
                int b = *it;
                ans--;
                r[x].erase(b);
                c[b].erase(x);
            }
            it = c[y].lower_bound(x);
            if (it != c[y].begin()) {
                int a = *std::prev(it);
                ans--;
                r[a].erase(y);
                c[y].erase(a);
            }
            if (it != c[y].end()) {
                int a = *it;
                ans--;
                r[a].erase(y);
                c[y].erase(a);
            }
        }
    }
    std::cout << ans << "\n";
    
    return 0;
}
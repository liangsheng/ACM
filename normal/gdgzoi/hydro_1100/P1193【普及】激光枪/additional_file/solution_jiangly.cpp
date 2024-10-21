// https://atcoder.jp/contests/abc374/submissions/58447196
#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;
    std::cin >> N;
    
    int S, T;
    std::cin >> S >> T;
    
    std::vector<int> A(N), B(N), C(N), D(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i] >> B[i] >> C[i] >> D[i];
    }
    
    double ans = INFINITY;
    std::vector<bool> vis(N);
    auto dfs = [&](auto &self, int x, int y, double sum = 0.0, int c = 0) {
        if (c == N) {
            ans = std::min(ans, sum);
            return;
        }
        for (int i = 0; i < N; i++) {
            if (vis[i]) {
                continue;
            }
            double d1 = std::hypot(A[i] - x, B[i] - y);
            double d2 = std::hypot(C[i] - x, D[i] - y);
            double d0 = std::hypot(A[i] - C[i], B[i] - D[i]);
            vis[i] = true;
            self(self, C[i], D[i], sum + d1 / S + d0 / T, c + 1);
            self(self, A[i], B[i], sum + d2 / S + d0 / T, c + 1);
            vis[i] = false;
        }
    };
    dfs(dfs, 0, 0);
    std::cout << std::fixed << std::setprecision(20) << ans << "\n";
    
    return 0;
}

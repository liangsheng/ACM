#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    // O(n ^ 5), 40分
    auto get_40 = [&]() {
        i64 ans = 0;
        for (int x1 = 0; x1 < n; x1++) for (int y1 = x1; y1 < n; y1++) {
            for (int x2 = y1 + 1; x2 < n; x2++) for (int y2 = x2; y2 < n; y2++) {
                // [x1, y1], [x2, y2]
                int tmp = 0;
                for (int i = x1; i <= y1; i++) {
                    tmp ^= a[i];
                }
                for (int i = x2; i <= y2; i++) {
                    tmp ^= a[i];
                }
                ans += (tmp == m);
            }
        }
        return ans;
    };

    // O(n ^ 4), 前缀和优化, 60分
    auto get_60 = [&]() {
        i64 ans = 0;

        // f[i] = a[1] ^ a[2] ^ ... a[i]
        vector<int> f(n + 1, 0);
        for (int i = 1; i <= n; i++) f[i] = f[i - 1] ^ a[i];

        for (int x1 = 1; x1 <= n; x1++) for (int y1 = x1; y1 <= n; y1++) {
            for (int x2 = y1 + 1; x2 <= n; x2++) for (int y2 = x2; y2 <= n; y2++) {
                // [x1, y1], [x2, y2]
                int tmp = f[y1] ^ f[x1 - 1] ^ f[y2] ^ f[x2 - 1];
                ans += (tmp == m);
            }
        }
        return ans;
    };

    // O(n * m) 模仿最大两段和, 80分, 最后 2 组 MLE
    auto get_80 = [&]() {
        i64 ans = 0;

        // L[i][j] : 以 a[i] 结尾, 异或和是 j 的方案数
        vector<vector<int>> L(n + 2, vector<int>(2048, 0));
        for (int i = 1; i <= n; i++) {
            L[i][a[i]] = 1;
            for (int j = 0; j < 2048; j++) {
                L[i][j ^ a[i]] += L[i - 1][j];
            }
        }

        // R[i][j] : 以 a[i] 开头, 异或和是 j 的方案数
        vector<vector<int>> R(n + 2, vector<int>(2048, 0));
        for (int i = n; i >= 1; i--) {
            R[i][a[i]] = 1;
            for (int j = 0; j < 2048; j++) {
                R[i][j ^ a[i]] += R[i + 1][j];
            }
        }

        // R[i][j] : 以开头的节点是 a[i, i + 1,..., n] 的, 异或和是 j 的方案数
        for (int i = n; i >= 1; i--) {
            for (int j = 0; j < 2048; j++) {
                R[i][j] += R[i + 1][j];
            }
        }

        for (int i = 1; i <= n; i++) for (int j = 0; j < 2048; j++) {
            ans += L[i][j] * R[i + 1][m ^ j];
        }
        return ans;
    };

    // O(n * m) 将 L 数组变成 1 维 80分, 最后 2 组 MLE
    // R 数组求和
    auto get_80_1 = [&]() {
        i64 ans = 0;

        vector<vector<int>> R(n + 2, vector<int>(2048, 0));
        for (int i = n; i >= 1; i--) {
            R[i][a[i]] = 1;
            for (int j = 0; j < 2048; j++) {
                R[i][j ^ a[i]] += R[i + 1][j];
            }
        }

        // R[i][j] : 以开头的节点是 a[i, i + 1,..., n] 的, 异或和是 j 的方案数
        for (int i = n; i >= 1; i--) {
            for (int j = 0; j < 2048; j++) {
                R[i][j] += R[i + 1][j];
            }
        }

        // L[i][j] : 以 a[i] 结尾, 异或和是 j 的方案数
        vector<int> L(2048, 0);
        for (int i = 1; i <= n; i++) {
            vector<int> t(2048, 0);
            t[a[i]] = 1;
            for (int j = 0; j < 2048; j++) t[j ^ a[i]] += L[j];
            L = t;
            for (int j = 0; j < 2048; j++) {
                ans += L[j] * R[i + 1][j ^ m];
            }
        }
        return ans;
    };

    // O(n * m) 将 L 数组变成 1 维 80分, 最后 2 组 MLE
    // L 数组求和
    auto get_80_2 = [&]() {
        i64 ans = 0;

        vector<vector<int>> R(n + 2, vector<int>(2048, 0));
        for (int i = n; i >= 1; i--) {
            R[i][a[i]] = 1;
            for (int j = 0; j < 2048; j++) {
                R[i][j ^ a[i]] += R[i + 1][j];
            }
        }

        // L[i][j] : 以 a[i] 结尾, 异或和是 j 的方案数
        // f[j]: L 的前缀和
        vector<int> L(2048, 0), f(2048, 0);
        for (int i = 1; i <= n; i++) {
            vector<int> t(2048, 0);
            t[a[i]] = 1;
            for (int j = 0; j < 2048; j++) t[j ^ a[i]] += L[j];
            L = t;
            for (int j = 0; j < 2048; j++) f[j] += L[j];
            for (int j = 0; j < 2048; j++) {
                ans += f[j] * R[i + 1][j ^ m];
            }
        }
        return ans;
    };

    // O(n * m) 将 L, R 数组变成 1 维 100分
    // 将 (对应 i 的 L 数组) 还原成 (对应 i-1 的 L 数组)
    auto get_100 = [&]() {
        i64 ans = 0;

        vector<int> L(2048, 0);
        for (int i = 1; i < n; i++) {
            vector<int> t(2048, 0);
            t[a[i]] = 1;
            for (int j = 0; j < 2048; j++) t[j ^ a[i]] += L[j];
            L = t;       
        }
        vector<int> R(2048, 0), r(2048, 0);
        for (int i = n; i >= 2; i--) {
            vector<int> t(2048, 0);
            t[a[i]] = 1;
            for (int j = 0; j < 2048; j++) t[j ^ a[i]] += r[j];
            r = t;

            for (int j = 0; j < 2048; j++) R[j] += r[j];
            for (int j = 0; j < 2048; j++) ans += L[j] * R[j ^ m];

            // 将 (对应 i 的 L 数组) 还原成 (对应 i-1 的 L 数组)
            L[a[i - 1]]--;
            fill(t.begin(), t.end(), 0);
            for (int j = 0; j < 2048; j++) t[j] = L[j ^ a[i - 1]];
            L = t;
        }
        return ans;
    };

    cout << get_100() << '\n';
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

// 遍历所有子集
void all_sub() {
    // 13 的二进制是 1101
    // 所有子集是 1(0001), 4(0100), 5(0101), 8(1000), 9(1001), 12(1100), 13(1101)
    int st = 13;
    for (int i = st; i > 0; i = (i - 1) & st) cout << i << '\n';
}

// 遍历所有大小为 k 的子集
void all_sub_k() {
    // 1111 所有大小为 2 的子集是 3(0011), 5(0101), 6(0110), 9(1001), 10(1010), 12(1100)
    int n = 4, k = 2;
    int comb = (1 << k) - 1;
    while (comb < 1 << n) {
        cout << comb << '\n';
        int x = comb & -comb, y = comb + x;
        comb = ((comb & ~y) / x >> 1) | y;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, r;
    cin >> n >> r;

    int comb = (1 << r) - 1;
    while (comb < 1 << n) {
        int c = 0;
        for (int i = 0; i < n; i++) if (comb >> i & 1) {
            cout << i + 1;
            if (++c == r) cout << '\n';
            else cout << ' ';
        }
        int x = comb & -comb, y = comb + x;
        comb = ((comb & ~y) / x >> 1) | y;
    }

    return 0;
}

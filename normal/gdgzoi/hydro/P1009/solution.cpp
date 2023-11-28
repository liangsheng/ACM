#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, m, t;
    cin >> n >> m;
    while (m != 0) {
        // 把大的数放在 n, 小的数放在 m
        // 如果 n < m, 就 swap(n, m)
        if (n < m) {
            t = n;
            n = m;
            m = t;
        }
        t = m;
        // 把 m 变成 n % m
        m = n % m;
        // n 变成原来的 m
        n = t;
    }
    cout << n << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int gao(int x) {
    set<int> q;
    q.insert(x);
    while (1) {
        if (x % 2) x += 3;
        else x /= 2;
        if (q.count(x)) return x;
        q.insert(x);
    }
}

int main() {
    int x;
    // while (cin >> x) cout << gao(x) << '\n';
    for (int i = 1; i <= 100; i++) cout << i << ' ' << gao(i) << '\n';
    return 0;
}
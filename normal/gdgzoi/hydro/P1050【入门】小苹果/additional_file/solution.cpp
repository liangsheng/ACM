#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        int tol = 0, idx = 0, m = n;
        while (m > 0) {
            tol++;
            if (idx == 0 && m % 3 == 1) idx = tol;
            m = m * 2 / 3;
        }
        cout << tol << ' ' << idx << '\n';
    }
    return 0;
}
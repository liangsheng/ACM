#include <bits/stdc++.h>
using namespace std;

void gen_arr(int n, int l, int r) {
    for (int i = 0; i < n; i++) {
        int x = rand() % 10;
        cout << x;
        if (i != n - 1) cout << ' ';
        else cout << '\n';
    }
}

int main() {
    srand(time(0));
    int T = 5;
    for (int t = 1, d = 10; t <= T; t++, d *= 10) {
        freopen(("./in/" + to_string(t) + ".in").c_str(), "w", stdout);
        int n = rand() % d + 1, m = rand() % d + 1;
        cout << n << ' ' << m << '\n';
        gen_arr(n + 1, 0, 9);
        gen_arr(m + 1, 0, 9);
        cout.clear();
    }
    fclose(stdout);
    return 0;
}
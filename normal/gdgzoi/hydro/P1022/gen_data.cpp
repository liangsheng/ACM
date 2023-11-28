#include <bits/stdc++.h>
using namespace std;

int rand(int l, int r) {
    return rand() % (r - l + 1) + l;
}

int main() {
    srand(time(0));
    int T = 5;
    freopen("./in/1.in", "w", stdout);
    cout << T << endl;
    vector<int> a = {0, 10, 20, 50, 100, 500, 1000, 2000, 5000, 10000, 50000};
    for (int t = 1; t <= T; t++) {
        int n = rand(a[t - 1], a[t]);
        int m = rand() % n + 1;
        if (rand() % 3 == 0) m = n;
        cout << n << ' ' << m << '\n';
        for (int i = 0; i < n; i++) {
            cout << rand() % 100 << ' ';
        }
        cout << endl;
        cout.clear();
    }
    fclose(stdout);
    return 0;
}
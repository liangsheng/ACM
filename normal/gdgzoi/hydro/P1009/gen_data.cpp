#include <bits/stdc++.h>
using namespace std;

int rand(int l, int r) {
    return rand() % (r - l + 1) + l;
}

int main() {
    srand(time(0));
    int T = 5;
    vector<int> a(T);
    a[0] = 14, a[1] = 50, a[2] = 43, a[3] = 1, a[4] = 45;
    for (int t = 1; t <= T; t++) {
        freopen(("./in/" + to_string(t) + ".in").c_str(), "w", stdout);
        int l = rand(30000000, 40000000);
        int r = rand(30000000, 40000000);
        cout << l * a[t - 1] << ' ' << r * a[t - 1] << '\n';
        cout.clear();
    }
    fclose(stdout);
    return 0;
}
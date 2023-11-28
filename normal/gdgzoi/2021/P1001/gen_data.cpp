#include <bits/stdc++.h>
using namespace std;

int main() {
    srand(time(0));
    int T = 5;
    vector<int> a = {3, 104857601, 167772161, 469762049, 998244353};
    for (int t = 1; t <= T; t++) {
        freopen(("./in/" + to_string(t) + ".in").c_str(), "w", stdout);
        // int r = rand() % 1000 + 1;
        cout << a[t - 1] << '\n';
        cout.clear();
    }
    fclose(stdout);
    return 0;
}
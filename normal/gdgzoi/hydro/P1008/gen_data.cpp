#include <bits/stdc++.h>
using namespace std;

int rand(int l, int r) {
    return rand() % (r - l + 1) + l;
}

int main() {
    srand(time(0));
    int T = 5;
    for (int t = 1; t <= T; t++) {
        freopen(("./in/" + to_string(t) + ".in").c_str(), "w", stdout);
        int r = rand(999999980, 1000000000) + 1;
        cout << r << '\n';
        cout.clear();
    }
    fclose(stdout);
    return 0;
}
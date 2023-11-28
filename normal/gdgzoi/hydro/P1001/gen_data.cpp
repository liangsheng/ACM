#include <bits/stdc++.h>
using namespace std;

int main() {
    srand(time(0));
    int T = 3;
    for (int t = 1; t <= T; t++) {
        freopen(("./in/" + to_string(t) + ".in").c_str(), "w", stdout);
        int r = rand() % 1000 + 1;
        cout << r << '\n';
        cout.clear();
    }
    fclose(stdout);
    return 0;
}
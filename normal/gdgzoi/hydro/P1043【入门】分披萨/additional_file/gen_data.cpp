#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int rand(int l, int r) {
    return rand() % (r - l + 1) + l;
}

string rand_str(int l, int r) {
    string ans;
    int n = rand() % (r - l + 1) + l;
    for (int i = 0; i < n; i++) {
        ans.push_back(rand() % 26 + 'a');
    }
    return ans;
}

int main() {
    srand(time(0));
    int T = 10;
    vector<LL> n(T);
    for (int i = 0; i < T / 2; i++) {
        n[i] = i;
        n[i + T / 2] = 10000000000LL + n[i];
    }

    for (int t = 0; t < T; t++) {
        freopen(("./testdata/" + to_string(t + 1) + ".in").c_str(), "w", stdout);
        cout << n[t] << '\n';   
        cout.clear();
    }

    fclose(stdout);
    return 0;
}
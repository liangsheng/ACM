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
    int T = 5;
    vector<int> n = {10, 100, 1000, 10000, 100000};

    for (int t = 0; t < T; t++) {
        freopen(("./testdata/" + to_string(t + 1) + ".in").c_str(), "w", stdout);
        cout << n[t] << '\n';
        vector<int> a(n[t]);
        int m = min(n[t], 1000);
        for (int i = 0; i < n[t]; i++) {
            a[i] = rand(1, m) * 2;
        }
        for (int i = 0; i < n[t] - 1; i++) cout << a[i] << ' ';
        cout << a[n[t] - 1] << '\n';     
        cout.clear();
    }

    fclose(stdout);
    return 0;
}
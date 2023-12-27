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
    vector<int> n = {10, 100, 1000, 1000, 1000};
    vector<int> m = {100, 1000, 10000, 10000, 100000};

    for (int t = 0; t < T; t++) {
        freopen(("./testdata/" + to_string(t + 1) + ".in").c_str(), "w", stdout);
        cout << n[t] << ' ' << m[t] << '\n';
        for (int i = 0; i < m[t]; i++) {
            int c = rand() % 10 + 1;
            if (c <= 4) c = 0;
            else if (c <= 8) c = 1;
            else c = 2;
            int id = rand() % n[t];
            if (c == 0) {
                int x = rand() % n[t];
                cout << c << ' ' << id << ' ' << x << '\n';
            } else {
                cout << c << ' ' << id << '\n';
            }
        }
        cout.clear();
    }

    fclose(stdout);
    return 0;
}
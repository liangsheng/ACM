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
    vector<int> n = {10, 20, 100, 100, 100};
    vector<int> m = {10, 20, 100, 100, 100};
    vector<int> k = {10, 20, 100, 100, 100};

    for (int t = 0; t < T; t++) {
        freopen(("./testdata/" + to_string(t + 1) + ".in").c_str(), "w", stdout);
        cout << n[t] << ' ' << m[t] << '\n';
        for (int i = 1; i <= n[t]; i++) {
            int p = rand() % (n[t] / 2) + 1;
            cout << p;
            for (int j = 1; j <= p; j++) cout << ' ' << rand(1, m[t]);
            cout << '\n';
        }
        cout << k[t] << '\n';
        for (int i = 1; i <= k[t]; i++) {
            int p = rand() % (n[t] / 2) + 1, c = rand() % 2;
            p = min(p, 10);
            if (c == 1) p = min(p, 3);
            cout << c << ' ' << p;
            vector<int> a(n[t] + 1, 0);
            for (int j = 1; j <= p; j++) {
                int x = rand(1, n[t]);
                while (a[x]) x = rand(1, n[t]);
                cout << ' ' << x;
                a[x] = 1;
            }
            cout << '\n';
        }
        cout.clear();
    }

    fclose(stdout);
    return 0;
}
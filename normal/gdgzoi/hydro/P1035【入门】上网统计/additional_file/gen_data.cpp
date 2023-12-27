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
    vector<int> m = {20, 200, 2000, 2000, 2000};
    vector<int> d = {1, 1, 2, 2, 2};
    vector<vector<string>> a(T, vector<string>());
    vector<vector<string>> b(T, vector<string>());
    for (int i = 0; i < T; i++) {
        set<string> names;
        for (int j = 0; j < m[i]; j++) {
            string x = rand_str(d[i], d[i]), y = rand_str(d[i], d[i]);
            a[i].push_back(x);
            b[i].push_back(y);
            names.insert(x);
        }
        n[i] = names.size();
    }

    for (int t = 0; t < T; t++) {
        freopen(("./testdata/" + to_string(t + 1) + ".in").c_str(), "w", stdout);
        cout << n[t] << ' ' << m[t] << '\n';
        for (int i = 0; i < m[t]; i++) {
            cout << a[t][i] << ' ' << b[t][i] << '\n';
        }
        cout.clear();
    }

    fclose(stdout);
    return 0;
}
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
    vector<string> n(T);
    n[0] = "00:00";
    n[1] = "00:13";
    n[2] = "00:19";
    n[3] = "01:10";
    n[4] = "15:14";
    n[5] = "15:29";
    n[6] = "16:35";
    n[7] = "18:43";
    n[8] = "20:23";
    n[9] = "23:59";

    for (int t = 0; t < T; t++) {
        freopen(("./testdata/" + to_string(t + 1) + ".in").c_str(), "w", stdout);
        cout << n[t] << '\n';   
        cout.clear();
    }

    fclose(stdout);
    return 0;
}
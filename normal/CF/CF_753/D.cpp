#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<LL> ans[10];

void gen(vector<string>& a, string& tmp, int p, int k) {
    if (p >= (tmp.size() + 1) / 2) {
        a.push_back(tmp);
        return ;
    }
    int l = 0, r = k - 1;
    if (p == 0) l++;
    for (int i = l; i <= r; i++) {
        tmp[p] = i + '0';
        tmp[tmp.size() - p - 1] = i + '0';
        gen(a, tmp, p + 1, k);
    }
}

bool ok(LL t) {
    vector<int> a;
    while (t != 0) a.push_back(t % 10), t /= 10;
    for (int i = 0; i < (a.size() + 1) / 2; i++) {
        if (a[i] != a[a.size() - 1 - i]) return 0;
    }
    return 1;
}

vector<LL> last(vector<string>& a, int k) {
    vector<LL> res;
    for (auto s: a) {
        LL t = 0;
        for (auto ch : s) t = t * k + ch - '0';
        if (ok(t)) {
            res.push_back(t);
            if (res.size() == 30) break;
        }
    }
    return res;
}

vector<LL> gao(int k) {
    int n = 30;
    vector<string> a;
    map<int, int> sz;
    sz[2] = 30;
    sz[3] = 18;
    sz[4] = 19;
    sz[5] = 15;
    sz[6] = 10;
    sz[7] = 14;
    sz[8] = 10;
    sz[9] = 10;
    for (int i = 1; i <= sz[k]; i++) {
        string tmp;
        for (int j = 0; j < i; j++) tmp.push_back('0');
        gen(a, tmp, 0, k);
    }
    return last(a, k);
}

int main() {
    for (int k = 2; k <= 9; k++) {
        ans[k] = gao(k);
        // cout << "over k= " << k << '\n';
    }
    for (int k = 2; k <= 9; k++) {
        cout << "k= " << k << ' ' <<ans[k].size() << '\n';
        for (int i = 1; i < ans[k].size(); i++) ans[k][i] += ans[k][i - 1];
        for (int i = 0; i < ans[k].size(); i++) cout << ans[k][i] << ", ";
        cout << '\n';
    }
    return 0;
}
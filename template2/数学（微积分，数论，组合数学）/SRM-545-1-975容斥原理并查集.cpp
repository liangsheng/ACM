/*
题目数据给出一串数（2~50个），现在给这些数着色，可着蓝色可着红色。要求是，至少各有一个数被涂成了红色、蓝色，
并且所有红色的数按位与运算所得结果和所有蓝色的数按位与运算所得结果要求相等。问满足要求的着色方案共有多少种。
若无任何限制条件，N个数的着色方案共有2^N个。对于单个集合Ck，不满足题意的着色方法共有2^(N-[Ck]+1)种
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cassert>
#include <vector>

#define pause cout << " press any key to continue...", cin >> chh
#define file_r(x) freopen(x, "r", stdin)
#define file_w(x) freopen(x, "w", stdout)

using namespace std;
int chh;

typedef long long LL;

const int N = 20, M = 50;

int n;
vector<int> a[N];

struct SetAndSet {
    int find(int f[], int x) {
        if (f[x] == x) return f[x];
        f[x] = find(f, f[x]);
        return f[x];
    }

    LL dfs(int p, int f, int fa[]) {
        if (p == N) {
            int i, num = 0;
            for (i = 0; i < n; i++) if (find(fa, i) == i) num++;
            return ((1LL << num) - 2) * f;
        }
        LL res = dfs(p + 1, f, fa);
        if (a[p].size() == n || a[p].size() == 0) return res;
        int i, x, y, ff[M];
        for (i = 0; i < n; i++) ff[i] = fa[i];
        for (i = 1; i < a[p].size(); i++) {
            x = find(ff, a[p][0]), y = find(ff, a[p][i]);
            if (x != y) ff[y] = x;
        }
        res += dfs(p + 1, -f, ff);
        return res;
    }

    long long countandset(vector<int> A) {
        int i, j;
        int f[M];
        n = A.size();
        for (i = 0; i < N; i++) {
            a[i].clear();
            for (j = 0; j < n; j++) {
                if ((A[j] >> i) & 1) continue;
                a[i].push_back(j);
            }
            if (a[i].size() == 1) return 0LL;
        }
        for (i = 0; i < n; i++) f[i] = i;
        return dfs(0, 1, f);
    }
};

int main() {
    int i, j, n;
    SetAndSet tmp;
    vector<int> aa;
    while (cin >> n) {
        aa.clear();
        while (n--) {
            cin >> i;
            aa.push_back(i);
        }
        cout << tmp.countandset(aa) << endl;
    }
    return 0;
}

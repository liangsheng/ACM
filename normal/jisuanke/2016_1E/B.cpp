#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>

#define X first
#define Y second
#define pb push_back
#define mp make_pair

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;

const int N = 1005;

int n, m;
int c[N];
int X, A, Y, B;
vector<int> q[N], hx, hy;
set<pii> s;
set<pii> :: iterator it;

pii gao(int id) {
    int i, d = 0, p = 0;
    for (i = 0; i < c[id]; i++) {
        if (d >= q[id][i]) d++;
        else {
            p += q[id][i] - d;
            d = q[id][i] + 1;
        }
    }
    //cout << "id= " << id << ' ' << p << ' ' << c[id] << '\n';
    return mp(p, id);
}

int main() {
    int i, j, t, ans, now;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &c[i]);
        for (j = 0; j < c[i]; j++) {
            scanf("%d", &t);
            q[i].pb(t);
        }
    }
    scanf("%d", &m);
    while (m--) {
        scanf("%d %d %d %d", &X, &A, &Y, &B);
        X--, Y--;
        if (A > c[X]) A = c[X];
        if (B > c[Y]) B = c[Y];
        hx.clear(), hy.clear();
        for (i = 0; i < A; i++) hy.pb(q[X][i]);
        for (i = B; i < c[Y]; i++) hy.pb(q[Y][i]);

        for (i = 0; i < B; i++) hx.pb(q[Y][i]);
        for (i = A; i < c[X]; i++) hx.pb(q[X][i]);
        q[X] = hx, q[Y] = hy;
        c[X] = hx.size(), c[Y] = hy.size();

//        for (i = 0; i < n; i++) {
//            cout << "i= " << i << '\n';
//            for (j = 0; j < c[i]; j++) cout << q[i][j] << ' ';
//            puts("");
//        }
//        system("pause");

        s.clear();
        for (i = 0; i < n; i++) {
            s.insert(gao(i));
        }

        ans = now = 0;
        while (!s.empty()) {
            it = s.begin();
            s.erase(it);
            if (it->X <= now) now += c[it->Y];
            else {
                ans += it->X - now;
                now = it->X + c[it->Y];
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

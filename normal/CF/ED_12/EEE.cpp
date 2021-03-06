#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <cfloat>
#define zero(x) (((x)>0?(x):-(x))<eps)

#define pause cout << " press ansy key to continue...",  cin >> chh
#define file_r(x) freopen(x,  "r",  stdin)
#define file_w(x) freopen(x,  "w",  stdout)
#define lowbit(x) ((x) & (-x))
#define repit(i, c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repe(i, u) for (int i = head[u]; i != -1; i = nxt[i])
#define repd(i, n) for (int i = (n - 1); i >= 0; i--)
#define FOR(i, n, m) for (int i = (n); i <= (m); i++)
#define FORD(i, n, m) for (int i = (n); i >= (m); i--)
#define pb push_back
#define X first
#define Y second
#define ins insert
#define rb rbegin
#define be begin
#define er erase
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define SZ(c) (c).size()
#define ALL(c) (c).begin(), (c).end()
#define sqr(r) ((r) * (r))
#define dis(x1, y1, x2, y2) (((x1) - (x2)) * ((x1) - (x2)) + ((y1) - (y2)) * ((y1) - (y2)))
#define FASTIO ios::sync_with_stdio(false);cin.tie(0)

#define sc(x) cout << #x" = " << x << endl, system("pause")
#define sc2(x, y) cout << #x" = " << x << " " << #y" = " << y << endl, system("pause")
#define sc3(x, y, z) cout << #x" = " << x << " " << #y" = " << y << " " << #z" = " << z << endl, system("pause")
#define sc4(x, y, z, w) cout << #x" = " << x << " " << #y" = " << y << " " << #z" = " << z << " " << #w" = " << w << endl, system("pause")

#define in(n) scanf("%d", &n)
#define in2(n, m) scanf("%d %d", &n, &m)
#define in3(x, y, z) scanf("%d %d %d", &x, &y, &z)

using namespace std;
int chh;

typedef vector<int> vi;
typedef set<int> si;
typedef map<int, int> mii;
typedef pair<int, int> pii;
typedef pair<int, pii> pi3;
typedef vector< pair<int, int> > vpii;
typedef long long LL;

const int N = 30e6 + 5, L = 30;

struct Node {
    Node *ch[2];
    int val;

    Node() {
        ch[0] = ch[1] = NULL;
        val = 0;
    }

} *root;

int n, m, e, d;

void init() {
    root = new Node();
}

void add(int x) {
    int id;
    Node *p = root;
    p->val ++;
    FORD (i, L - 1, 0) {
        id = (x >> i) & 1;
        if (p->ch[id] == NULL) {
            Node *tmp = new Node();
            p->ch[id] = tmp;
        }
        p = p->ch[id], p->val ++;
    }
}

int cal() {
    int ans = 0, id, x;
    Node *p = root;
    FORD (i, L - 1, 0) {
        id = (m >> i) & 1, x =  (d >> i) & 1 ^ 1;
        if (id) {                   // for bit = 1
            if (p->ch[x] == NULL) return ans;
            p = p->ch[x];
        } else {                    // for bit = 0
            if (p->ch[x] != NULL) ans += p->ch[x]->val;
            if (p->ch[x ^ 1] != NULL) p = p->ch[x ^ 1];
            else return ans;
        }
    }
    return ans + p->val;
}

int main() {
    int x;
    LL ans;
    while (~scanf("%d %d", &n, &m)) {
        init();
        ans = 0, d = 0;
        rep (i, n) {
            scanf("%d", &x);
            add(d);
            d ^= x;
            ans += cal();
        }
        printf("%I64d\n", ans);
    }
    return 0;
}

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

const int N = 100005;

struct Node {
    int x, y, z, id;
    Node() {}
    Node(int X, int Y, int Z, int ID): x(X), y(Y), z(Z), id(ID) {}
    bool operator <(const Node& arg) const {
        if (z != arg.z) return z < arg.z;
        if (x != arg.x) return x < arg.x;
        return y < arg.y;
    }
} p[N];

int c[MAX][MAX];
int n;
int Lowbit(int x) {
	return x & (-x);
}

void Updata(int x,int y) {
	int i,k;
	for(i=x; i<=e + 5; i+=Lowbit(i))
		for(k=y; k<=n; k+=Lowbit(k))
			c[i][k]++;
}

int Get(int x,int y) {
	int i,k,sum = 0;
	for(i=x; i>0; i-=Lowbit(i))
		for(k=y; k>0; k-=Lowbit(k))
			sum += c[i][k];
	return sum;
}

bool ok(Node a, Node b) {
    return a.x == b.x && a.y == b.y && a.z == b.z;
}

int T, n, e;
int a[N * 2], ans[N];

int main() {
    int c, t;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        rep (i, n) scanf("%d %d %d", &p[i].x, &p[i].y, &p[i].z), p[i].id = i;
        sort(p, p + n);
        e = 0;
        rep (i, n) a[e++] = p[i].x, a[e++] = p[i].y;
        sort(a, a + e);
        e = unique(a, a + e) - a;
        rep (i, n) {
            p[i].x = lower_bound(a, a + e, p[i].x) - a;
            p[i].y = lower_bound(a, a + e, p[i].y) - a;
        }
        rep (i, n) {
            t = i, c = 0;
            while (i + 1 < n && ok(p[t], p[i + 1])) i++, c++;
        }
    }
    return 0;
}

#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<functional>
#include<iostream>
#include<cmath>
#include<set>
#include<map>
#include<unordered_map>
#include<cctype>
#include<ctime>
#include<iomanip>
using namespace std;
#define For(i,n) for(int i=1;i<=n;i++)
#define Fork(i,k,n) for(int i=k;i<=n;i++)
#define Rep(i,n) for(int i=0;i<n;i++)
#define ForD(i,n) for(int i=n;i;i--)
#define RepD(i,n) for(int i=n;i>=0;i--)
#define Forp(x) for(int p=pre[x];p;p=next[p])
#define Forpiter(x) for(int &p=iter[x];p;p=next[p])
#define Lson (x<<1)
#define Rson ((x<<1)+1)
#define MEM(a) memset(a,0,sizeof(a));
#define MEMI(a) memset(a,127,sizeof(a));
#define MEMi(a) memset(a,128,sizeof(a));
#define MAXN (60000+10)
#pragma comment(linker, "/STACK:1024000000,1024000000")

#define MAXM (200000+10)
#define MAXQ (200000+10)
#define pb push_back
#define mp make_pair
typedef int ll;

void mul(ll &a, ll b) {
	a = a * b;
}
void add(ll &a, ll b) {
	a = a + b;
}
class LCT {
public:
	int father[MAXN], siz[MAXN];
	int ch[MAXN][2];
	bool root[MAXN];
	bool rev[MAXN];
	ll mulv[MAXN], sumv[MAXN], val[MAXN];
	void mem(int n) {
		MEM(father)
		MEM(siz)
		MEM(root)
		For(i,n+1)
			siz[i] = root[i] = mulv[i] = val[i] = sumv[i] = 1;
		root[0] = 1;
		MEM(ch)
		MEM(rev)
	}
	void Set(int x, ll bi) {
		val[x] = sumv[x] = bi;
	}

	void pushdown(int x) {
		if (!x)
			return;
		if (rev[x]) {
			if (ch[x][0])
				rev[ch[x][0]] ^= 1;
			if (ch[x][1])
				rev[ch[x][1]] ^= 1;
			swap(ch[x][0], ch[x][1]);
			rev[x] ^= 1;
		}
		if (mulv[x] != 1) {
			if (ch[x][0])
				mul(mulv[ch[x][0]], mulv[x]), mul(val[ch[x][0]], mulv[x]), mul(
						sumv[ch[x][0]], mulv[x]);
			if (ch[x][1])
				mul(mulv[ch[x][1]], mulv[x]), mul(val[ch[x][1]], mulv[x]), mul(
						sumv[ch[x][1]], mulv[x]);
			mulv[x] = 1;
		}
	}
	void maintain(int x) {
		siz[x] = siz[ch[x][0]] + siz[ch[x][1]] + 1;
		sumv[x] = (sumv[ch[x][0]] + sumv[ch[x][1]] + val[x]);
	}
	void rotate(int x) {
		int y = father[x], kind = ch[y][1] == x;

		ch[y][kind] = ch[x][!kind];
		if (ch[y][kind]) {
			father[ch[y][kind]] = y;
		}
		father[x] = father[y];
		father[y] = x;
		ch[x][!kind] = y;
		if (root[y]) {
			root[x] = 1;
			root[y] = 0;
		} else {
			ch[father[x]][ch[father[x]][1] == y] = x;
		}
		maintain(y);
		maintain(x);
	}

	void P(int x) {
		if (!root[x])
			P(father[x]);
		pushdown(x);
	}

	void splay(int x) {
		P(x);
		while (!root[x]) {
			int y = father[x];
			int z = father[y];
			if (root[y])
				rotate(x);
			else if ((ch[y][1] == x) ^ (ch[z][1] == y)) {
				rotate(x);
				rotate(x);
			} else {
				rotate(y);
				rotate(x);
			}
		}
	}

	int access(int x) {
		int y = 0;
		do {
			splay(x);
			if (ch[x][1])
				root[ch[x][1]] = 1;
			ch[x][1] = y;
			if (y)
				root[y] = 0;
			maintain(x);
			y = x;
			x = father[x];
		} while (x);
		return y;
	}

	void cut(int x) {
		access(x);
		splay(x);

		father[ch[x][0]] = 0;
		root[ch[x][0]] = 1;
		ch[x][0] = 0;
		maintain(x);
	}

	void join(int x, int y) {
		make_root(x);
		access(y);
		splay(y);
		ch[y][1] = x;
		father[x] = y;
		maintain(y);
		root[x] = 0;
	}
	void reverse(int x) {
		rev[x] ^= 1;   // 标记记完后迅速处理
	}
	void make_root(int x) {
		access(x);
		splay(x);
		reverse(x);
		pushdown(x);
	}
	int get_root(int x) {
		access(x);
		splay(x);
		do {
			pushdown(x);
			if (ch[x][0])
				x = ch[x][0];
			else
				break;
		} while (1);
		return x;
	}

	void Mul(int x, ll cost) {
		pushdown(x);
		mulv[x] = cost;
		mul(val[x], cost);
		mul(sumv[x], cost);
	}

	bool check(int x, int y) {
		while (father[x])
			x = father[x];
		while (father[y])
			y = father[y];
		return x == y;

	}

} S;

int n, m, q;
int u[MAXM], v[MAXM];
struct ask {
	int p, x, y;
} comm[MAXQ];
ll ans[MAXQ];

map<pair<int, int>, int> S2;
map<pair<int, int>, int>::iterator it;
int main() {
	int T;
	cin >> T;
	For(kcase,T)
	{
		S2.clear();
		scanf("%d%d%d", &n, &m, &q);
		printf("Case #%d:\n", kcase);

		For(i,m)
		{
			scanf("%d%d", &u[i], &v[i]);
			if (u[i] > v[i])
				swap(u[i], v[i]);
		}

		int qm = 0;
		For(i,q)
		{
			scanf("%d%d%d", &comm[i].p, &comm[i].x, &comm[i].y);
			if (comm[i].x > comm[i].y)
				swap(comm[i].x, comm[i].y);
			if (comm[i].p == 1) {
				++qm;
				if ((it = S2.find(mp(comm[i].x, comm[i].y))) != S2.end())
					(it->second)++;
				else
					S2[ mp(comm[i].x, comm[i].y)] = 1;
			}
		}

		S.mem(2 * n - 1);
		For(i,n)
			S.Mul(i, 0);

		int nownode = n;
		For(i,m)
		{
			if ((it = S2.find(mp(u[i], v[i]))) != S2.end())
				if ((it->second) > 0) {
					(it->second)--;
					continue;
				}
			if (S.check(u[i], v[i])) {
				S.make_root(u[i]);
				S.access(v[i]);
				S.splay(v[i]);
				S.Mul(v[i], 0);
			} else {
				S.join(++nownode, u[i]);
				S.join(nownode, v[i]);
			}
		}

		ForD(i,q)
		{
			int x = comm[i].x, y = comm[i].y;
			if (comm[i].p == 1) {
				if (S.check(x, y)) {
					S.make_root(x);
					S.access(y);
					S.splay(y);
					S.Mul(y, 0);
				} else {
					S.join(++nownode, x);
					S.join(nownode, y);
				}

			} else {
				S.make_root(x);
				S.access(y);
				S.splay(y);
				ans[i] = S.sumv[y];

			}
		}

		For(i,q)
		{
			if (comm[i].p == 2)
				printf("%d\n", ans[i]);
		}

	}

	return 0;
}

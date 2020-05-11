#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define pause cout << " press any key to continue...",  cin >> chh
#define file_r(x) freopen(x,  "r",  stdin)
#define file_w(x) freopen(x,  "w",  stdout)

using namespace std;
int chh;

const int maxn = 100010;

int n, top;
int look[maxn];

struct splaytree {
	int ch[maxn][2], f[maxn], size[maxn], flag[maxn];
	int root;

	inline void zig(int x) { //右旋
		int y = f[x], z = f[y];
		ch[y][0] = ch[x][1];
		f[ch[x][1]] = y;
		ch[x][1] = y;
		f[y] = x;
		f[x] = z;
		if (z)
			ch[z][ch[z][1] == y] = x;
		push_up(y);
	}

	inline void zag(int x) { //左旋
		int y = f[x], z = f[y];
		ch[y][1] = ch[x][0];
		f[ch[x][0]] = y;
		ch[x][0] = y;
		f[y] = x;
		f[x] = z;
		if (z)
			ch[z][ch[z][1] == y] = x;
		push_up(y);
	}

	void splay(int x, int goal) { //将x旋转到goal之下
		int y, z;
		push_down(x);
		while (f[x] != goal) {
			if (f[f[x]] == goal) {
				y = f[x];
				push_down(y);
				push_down(x);
				if (ch[y][0] == x) zig(x);
				else zag(x);
			} else {
				y = f[x];
				z = f[y];
				push_down(z);
				push_down(y);
				push_down(x);
				if (ch[z][0] == y) {
					if (ch[y][0] == x) {
						zig(y);
						zig(x);
					} else {
						zag(x);
						zig(x);
					}
				} else {
					if (ch[y][1] == x) {
						zag(y);
						zag(x);
					} else {
						zig(x);
						zag(x);
					}
				}
			}
		}
		push_up(x);
		if (f[x] == 0) root = x;
	}

	inline void push_up(int x) { //将子节点的信息跟新上来
		size[x] = 1 + size[ch[x][0]] + size[ch[x][1]];
	}

	inline void push_down(int x) { //将延迟标记推向儿子结点
		if (flag[x]) {
			int temp = ch[x][0];
			ch[x][0] = ch[x][1];
			ch[x][1] = temp;
			flag[ch[x][0]] ^= 1;
			flag[ch[x][1]] ^= 1;
			flag[x] = 0;
		}
	}

	inline int findmin(int x) { //在以x为根的子树中找最小值
		push_down(x);
		while (ch[x][0]) {
			x = ch[x][0];
			push_down(x);
		}
		return x;
	}

	inline void erase() { // 删除根节点
		if (ch[root][1] == 0) {
			root = ch[root][0];
			f[root] = 0;
		} else {
			int m = findmin(ch[root][1]); //在右子树中找最小值
			splay(m, root);
			ch[m][0] = ch[root][0];
			f[ch[root][0]] = m;
			root = m;
			f[root] = 0;
			push_up(root);
		}
	}

	void newnode(int&x) { //新建一个节点
		x = ++top;
		ch[x][0] = ch[x][1] = f[x] = flag[x] = 0;
		size[x] = 1;
	}

	void build(int &x, int l, int r, int father) { //递归建树
		if (l > r) return;
		int mid = (l + r) >> 1;
		newnode(x);
		look[mid] = x;
		build(ch[x][0], l, mid - 1, x);
		build(ch[x][1], mid + 1, r, x);
		f[x] = father;
		push_up(x);
	}

	void init() {
		top = 0;
		memset(ch, 0, sizeof(ch));
		memset(f, 0, sizeof(f));
		memset(size, 0, sizeof(size));
		memset(flag, 0, sizeof(flag));
		memset(look, -1, sizeof(look));
		build(root, 0, n - 1, 0);
	}

	int query(int k) {
		int x = look[k], ans;
		splay(x, 0);
		ans = size[ch[x][0]] + 1;
		flag[ch[x][0]] ^= 1; //左子树根节点加旋转标记
		erase();
		return ans;
	}
} tree;

struct node {
	int pos;
	int val;
	bool friend operator <(const node&a, const node&b) {
		if (a.val == b.val) return a.pos < b.pos;
		return a.val < b.val;
	}
} a[maxn];

int main() {
	while (scanf("%d", &n), n) {
		int i;
		for (i = 0; i < n; i++) {
			scanf("%d", &a[i].val);
			a[i].pos = i;
		}
		sort(a, a + n);
		tree.init();
		for (i = 0; i < n - 1; i++) {
			printf("%d ", tree.query(a[i].pos) + i);
		}
		printf("%d\n", tree.query(a[i].pos) + n - 1);
	}
	return 0;
}

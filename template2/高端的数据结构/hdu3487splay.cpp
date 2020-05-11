#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define pause cout << " press any key to continue...",  cin >> chh
#define file_r(x) freopen(x,  "r",  stdin)
#define file_w(x) freopen(x,  "w",  stdout)

using namespace std;
int chh;

const int N = 300010;

int top, root;
int look[N];
int ch[N][2], f[N], size[N], flag[N];
int res[N];

struct splaytree {
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

	void newnode(int&x) { //新建一个节点
		x = ++top;
		ch[x][0] = ch[x][1] = f[x] = flag[x] = 0;
		size[x] = 1;
	}

	void build(int &x, int l, int r, int father) { //递归建树
		if (l > r) return;
		int mid = (l + r) >> 1;
		newnode(x);
		look[x] = mid;
		build(ch[x][0], l, mid - 1, x);
		build(ch[x][1], mid + 1, r, x);
		f[x] = father;
		push_up(x);
	}

	void init(int l, int r) {
		top = 0;
		for (int i = 1; i <= r; i++) ch[i][0] = ch[i][1] = 0;
		fill(f, f + r + 1, 0);
		fill(size, size + r + 1, 0);
		fill(flag, flag + r + 1, 0);
		fill(look, look + r + 1, -1);
		build(root, l, r, 0);
	}

	int find_x(int x) {
	    int p = root, tmp;
	    while (1) {
	        push_down(p);
	        tmp = size[ch[p][0]];
            if (tmp == x - 1) return p;
            if (tmp > x - 1) p = ch[p][0];
            else {
                p = ch[p][1];
                x = x - tmp - 1;
            }
	    }
	}

	void rev(int s, int t) {
	    int x, y;
        y = find_x(t);
        splay(y, 0);
        x = find_x(s);
        splay(x, y);
        flag[ch[x][1]] ^= 1;
	}

    void cut(int s, int t, int k) {
        int x, y, z, u, r;
        y = find_x(t);
        splay(y, 0);
        x = find_x(s);
        splay(x, y);
        push_down(x);
        r = ch[x][1];
        ch[x][1] = 0;
        push_up(x), push_up(y);
        z = find_x(k);
        splay(z, 0);
        if (ch[z][1] == 0) {
            ch[z][1] = r;
            f[r] = z;
            push_up(z);
        } else {
            u = findmin(ch[z][1]);
            splay(u, z);
            ch[u][0] = r;
            f[r] = u;
            push_up(u), push_up(z);
        }
    }

    void dfs(int p) {
        push_down(p);
        if (ch[p][0] != 0) dfs(ch[p][0]);
        res[++res[0]] = look[p];
        if (ch[p][1] != 0) dfs(ch[p][1]);
    }
} tree;

int n, m;
char cmd[5];

int main() {
    int i, j, s, t, k;
    while (scanf("%d %d", &n, &m) != EOF) {
        if (n == -1 && m == -1) break;
        tree.init(0, n + 1);
        for (i = 1; i <= m; i++) {
            scanf("%s", cmd);
            if (cmd[0] == 'F') {
                scanf("%d %d", &s, &t);
                tree.rev(s, t + 2);
            } else {
                scanf("%d %d %d", &s, &t, &k);
                tree.cut(s, t + 2, k + 1);
            }
        }
        res[0] = 0;
        tree.dfs(root);
        for (i = 2; i <= n; i++) printf("%d ", res[i]);
        printf("%d\n", res[n + 1]);
    }
	return 0;
}

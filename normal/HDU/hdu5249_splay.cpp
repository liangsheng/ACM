#include<iostream>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
using namespace std;
struct node {
	int ch[2], sz, v, fix;
} t[100005];
int ndtot = 0;
int root = 0;
void rot(int &x, int f) {
	int y = t[x].ch[!f];
	t[x].ch[!f] = t[y].ch[f];
	t[y].ch[f] = x;
	t[y].sz = t[x].sz;
	t[x].sz = t[t[x].ch[0]].sz + t[t[x].ch[1]].sz + 1;
	x = y;
}
void ins(int &x, int v) {
	if (x == 0) {
		x = ++ndtot;
		t[x].ch[0] = t[x].ch[1] = 0;
		t[x].sz = 1;
		t[x].fix = rand();
		t[x].v = v;
	} else {
		int f = v >= t[x].v;
		ins(t[x].ch[f], v);
		t[x].sz++;
		if (t[t[x].ch[f]].fix < t[x].fix)
			rot(x, !f);
	}
}
void del(int &x) {
	if (!t[x].ch[0] && !t[x].ch[1])
		x = 0;
	else {
		int f = !t[x].ch[0]
				|| t[x].ch[1] && t[t[x].ch[1]].fix < t[t[x].ch[0]].fix;
		rot(x, !f);
		t[x].sz--;
		del(t[x].ch[!f]);
	}
}
void del_num(int &x, int v) {
	if (t[x].v == v)
		del(x);
	else {
		int f = v >= t[x].v;
		t[x].sz--;
		del_num(t[x].ch[f], v);
	}
}
int rk(int v) {
	int x = root;
	int ans = 0;
	while (x) {
		if (t[x].v >= v)
			x = t[x].ch[0];
		else {
			ans += t[t[x].ch[0]].sz + 1;
			x = t[x].ch[1];
		}
	}
	return ans + 1;
}
int kth(int k) {
	int x = root;
	while (1) {
		if (t[t[x].ch[0]].sz + 1 == k)
			return t[x].v;
		else if (k <= t[t[x].ch[0]].sz)
			x = t[x].ch[0];
		else {
			k -= t[t[x].ch[0]].sz + 1;
			x = t[x].ch[1];
		}
	}
}
int pre(int v) {
	int x = root, y = 0;
	while (x) {
		if (v > t[x].v) {
			y = t[x].v;
			x = t[x].ch[1];
		} else
			x = t[x].ch[0];
	}
	return y;
}
int suc(int v) {
	int x = root, y = 0;
	while (x) {
		if (v < t[x].v) {
			y = t[x].v;
			x = t[x].ch[0];
		} else
			x = t[x].ch[1];
	}
	return y;
}
int qu[111111];
int main() {
	int m, tes = 0;
	while (scanf("%d", &m) != EOF) {
		int p = 0, q = 0;
		tes++;
		printf("Case #%d:\n", tes);
		root = ndtot = 0;
		t[0].sz = 0;
		while (m--) {
			char opt[11];
			scanf("%s", opt);
			if (opt[0] == 'i') {
				int x;
				scanf("%d", &x);
				qu[q++] = x;
				ins(root, x);
			} else if (opt[0] == 'q') {
				int ss = q - p;
				ss = ss / 2 + 1;
				printf("%d\n", kth(ss));
			} else {
				del_num(root, qu[p++]);
			}
		}
	}
	return 0;
}

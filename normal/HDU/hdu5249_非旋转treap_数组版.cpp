#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdio>
using namespace std;

struct tree {
	int l, r, size, w, f;
} t[1100000];

int n, len, root;

int getrank() {
	return (rand() << 16) + rand();
}

void change(int k) {
	if (k == 0) return;
	t[k].size = t[t[k].l].size + t[t[k].r].size + 1;
}

int merge(int k1, int k2) {
	if (k1 == 0 || k2 == 0) return k1 + k2;
	if (t[k1].f > t[k2].f) {
		t[k1].r = merge(t[k1].r, k2);
		change(k1);
		return k1;
	} else {
		t[k2].l = merge(k1, t[k2].l);
		change(k2);
		return k2;
	}
}

void splite(int k1, int k2, int &k3, int &k4) {
	if (k1 == 0) {
		k3 = 0, k4 = 0;
		return;
	}
	if (t[k1].w < k2) {
		k3 = k1;
		splite(t[k1].r, k2, t[k1].r, k4);
	} else {
		k4 = k1;
		splite(t[k1].l, k2, k3, t[k1].l);
	}
	change(k1);
}

int insert(int k1, int k2) {
	if (k1 == 0) return k2;
	if (t[k1].f > t[k2].f) {
		if (t[k1].w < t[k2].w) t[k1].r = insert(t[k1].r, k2);
		else t[k1].l = insert(t[k1].l, k2);
		change(k1);
		return k1;
	};
	splite(k1, t[k2].w, t[k2].l, t[k2].r);
	change(k2);
	return k2;
}

int find(int k1, int k2) {
	if (t[t[k1].l].size == k2 - 1) return t[k1].w;
	if (t[t[k1].l].size >= k2) return find(t[k1].l, k2);
	return find(t[k1].r, k2 - t[t[k1].l].size - 1);
}

int findleft(int k) {
	while (t[k].l) k = t[k].l;
	return t[k].w;
}

int findright(int k) {
	while (t[k].r) k = t[k].r;
	return t[k].w;
}

void solve() {
	root = 0, len = 0;
	int l = 0;
	char ch[10];
	for (; n; n--) {
		scanf("%s", ch + 1);
		if (ch[1] == 'q') {
			int k2 = (len - l) / 2 + 1;
			printf("%d\n", find(root, k2));
		} else if (ch[1] == 'o') {
			l++;
			int k2 = t[l].w;
			int k3, k4, k5, k6;
			splite(root, k2, k3, k4);
			splite(k4, k2 + 1, k5, k6);
			root = merge(k3, k6);
		} else {
			len++;
			scanf("%d", &t[len].w);
			t[len].l = 0;
			t[len].r = 0;
			t[len].f = getrank();
			t[len].size = 1;
			root = insert(root, len);
		}
	}
}

int main() {
	srand(1342);
	int now = 0;
	while (scanf("%d", &n) != EOF) {
		now++;
		printf("Case #%d:\n", now);
		solve();
	}
	return 0;
}

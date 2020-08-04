#include <cstdio>
#include <cstring>
#include <algorithm>
#include <ctime>
using namespace std;
const int maxn = 50005;
struct node;
node *null, *root[maxn];
struct node {
	node* c[2];
	char v;
	int r, sz;
	void up() {
		sz = c[0]->sz + c[1]->sz + 1;
	}
	node(char v=0): v(v) {
		sz = 1, r = rand();
		c[0] = c[1] = null;
	}
};
inline void copy(node* &a, node* b) {
	//可持久化时，修改操作经过的路径要新建节点
	if(b==null) a = b;
	else a = new node(), *a = *b;
}
void merge(node* &o, node* a, node* b) {
	if(a == null) copy(o, b);
	else if(b == null) copy(o, a);
	else if(a->r < b->r) {
		copy(o, a);
		merge(o->c[1], a->c[1], b);
		o->up();
	}
	else {
		copy(o, b);
		merge(o->c[0], a, b->c[0]);
		o->up();
	}
}
void split(node* o, node* &a, node* &b, int k) {
	if(!k) {//最后一次往右儿子走
		copy(b, o);
		a = null;
	}
	if(o->sz <= k) {//优化，减少加入的新节点(可以去掉)
		copy(a, o);
		b = null;
	}
	else if(o->c[0]->sz >= k) { //左移,属于treap<b>
		copy(b, o);
		split(o->c[0], a, b->c[0], k);
		b->up();
	}
	else { //右移,属于treap<a>
		copy(a, o);
		split(o->c[1], a->c[1], b, k-o->c[0]->sz-1);
		a->up();
	}
}
char s[203];
void build(node* &o, int l, int r) {
	if(l > r) return;
	int m = (l + r) >> 1;
	o = new node(s[m]);
	build(o->c[0], l, m-1);
	build(o->c[1], m+1, r);
	o->up();
}
void ins(node* &o, node* pre, int pos) {
	node *a, *b, *c;
	int len = strlen(s);
	split(pre, a, b, pos);
	build(c, 0, len-1);
	merge(a, a, c);
	merge(o, a, b);
}
void del(node* &o, node* pre, int pos, int len) {
	node *a, *b, *c;
	split(pre, a, b, pos-1);
	split(b, b, c, len);
	merge(o, a, c);
}
int dlt; //题目强制在线的改变量
void out(node *o) {
	if(o == null) return;
	out(o->c[0]);
	if(o->v == 'c') dlt++;
	printf("%c", o->v);
	out(o->c[1]);
}
void out(node *o, int pos, int len) {
	node *a, *b, *c;
	split(o, a, b, pos-1);
	split(b, b, c, len);
	out(b);
	puts("");
}
void init() {
	null = new node();
	null->sz = 0;
	for(int i = 0; i < maxn; i++)
		root[i] = null;
}
int n;
int main() {
	scanf("%d", &n);
	init();
	int op, pos, len, v, nowv = 0;
	while(n--) {
		scanf("%d", &op);
		if(op == 1) {
			scanf("%d%s", &pos, s);
			pos -= dlt;
			ins(root[nowv+1], root[nowv], pos);
			nowv++;
		}
		else if(op == 2) {
			scanf("%d%d", &pos, &len);
			pos -= dlt, len -= dlt;
			del(root[nowv+1], root[nowv], pos, len);
			nowv++;
		}
		else {
			scanf("%d%d%d", &v, &pos, &len);
			v -= dlt, pos -= dlt, len -= dlt;
			out(root[v], pos, len);
		}
	}
	return 0;
}

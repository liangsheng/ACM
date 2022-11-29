#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 100000 + 10;
namespace Treap {
    const int INF = ~0U >> 1;

    struct Node {
        int val, pri, sz;
        Node* ch[2];
        Node() {
        }
        Node(int v, Node* n) :
                val(v) {
            ch[0] = ch[1] = n;
            sz = 1;
            pri = rand() - 1;
        }
        void update() {
            sz = ch[0]->sz + ch[1]->sz + 1;
        }
    } pool[MAXN], *root, *null, *pt;
    Node *newNode(int v, Node *n) {
        pt->val = v;
        pt->sz = 1;
        pt->ch[0] = pt->ch[1] = n;
        pt->pri = rand() - 1;
        return pt++;
    }
    void rot(Node* &o, int d) { //d = 1, left; d = 0, right
        Node* k = o->ch[d];
        o->ch[d] = k->ch[!d];
        k->ch[!d] = o;
        o->update();
        k->update();
        o = k;
    }
    void ins(Node* &o, int val) {
        if (o == null)
            o = newNode(val, null);
        else {
            if (val == o->val)
                return; //same val
            int d = val > o->val;
            ins(o->ch[d], val);
            if (o->ch[d]->pri < o->pri)
                rot(o, d);
            else
                o->update();
        }
    }
    void del(Node* &o, int val) {
        if (o == null)
            return;
        if (o->val == val) {
            int d = o->ch[1]->pri < o->ch[0]->pri;
            if (o->ch[d] == null) {
                o = null;
                return;
            }
            rot(o, d);
            del(o->ch[!d], val);
        } else {
            int d = val > o->val;
            del(o->ch[d], val);
        }
        o->update();
    }
    int Kth(Node* o, int k) { //kth number k >= 1
        int s = o->ch[0]->sz + 1;
        if (k == s)
            return o->val;
        if (k < s)
            return Kth(o->ch[0], k);
        else
            return Kth(o->ch[1], k - s);
    }
    int Rank(Node* o, int val) { //return how many elements smaller than val
        if (o == null)
            return 0;
        int s = o->ch[0]->sz;
        if (val == o->val)
            return s;
        if (val < o->val)
            return Rank(o->ch[0], val);
        else
            return s + 1 + Rank(o->ch[1], val);
    }
    void init() {
        pt = pool;
        null = newNode(0, 0);
        null->ch[0] = null->ch[1] = null;
        null->sz = 0;
        null->pri = INF;
        root = null;
    }
}

int main() {
	for (int cas = 1, n; scanf("%d", &n) == 1; ++cas) {
		Treap::init();
		int m = 0;
		queue<int> Q;
		printf("Case #%d:\n", cas);
		for (int i = 0; i < n; ++i) {
			char op[10];
			scanf("%s", op);
			if (op[0] == 'i') {
				int x;
				scanf("%d", &x);
				Q.push(x);
				m++;
				Treap::ins(Treap::root, x);
			} else if (op[0] == 'o') {
				int x = Q.front();
				Q.pop();
				Treap::del(Treap::root, x);
				m--;
			} else if (op[0] == 'q') {
				int k = m / 2 + 1;
				printf("%d\n", Treap::Kth(Treap::root, k));
			}
		}
	}
	return 0;
}

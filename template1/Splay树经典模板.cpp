
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
 
#define min(a,b) (a<b?a:b)
 
const int MAXN = 32770;
 
class SplayTree {
public:
	struct Item {
		int element,size,times;
		Item *left,*right,*father;
	}*root,*null;
	Item SE[MAXN];
	int LE;
 
	SplayTree() {
		null = &SE[LE=0];
		null->element = ~0U>>1;
		null->size = null->times = 0;
		root = null->left = null->right = null;
	}
 
	// resize
	void Resize(Item* x) {
		x->size = x->left->size + x->right->size + x->times;
	}
 
	// rotate left
	void ZAG(Item* x) {
		Item *y = x->father;
		Item *z = x->left;
		if (y->father->left == y)
			y->father->left = x;
		else
			y->father->right = x;
		x->father = y->father;
		x->left = y;
		y->father = x;
		y->right = z;
		z->father = y;
		Resize(y);
		Resize(x);
	}
 
	// rotate right
	void ZIG(Item* x) {
		Item *y = x->father;
		Item *z = x->right;
		if (y->father->left == y)
			y->father->left = x;
		else
			y->father->right = x;
		x->father = y->father;
		x->right = y;
		y->father = x;
		y->left = z;
		z->father = y;
		Resize(y);
		Resize(x);
	}
 
	// splay
	void Splay(Item* x,Item* y) {
		while (x->father != y) {
			if (x->father->father == y) {
				if (x->father->left == x)
					ZIG(x);
				else
					ZAG(x);
			} else {
				if (x->father->father->left == x->father) {
					if (x->father->left == x) {
						ZIG(x->father);
						ZIG(x);
					} else {
						ZAG(x);
						ZIG(x);
					}
				} else {
					if (x->father->right == x) {
						ZAG(x->father);
						ZAG(x);
					} else {
						ZIG(x);
						ZAG(x);
					}
				}
			}
		}
		if (y == null) 
			root = x;
	}
 
	// insert
	void Insert(Item* x,int e) {
		Item *y = null;
		for(;;) {
			if (x == null) {
				x = &SE[++LE];
				x->element = e;
				x->size = x->times = 1;
				x->father = y;
				x->left = x->right = null;
				if (e < y->element)
					y->left = x;
				else
					y->right = x;
				Splay(x,null);
				return;
			}
			y = x;
			if (e < x->element)
				x = x->left;
			else if (e > x->element)
				x = x->right;
			else {
				++x->times;
				Splay(x,null);
				return;
			}
		}
	}
 
	// find min
	Item* FindMin(Item* x) {
		for (;x->left != null;x = x->left);
		return x;
	}
 
	// find max
	Item* FindMax(Item* x) {
		for (;x->right != null;x = x->right);
		return x;
	}
 
	// join
	Item* Join(Item* x,Item* y) {
		if (x != null)
			x->father = null;
		else
			return y;
			
		if (y != null)
			y->father = null;
		else
			return x;
			
		Item *z = FindMax(x);
		z->right = y;
		y->father = z;
		Splay(z,null);
		return z;
	}
 
	// remove
	void Remove(Item* x,int e) {
		if (x == null)
			return;
		if (e < x->element)
			Remove(x->left,e);
		else if (e > x->element)
			Remove(x->right,e);
		else if (--x->times <= 0) {
			Splay(x,null);
			root = Join(x->left,x->right);
		}
	}
 
	// select
	Item* Select(Item* x,int n) {
        if (x->left->size < n) {
            if (x->left->size + x->times >= n)
                return x;
            return Select(x->right,n - x->left->size - x->times);
        }
        return Select(x->left,n);
    }
 
    // rank
   int Rank(Item* x,int e) {
        if (e < x->element)
            return Rank(x->left,e);
        else if (e > x->element)
            return Rank(x->right,e) + x->left->size + x->times;
        return x->left->size + 1;
    }
 
	// Predecessor
	Item* Pred(Item* x,Item* y,int e) {
		if (x == null)
			return y;
		if (e < x->element)
			return Pred(x->left,y,e);
		return Pred(x->right,x,e);
	}
 
	// Successor
	Item* Succ(Item* x,Item* y,int e) {
		if (x == null)
			return y;
		if (e <= x->element)
			return Succ(x->left,x,e);
		return Succ(x->right,y,e);
	}
 
	int count(int e) {
		Item *p = Pred(root,null,e);
		Item *s = Succ(root,null,e);
		return min(abs(p->element - e),abs(s->element - e));
	}
};
 
int main()
{
 
	SplayTree tree;
	int N,ans,a;
 
	scanf("%d%d",&N,&ans);
	tree.Insert(tree.root,ans);
 
	for (int i=1;i<N;++i) {
		if (scanf("%d",&a) == EOF)
			a = 0;
		ans += tree.count(a);
		tree.Insert(tree.root,a);
	}
 
	printf("%d\n",ans);
	
	return 0;
}

#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 5000005
#define inf 0x7f7f7f7f
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)

int N, M, x;

inline int sqr(const int x) {
	return x * x;
} //平方
int power2(int x) { //找到第一个大于等于x的二的整次幂
	int ans = 1;
	for (; ans < x; ans <<= 1);
	return ans;
}

struct SQRT { //二的整次幂的开根上取和开根下取
	int upper, lower;
} Sqrt[maxn];

/////////////////* van Emde Boas tree

int cluster_cnt, max_low, min_low, offset, succ_cluster, pred_cluster, first_cluster, summary_max;

struct vEB_tree;
vEB_tree *cluster[maxn];

struct vEB_tree { //以下部分解释详见《算法导论》
	int p, u, Min, Max;
	vEB_tree *summary;

	inline int high(int x) {
		return x / Sqrt[u].lower;
	}
	inline int low(int x) {
		return x % Sqrt[u].lower;
	}
	inline int index(int x, int y) {
		return x * Sqrt[u].lower + y;
	}
	vEB_tree() {}

	vEB_tree(int n) :
			u(n) {
		p = cluster_cnt;
		if (n > 2) {
			cluster_cnt += Sqrt[n].upper;
			Min = cluster_cnt - 1;
			rep (i, p, Min) cluster[i] = new vEB_tree(Sqrt[n].lower);
			summary = new vEB_tree(Sqrt[n].upper);
		}
		Min = Max = inf;
	}

	int vEB_tree_Minimum() {
		return Min;
	}
	int vEB_tree_Maximum() {
		return Max;
	}

	bool vEB_tree_Member(int x) {
		if (x == Min || x == Max) return true;
		if (u == 2) return false;
		return cluster[p + high(x)]->vEB_tree_Member(low(x));
	}

	int vEB_tree_Successor(int x) {
		if (u == 2) {
			if (x == 0 && Max == 1) return 1;
			return inf;
		}
		if (Min <= N && x < Min) return Min;
		max_low = cluster[p + high(x)]->vEB_tree_Maximum();
		if (max_low <= N && low(x) < max_low) {
			offset = cluster[p + high(x)]->vEB_tree_Successor(low(x));
			return index(high(x), offset);
		}
		succ_cluster = summary->vEB_tree_Successor(high(x));
		if (succ_cluster > N) return inf;
		offset = cluster[p + succ_cluster]->vEB_tree_Minimum();
		return index(succ_cluster, offset);
	}

	int vEB_tree_Predecessor(int x) {
		if (u == 2) {
			if (x == 1 && Min == 0) return 0;
			return inf;
		}
		if (Max <= N && x > Max) return Max;
		min_low = cluster[p + high(x)]->vEB_tree_Minimum();
		if (min_low <= N && low(x) > min_low) {
			offset = cluster[p + high(x)]->vEB_tree_Predecessor(low(x));
			return index(high(x), offset);
		}
		pred_cluster = summary->vEB_tree_Predecessor(high(x));
		if (pred_cluster > N) {
			if (Min <= N && x > Min) return Min;
			return inf;
		}
		offset = cluster[p + pred_cluster]->vEB_tree_Maximum();
		return index(pred_cluster, offset);
	}

	inline void vEB_empty_tree_Insert(int x) {
		Min = Max = x;
	}

	void vEB_tree_Insert(int x) {
		if (Min > N) vEB_empty_tree_Insert(x);
		else {
			if (x < Min) swap(x, Min);
			if (u > 2) {
				if (cluster[p + high(x)]->vEB_tree_Minimum() > N) {
					summary->vEB_tree_Insert(high(x));
					cluster[p + high(x)]->vEB_empty_tree_Insert(low(x));
				} else
					cluster[p + high(x)]->vEB_tree_Insert(low(x));
			}
			if (x > Max) Max = x;
		}
	}

	void vEB_tree_Delete(int x) {
		if (Min == Max)
			Min = Max = inf;
		else {
			if (u == 2) {
				if (x == 0) Min = 1;
				else Min = 0;
				Max = Min;
			} else {
				if (x == Min) {
					first_cluster = summary->vEB_tree_Minimum();
					x = index(first_cluster, cluster[p + first_cluster]->vEB_tree_Minimum());
					Min = x;
				}
				cluster[p + high(x)]->vEB_tree_Delete(low(x));
				if (cluster[p + high(x)]->vEB_tree_Minimum() > N) {
					summary->vEB_tree_Delete(high(x));
					if (x == Max) {
						summary_max = summary->vEB_tree_Maximum();
						if (summary_max > N) Max = Min;
						else
							Max = index(summary_max, cluster[p + summary_max]->vEB_tree_Maximum());
					}
				} else if (x == Max)
					Max = index(high(x), cluster[p + high(x)]->vEB_tree_Maximum());
			}
		}
	}

}*root;

void Initialization(int n) { //初始化
	for (int i = 0; (1 << i) <= n; ++i) {
		Sqrt[1 << i].lower = 1 << i / 2;
		Sqrt[1 << i].upper = 1 << i / 2 + i % 2;
	}

	root = new vEB_tree(n); //构造vEB tree
}

int main() {
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);

	scanf("%d", &N);

	Initialization(power2(N));

	rep (i, 1, N) {
		scanf("%d", &x);
		root->vEB_tree_Insert(x - 1);
	}

	int opt, x;
	rep (i, 1, N){
		scanf("%d%d", &opt, &x);

		if (opt == 1) root->vEB_tree_Insert(x - 1);
		if (opt == 2) root->vEB_tree_Delete(x - 1);
		if (opt == 3) printf("%d\n", root->vEB_tree_Predecessor(x - 1) + 1);
		if (opt == 4) printf("%d\n", root->vEB_tree_Successor(x - 1) + 1);
	}
	return 0;
}

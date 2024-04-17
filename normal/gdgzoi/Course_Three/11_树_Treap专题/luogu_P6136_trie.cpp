#include <bits/stdc++.h>
using namespace std;

namespace Trie {
    const int N = 100005, D = 30;

    int e;
    int chd[N * D][2];
    int wv[N * D];

    void init() {
        // 0 是兜底节点, 1 是起始节点, e 表示节点个数
        e = 2;
        wv[0] = 0, wv[1] = 0;
        memset(chd[0], 0, sizeof(chd[0]));
        memset(chd[1], 0, sizeof(chd[1]));
    }

    int new_node() {
        wv[e] = 0;
        memset(chd[e], 0, sizeof(chd[e]));
        return e++;
    }

    void add(int x, int v) {
        int p = 0;
        for (int i = D - 1; i >= 0; i--) {
            int id = (x >> i) & 1;
            if (!chd[p][id]) chd[p][id] = new_node();
            p = chd[p][id];
            wv[p] += v;
        }
    }

    // 查询 x 的排名
    // 注意: x 可能并不存在(在求 pre() 的时候)
    int rnk(int x) {
        int p = 0, sz = 0;
        for (int i = D - 1; i >= 0; i--) {
            int id = (x >> i) & 1;
            if (id == 1) sz += wv[chd[p][0]];
            p = chd[p][id];
            if (!p) break;  // x 可能之前不存在
        }
        return sz + 1;
    }

    // 查询从小到大排序后, 排名第 k 的数,
    int kth(int k) {
        int p = 0, x = 0;
        for (int i = D - 1; i >= 0; i--) {
            int l = chd[p][0], r = chd[p][1];
            if (wv[l] >= k) p = l;
            else {
                x |= 1 << i, p = r;
                k -= wv[l];
            }
        }
        return x;
    }

	// 比 x 小的数里面最大的数
	int pre(int x) {
		return kth(rnk(x) - 1);
        // return kth(rnk(x - 1));  // 这个是错的
	}

	// 比 x 大的数里面最小的数
	int suc(int x) {
        return kth(rnk(x + 1));
		// return kth(rnk(x) + 1);  // 这个是错的
	}
};

int main() {
    // 这两句是为了让 cin 更快
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    Trie::init();
    int n, m, c, x, last = 0, ans = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> x;
        Trie::add(x, 1);
    }
	for (int i = 0; i < m; i++) {
        cin >> c >> x;
        x = last ^ x;
		if (c == 1) Trie::add(x, 1);           // 插入 x[i]
        else if (c == 2) Trie::add(x, -1);     // 删除 x[i]
        else if (c == 3) last = Trie::rnk(x);  // x[i] 的排名
        else if (c == 4) last = Trie::kth(x);  // 排名为 x[i] 的数
        else if (c == 5) last = Trie::pre(x);  // 比 x[i] 小的数中最大的
        else if (c == 6) last = Trie::suc(x);  // 比 x[i] 大的数中最小的
        if (c >= 3) ans ^= last;
	}
    cout << ans << '\n';

    return 0;    
}
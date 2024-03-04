#include <bits/stdc++.h>
#define repe(i, u) for (int i = head[u]; i != -1; i = nxt[i])
using namespace std;

const int N = 20005, M = N * 2;
const int INF = numeric_limits<int>::max() / 2;

/*-------------------------- 邻接表存储 begin -------------*/


/*-------------------------- 邻接表存储 end ---------------*/


int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    
    int T, x, y;
    cin >> T;
    while (T--) {
        cin >> n;
        init();
        for (int i = 1; i < n; i++) {
            cin >> x >> y;
            add_edge(x, y);
            add_edge(y, x);
        }
        // get_centroid(1, -1, n);
        // if (cnt == 2 && cent[0] > cent[1]) swap(cent[0], cent[1]);
        // cout << cent[0] << ' ' << w[cent[0]] << '\n';
        
        root = -1;               // 求重心前记得设置 root = -1;
        get_centroid(1, -1, n);  // 求整个树的重心, 结果放在 root, n 是子树大小
        cout << root << " " << w[root] << '\n';
    }
    return 0; 
}
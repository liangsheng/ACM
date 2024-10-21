#pragma comment(linker, "/STACK:536870912")
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    int l, r;  // [<= val: l], [> val: r] 

    Node() {}
    Node (int A, int B, int C): val(A), l(B), r(C) {}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int m, q;
    string s;
    cin >> m >> q >> s;
    int n = s.size();

    // 把 x 调整到 s[0]
    // int x = s.find('x');
    // int w = s.find('?');
    // if (x != 0) {
    //     string t = "x";
    //     if (s[x - 1] == '<') t += ">";
    //     else t += "<";
    //     t += s.substr(0, x - 1);
    //     t += s.substr(w);
    //     s = t;
    // }
    
    // 对于每个 ?, 找到对应的 :
    vector<int> p(n);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        if (s[i] == '?') st.push(i);
        else if (s[i] == ':') p[st.top()] = i, st.pop();
    }

    auto stoi = [&](int l, int r) {
        int ans = 0;
        for (int i = l; i <= r; i++) ans = ans * 10 + s[i] - '0';
        return ans;
    };

    int e = 0;
    vector<Node> tr;
    function<int(int, int)> gao = [&](int l, int r) {
        int x = -1, wen = -1, mao = -1;
        for (int i = l; i <= r; i++) {
            if (s[i] == 'x') x = i;
            else if (s[i] == '?') {
                wen = i;
                break;
            }
        }

        Node t;
        // 到叶节点了
        if (wen == -1) {
            int val = stoi(l, r);
            t = Node(val, -1, -1);
        } else {
            mao = p[wen];
            int u = gao(wen + 1, mao - 1);
            int v = gao(mao + 1, r);
            int val = stoi(x + 2, wen - 1);
            if (s[x + 1] == '<') t = Node(val, u, v);
            else t = Node(val + 1, v, u);
        }
        // cout << "l= " << l << ", r= " << r << ", s= " << s.substr(l, r - l + 1) << '\n';
        // cout << "e= " << e << ", val= " << t.val << ", u= " << t.l << ", v= " << t.r << '\n';
        tr.push_back(t);
        return e++;
    };
    gao(0, n - 1);
    // cout << "e= " << e << '\n';

    vector<tuple<int, int, int>> ans;
    function<void(int, int, int)> dfs = [&](int p, int l, int r) {
        if (l > r) return ;
        if (tr[p].l == -1) {
            // cout << "l= " << l << ", r= " << r << ", val= " << tr[p].val << '\n';
            ans.push_back({l, r, tr[p].val});
            return ;
        }
        dfs(tr[p].l, l, min(r, tr[p].val - 1));
        dfs(tr[p].r, max(l, tr[p].val), r);
    };
    dfs(e - 1, 1, 1000000000);
    sort(ans.begin(), ans.end());
    int sz = ans.size();
    vector<int> a(sz), b(sz);
    for (int i = 0; i < sz; i++) {
        auto [l, r, val] = ans[i];
        a[i] = l, b[i] = val;
    }

    while (q--) {
        int x;
        cin >> x;
        // int p = e - 1;
        // while (tr[p].l != -1) {
        //     if (x < tr[p].val) p = tr[p].l;
        //     else p = tr[p].r;
        // }
        // cout << tr[p].val << '\n';
        int id = upper_bound(a.begin(), a.end(), x) - a.begin() - 1;
        cout << b[id] << '\n';
    }
    return 0;
}
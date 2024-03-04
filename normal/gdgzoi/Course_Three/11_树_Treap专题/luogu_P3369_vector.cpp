// http://gdgzoi.com/showsource.php?id=987790
#include <bits/stdc++.h>
using namespace std;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int n, op, x;
    cin >> n;
    vector<int> a;
    while (n--) {
        cin >> op >> x;
        if (op == 1) {         // 插入 x
            a.insert(lower_bound(a.begin(), a.end(), x), x);
        } else if (op == 2) {  // 删除 x
            a.erase(lower_bound(a.begin(), a.end(), x));
        } else if (op == 3) {  // 查询 x 的排名
            cout << lower_bound(a.begin(), a.end(), x) - a.begin() + 1 << '\n';
        } else if (op == 4) {  // 查询排名 x 的数
            cout << a[x - 1] << '\n';
        } else if (op == 5) {  // 查询 x 的前驱
            cout << *(lower_bound(a.begin(), a.end(), x) - 1) << '\n';
        } else if (op == 6) {  // 查询 x 的后继
            cout << *upper_bound(a.begin(), a.end(), x) << '\n';
        }
    }
    return 0;
}
/**************************************************************
    Problem: 2085
    User: ls01
    Language: C++
    Result: Accepted
    Time:24 ms
    Memory:2336 kb
****************************************************************/
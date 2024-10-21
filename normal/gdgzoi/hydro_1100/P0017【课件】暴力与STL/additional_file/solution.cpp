#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a = {1, 2, 3, 4, 5};

    // 通过匿名函数将 a 从大到小排序
    sort(a.begin(), a.end(), [&](const int& x, const int& y) {
        return x > y;
    });
    
    // 输出 5 4 3 2 1
    for (int x : a) cout << x << ' ';
    cout << '\n';

    return 0;
}
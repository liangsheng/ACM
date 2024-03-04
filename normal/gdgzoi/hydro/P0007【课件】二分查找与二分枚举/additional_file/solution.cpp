#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 4, k = 11;
    vector<int> a = {8, 7, 4, 5};

    // 可以理解为定义了函数 C(int mid)
    // auto 函数名 [&](变量类型 变量名) { };
    auto C = [&](int mid) {
        int cnt = 0;
        // 计算能切割出多少长度为 $mid$ 的绳子
        for (int i = 0; i < n; i++) cnt += a[i] / mid;
        // 当 cnt >= k 时, mid 才满足要求
        return cnt >= k;
    };

    // *max_element() 表示求最大值
    // 语法: *max_element(起始迭代器, 终止迭代器)
    // 切割出来的绳子最短是 l = 1, 最长是绳子的最大值
    int l = 1, r = *max_element(a.begin(), a.end()), mid;
    while (l != r) {
        mid = (l + r) / 2 + 1;  // 注意: 这里要 +1, 不然会死循环
        if (C(mid)) l = mid;    // 如果 mid 满足条件, 则解必然大于等于 mid, 解的范围变成 [mid, r]
        else r = mid - 1;       // 如果 mid 不满足条件, 解的范围变成 [l, mid - 1]
    }

    // 如果 mid = (l + r) / 2 没有 +1 的话, 会死循环
    // 可以执行下下面的代码
    // int l = 1, r = accumulate(a.begin(), a.end(), 0), mid;
    // while (l != r) {
    //     mid = (l + r) / 2;
    //     cout << "l= " << l << ", r= " << r << ", mid= " << mid << " " << C(mid) << '\n';
    //     if (C(mid)) l = mid;
    //     else r = mid - 1;
    // }

    cout << l << '\n';
    return 0;
}
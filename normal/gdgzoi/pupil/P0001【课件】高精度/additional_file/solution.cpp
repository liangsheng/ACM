#include <bits/stdc++.h>
using namespace std;

int main() {

    // 申请长度为 3 的 vector<int>, 初始值都是 1
    // 相当于: int a[3] = {1, 1, 1};
    vector<int> a(3, 1);

    // 输出 a 的长度: 3
    cout << a.size() << '\n';

    // 在 a 的最后插入 5, {1, 1, 1} => {1, 1, 1, 5}
    a.push_back(5);

    // 在 a 的最后插入 7, {1, 1, 1, 7} => {1, 1, 1, 5, 7}
    a.push_back(7);

    // 输出 a 的长度: 5
    cout << a.size() << '\n';

    // 删除 a 的最后一个元素，{1, 1, 1, 5, 7} => {1, 1, 1, 5}
    a.pop_back();

    // 输出 a 的第 1 个和最后 1 个元素: 1 5
    cout << a.front() << ' ' << a.back() << '\n';
    return 0;
}
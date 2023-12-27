#include <bits/stdc++.h>
using namespace std;

int main() {
    set<int> s;

    // 插入集合 s 中的元素, 默认从小到大排列
    // 所以 set 也可以用来排序
    s.insert(3);  // s = {3}
    s.insert(2);  // s = {2, 3}
    s.insert(1);  // s = {1, 2, 3}
    s.insert(1);  // s = {1, 2, 3}, 元素 1 本来就存在

    // 通过 s.beign() 获取 s 中最小的数的迭代器
    // 通过 * 解引用, 可以获取迭代器指向的具体指
    cout << *s.begin() << '\n';   // 输出: 1

    // 通过 s.rbeign() 获取 s 中最小的数的迭代器
    cout << *s.rbegin() << '\n';  // 输出: 3 

    // 输出: 1 2 3
    for (int x : s) cout << x << ' ';
    cout << '\n';

    // 还可以通过迭代器遍历
    // 输出: 1 2 3
    for (auto i = s.begin(); i != s.end(); i++) cout << *i << ' ';
    cout << '\n';

    // 通过 s.count(x) 判断元素 x 是否在集合 s 中
    cout << (s.count(1) ? "s 中存在 1" : "s 中不存在 1") << '\n';
    cout << (s.count(4) ? "s 中存在 4" : "s 中不存在 4") << '\n';

    // 如果 s 中存在 x, 可以通过 s.find(x) 找到 x 对应的迭代器
    if (s.count(2)) {
        auto it = s.find(2);
        // 输出: 1, 也就是集合 s 中 2 的前一个数
        // 这里需要判断 it 是否是 s 的第 1 个指针
        // 如果 it == s.beign(), it 就不能再往前移
        if (it != s.begin()) {
            auto pre = it;
            cout << *(--pre) << '\n';
        }
        
        // 输出: 3, 也就是集合 s 中 2 的后一个数
        auto after = it;
        // 这里需要判断 after == s.end()
        if (++after != s.end()) cout << *after << '\n';
    }

    // 可以通过 s.erase(x), 删除 s 中的元素
    // 如果 s 中存在 x, 则删除 x; 否则, 就什么也不做
    s.erase(1);
    // 输出: 2 3
    for (int x : s) cout << x << ' ';
    cout << '\n';

    // erase() 里面的参数也可以是迭代器
    s.erase(s.find(2));
    // 输出: 3
    for (int x : s) cout << x << ' ';
    cout << '\n';

    // 通过 s.size() 获取 s 中元素的个数
    // 输出: 1
    cout << s.size() << '\n';

    // 通过 s.empty() 判断 s 是否为空集合
    // 输出: s 不为空
    cout << (s.empty() ? "s 为空" : "s 不为空") << '\n';

    // 通过 s.clear()，可以将 s 清空
    s.clear();
    cout << (s.empty() ? "s 为空" : "s 不为空") << '\n';

    // 思考下下面这个复杂的 map, 要如何遍历
    map<vector<int>, pair<int, set<int>>> f;
    for (auto i : f) {
        // i.first 是 vector<int>
        cout << "key: " << '\n';
        for (int j : i.first) cout << ' ';
        cout << '\n';

        // i.second 是 pair<int, set<int>>
        cout << "value: " << '\n';
        // i.second.first 是 int
        cout << i.second.first << '\n';
        // i.second.second 是 set<int>
        for (int j : i.second.second) cout << j << ' ';
        cout << '\n';
    }
    return 0;
}
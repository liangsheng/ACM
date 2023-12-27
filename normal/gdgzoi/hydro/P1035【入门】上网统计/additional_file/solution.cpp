#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    string name, web;
    map<string, vector<string>> q;  // 存储每个人看的网页
    vector<string> names;           // 当每个人第一次浏览网页的时候, 存到数组里
    cin >> n >> m;
    while (m--) {
        cin >> name >> web;
        if (!q.count(name)) names.push_back(name);
        q[name].push_back(web);
    }
    for (string i : names) {       // 按照用户名出现的次序排序输出
        cout << i;
        for (auto s : q[i]) cout << ' ' << s;
        cout << '\n';
    }
    return 0;
}
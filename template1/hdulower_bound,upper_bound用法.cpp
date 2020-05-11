/*
lower_bound(val): 返回容器中第一个值【大于或等于】val的元素的iterator位置。
upper_bound(val): 返回容器中第一个值【大于】val的元素的iterator位置。
Lower_bound函数用法，这个函数用来返回要查找关键字的下界(是一个迭代器) 　　
Upper_bound函数用法，这个函数用来返回要查找关键字的上界(是一个迭代器) 　　
例如：map中已经插入了1，2，3，4的话，如果lower_bound(2)的话，返回的2，
而upper_bound（2）的话，返回的就是3
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#define N 10005
using namespace std;

int n, m;

int main()
{
    int i, j, x, y, t1, t2;
    vector<int> start, end;
    while (scanf("%d%d", &n, &m) != EOF && n != 0 && m != 0)
    {
        start.clear(), end.clear();
        for (i = 1; i <= n; i++)
        {
            scanf("%d%d%d%d", &t1, &t2, &x, &y);
            y = x + y;
            start.push_back(x);
            end.push_back(y);
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        for (i = 1; i <= m; i++)
        {
            scanf("%d%d", &x, &y);
            y = x + y;
            t1 = start.end() - lower_bound(start.begin(), start.end(), y);
            t2 = upper_bound(end.begin(), end.end(), x) - end.begin();
            printf("%d\n", n - t1 - t2);
        }
    }
    system("pause");
    return 0;
}

//============================================================================
// Name        : zoj3574.cpp
// Author      : 0222_
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define lowbit(x) (x & (-x))
#define N 30010
using namespace std;

struct Node
{
	int x, y;
};
int n, x1, x2;
int k[N], d[N];
Node p1[N], p2[N];

int a[N];

bool operator < (Node arg0, Node arg1)
{
	return arg0.x < arg1.x;
}

int find(int i)
{
	int ans = 0;
	while (i > 0)
	{
		ans += a[i];
		i -= lowbit(i);
	}
	return ans;
}

int add(int i)
{
	while (i <= n)
	{
		a[i]++;
		i += lowbit(i);
	}
	return 1;
}

int main()
{
	setvbuf(stdout, NULL, _IONBF,0);
	int i, ans;
	while (scanf("%d%d", &x1, &x2)!= EOF)
	{
		scanf("%d", &n);
		for (i = 1; i <= n; i++) scanf("%d%d", &k[i], &d[i]);
		for (i = 1; i <= n; i++)
		{
			p1[i].x = k[i] * x1 + d[i];
			p1[i].y = k[i] * x2 + d[i];
		}
		sort(p1 + 1, p1 + n + 1);
		for (i = 1; i <= n; i++)
		{
			p2[i].x = p1[i].y;
			p2[i].y = i;
		}
		sort(p2 + 1, p2 + n + 1);
		memset(a, 0, sizeof(a));
		ans = 0;
		for (i = n; i >= 1; i--)
		{
			ans += find(p2[i].y);
			add(p2[i].y);
		}
		printf("%d\n", ans + n + 1);
	}
	return 0;
}

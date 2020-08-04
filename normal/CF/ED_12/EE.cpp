#include<stdio.h>
#include<iostream>
#include<string.h>
#include<string>
#include<ctype.h>
#include<math.h>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<bitset>
#include<algorithm>
#include<time.h>
using namespace std;
void fre() { freopen("c://test//input.in", "r", stdin); freopen("c://test//output.out", "w", stdout); }
#define MS(x,y) memset(x,y,sizeof(x))
#define MC(x,y) memcpy(x,y,sizeof(x))
#define MP(x,y) make_pair(x,y)
#define ls o<<1
#define rs o<<1|1
typedef long long LL;
typedef unsigned long long UL;
typedef unsigned int UI;
template <class T1, class T2>inline void gmax(T1 &a, T2 b) { if (b>a)a = b; }
template <class T1, class T2>inline void gmin(T1 &a, T2 b) { if (b<a)a = b; }
const int N = 31e6+10, M = 0, Z = 1e9 + 7, ms63 = 0x3f3f3f3f;
int n, K;
int a[N][2];
int cnt[N];
int id;
int X;
void ins(int x)
{
	int k = 0;
	for (int i = 30; i >= 0; --i)
	{
		int w = x >> i & 1;
		if (a[k][w] == 0)a[k][w] = ++id;
		k = a[k][w];
		++cnt[k];
	}
}

//我们要使得异或值>=K
int check(int x)
{
	int ret = 0;
	int k = 0;
	for (int i = 30; i >= 0; --i)
	{
		int w = x >> i & 1;
		int kw = K >> i & 1;

		//异或值为1，必须这么走
		if (kw == 1)
		{
			k = a[k][w ^ 1];
			if (k == 0)return ret;
		}
		//异或值为0，走1即YES；走0则继续
		else
		{
			int kk = a[k][w ^ 1];
			ret += cnt[kk];
			k = a[k][w];
			if (k == 0)return ret;
		}
	}
	return ret + cnt[k];
}
int main()
{cout << N;
	while (~scanf("%d%d", &n, &K))
	{
		MS(a, 0); MS(cnt, 0); id = 0;
		ins(0);

		X = 0;
		LL ans = 0;
		for (int i = 1; i <= n; ++i)
		{
			int x; scanf("%d", &x); X ^= x;
			ans += check(X);
			ins(X);
			printf("%d\n", ans);
		}
		printf("%lld\n", ans);
	}
	return 0;
}

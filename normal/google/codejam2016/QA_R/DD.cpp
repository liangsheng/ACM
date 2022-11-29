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
const int N = 1010, M = 0, Z = 1e9 + 7, ms63 = 0x3f3f3f3f;
int casenum, casei;
void fre()
{
	freopen("c://test//input.in", "r", stdin);
	freopen("c://test//output.out", "w", stdout);
}
LL k, c, s;
void solve()
{
	int p = 0;
	while (p < k)
	{
		LL pos = 0;
		for (int i = 0; i < c; ++i)
		{
			pos = pos*k + min((LL)p, k - 1);
			++p;
		}
		printf("%lld ", pos + 1);
	}puts("");
}
int main()
{
	//fre();
	scanf("%d", &casenum);
	for (casei = 1; casei <= casenum; ++casei)
	{
		scanf("%lld%lld%lld", &k, &c, &s);
		printf("Case #%d: ", casei);
		if (s*c < k)puts("IMPOSSIBLE");
		else solve();
	}
}
/*
【trick&&吐槽】
手动模拟找规律其实是解决构造问题很行之有效的方法。

【题意】
https://code.google.com/codejam/contest/6254486/dashboard#s=p3
给你一个K，表示我们的基础图形（其位于复杂度1下），
图形包括'L'和'G'两种字符。
对于在复杂度i下的图形，在其变化为复杂度i+1图形的时候
'L'会变成复杂度为1的基础图形
'G'会变为长度为K的全'G'图形

我们现在得到了复杂度为C的图形。然而并不知道这个图形是什么。
不过，我们现在拥有S次机会，可以知道复杂度为C图形的最多S个位置的图形是什么（'L'还是'G'）
问你能否选择S个位置，判断出原始图形中是否有'G'存在

1 ≤ T ≤ 100.
1 ≤ K ≤ 100.
1 ≤ C ≤ 100.
1<=S<=K
K^C ≤ 1018.
（小数据S==K）

【类型】
构造 找规律

【分析】
这题的小数据完全是送分的。
对于小数据，我们可以发现，原来第i个位置（i为0base from 0~K-1)，
在复杂度2下，会变为i*K+i
在复杂度3下，会变为(i*K+i)*K+i
我们只要这样映射下去，最后直接处理这就可以找到答案。
然而，更进一步，其实我们只要输出前K个位置就可以了。
因为它们要不就全部为G，要不就为第一行，不论是哪种情况，我们都可以还原整个序列。

======================================================================
而我们要如何处理大数据呢？
事实上——
K作为原串长度，C作为原串扩展的次数，S为我们可以查看的位置
只要K<=C*S，就一定有解。

举例说，原串的长度K为2，变换的次数C为2，查看的位置S为1。
答案为yes，我们只要查看第二个位置就可以了。

为什么呢？
长度K为2的原始串有4个
LL，LG，GL，GG，
它们经过变换后会相应变为——
LLLL，LGGG，GGGL，GGGG
果然，我们只要查看第二个位置就可以。

原始串的长度越少，我们需要的查看次数就越少，这个很好理解。
然而，变换的次数越多，我们需要查看的次数同样也越少，这个是为什么呢？

---------------------------------------------------------------------
设第一次的串长度为n，第i个位置的为a[i]

经过一次变换之后，这个字符串会变为n段，每段各有n个字符。
如果是在第二层的字符串上查询，我们可以查询第1段字符中的第2个。
如果这个字符是G，显然已经结束。
如果这个字符不是G，显然它能够说明a[1]!='G'且a[2]!='G'，一下子验证了2个位置

经过两次变换之后，这个字符串会变为n*n*n的结构
如果我们是在第三层的字符串上查询，我们可以查询第1大段中第2小段中的第3个字符。
如果这个字符是G，显然已经结束。
如果这个字符不是G，显然它能说明a[1]!='G'且a[2]!='G'且a[3]!='G'

于是——
C*S是我们的验证能力，C*S>=K答案即为Possible，我们即可以根据之前找到的规律构造具体实现方案。
详细参照代码

【时间复杂度&&优化】
O(c+s+k)

*/

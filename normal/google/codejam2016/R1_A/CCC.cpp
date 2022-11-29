#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MAXN 1005

using namespace std;

static int a[MAXN];

static char b[MAXN];
int cycleId;
int cycleLength;
int cycleBreak;
int pathLength;
char inCycle;

void DFS1 (int point, int depth)
{
	if (b[point])
	{
		cycleBreak = point;
		cycleLength = 0;
		cycleId = point;
		inCycle = 1;
		return;
	}
	b[point] = 1;
	DFS1(a[point], depth+1);
	if (inCycle)
	{
		cycleLength++;
		if (point == cycleBreak)
		{
			inCycle = 0;
			pathLength = depth + 1;
		}
	}
}

int main ()
{
	int T, iT;
	scanf("%d",&T);
	static int cnt[MAXN];
	for (iT = 0; iT < T; iT++)
	{
		int N;
		scanf("%d",&N);
		int i;
		for (i = 0; i < N; i++)
		{
			scanf("%d",&a[i]);
			a[i]--;
		}
		int res = 0;
		memset(cnt, 0, sizeof(cnt));
		for (i = 0; i < N; i++)
		{
			memset(b, 0, sizeof(b));
			DFS1(i, 0);
			if (cycleLength == 2)
			{
				if (pathLength > cnt[cycleId]) cnt[cycleId] = pathLength;
			}
			else
			{
				if (cycleLength > res) res = cycleLength;
			}
		}
		int cntSum = 0;
		for (i = 0; i < N; i++)
		{
			cntSum += cnt[i];
		}
		if (cntSum > res) res = cntSum;
		printf("Case #%d: %d\n",iT+1,res);
	}
	return 0;
}


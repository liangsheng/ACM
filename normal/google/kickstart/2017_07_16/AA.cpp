#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 2222;
const long long inf = 1e18;

long long dp[maxn][maxn];
long long S[maxn], F[maxn], D[maxn];

long long ceil(long long a, long long b)
{
    return (a + b - 1) / b;
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int kase = 1; kase <= T; ++kase)
    {
        long long N, Ts, Tf;
        scanf("%lld %lld %lld", &N, &Ts, &Tf);
        for (int i = 1; i < N; ++i)
            scanf("%lld %lld %lld", &S[i], &F[i], &D[i]);
        for (int i = 0; i <= N; ++i)
            dp[0][i] = inf;
        dp[0][0] = 0;
        for (int i = 1; i < N; ++i)
        {
            for (int j = 0; j <= N; ++j)
                dp[i][j] = inf;
            for (int j = 0; j <= N; ++j)
            {
                if (dp[i - 1][j] > Tf)
                    continue;
                long long tmp = max(dp[i - 1][j], S[i]);
                long long cnt = ceil(tmp - S[i], F[i]);
                long long st = S[i] + cnt * F[i];
                dp[i][j] = min(dp[i][j], st + D[i]);
            }
            for (int j = 0; j <= N; ++j)
            {
                if (dp[i - 1][j] + Ts > Tf)
                    continue;
                long long tmp = max(dp[i - 1][j] + Ts, S[i]);
                long long cnt = ceil(tmp - S[i], F[i]);
                long long st = S[i] + cnt * F[i];
                dp[i][j + 1] = min(dp[i][j + 1], st + D[i]);
            }
        }
        int ans = -1;
        for (int i = 0; i <= N; ++i)
            if (dp[N - 1][i] <= Tf)
                ans = max(ans, i);
        printf("Case #%d: ", kase);
        if (ans == -1)
            puts("IMPOSSIBLE");
        else
            printf("%d\n", ans);
    }
    return 0;
}
#include<cstdio>
#define MOD 1000000000
typedef long long int lld;
using namespace std;
int N, K;
lld dp[202][202];
/*
	직접 손으로 그리고, 표로 그려봐야해
*/
int main()
{
	scanf("%d %d", &N, &K);
	dp[0][0] = 1LL;
	//dp[n][k] = dp[n][k-1]+dp[n-1][k];
	for (int i = 0; i <= K; ++i)
	{
		dp[0][i] = 1LL;
	}
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= K; ++j)
		{
			dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
			dp[i][j] %= MOD;
		}
	}
	printf("%lld\n", dp[N][K]);
	return 0;
}
#include<cstdio>
#define MOD 1000000000
typedef long long int lld;
using namespace std;
lld dp[101][11];
int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= 9; ++i)
		dp[1][i] = 1;

	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j <= 9; ++j)
		{
			if (j == 0)
			{
				dp[i][j] = dp[i - 1][j + 1];
				dp[i][j] %= MOD;
			}
			else if(j == 9)
			{
				dp[i][j] = dp[i - 1][j - 1];
				dp[i][j] %= MOD;
			}
			else 
			{
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
				dp[i][j] %= MOD;
			}
		}
	}
	lld result = 0;
	for (int i = 0; i <= 9; ++i)
	{
		result += dp[N][i];
		result %= MOD;
	}
		

	printf("%lld\n", result%MOD);
	
	return 0;
}
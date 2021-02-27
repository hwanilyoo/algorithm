#include<cstdio>
#define MOD 10007
using namespace std;

int dp[1010][10];
int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i <= 9; i++)
		dp[1][i] = 1;

	for (int i = 2; i <= N; ++i)
	{
		for (int j = 0; j <= 9; ++j)
		{
			for (int k = 0; k <= j; ++k)
			{
				dp[i][j] += dp[i - 1][k];
				dp[i][j] %= MOD;
			}
		}
	}
	int result = 0;
	for (int i = 0; i <= 9; ++i) 
	{
		result += dp[N][i];
		result %= MOD;
	}
		
	
	printf("%d\n", result% MOD);
	return 0;
}
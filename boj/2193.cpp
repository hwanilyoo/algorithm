#include<cstdio>
typedef long long int lld;
using namespace std;
int N;
lld dp[101][2]; // dp[N][i] : 길이가 N이고 끝이 i인 이친수의 갯수 
int main()
{
	scanf("%d", &N);
	dp[1][1] = 1;

	for (int i = 2; i <= N; ++i)
	{
		for (int j = 0; j <= 1; ++j)
		{
			if (j == 0)
			{
				dp[i][j] = dp[i - 1][1] + dp[i - 1][0]; //길이가 N인 이친수의 끝자리가 0이면 
			}											//길이가 N-1인 이친수의 끝자리는 0 or 1 둘 다 된다.	
			else
			{
				dp[i][j] += dp[i - 1][0]; //길이가 N인 이친수의 끝자리가 1이면 길이가 N-1인 이친수의 끝자리는 0 만 된다.
			}
		}
	}
	
	lld result = 0;
	for (int i = 0; i <= 1; ++i)
	{
		result += dp[N][i];
	}
	printf("%lld\n",result);
	return 0;
}
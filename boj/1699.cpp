#include<cstdio>
#include<algorithm>
using namespace std;
int N, dp[100010];
/*
	dp[i] : i를 제곱수의 합으로 나타냈을때, 필요한 항의 갯수
	dp[N] = dp[N-i^2] + 1 -> 1을 더하는이유는 i^2을 1개로 계산하니깐!
*/
int main()
{
	scanf("%d", &N);
	
	int cnt = 1;
	for (int i = 1; i <= N; ++i)
	{
		dp[i] = i;
		for (int j = 1; j*j <= i; ++j)
		{
			if (dp[i] > dp[i - j * j] + 1)
			{
				dp[i] = dp[i - j * j] + 1;
			}
		}
	}
	printf("%d\n", dp[N]);
	return 0;
}
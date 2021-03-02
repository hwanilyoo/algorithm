#include<cstdio>
#include<algorithm>
using namespace std;
int N, dp[1001], arr[1001];

/*
dp[i] : i번째를 마지막으로 하는 가장 긴 증가하는 부분수열의 길이

*/
int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i)
		scanf("%d", &arr[i]);
	
	
	for (int i = 1; i <= N; i++)
	{
		dp[i] = 1;
		for (int j = 1; j <= i; ++j)
		{
			if (arr[i] > arr[j])
			{
				dp[i] = max(dp[j] + 1, dp[i]);
			}
		
		}
	}
	int res = 0;
	for (int i = 1; i <= N; ++i)
	{
		if (res < dp[i])
		{
			res = dp[i];
		}
	}
	printf("%d\n", res);
	return 0;
}
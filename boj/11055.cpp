#include<cstdio>
#include<algorithm>
using namespace std;
int N, dp[1001], arr[1001];

/*
dp[i] : i번째를 마지막으로 하는 증가하는 부분수열 의 합

*/
int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i)
	{
		scanf("%d", &arr[i]);
	}

	for (int i = 1; i <= N; ++i)
	{
		dp[i] = arr[i];
		for (int j = 1; j < i; ++j)
		{
			if (arr[i] > arr[j])
			{
				dp[i] = max(dp[j] + arr[i], dp[i]);
			}
		}
	}

	int result = 0;
	for (int i = 1; i <= N; ++i) 
	{
		if (result < dp[i])
			result = dp[i];
	}
	printf("%d\n", result);
	return 0;
}
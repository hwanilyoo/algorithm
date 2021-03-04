#include<cstdio>
#include<algorithm>
using namespace std;
int N, arr[100010], dp[100010];

//dp[i] : i번째를 마지막으로 더했을때의 연속합의 최대값
int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i)
	{
		scanf("%d", &arr[i]);
		dp[i] = arr[i];
	}

	for (int i = 2; i <= N; ++i)
	{
		dp[i] = max(dp[i], dp[i - 1] + arr[i]);
	}
	
	int result = -987654321;
	for (int i = 1; i <= N; ++i)
		if (result < dp[i])
			result = dp[i];

	printf("%d\n", result);
	return 0;
}
#include<cstdio>
#include<algorithm>
using namespace std;
int N, arr[310], dp[310];
/*
dp[i] = i번째 계단을 마지막으로 밟았을때의 최대값
*/
int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", &arr[i]);

	dp[1] = arr[1]; 
	dp[2] = dp[1] + arr[2];
	for (int i = 3; i <= N; ++i)
	{
		dp[i] = max(dp[i - 3] + arr[i - 1], dp[i - 2]) + arr[i];
	}
	printf("%d\n", dp[N]);
	return 0;
}
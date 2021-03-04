#include<cstdio>
#include<algorithm>
using namespace std;
int N, arr[1010], dp1[1010], dp2[1010];
/*
dp1 : 증가하는 부분수열
dp2 : 뒤에서부터 증가하는 수열(즉 감소하는)

dp1 + dp2 - 1

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
		dp1[i] = 1;
		for (int j = 1; j <= N; ++j)
		{
			if (arr[i] > arr[j] && dp1[i] < dp1[j] + 1)
			{
				dp1[i] = dp1[j] + 1;
			}
		}
	}

	for (int i = N; i >= 1; --i)
	{
		dp2[i] = 1;
		for (int j = i+1; j <= N; ++j)
		{
			if (arr[i] > arr[j] && dp2[i] < dp2[j] + 1)
			{
				dp2[i] = dp2[j] + 1;
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		if (ans < dp1[i] + dp2[i] - 1) {
			ans = dp1[i] + dp2[i] - 1;
		}
	}
	printf("%d\n", ans);
	return 0;
}
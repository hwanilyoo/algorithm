#include<cstdio>
#include<cstring>
typedef long long int lld;
using namespace std;
/*
 인내심을 갖고 그림을 잘 보면 규칙이 보인다
*/
int main()
{
	int T;
	scanf("%d", &T);
	for (int test = 0; test < T; ++test)
	{
		int N;
		lld dp[102];
		
		scanf("%d", &N);
		memset(dp, 0, sizeof(dp));
		dp[1] = 1;
		dp[2] = 1;
		dp[3] = 1;
		dp[4] = 2;
		dp[5] = 2;
		for (int i = 6; i <= N; ++i)
		{
			dp[i] = dp[i - 1] + dp[i - 5];
		}
		printf("%lld\n", dp[N]);
	}

	return 0;
}
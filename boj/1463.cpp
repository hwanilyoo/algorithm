#include<cstdio>
#include<algorithm>

using namespace std;

int N;
int memo[1000011];

// 정수 N을 1로 만들때의 연산의 횟수
int solve(int n)
{
	if (n == 1)
		return 0; // 1을 1로만들때의 연산횟수는 0번
	if (memo[n] != -1)
		return memo[n];
	

	int result = solve(n - 1) + 1;
	if (n % 3 == 0) result = min(result, solve(n / 3) + 1);
	if (n % 2 == 0) result = min(result, solve(n / 2) + 1);
	memo[n] = result;
	return result;
}
int main()
{
	scanf("%d", &N);
	for (int i = 0; i <= N; ++i)
	{
		memo[i] = -1;
	}
	printf("%d\n", solve(N));
	return 0;
}
#include<cstdio>
#include<iostream>
using namespace std;

int N, R, C;
int solve(int n, int y, int x)
{
	if (n == 0) return 0; // n = 0 -> 1*1 = 0번째!
	int half = 1 << (n - 1);
	if (y < half && x < half) // 1번 사각형
	{
		return solve(n - 1, y, x);
	}
	else if (y < half && x >= half)
	{
		return half * half + solve(n - 1, y, x - half);
	}
	else if (y >= half && x < half)
	{
		return 2 * half * half + solve(n - 1, y - half, x);
	}
	else
	{
		return 3 * half * half + solve(n - 1, y - half, x - half);
	}
}
int main()
{

	scanf("%d %d %d", &N, &R, &C);
	cout << solve(N, R, C);
	return 0;
}
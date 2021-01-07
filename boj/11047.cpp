#include<cstdio>
using namespace std;

int main()
{
	int arr[12];
	int N, K;
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
	int cnt = 0;
	for (int i = N - 1; i >= 0; i--)
	{
		if (K / arr[i] == 0)
			continue;
		cnt += K / arr[i];
		K = K % arr[i];
	}
	printf("%d\n", cnt);
	return 0;
}
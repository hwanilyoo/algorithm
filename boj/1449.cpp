#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	int N, L;
	int arr[1011];
	memset(arr, 0, sizeof(arr));
	scanf("%d %d", &N, &L);
	for (int i = 0; i < N; i++)
	{
		int num;
		scanf("%d", &num);
		arr[num] = -1;
	}
	int cnt = 0;
	for (int i = 1; i <= 1000; i++)
	{
		if (arr[i] == -1)
		{
			++cnt;
			for (int j = i; j <= i + L - 1; j++)
			{
				arr[j] = cnt;
				if (j >= 1000)
					break;
				
			}
		}
	}
	printf("%d\n",cnt);
	return 0;
}
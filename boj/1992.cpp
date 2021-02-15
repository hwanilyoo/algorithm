#include<cstdio>
#include<algorithm>

using namespace std;

int N, map[65][65];
int isOkay(int y, int x, int size)
{
	int start = map[y][x];
	for (int i = y; i < y + size; ++i)
	{
		for (int j = x; j < x + size; ++j)
		{
			if (start != map[i][j])
				return -1;
		}
	}
	return start;
}
void solve(int y, int x, int size)
{
	if (size == 0)
		return;

	
	int ans = isOkay(y, x, size);
	if ( ans != -1)
	{
		printf("%d",ans);
	}
	else {
		printf("(");
		size = size / 2;
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				
				solve(y + i * size, x + j * size, size);
			}
		}
		printf(")");
	}
	
	
}
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; ++j)
		{
			scanf("%1d", &map[i][j]);
		}
	}
	solve(0, 0, N);
	return 0;
}
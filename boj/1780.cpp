#include<cstdio>

using namespace std;

int map[2222][2222];
int N;
int ans[3];

//종이가 모두 같은 수 인지 check 
bool check(int y, int x, int size)
{
	int tmp = map[y][x];
	for (int i = y; i < y + size; ++i)
	{
		
		for (int j = x; j < x + size; ++j)
		{
			if (tmp != map[i][j])
			{
				return false;
			}
		}
	}

	return true;
}

void cut(int y, int x, int n)
{
	if (check(y, x, n))
	{
		ans[map[y][x]]++;
	}
	else 
	{
		int size = n / 3;

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cut(y + size * i, x + size * j, size);
			}
		}
	}
}
int main()
{
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int input;
			scanf("%d", &input);
			input++;
			map[i][j] = input;
		}
	}

	cut(0, 0, N);
	printf("%d\n%d\n%d\n", ans[0], ans[1], ans[2]);
	return 0;
}
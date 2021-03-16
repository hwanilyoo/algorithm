#include<cstdio>
#include<queue>
#include<algorithm>
#include<vector>

using namespace std;

int Y, X;
int arr[1002][1002];
int dist[1002][1002];
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };
int main()
{
	scanf("%d %d", &X, &Y);
	queue<pair<int, int > > tomato;
	int ans = 0;
	for (int i = 0; i < Y; ++i)
	{
		for (int j = 0; j < X; ++j)
		{
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 1) 
				tomato.push({ i,j });
			if (arr[i][j] == 0)
				dist[i][j] = -1;
		}
	}
	
	while (!tomato.empty())
	{
		pair<int, int > now = tomato.front(); tomato.pop();

		for (int dir = 0; dir < 4; ++dir)
		{
			int nY = now.first + dy[dir];
			int nX = now.second + dx[dir];
			if (nY < 0 || nY >= Y || nX<0 || nX > X)
				continue;
			if (dist[nY][nX] >= 0)
				continue;
			dist[nY][nX] = dist[now.first][now.second] + 1;
			tomato.push({ nY,nX });
		}
	}

	for (int i = 0; i < Y; ++i)
	{
		for (int j = 0; j < X; ++j)
		{
			if (dist[i][j] == -1)
			{
				printf("-1\n");
				return 0;
			}
			ans = max(ans, dist[i][j]);
		}
	}
	printf("%d\n", ans);
	return 0;
}
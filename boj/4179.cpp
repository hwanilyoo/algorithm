#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
int Y, X;
char map[1010][1010];
int dist1[1010][1010], dist2[1010][1010];
int dy[] = { 0,0,-1,1 };
int dx[] = { -1,1,0,0 };
int main()
{
	queue < pair<int, int>> q1, q2;
	scanf("%d %d", &Y, &X);
	for (int i = 0; i < Y; i++) {
		fill(dist1[i], dist1[i] + X, -1);
		fill(dist2[i], dist2[i] + X, -1);
	}
	for (int i = 0; i < Y; ++i)
	{
		for (int j = 0; j < X; ++j)
		{
			scanf(" %c", &map[i][j]);
			if (map[i][j] == 'J')
			{
				q1.push({ i,j });
				dist1[i][j] = 0;
			}
			else if (map[i][j] == 'F')
			{
				q2.push({ i,j });
				dist2[i][j] = 0;
			}
			
		}
	}
	
	while (!q2.empty())
	{
		pair<int, int> now = q2.front(); q2.pop();
		for (int dir = 0; dir < 4; ++dir)
		{
			int nY = now.first + dy[dir];
			int nX = now.second + dx[dir];
			if (nY >= 0 && nY < Y && nX >= 0 && nX < X && dist2[nY][nX] == -1 && map[nY][nX] != '#') 
			{
				dist2[nY][nX] = dist2[now.first][now.second] + 1;
				q2.push({ nY, nX });
			}

		}
	}
	
	int ans = -1;
	while (!q1.empty())
	{
		pair<int, int > now = q1.front(); q1.pop();
		if (now.first == 0 || now.first == Y - 1 || now.second == 0 || now.second == X - 1)
		{
			ans = dist1[now.first][now.second]+1;
			break;
		}
		for (int dir = 0; dir < 4; ++dir)
		{
			int nY = now.first + dy[dir];
			int nX = now.second + dx[dir];
			if (nY >= 0 && nY < Y && nX >= 0 && nX < X && dist1[nY][nX] == -1 && map[nY][nX] != '#' && 
				 (dist2[nY][nX] == -1 || dist1[now.first][now.second] + 1 < dist2[nY][nX] ))
			{
				dist1[nY][nX] = dist1[now.first][now.second] + 1;
				q1.push({ nY,nX });
			}
			
		}
	}

	if (ans == -1)
	{
		printf("IMPOSSIBLE\n");
	}
	else
	{
		printf("%d\n", ans);
	}
	return 0;
}
#include<cstdio>
#include<algorithm>

using namespace std;
int N, A[100000];

int histogram(int s, int e)
{
	if (s == e) // (s,e]
		return 0;
	if (s + 1 == e)
		return A[s];

	int mid = (s + e) / 2;
	int result = max(histogram(s, mid), histogram(mid, e));
	int w = 1, h = A[mid], l = mid, r = mid;
	int p = -1, q = -1, value;
	while (r - l + 1 < e - s)
	{
		//왼쪽 막대기
		if (l > s)
		{
			p = min(h, A[l - 1]);
		}
		else {
			p = -1;
		}
		//오른쪽 막대기
		if (r < e-1)
		{
			q = min(h, A[r + 1]);
		}
		else
		{
			q = -1;
		}

		//왼쪽 막대기, 오른쪽 막대기 크기 비교
		if (p >= q)
		{
			h = p;
			--l;
		}
		else
		{
			h = q;
			++r;
		}
		result = max(result, ++w * h);
	}
	return result;
}
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &A[i]);
	}
	printf("%d", histogram(0, N));
	return 0;
}
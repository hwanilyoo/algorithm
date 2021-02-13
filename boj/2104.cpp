#include<cstdio>
#include<algorithm>
using namespace std;

int N, A[100000];

long long maxScore(int s, int e)
{
	if (s == e - 1)
		return 1LL * A[s] * A[s];

	int mid = (s + e) / 2;
	long long result = max(maxScore(s, mid), maxScore(mid, e));
	
	long long sum = A[mid],minVal = A[mid];
	result = max(result, sum * minVal);

	for (int lo = mid, hi = mid; lo > s || hi < e - 1;)
	{
		if (lo == s || hi < e-1 && A[hi + 1] > A[lo - 1])
		{
			sum += A[++hi];
			minVal = min(minVal, (long long) A[hi]);
		}
		else
		{
			sum += A[--lo];
			minVal = min(minVal, (long long) A[lo]);
		}
		result = max(result, sum * minVal);
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

	printf("%lld\n", maxScore(0, N));
	return 0;
}
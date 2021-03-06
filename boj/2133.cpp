#include<cstdio>
typedef long long int lld;
using namespace std;

int N;
lld d[33];
/*
  
  3x2 를 만들 수 있는 모양 :3개
  3x4
  3x6
  ...
  3*2N (N>1) -> 만들 수 있는 모양 : 2개
  그러므로, d[n] = 3*d[i-2] + 2*d[i-4]+ 2*d[i-6] ...
 
 */
int main()
{
	scanf("%d", &N);
	d[0] = 1;
	for (int i = 2; i <= N; ++i)
	{
		d[i] = 3 * d[i - 2];
		for (int j = i-4; j >= 0; j -= 2)
		{
			d[i] += 2 * d[j];
		}
	}
	printf("%lld\n", d[N]);
	return 0;
}
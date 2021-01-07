#include <cstdio>
using namespace std;
typedef long long int lld;
int A, B, C;

// n^k�� �����ִ� �Լ�
lld power(int n, int k) {
	if (k == 0)
		return 1;

	lld temp = power(n, k / 2);
	lld result = temp * temp % C;

	if (result % 2)
		result = result * n % C;
	return result;
}

int main() {
	scanf("%d %d %d", &A, &B, &C);
	printf("%lld\n", power(A, B));
}
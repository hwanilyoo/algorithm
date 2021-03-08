#include<cstdio>
#include<algorithm>
#include<map>
#include<vector>
typedef long long int lld;
using namespace std;

//MAP과 람다를 이용한 풀이
int N;
map<lld, int> m;
void sort(map<lld, int>& mm)
{
	vector<pair<lld, int> > v;
	for (auto it : mm)
	{
		v.push_back(it);
	}
	sort(v.begin(), v.end(), [](pair<lld, int> &n1, pair<lld, int> &n2) {
		return (n1.second > n2.second) || (n1.second == n2.second && n1.first < n2.first);
	});

	printf("%lld\n", v[0].first);
}
int main()
{
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; ++i)
	{
		lld num;
		scanf("%lld", &num);
		if (m.find(num) != m.end())
		{
			m[num]++;
		}
		else
		{
			m.insert(pair<lld, int>(num, 1));
		}
	}
	sort(m);

	return 0;
}
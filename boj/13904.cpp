#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

int main()
{
	int N;
	int arr[1011];
	memset(arr, 0x00, sizeof(arr));
	scanf("%d", &N);
	vector< pair<int, int> > v(N + 1);
	for (int i = 0; i < N; i++)
	{
		cin >> v[i].second >> v[i].first;
	}
	sort(v.rbegin(), v.rend());

	for (int i = 0; i < v.size(); i++)
	{
		for (int j = v[i].second; j >= 1; j--)
		{
			if (!arr[j]) {
				arr[j] = v[i].first;
				break;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= 1000; i++)
		ans += arr[i];

	cout << ans;
	return 0;
}
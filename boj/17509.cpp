#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	vector<pair<int, int> > v(11);

	for (int i = 0; i < 11; i++)
	{
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(), v.end());
	int time = 0;
	int penalty = 0;
	for (int i = 0; i < 11; i++)
	{
		time += v[i].first;
		penalty = penalty + (time + v[i].second * 20);
	}
	cout << penalty;
	return 0;
}
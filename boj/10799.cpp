#include<cstdio>
#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main()
{
	stack<int> stick;
	string s;
	cin >> s;
	int ans = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == '(')
		{
			stick.push(i);
		}
		else
		{
			if (stick.top() == i - 1)
			{
				ans = ans + (stick.size()-1);
			}
			else {
				ans = ans + 1;
			}
			stick.pop();
		}
	}
	printf("%d\n", ans);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;   

	while (t--)
	{
		string s;
		cin >> s; 
		int n = s.size(); 

		int count_0 = 0, count_1 = 0; 

		for (int i = 0; i < n; i++)
		{
			if (s[i] == '0')
				count_0++;
			else
				count_1++;
		}

		int lent = 0; 

		for (int i = 0; i < n; i++)
		{
			if (s[i] == '0' && count_1 > 0)
			{
				count_1--; 
				lent++; 
			}
			else if (s[i] == '1' && count_0 > 0)
			{
				count_0--; 
				lent++;
			}
			else
			{
				break; 
			}
		}

		cout << n - lent << endl;
	}
	return 0;
}


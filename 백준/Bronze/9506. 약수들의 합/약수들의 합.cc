#include<iostream>
#include<vector>
using namespace std;

int main(void)
{
	while (1)
	{
		vector<int>measure;
		int sum = 0;
		int n;
		cin >> n;
		if (n == -1)
			break;
		for (int i = 1; i < n; i++)
			if (n % i == 0)
				measure.push_back(i);
		for (int i = 0; i < measure.size(); i++)
			sum += measure[i];
		if (n == sum)
		{
			cout << n << " = ";
			for (int i = 0; i < measure.size(); i++)
			{
				if (i == measure.size() - 1)
					cout << measure[i];
				else
					cout << measure[i] << " + ";
			}
			cout << '\n';
		}
		else
			cout << n << " is NOT perfect.\n";
	}
	return 0;
}
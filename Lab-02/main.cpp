#include <iostream>
using namespace std;

int main()
{
	
	long long n;
	cout << "Enter number n: ";
	cin >> n;

	int count = 0;

	while (n > 0)
	{
		int digit = n % 10;

		if (digit == 1)
		{
			count++;

			if (count == 6)
			{
				break;
			}
		}
		else
		{
			count = 0;
		}

		n /= 10;
	}

	if (count == 6)
		cout << "Result: Yes" << endl;
	else
		cout << "Result: No" << endl;

	return 0;
}

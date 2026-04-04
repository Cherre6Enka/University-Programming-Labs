#include <iostream>
#include <math.h>
using namespace std;

int main()
{

	double a;
	while (true)
	{
		cout << "Enter number a: ";

		if (!(cin >> a))
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Error: please enter a valid number!" << endl;
			continue;
		}

		if (a < 0)
		{
			cout << "Error: a must be non-negative!" << endl;
		}
		else if (a == 0)
		{
			cout << "Error: when a = 0, division by zero occurs! " << endl;
		}
		else if (a == 2)
		{
			cout << "Error: when a = 2, division by zero occurs!" << endl;
		}
		else
		{
			break;
		}
	}

	double z1 = ((a + 2) / sqrt(2 * a) - a / (sqrt(2 * a) + 2) + 2 / (a - sqrt(2 * a))) * ((sqrt(a) - sqrt(2)) / (a + 2));
	double z2 = (1 / (sqrt(a) + sqrt(2)));

	cout << "z1 = " << z1 << endl;
	cout << "z2 = " << z2 << endl;

	return 0;
}

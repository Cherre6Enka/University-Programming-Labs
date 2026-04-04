#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

int main() {

	int n;
	cout << "Enter the arrays size: ";
	cin >> n;

	double* arr = new double[n];

	int choice;
	cout << "Choose input method (1 - manual , 2 - random): ";
	cin >> choice;

	if (choice == 1) {
		for (int i = 0; i < n; i++) {
			cout << "Enter element: " << i << ": ";
			cin >> arr[i];
		}
	
	}
	else {
		double a, b;
		cout << "Enter interval [a, b]: ";
		cin >> a >> b;
		srand(time(0));
		for (int i = 0; i < n; i++) {
			double r = (double)rand() / RAND_MAX;
			arr[i] = round((a + r * (b - a)) * 100) / 100;
		}
	
	}

	cout << "Array: ";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	int taskChoice;
	cout << "Choose task (1, 2 or 3): ";
	cin >> taskChoice;

	if (taskChoice == 1) {
		double C;
		cout << "Enter C: ";
		cin >> C;
		int count = 0;
		for (int i = 0; i < n; i++) {
		if (arr[i] < C) {
				count++;
		}

	}
		cout << "The number of elements is less than C: " << count << endl;
	}

	if (taskChoice == 2) {
		int lastNeg = -1;
		for (int i = 0; i < n; i++) {
			if (arr[i] < 0) {
				lastNeg = i;
			}

		}

		if (lastNeg == -1) {
		 cout << "No negative elements found." << endl;
		}
		else {
			int sum = 0;
			for (int i = lastNeg + 1; i < n; i++) {
				sum = sum + (int)arr[i];
			}
			cout << "The sum is: " << sum << endl;
		}
	}
	if (taskChoice == 3) {
		double maxVal = arr[0];
		for (int i = 1; i < n; i++) {
			if (arr[i] > maxVal) {
				maxVal = arr[i];
			}
		}
		int pos = 0;
		for (int i = 0; i < n; i++) {
			if (arr[i] >= maxVal * 0.8) {
				double temp = arr[i];
				arr[i] = arr[pos];
				arr[pos] = temp;
				pos++;

			}
		}
		cout << "Array after transformation: ";
			for (int i = 0; i < n; i++) {
				cout << arr[i] << " ";
			}
		cout << endl;
	}

	delete[] arr;
	return 0;
}

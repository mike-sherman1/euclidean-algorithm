#include <iostream>
#include <string>

using namespace std;

int EEA(int a, int b)
{
	int S = 0;
	int old_S = 1;
	int t = 1;
	int old_t = 0;
	int r = b;
	int old_r = a;
	
	while (r != 0)
		{
			int q = old_r / r;
			int temp = r;
			r = old_r - q * r;
			old_r = temp;
			old_S = S;
			S = old_S - q*S;
			old_t = t;
			t = old_t - q*t;
		}
	
	return old_r;
}

int main()
{
	float a, b;
	bool exit = false;
	
	//main while loop, program runs until user enters 1
	while (!exit) {
		try {
			cout << endl << "Enter the two integers that you would like the greatest common divisor of.\nFirst: ";
			cin >> a;
			//if decimal or not an int, throw invalid input error
			if ((int(a) != a)|| cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignore the bad input until line end
				throw string("Invalid input. Please try again.");
			}
			cout << "Second: ";
			cin >> b;
			//if decimal or not an int, throw invalid input error
			if (cin.fail() || (int(b) != b)) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignore the bad input until line end
				throw string("Invalid input. Please try again.");
			}
			int result = EEA(int(a), int(b));
			cout << "The greatest common divisor is: " << result << endl;
			cout << "Press 0 to restart, or 1 to exit." << endl;
			cin >> exit;
			if (cin.fail() || (exit != 0 && exit != 1)) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); //ignore the bad input until line end
				throw string("Invalid input. Please try again.");
			}
		} catch(string e) {
			cout << e << endl;
		}
	}//end main while
	
	return 0;
}
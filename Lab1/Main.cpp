/*
 * Main.cpp
 *
 *  Created on: Sep 12, 2016
 *      Author: Ryan
 */

/*
 * Hello.cpp
 *
 *  Created on: Sep 10, 2016
 *      Author: Ryan
 */
#include <iostream>
using namespace std;
int collatz(int n);
int collatz2();

int main() {
	cout << "!!!Hello, world!!!" << endl;
	//string response;
	//cout << "Enter a positive natural number: " << endl;
	//cin >> response;
	//int input = atoi(response.c_str());
	//int n = input;
	cout << collatz(17);
	collatz2();


	return 0;
}

int collatz(int n) {

	int count = 0;
	while (n != 1) {
		if (n % 2 == 0) {
			n = n / 2;
			count += 1;
		}
		else {
			n *= 3;
			n += 1;
			count += 1;
		}


	}
	//cout << count << endl;
	//cout << n << endl;

	return n;

}
int collatz2() {
	string response;
	string response2;
	cout << "Enter a positive natural number: " << endl;
	cin >> response;
	cout << "Enter another positive natural number: " << endl;
	int input = atoi(response.c_str());
	int input2 = atoi(response2.c_str());
	int larger;
	int smaller;

	if (input > input2) {
		larger = input;
		smaller = input2;
	}
	else {
		larger = input2;
		smaller = input;
	}
	while (larger != 0 && smaller != 0) {
		for (int i = smaller; i < larger; i++) {
			cout << i << endl;
		}
	}

	return 0;
}







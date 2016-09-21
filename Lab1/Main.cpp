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
 *      Author: Ryan Gray and Brian Turnbull
 */
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <iterator>
#include <math.h>

using namespace std;

int collatz(int n);
void collatz2();
bool isOrdered(int *x, int *y, int *z);
bool isPerfect(int num, int div, int sum);
bool isPerfect2(int &num, int &div, int &sum);
void randArray(int arr[], int size);
void printArray(int arr[], int size);
void reverseArray(int arr[], int size);
int minimum(int arr[], int size);
int sum1(int arr[], int size, int sum, int count);
int sortArray(int arr[], int size);
int * lowPass(int arr[], int win, int size);
void createMatrix(int ** arr[], int &j, int &k, int &l);
void printMatrix(int ** arr[], int &j, int &k, int &l);

int main() {
//  Problem 1
	cout << "!!!Hello, world!!!" << endl;

//  Problem 2
	string response;
	cout << "Enter a positive natural number: " << endl;
	cin >> response;
	int input = atoi(response.c_str());
	int n = input;
	cout << "count = " << collatz(n);
	cout << endl;
	collatz2();
	cout << endl;

//  Problem 3
	srand(time(NULL));
	int a = rand();
	int b = rand();
	int c = rand();
	cout << a << ", " << b << ", " << c << endl;
	bool answer = isOrdered(&a, &b, &c);
	cout << answer << endl;
	if (answer == false) {
		cout << a << ", " << b << ", " << c << endl;
	}
	cout << endl;
//  Problem 4
	cout << isPerfect(6, 6, 0) << endl;
	cout << isPerfect(7, 7, 0) << endl;
	cout << endl;
//  Problem 5
	int num6 = 6;
	int div6 = 6;
	int sum6 = 0;
	cout << isPerfect2(num6, div6, sum6) << endl;
	int num7 = 7;
	int div7 = 7;
	int sum7 = 0;
	cout << isPerfect2(num7, div7, sum7) << endl;
	cout << endl;
//	Problem 6
	int d = (rand() % 30) + 20;
	int dArray[d];
    randArray(dArray, d);
    printArray(dArray, d);
    cout << endl;

//  Problem 7
	reverseArray(dArray, d);
	printArray(dArray, d);
	cout << endl;

//  Problem 8
	minimum(dArray, d);
	cout << endl;

//  Problem 9
    cout << sum1(dArray, d, 0, 0);
    cout << endl;

// Problem 10
	int ten = (rand() % 30) + 20;
	int tenArray[ten];
	randArray(tenArray, ten);
	cout << sortArray(tenArray, ten) << endl;
	printArray(tenArray, ten);
	cout << endl;

//  Problem 11
	int win_size = rand() % 4 + 3;
	int rand_size = rand() % 30 + 20;
	int newrandarr[rand_size];
	randArray(newrandarr, rand_size);
	cout << "filtered array: ";
	lowPass(newrandarr, win_size, rand_size);
	cout << endl;


//  Problem 12
	int ***z = NULL;
	int j = -1;
	int k = -1;
	int l = -1;
	createMatrix(z, j, k, l);
	printMatrix(z, j, k, l);


	for (int a = 0; a < j; a++) {
	    for (int b = 0; b < k; b++) {
	    	delete[] z[a][b];
	    } // 2nd for
	    delete[] z[a];
	} // 1st for
	delete[] z;

	return 0;
}

int collatz(int n) {

	int count = 0;
	while (n != 1) {
		if (n % 2 == 0) {
			n = n / 2;
			count += 1;
		} // if
		else {
			n *= 3;
			n += 1;
			count += 1;
		} // else
	} // while

	return count;

} // collatz

void collatz2() {
	string response1;
	string response2;
	cout << "Enter a positive natural number: " << endl;
	cin >> response1;
	cout << "Enter another positive natural number: " << endl;
	cin >> response2;
	int n1 = atoi(response1.c_str());
	int n2 = atoi(response2.c_str());
	int larger, smaller;
	if (n1 >= n2) {
		larger = n1;
		smaller = n2;
	} // if
	else {
		larger = n2;
		smaller = n1;
	} // else
	for (int i = smaller; i < larger; i++) {
		cout << "input = " << i << ", ";
		cout << "count = " << collatz(i) << ", ";
		cout << "Collatz Conjecture is still working." << endl;
	} // for

} // collatz2

bool isOrdered(int *x, int *y, int *z) {
	int tempx = *x;
	int tempy = *y;
	int tempz = *z;

	if (*x < *y) {
		if (*x < *z) {
			if (*y < *z) {
				return true;
			} // 3rd if
		} // 2nd if
	} // 1st if
	if (*x < *z) {
		if (*x < *y) {
			if (*z < *y) {
				*z = tempy;
				*y = tempz;
				return false;
			} // 3rd if
		} // 2nd if
	} // 1st if
	if (*z < *x) {
		if (*z < *y) {
			if (*x < *y) {
				*z = tempy;
				*x = tempz;
				*y = tempx;
				return false;
			} // 3rd if
		} // 2nd if
	} // 1st if
	if (*y < *x) {
		if (*y < *z) {
			if (*x < *z) {
				*y = tempx;
				*x = tempy;
				return false;
			} // 3rd if
		} // 2nd if
	} // 1st if
	if (*y < *z) {
		if (*y < *x) {
			if (*z < *x) {
				*y = tempz;
				*x = tempy;
				*z = tempx;
				return false;
			} // 3rd if
		} // 2nd if
	} // 1st if
	if (*z < *y) {
		if (*z < *x) {
			if (*y < *x) {
				*z = tempx;
				*x = tempz;
				return false;
			} // 3rd if
		} // 2nd if
	} // 1st if
	return false;
} // isOrdered

bool isPerfect(int num, int div, int sum) {
	if (div == 0) {
		if (!(num == sum)) {
			return false;
		} // if
		else {
			return true;
		} // else
	}
	if (num == div) {
		return isPerfect(num, (div - 1), sum);
	} // if
	else if (num % div == 0) {
		sum += div;
		return isPerfect(num, (div - 1), sum);
	} // else if
	else {
		return isPerfect(num, (div - 1), sum);
	} // else
} // isPerfect

bool isPerfect2(int &num, int &div, int &sum) {
	if (div == 0) {
		if (!(num == sum)) {
			return false;
		} // if
		else {
			return true;
		} // else
	} // if
	if (num == div) {
		return isPerfect(num, (div - 1), sum);
	} // if
	else if (num % div == 0) {
		sum += div;
		return isPerfect(num, (div - 1), sum);
	} // else if
	else {
		return isPerfect(num, (div - 1), sum);
	} // else
} // isPerfect2

void randArray(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = (rand() % 100) - 50;
	} // for
} // randArray

void printArray(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << endl;
	} // for
} // printArray

void reverseArray(int arr[], int size) {
	int count = size - 1;
	float half = size / 2;
	for (int i = 0; i < half; i++) {
		int temp = arr[i];
		arr[i] = arr[count];
		arr[count] = temp;
		count -= 1;
	} // for
} // reverseArray

int minimum(int arr[], int size) {
	int low = arr[0];
	for (int i = 0; i < size; i++) {
		if (arr[i] < low) {
			low = arr [i];
		} // if
	} // for
	return low;
} // minimum

int sum1(int arr[], int size, int sum, int count) {
	if (count == size) {
		return sum;
	} // if
	else {
		sum += arr[count];
		return sum1(arr, size, sum, (count + 1));
	} // else
} // sum

int sortArray(int arr[], int size) {
	int temp;
	int count = 0;
	for (int i = 0; i < size; ++i) {
		for (int j = i; j < size; ++j) {
			if (arr[j] < arr[i]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
				count += 1;
			} // if
		} // 2nd for
	} // 1st for
	return count;
} // sortArray


int * lowPass(int arr[], int win, int size) {
	if (win % 2 == 0) {
		win += 1;
	} // if
	int filter[size];
	int num;
	int sizeminus = size - 1;
	if (win == 3) {
		filter[0] = 0;
		filter[(size - 1)] = 0;
		num = 1;
		cout << 0 << ", ";
		for (int i = num; i < (sizeminus - num); i++) {
			int sum = arr[(i - 1)] + arr[i] + arr[(i + 1)];
			int avg = floor(sum / win);
			filter[i] = avg;
			cout << avg << ", ";
		} // for
	} // if
	else if (win == 5) {
		filter[0] = 0;
		filter[1] = 0;
		filter[(size - 1)] = 0;
		filter[(size - 2)] = 0;
		num = 2;
		cout << 0 << ", " << 0 << ", ";
		for (int i = num; i < (sizeminus - num); i++) {
			int sum = arr[(i - 2)] + arr[(i - 1)] + arr[i] + arr[(i + 1)]
					+ arr[(i + 2)];
			int avg = floor(sum / win);
			filter[i] = avg;
			cout << avg << ", ";
		} // for
	} // else if
	else if (win == 7) {
		filter[0] = 0;
		filter[1] = 0;
		filter[2] = 0;
		filter[(size - 1)] = 0;
		filter[(size - 2)] = 0;
		filter[(size - 3)] = 0;
		num = 3;
		cout << 0 << ", " << 0 << ", " << 0 << ", ";
		for (int i = num; i < (sizeminus - num); i++) {
			int sum = arr[(i - 3)] + arr[(i - 2)] + arr[(i - 1)] + arr[i]
					+ arr[(i + 1)] + arr[(i + 2)] + arr[(i + 3)];
			int avg = floor(sum / win);
			filter[i] = avg;
			cout << avg << ", ";
		} // for
	} // else if
	if (win == 3) {
		cout << 0;
	} // if
	else if (win == 5) {
		cout << 0 << ", " << 0;
	} // else if
	else if (win == 7) {
		cout << 0 << ", " << 0 << ", " << 0;
	} // else if
	return filter;
} // lowPass

void createMatrix(int ** arr[], int &j, int &k, int &l) {
	j = (rand() % 4) + 2;
	k = (rand() % 4) + 2;
	l = (rand() % 4) + 2;
	int abc;
	arr = new int **[j];
	for (int a = 0; a < j; a++) {
		arr[a] = new int*[k];
	    for (int b = 0; b < k; b++) {
	    	arr[a][b] = new int[l];
	    } // 2nd for
	} // 1st for

	for (int a = 0; a < j; a++) {
	    for (int b = 0; b < k; b++) {
	        for (int c = 0; c < l; c++) {
	        	abc = a + b + c;
	            arr[a][b][c] = abc;
	        } // 3rd for
	    } // 2nd for
	} // 1st for
} // createMatrix

void printMatrix(int ** arr[], int &j, int &k, int &l) {
	for (int a = 0; a < j; a++) {
	    for (int b = 0; b < k; b++) {
	        for (int c = 0; c < l; c++) {
	            cout << arr[a][b][c] << endl;
	        } // 3rd for
	        cout << endl;
	    } // 2nd for
	    cout << endl;
	} // 1st for
}









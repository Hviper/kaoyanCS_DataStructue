#include<iostream>
using namespace std;


//找第一个大于等于target的数
int findFirstMaxTarget(int arr[], int len, int target) {
	int low = 0;
	int high = len - 1;
	while (low <= high) {
		int mid = (low + high) >> 1;
		if (arr[mid] >= target) {
			if (mid == 0 || arr[mid - 1] < target) {
				return mid;
			}
			else {
				high = mid - 1;
			}
		}
		else {   //arr[mid]<target  往右边找
			low = mid + 1;
		}
	}
	return -1;
}

//找第一个大于等于target的数
int findFirstMaxTarget2(int arr[], int len, int target) {
	int low = 0;
	int high = len - 1;
	while (low <= high) {
		int mid = (low + high) >> 1;
		if (arr[mid] >= target) {
			high = mid - 1;
		}
		else if (arr[mid] < target) {
			low = mid + 1;
		}

	}
	if (low >= 0 && low < len) {
		return low;
	}
	return -1;
}

void test() {
	//            0  1  2  3  4  5  6  7
	int arr[] = { 10,18,20,30,40,50,60,70 };
	int len = sizeof(arr) / sizeof(int);
	int targetIndex = findFirstMaxTarget(arr, len, 18);
	int targetIndex2 = findFirstMaxTarget2(arr, len, 18);
	cout << targetIndex << endl;
	cout << targetIndex2 << endl;
}
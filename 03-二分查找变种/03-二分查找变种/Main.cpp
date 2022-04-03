#include<iostream>
using namespace std;


int findTarget(int arr[],int len,int target) {
	int left = 0;
	int right = len - 1;
	while (left<=right) {
		int mid = left + ((right - left) >> 1);
		if (arr[mid]==target) {
			return mid;
		}
		else if (arr[mid]>target) {
			right = mid-1;
		}
		else {
			left = mid + 1;
		}
	}
	return -1;
}


//--------------------�����ظ���һ��ֵ���ڸ���ֵ��Ԫ��-----------------------

int findTarget1(int arr[], int len, int target) {
	int left = 0;
	int right = len - 1;
	while (left <= right) {
		int mid = left + ((right - left) >> 1);
		if (arr[mid] == target) {
			if (mid==0 || arr[mid-1]!=target) {
				return mid;
			}
			else {
				right = mid - 1;
			}
		}
		else if (arr[mid] > target) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	return -1;
}



//--------------------�������һ��ֵ���ڸ���ֵ��Ԫ��-----------------------
int findTarget2(int arr[], int len, int target) {
	int left = 0;
	int right = len - 1;
	while (left <= right) {
		int mid = left + ((right - left) >> 1);
		if (arr[mid] == target) {
			if (mid == right || arr[mid + 1] != target) {
				return mid;
			}
			else {
				left = mid + 1;
			}
		}
		else if (arr[mid] > target) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	return -1;
}


//--------------------�����ظ���һ��ֵ���ڵ��ڸ���ֵ��Ԫ��-----------------------
int findTarget3(int arr[], int len, int target) {
	int left = 0;
	int right = len - 1;
	while (left <= right) {
		int mid = left + ((right - left) >> 1);
		if (arr[mid] >= target) {
			if (mid == 0 || arr[mid - 1] < target) {
				return mid;
			}
			else {
				right = mid - 1;
			}
		}
		else {
			left = mid + 1;
		}
	}
	return -1;
}


//--------------------�������һ��ֵС�ڵ��ڸ���ֵ��Ԫ��-----------------------

int findTarget4(int arr[], int len, int target) {
	int left = 0;
	int right = len - 1;
	while (left <= right) {
		int mid = left + ((right - left) >> 1);
		if (arr[mid] > target) {
			right = mid - 1;
		}
		else {
			if (mid == len-1 || arr[mid + 1] > target) {
				return mid;
			}
			else {
				left = mid + 1;
			}
		}
	}
	return -1;
}




int main() {
	//            0 1 2 3 4 5 6 7  8  9
	int arr[] = { 1,3,4,5,6,8,8,8,11,18 };
	int len = sizeof(arr) / sizeof(int);
	cout << findTarget3(arr,len,7);
}
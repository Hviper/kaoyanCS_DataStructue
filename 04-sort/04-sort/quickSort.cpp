#include<iostream>
using namespace std;

int len = 0;   //数组长度
int p = 1; //记录第几趟扫描
//[left,right]
void sort(int *arr,int left,int right) {
	if (left >= right) {
		return;
	}
	int l = left;
	int r = right;
	int i = rand() % (right - left + 1) + l; // 随机选一个作为我们的主元
	swap(arr[left], arr[i]);
	int target = arr[left];  //默认第一个left位置的作为轴点

	for (int i = 0; i < len; i++) {
		cout << arr[i] << ",";
	}
	cout << endl;
	//打印
	cout << "第" << p++ << "趟" << ",  关键字：" << target << "\n ";

	while (left<right) {
		while (left < right && arr[right]>target) {      //不要等于---> 切割更均匀  【极差的情况下，全是相等的元素1,1,1,1,1,1,1,1,1,1,1.....】
			right--;
		}
		arr[left] = arr[right];  //不用判断 (left<right) 也行
		while (left < right && arr[left]<target) {
			left++;
		}
		arr[right] = arr[left];	
	}
	//right==left   //轴点最终确定位置
	arr[right] = target;
	sort(arr, l, right-1);
	sort(arr,right+1, r);
}

void quickSort(int *arr,int len) {
	sort(arr,0,len-1);
}

int mmmm() {
	//[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28]
	// 200,64,8,3,6,15,49,4,-1,-6,51,35,46,81,351,1525
	int arr[] = {
		200,64,8,3,6,15,49,4,-1,-6,51,35,46,81,351,1525,55,69
	};
	len = sizeof(arr) / sizeof(int);
	quickSort(arr,len);
	cout << "\n最终打印结果为：\n" << endl;
	for (int i = 0; i < len; i++) {
		cout << arr[i] << ",";
	}
	return 0;
}
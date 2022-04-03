
#include<iostream>
using namespace std;

//工具
//--------------------------------------------------------------
//升序
bool test1(int* arr, int len) {
	for (int i = 1; i < len; i++) {
		if (arr[i] < arr[i - 1]) {
			return false;
		}
	}
	return true;
}

//降序
bool test2(int* arr, int len) {
	for (int i = 1; i < len; i++) {
		if (arr[i] < arr[i - 1]) {
			return false;
		}
	}
	return true;
}

bool test(int* arr, int len) {
	return test1(arr, len) || test2(arr, len);
}



//sort  begin


//冒泡排序  
//arr：待排序数组
void Bubbosort(int *arr,int len) {
	for (int i = len-1; i >=1 ;i--) {
		bool flag = true;
		for (int j = 1; j <= i;j++) {
			if (arr[j]<arr[j-1]) {   //等于不能交换
				int temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
				flag = false;
			}
		}
		if (flag) {
			break;
		}
	}
}

void Bubbosort2(int* arr, int len) {
	for (int i = len-1; i >= 1; i--) {
		int sortedIndex = 1;
		for (int j = 1; j <= i; j++) {
			if (arr[j] < arr[j - 1]) {   //等于不能交换
				int temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
				sortedIndex = j;
			}
		}
		i = sortedIndex;
	}
}


//选择排序（Selection Sort）
//选择排序的交换次数要远远少于冒泡排序，平均性能优于冒泡排序
//最好、最坏、平均时间复杂度：O(n）
//空间复杂度：O(1)，属于不稳定排序
void selectSort(int* arr, int len) {
	for (int i = len - 1; i >= 1;i--) {
		int maxValIndex = i;
		for (int j = 0; j < i; j++) {
			if (arr[maxValIndex]<arr[j]) {
				maxValIndex = j;
			}
		}
		if (maxValIndex!=i) {
			int temp = arr[maxValIndex];
			arr[maxValIndex] = arr[i];
			arr[i] = temp;
		}
	}
}

//插入排序  (稳定排序)
void insertSort(int* arr, int len) {
	//抓牌
	for (int i = 1; i < len;i++) {
		//与前面的元素比较交换
		int index = i;
		while (index >=1 && arr[index]<arr[index-1]) {
			int temp = arr[index];
			arr[index] = arr[index - 1];
			arr[index - 1] = temp;
			index--;
		}
	}
}

//插入排序  【稳定排序】
// 2，3，8，1
//逆序对  <2,1> <3,1>
//时间复杂度与逆序对的数量成正比\

//优化：交换转为挪动

//找到合适的插入位置  【找第一个大于target的数】
int findTargetIndex(int* arr, int len,int target) {
	int left = 0;
	int right = len - 1;
	while (left<=right) {
		int mid = (left + right) >> 1;
		if (arr[mid]>=target) {
			if (mid==0 || arr[mid-1]<target) {
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
//插入排序：最终优化(binary search + 插入排序)
void insertSort2(int* arr, int len) {
	//抓牌
	for (int i = 1; i < len; i++) {
		int curVal = arr[i];
		//二分找到插入点
		int beginIndex = findTargetIndex(arr, i, curVal);
		if (beginIndex==-1) {
			continue;
		}
		//挪动数组
		for (int j = i-1; j >= beginIndex;j--) {
			arr[j + 1] = arr[j];
		}
		arr[beginIndex] = curVal;
	}
}



//-----------------------------------------------
//-----------------------quickSort------------------------
//void sort(int* arr, int left, int right) {
//	if (left >= right) {
//		return;
//	}
//	int l = left;
//	int r = right;
//	int i = rand() % (right - left + 1) + l; // 随机选一个作为我们的主元
//	swap(arr[left], arr[i]);
//	int target = arr[left];  //默认先是这个
//	while (left < right) {
//		while (left < right && arr[right] >= target) {
//			right--;
//		}
//		arr[left] = arr[right];
//		while (left < right && arr[left] <= target) {
//			left++;
//		}
//		arr[right] = arr[left];
//	}
//	arr[right] = target;   //将值放到最终的位置 《确定最终数据位置下标》
//	sort(arr, l, right - 1);  
//	sort(arr, right + 1, r);
//}
//
//void quickSort(int* arr, int len) {
//	sort(arr, 0, len - 1);
//}


int *arraylist;
//merge sort 归并排序（冯诺依曼）
void mergeSort(int *arr,int len) {
	
	
}
//merge两个有序的数组
void merge(int *arr1,int len1,int *arr2,int len2) {
	
}




int test() {
	// 5864,-12333,4151,-6239,-10306,10866,-7013,13195,-8855,1150,-560,32  
	//15,64,8,3,6,598,49,4,51,35,46,81,351,4
	int arr[] = {
		8,1800,64,8,3,6,232,233,234,235,236,237,238,239,240,
		241,242,243,244,245,246,247,248,249,250,251,252,253,254,
		255,256,257,258,259,260,261,262,263,264,265,266,267,268,
		269,270,271,272,273,274,275,276,27715,49,4,-1,-6,51,35,46,
		81,351,1525,230,231
	};
	int len = sizeof(arr)/sizeof(int);

	//merge需要的临时数组（开辟一半的空间）
	arraylist = (int*)malloc(sizeof(int) * (len>>1));

	insertSort2(arr,len);
	for (int i = 0; i < len;i++) {
		cout << arr[i] << "(" << i << "), ";
	}
	//cout << "\n" << findTargetIndex(arr, len, 666) << endl;
	cout <<"\n\n最终结果显示：" << test(arr, len) << endl;
	mergeSort(arr,len);
	return 0;
}


//注：
//对于算法的稳定性而言： 
//	需求：实现一个功能，订单有两个属性，一个是下单的时间，另一个是订单金额    
//	我们希望：按照金额从小到大对订单数据排序。对于金额相同的订单，我们希望按照下单时间从早到晚有序
// 【已知需要排序的订单已经是按照时间有序的情况排好序了的】，假如没用排序的话可以先对时间进行排序，再对金额进行排序
// 这样就解决了 《按照金额从小到大对订单数据排序。对于金额相同的订单，我们希望按照下单时间从早到晚有序》
//




#include<iostream>
#include<vector>
using namespace std;

//思路：生成子表：i,i+d,i+2d,i+3d,i+4d……,i+kd


//生成步长序列
void shellSequence(vector<int>& vet, int step) {
	while ((step = step >> 1) > 0) {
		vet.push_back(step);   
	}
}

//核心代码
//对步长为step的数组进行排序  9，4，2，1  
void sort(int* arr, int len, int step) {
	for (int col = 0; col < step;col++) {  //起点  【列数】
		//插入排序
		for (int i = col+step; i < len; i+=step) {  //i=cok+step 表示第二个元素开始
			int cur = i;
			while (cur>col && (arr[cur] - arr[cur - step])<0) {
				int temp = arr[cur];
				arr[cur] = arr[cur - step];
				arr[cur - step] = temp;
				cur -= step;
			}
		}
	}
}

//堆排序是对选择排序的一个改进   【依旧不稳定】
//shellSort：对插入排序（稳定排序）的一个改进   【不稳定】
//仅仅适用于顺序表，不适合链表
void shellSort(int *arr,int len) {
	vector<int> vet;
	shellSequence(vet,len);
	int size = vet.size();
	for (int i = 0; i < size;i++) {
		cout <<"arr[i] = " << vet[i] << endl;  //9，4，2，1
		sort(arr,len, vet[i]);
	}
}




void Test() {
	int arr[] = {
		200,64,8,3,6,15,49,4,-1,-6,51,35,46,81,351,1525,55,69
	};
	int len = sizeof(arr) / sizeof(int);
	shellSort(arr, len);
	for (int i = 0; i < len; i++) {
		cout << arr[i] << ",";
	}
}


//计数排序   【相当于桶排序的特殊】  高考分数排名
int* countSort(int *arr,int len) {
	if (len<=0) {
		return NULL;
	}
	int* res = new int[len] {0};
	int max = arr[0];
	for (int i = 1; i < len;i++) {
		max = max > arr[i] ? max : arr[i];
	}
	int* array = new int[max+1] {0};
	for (int i = 0; i < len;i++) {
		array[arr[i]] += 1;
	}
	int index = 0;
	for (int i = 0; i <= max;i++) {
		int cur = i;
		while (array[cur]!=0) {
			res[index++] = i;
			array[cur] -= 1;
		}
	}
	delete[] array;
	return res;
}

//基数排序   【比如10w个手机号排序】


//bubbleSort（冒泡排序）：有序度 = 满有序度 [ n*(n-1)/2 ] - 逆有序度
//比较交换次数==逆有序度
void bubbleSort(int* arr, int len) {
	int size = 0;
	for (int end = len - 1; end > 0; end--) {
		for (int begin = 1; begin <= end; begin++) {
			if (arr[begin] < arr[begin - 1]) {
				int temp = arr[begin - 1];
				arr[begin - 1] = arr[begin];
				arr[begin] = temp;
				size++;
			}
		}
	}
	cout << "最终结果size：" << size << endl;
}


// [left,right]
int findKmaxNum(int *arr,int len,int k,int left,int right) {
	int l = left;
	int r = right;
	int pivot = arr[right];
	while (l<r) {
		while (l<r && arr[l]>=pivot) {
			l++;
		}
		if (l<r) {
			arr[r] = arr[l];
		}
		while (l<r && arr[r] <= pivot) {
			r--;
		}
		if (l<r) {
			arr[l] = arr[r];
		}
	}
	arr[l] = pivot;  //每次执行这个操作都会将该元素的最终位置确定下来
	if (l+1==k) {
		return arr[l];
	}
	else if (l+1<k) {
		return findKmaxNum(arr,len,k,l+1,right);
	}
	else {
		return findKmaxNum(arr,len,k,left,l-1);
	}
}
int findTarget(int* arr, int len, int k) {
	return findKmaxNum(arr,len,k,0,len-1);
}

//int min() {
//	int arr[] = {4,5,6,3,2,1};
//	int len = sizeof(arr) / sizeof(int);
//	cout << findTarget(arr,len,3) << endl;
//	return 0;
//}
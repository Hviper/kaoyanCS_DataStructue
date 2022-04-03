
#include<iostream>
using namespace std;

//����
//--------------------------------------------------------------
//����
bool test1(int* arr, int len) {
	for (int i = 1; i < len; i++) {
		if (arr[i] < arr[i - 1]) {
			return false;
		}
	}
	return true;
}

//����
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


//ð������  
//arr������������
void Bubbosort(int *arr,int len) {
	for (int i = len-1; i >=1 ;i--) {
		bool flag = true;
		for (int j = 1; j <= i;j++) {
			if (arr[j]<arr[j-1]) {   //���ڲ��ܽ���
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
			if (arr[j] < arr[j - 1]) {   //���ڲ��ܽ���
				int temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
				sortedIndex = j;
			}
		}
		i = sortedIndex;
	}
}


//ѡ������Selection Sort��
//ѡ������Ľ�������ҪԶԶ����ð������ƽ����������ð������
//��á����ƽ��ʱ�临�Ӷȣ�O(n��
//�ռ临�Ӷȣ�O(1)�����ڲ��ȶ�����
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

//��������  (�ȶ�����)
void insertSort(int* arr, int len) {
	//ץ��
	for (int i = 1; i < len;i++) {
		//��ǰ���Ԫ�رȽϽ���
		int index = i;
		while (index >=1 && arr[index]<arr[index-1]) {
			int temp = arr[index];
			arr[index] = arr[index - 1];
			arr[index - 1] = temp;
			index--;
		}
	}
}

//��������  ���ȶ�����
// 2��3��8��1
//�����  <2,1> <3,1>
//ʱ�临�Ӷ�������Ե�����������\

//�Ż�������תΪŲ��

//�ҵ����ʵĲ���λ��  ���ҵ�һ������target������
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
//�������������Ż�(binary search + ��������)
void insertSort2(int* arr, int len) {
	//ץ��
	for (int i = 1; i < len; i++) {
		int curVal = arr[i];
		//�����ҵ������
		int beginIndex = findTargetIndex(arr, i, curVal);
		if (beginIndex==-1) {
			continue;
		}
		//Ų������
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
//	int i = rand() % (right - left + 1) + l; // ���ѡһ����Ϊ���ǵ���Ԫ
//	swap(arr[left], arr[i]);
//	int target = arr[left];  //Ĭ���������
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
//	arr[right] = target;   //��ֵ�ŵ����յ�λ�� ��ȷ����������λ���±꡷
//	sort(arr, l, right - 1);  
//	sort(arr, right + 1, r);
//}
//
//void quickSort(int* arr, int len) {
//	sort(arr, 0, len - 1);
//}


int *arraylist;
//merge sort �鲢���򣨷�ŵ������
void mergeSort(int *arr,int len) {
	
	
}
//merge�������������
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

	//merge��Ҫ����ʱ���飨����һ��Ŀռ䣩
	arraylist = (int*)malloc(sizeof(int) * (len>>1));

	insertSort2(arr,len);
	for (int i = 0; i < len;i++) {
		cout << arr[i] << "(" << i << "), ";
	}
	//cout << "\n" << findTargetIndex(arr, len, 666) << endl;
	cout <<"\n\n���ս����ʾ��" << test(arr, len) << endl;
	mergeSort(arr,len);
	return 0;
}


//ע��
//�����㷨���ȶ��Զ��ԣ� 
//	����ʵ��һ�����ܣ��������������ԣ�һ�����µ���ʱ�䣬��һ���Ƕ������    
//	����ϣ�������ս���С����Զ����������򡣶��ڽ����ͬ�Ķ���������ϣ�������µ�ʱ����絽������
// ����֪��Ҫ����Ķ����Ѿ��ǰ���ʱ�����������ź����˵ġ�������û������Ļ������ȶ�ʱ����������ٶԽ���������
// �����ͽ���� �����ս���С����Զ����������򡣶��ڽ����ͬ�Ķ���������ϣ�������µ�ʱ����絽������
//




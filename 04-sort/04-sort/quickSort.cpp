#include<iostream>
using namespace std;

int len = 0;   //���鳤��
int p = 1; //��¼�ڼ���ɨ��
//[left,right]
void sort(int *arr,int left,int right) {
	if (left >= right) {
		return;
	}
	int l = left;
	int r = right;
	int i = rand() % (right - left + 1) + l; // ���ѡһ����Ϊ���ǵ���Ԫ
	swap(arr[left], arr[i]);
	int target = arr[left];  //Ĭ�ϵ�һ��leftλ�õ���Ϊ���

	for (int i = 0; i < len; i++) {
		cout << arr[i] << ",";
	}
	cout << endl;
	//��ӡ
	cout << "��" << p++ << "��" << ",  �ؼ��֣�" << target << "\n ";

	while (left<right) {
		while (left < right && arr[right]>target) {      //��Ҫ����---> �и������  �����������£�ȫ����ȵ�Ԫ��1,1,1,1,1,1,1,1,1,1,1.....��
			right--;
		}
		arr[left] = arr[right];  //�����ж� (left<right) Ҳ��
		while (left < right && arr[left]<target) {
			left++;
		}
		arr[right] = arr[left];	
	}
	//right==left   //�������ȷ��λ��
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
	cout << "\n���մ�ӡ���Ϊ��\n" << endl;
	for (int i = 0; i < len; i++) {
		cout << arr[i] << ",";
	}
	return 0;
}
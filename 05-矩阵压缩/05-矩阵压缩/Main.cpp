#include<iostream>
using namespace std;


void test(int x,int y) {
	int a[4][4] = { //��֪��ά����
	 {0, 1, 2, 3} ,   /*  ��ʼ��������Ϊ 0 ���� */
	 {1, 0, 6, 4} ,   /*  ��ʼ��������Ϊ 1 ���� */
	 {2, 6, 0, 5},   /*  ��ʼ��������Ϊ 2 ���� */
	{3 ,4 ,5 ,0},
	};

	//ѹ���洢
	int arr[10];
	int index = 0;
	for (int i = 0; i < 4;i++) {
		for (int j = 0; j <= i;j++) {
			arr[index++] = a[i][j];
		}
	}
	cout << a[x-1][y-1] << endl;

	int c;
	if (x>=y) {
		c = ((x * (x - 1)) / 2) + y - 1;
		
	}
	else {
		c = ((y * (y - 1)) / 2) + x - 1;
	}
	cout << arr[c] << endl;

}




//int main() {
//	test(2,3);
//	string s = "sdasdsadas";
//	s.size();
//}
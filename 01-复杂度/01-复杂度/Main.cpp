#include<iostream>
using namespace std;

int fb2(int n) {
	if (n<=1 || n==2) {
		return 1;
	}
	int first = 1;
	int second = 1;
	for (int i = 0; i < n - 2;i++) {
		int replace = second + first;
		first = second;
		second = replace;
	}
	return second;
}

//���Ӷ�:2^n
int fbn(int n) {
	if (n<=1) {
		return n;
	}
	else {
		//���ӶȾ��Ǽӷ����ã����ú����Ĵ���
		//ǰN��� ��2^n��
		return fbn(n - 1) + fbn(n-2);
	}
}

int main() {
	cout << fbn(30) << endl;
	cout << fb2(30) << endl;
}



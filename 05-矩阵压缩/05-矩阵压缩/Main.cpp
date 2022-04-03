#include<iostream>
using namespace std;


void test(int x,int y) {
	int a[4][4] = { //已知二维数组
	 {0, 1, 2, 3} ,   /*  初始化索引号为 0 的行 */
	 {1, 0, 6, 4} ,   /*  初始化索引号为 1 的行 */
	 {2, 6, 0, 5},   /*  初始化索引号为 2 的行 */
	{3 ,4 ,5 ,0},
	};

	//压缩存储
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
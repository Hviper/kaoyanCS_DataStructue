#include<iostream>
using namespace std;

struct Node {
	int l, r;
	int val;
}tree[40];  //存储在树节点中


int target[40];

//[left,right]
void build(int startIndex,int left,int right,int* arr) {
	if (left==right) {
		tree[startIndex].val = arr[left];  //左右没有
		target[startIndex] = arr[left];
		return;
	}
	int mid = (left + right) >> 1;
	//[]
	build(startIndex*2+1,left,mid,arr);
	//[]
	build(startIndex*2+2,mid+1,right,arr);
	//back();
	// <<1|1  == *2+1
	tree[startIndex].l = startIndex * 2 + 1;
	tree[startIndex].r = startIndex * 2 + 2;
	tree[startIndex].val = tree[startIndex*2 + 1].val + tree[startIndex*2 + 2].val;   //更新，向上负责
	target[startIndex] = target[startIndex * 2 + 1] + target[startIndex * 2 + 2];
}
void pushUp() {
	
}


void findMax(int ) {
	
}

void test() {
	int arr[] = { 5,4,3,8,2,5,0,8,5,7 };
	build(0, 0, 9, arr);
	cout << endl;
	for (int i = 0; i < 40; i++) {
		cout << tree[i].val << ",";
	}
}


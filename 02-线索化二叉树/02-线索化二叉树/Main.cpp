#include<iostream>
#include<stack>
#include<queue>
#include<vector>
using namespace std;
//节点类
struct Node {
	int val = 0;
	Node* left = NULL;
	Node* right = NULL;
	Node(int val, Node* left, Node* right) :val(val), left(left), right(right) {
	}
	Node(int val) :val(val) {
	}
};

Node* root;

//BST 插入操作
void add(int val) {
	if (root == nullptr) {
		root = new Node(val);
	}
	else {
		Node* temp = root;
		Node* parent = NULL;
		int cmp = 0;
		while (temp) {
			parent = temp;
			cmp = val - temp->val;
			if (cmp == 0) {
				return;
			}
			else if (cmp > 0) {
				temp = temp->right;
			}
			else {
				temp = temp->left;
			}
		}
		if (cmp > 0) {
			parent->right = new Node(val);
		}
		else {
			parent->left = new Node(val);
		}
	}
}

//-----------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------
//----------------------------------层序遍历-----------------------------------------

void levelPrint() {
	queue<Node*> q;
	Node* temp = root;
	q.push(temp);
	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			Node* cur = q.front();
			cout << cur->val << ",";
			q.pop();
			if (cur->left) {
				q.push(cur->left);
			}
			if (cur->right) {
				q.push(cur->right);
			}
		}
	}
}

//-----------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------
//--------------------------------------中序（线索二叉树）---------------------------
//递归创建
Node* pre;
void ThreadedBinaryTree_Mid(Node* root) {
	if (root==NULL) {
		return;
	}
	
	ThreadedBinaryTree_Mid(root->left);

	//前驱 （左指针指向前驱）
	if (root->left == NULL) {
		root->left = pre;
	}

	//后继 （右指针指向后继）
	if (pre && pre->right==NULL) {
		pre->right = root;
	}
	pre = root;


	ThreadedBinaryTree_Mid(root->right);

}


int main() {
	add(6);
	add(4);
	add(7);
	add(2);
	add(5);
	add(1);
	add(3);
	cout << "\n-----------------" << endl;
	levelPrint();
	cout << "\n-----------------" << endl;
}










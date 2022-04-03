#include<iostream>
#include<stack>
#include<queue>
#include<vector>
using namespace std;
//�ڵ���
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

//BST �������
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
//----------------------------------�������-----------------------------------------

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
//--------------------------------------����������������---------------------------
//�ݹ鴴��
Node* pre;
void ThreadedBinaryTree_Mid(Node* root) {
	if (root==NULL) {
		return;
	}
	
	ThreadedBinaryTree_Mid(root->left);

	//ǰ�� ����ָ��ָ��ǰ����
	if (root->left == NULL) {
		root->left = pre;
	}

	//��� ����ָ��ָ���̣�
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










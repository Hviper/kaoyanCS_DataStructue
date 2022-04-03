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
	Node(int val,Node *left,Node* right):val(val),left(left),right(right) {
	}
	Node(int val):val(val) {
	}
};

Node* root;

//BST �������
void add(int val) {
	if (root==nullptr) {
		root = new Node(val);
	}
	else {
		Node* temp = root;
		Node* parent = NULL;
		int cmp = 0;
		while (temp) {
			parent = temp;
			cmp =  val - temp->val;
			if (cmp==0) {
				return;
			}
			else if(cmp>0) {
				temp = temp->right;
			}
			else {
				temp = temp->left;
			}
		}
		if (cmp>0) {
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
		for (int i = 0; i < size;i++) {
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
//---------------------------------------------* --------------------------------------
//------------------------�ǵݹ�ǰ�����---------------------------------------------

void preorderTraversal2(Node* root) {
	if (root==nullptr) {
		return;
	}
	stack<Node*> std;
	std.push(root);
	while (!std.empty()) {   //�ж�������std!=empty()
		Node* cur = std.top();
		std.pop();
		cout << cur->val << ",";
		if (cur->right) {         //����������
			std.push(cur->right);
		}
		if (cur->left) {          //����������
			std.push(cur->left);
		}
	}
}

//����rootָ�룺ֵ����
vector<int> preorderTraversal(Node* root) {
	stack<Node*> st;
	vector<int> res;
	while (true) {
		if (root) {
			res.push_back(root->val);
			cout << root->val << ",";
			if (root->right) {
				st.push(root->right);
			}
			root = root->left;
		}
		else if (st.empty()) {
			return res;
		}
		else {
			root = st.top();
			st.pop();
		}

	}
	return res;
}


//-----------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------
//---------------------------------�ݹ飨ǰ��--------------------------------------


void preDigui(Node *root) {
	if (!root) {
		return;
	}
	cout << root->val << ",";
	preDigui(root->left);
	preDigui(root->right);
}


//-----------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------
//----------------------------------����������ǵݹ飩-------------------------------

void inorderTraversal(Node* root) {
	if (root==nullptr) {
		return;
	}
	stack<Node*> std;
	while (true) {
		if (root) {
			std.push(root);    //һֱ������Ȳ���
			root = root->left;
		}
		else if (std.empty()) {   //ջΪ�գ�return
			return;
		}
		else {   //ջ��Ϊ�գ��滻��ǰcur��root��ָ��
			Node *cur = std.top();
			std.pop();
			cout << cur->val << ",";
			root = cur->right; 
		}
	}
}

//----------------------------------����������ݹ飩-------------------------------
void inorderTraversaldigui(Node* root) {
	if (root==NULL) {
		return;
	}
	inorderTraversaldigui(root->left);
	cout << root->val << ",";
	inorderTraversaldigui(root->right);
}
//-----------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------
//----------------------------------����������ǵݹ飩-------------------------------

void postOrderTraversal(Node* root) {
	if (root == nullptr) {
		return;
	}
	stack<Node*> std;
	while (true) {
		
	}
}

void postOrderTraversaldigui(Node* root) {
	if (root==nullptr) {
		return;
	}
	postOrderTraversaldigui(root->left);
	postOrderTraversaldigui(root->right);
	cout << root->val << ",";
}

//-----------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------


void staticMain() {
	add(6);
	add(4);
	add(7);
	add(2);
	add(5);
	add(1);
	add(3);
	cout << "\n-----------------" << endl;
	cout << "\n-----------------" << endl;
}










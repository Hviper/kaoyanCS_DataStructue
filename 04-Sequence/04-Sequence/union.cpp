#include<iostream>
using namespace std;

class Union {
private:
	int n;
	int* parent;
	int* ranks;
public:
	Union(int n) :n(n) {
		parent = new int[n] {0};
		ranks = new int[n] {0};
		for (int i = 0; i < n; i++) {
			parent[i] = i;
			ranks[i] = i;
		}
	}
	~Union() {
		delete[] parent;
		delete[] ranks;
	}
	void union_two(int v1, int v2) {
		int parent1 = find(v1);
		int parent2 = find(v2);
		if (parent1 == parent2) {
			return;
		}
		if (ranks[parent1] > ranks[parent2]) {
			parent[parent2] = parent1;
		}
		else if (ranks[parent1] < ranks[parent2]) {
			parent[parent1] = parent2;
		}
		else {
			parent[parent1] = parent2;  //p1指向p2，p2升高
			ranks[parent2] += 1;
		}
	}
	bool isConnected(int v1, int v2) {
		return find(v2) == find(v1);
	}
	int find(int v1) {
		if (parent[v1] != v1) {
			parent[v1] = find(parent[v1]);   //往上找父节点
		}
		return parent[v1];
	}
};

int main() {
	Union un(10);
	un.union_two(1,2);
	un.union_two(3,2);
	un.union_two(5,3);
	un.union_two(9,5);
	cout << un.isConnected(1,9)<<endl;
	cout << un.isConnected(2,9)<<endl;
	cout << un.isConnected(6,9)<<endl;

}
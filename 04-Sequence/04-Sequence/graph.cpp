#include<iostream>
using namespace std;
#include<queue>
#include<vector>

//有向图的边称为：弧
//无向图的边称为：边
int mmm() {
	vector<vector<int>> info;
	info.resize(5);
	for (int i = 0; i < 10;i++) {
		info[0].push_back(i);
	}
	queue<int> q;
	q.push(2);
	cout << info[0].size() << endl;
	return 0;
}
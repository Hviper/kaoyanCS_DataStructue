#include<iostream>
#include<vector>
using namespace std;

void getNext(vector<int> &next,string pattern) {
	int len = pattern.length();
	if (len<2) {
		return;
	}
	next[0] = -1;
	next[1] = 0;
	for (int i = 2; i < len;i++) {
		int index = i-1;   //�͵�ǰ�ַ��޹�
		while (index >=0 && next[index]>=0 && pattern[i - 1] != pattern[next[index]]) {
			index = next[index];
		}
		if (index<0) {
			next[i] = 0;
		}
		else {
			next[i] = next[index] + 1;
		}
	}
}

int kmp(string s,string pattern) {
	int len1 = s.length();
	int len2 = pattern.length();
	if (len2>len1) {
		return -1;
	}
	int i = 0; //����ָ��
	int j = 0; //ģʽ��ָ��
	vector<int> next(pattern.size());
	getNext(next,pattern);
	for (int i = 0; i < next.size();i++) {
		cout << next[i] << ",";
	}
	while (i<len1 && j<len2) {
		if (s[i]==pattern[j]) {
			i++;
			j++;
		}
		else if (next[j]==-1) { //��������,next[j] == -1  �൱��j==0
			i++;
		}
		else { //����
			j = next[j];
		}
	}
	return j==len2?i-j:-1;
}

int staticMain() {
	//           0123456789abcd
	string s1 = "abcabceabcabcd";
	string pattern = "abcabcd";
	
	cout << kmp(s1,pattern);
	return 0;
}



#include<iostream>
#include "Main.h"
using namespace std;


//next���飺�͵�ǰ���ַ��޹أ���֮ǰ���ַ��й�
int* getNext(char *pattern,int len2) {
	int* next = new int[len2];
	if (len2<2) {
		return NULL;   //û�б�Ҫ
	}
	next[0] = -1;    //�ֶ�Ϊ-1
	next[1] = 0;     //0
	next[2] = pattern[0] == pattern[1] ? 1 : 0;
	for (int i = 3; i < len2;i++) {
		int index = i - 1;     //����һ��ָ�뼴��, �͵�ǰ�ַ��޹�
		while (index >=0 && pattern[next[index]]!=pattern[i-1]) {  //pattern[i-1]:ǰһ���ַ�
			index = next[index];
		}
		if (index<0) {   //��������
			next[i] = 0;
		}
		else  {   //pattern[index] == pattern[i]
			next[i] = next[index] + 1;
		}
	}
	//��ӡnext������
	for (int i = 0; i < len2; i++) {
		cout << next[i] +1 << ",";
	}
	return next;
}


int KMP(char *mainString,char *pattern,int len1,int len2) {
	if (len2>len1) {
		return -1;
	}
	int l = 0, i = 0;
	int *next = getNext(pattern,len2);
	while (i<len2 && l<len1) {
		if (mainString[l]==pattern[i]) {
			l++;
			i++;
		}
		else if (i==0) {  // i==0 || next[i] == -1;  ��һ������˼��
			l++;   //ģʽ����pattern���е�i�Ѿ������������ˣ���ô����l����Ҫ������ͷ
		}
		else {  //�����Լ�������������ô�͸�ֵ
			i = next[i];   
		}
	}
	// ֻ��iԽ�����ƥ��ɹ��ˣ�lԽ���޷�֤����ƥ��ɹ�
	return i == len2 ? l-i : -1;   //i�Ѿ�����len2����l-len2����ʾ��ͷ�����ص�һ��ƥ��ɹ���index
}

int test() {         //  0123456789a
	string a = "hello";
	int len = a.length();
	char mainString[] = "aabaabaataa";
	int len1 = sizeof(mainString) / sizeof(char);
	char subString[] = "taa";
	int len2 = sizeof(subString) / sizeof(char);
	cout <<  "\n" << KMP(mainString, subString, len1, len2);
	return 0;
}



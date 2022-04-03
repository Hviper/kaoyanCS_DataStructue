#include<iostream>
#include "Main.h"
using namespace std;


//next数组：和当前的字符无关，和之前的字符有关
int* getNext(char *pattern,int len2) {
	int* next = new int[len2];
	if (len2<2) {
		return NULL;   //没有必要
	}
	next[0] = -1;    //手动为-1
	next[1] = 0;     //0
	next[2] = pattern[0] == pattern[1] ? 1 : 0;
	for (int i = 3; i < len2;i++) {
		int index = i - 1;     //单靠一个指针即可, 和当前字符无关
		while (index >=0 && pattern[next[index]]!=pattern[i-1]) {  //pattern[i-1]:前一个字符
			index = next[index];
		}
		if (index<0) {   //回跳不了
			next[i] = 0;
		}
		else  {   //pattern[index] == pattern[i]
			next[i] = next[index] + 1;
		}
	}
	//打印next数组结果
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
		else if (i==0) {  // i==0 || next[i] == -1;  【一样的意思】
			l++;   //模式串（pattern）中的i已经不能往回跳了，那么主串l就需要换个开头
		}
		else {  //还可以继续往回跳，那么就赋值
			i = next[i];   
		}
	}
	// 只有i越界才算匹配成功了，l越界无法证明出匹配成功
	return i == len2 ? l-i : -1;   //i已经到了len2，（l-len2）表示开头，返回第一次匹配成功的index
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



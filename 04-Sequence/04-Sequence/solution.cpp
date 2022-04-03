#include<iostream>
using namespace std;
#include<vector>
class Solution {
public:
    void getNext(vector<int>& next, string pattern) {
        int len = pattern.length();
        if (len < 2) {
            next[0] = -1;
            return;
        }
        next[0] = -1;
        next[1] = 0;
        for (int i = 2; i < len; i++) {
            int index = i - 1;   //�͵�ǰ�ַ��޹�
            while (index >= 0 && next[index] >= 0 && pattern[i - 1] != pattern[next[index]]) {
                index = next[index];
            }
            if (index < 0) {
                next[i] = 0;
            }
            else {
                next[i] = next[index] + 1;
            }
        }
    }
    int strStr(string s, string pattern) {
        int len1 = s.length();
        int len2 = pattern.length();
        if (s == pattern) {
            return 0;
        }
        if (len2 == 0) {
            return 0;
        }
        if (len2 > len1) {
            return -1;
        }
        int i = 0; //����ָ��
        int j = 0; //ģʽ��ָ��
        vector<int> next(pattern.size());
        getNext(next, pattern);

        while (i < len1 && j < len2) {
            if (s[i] == pattern[j]) {
                i++;
                j++;
            }
            else if (next[j] == -1) { //��������,next[j] == -1  �൱��j==0
                i++;
            }
            else { //����
                j = next[j];
            }
        }
        return j == len2 ? i - j : -1;
    }
};
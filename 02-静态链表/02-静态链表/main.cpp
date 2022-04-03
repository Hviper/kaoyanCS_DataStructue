#include <stdio.h>
#define maxSize 6
typedef struct {
    int data;
    int cur;
}component;
//���ṹ�����������з������ӵ�����������
void reserveArr(component* array);
//��ʼ����̬����
int initArr(component* array);
//�������
void displayArr(component* array, int body);
//�ӱ���������ժ�¿��нڵ�ĺ���
int mallocArr(component* array);
int main() {
    component array[maxSize];
    int body = initArr(array);
    printf("��̬����Ϊ��\n");
    displayArr(array, body);
    return 0;
}
//������������
void reserveArr(component* array) {
    int i = 0;
    for (i = 0; i < maxSize; i++) {
        array[i].cur = i + 1;//��ÿ������������ӵ�һ��
        array[i].data = 0;
    }
    array[maxSize - 1].cur = 0;//�������һ�������α�ֵΪ0
}
//��ȡ����ռ�
int mallocArr(component* array) {
    //����������ǿգ��򷵻ط���Ľ���±꣬���򷵻� 0�����������һ�����ʱ���ý����α�ֵΪ 0��
    int i = array[0].cur;
    if (array[0].cur) {
        array[0].cur = array[i].cur;
    }
    return i;
}
//��ʼ����̬����
int initArr(component* array) {
    int tempBody = 0, body = 0;
    int i = 0;
    reserveArr(array);
    body = mallocArr(array);
    //������Ԫ���
    array[body].data = 1; 
    array[body].cur = 0;
    //����һ��������������ָ��ʹ��ָ�����������һ����㣬��ǰ����Ԫ����غ�
    tempBody = body;
    for (i = 2; i < 4; i++) {
        int j = mallocArr(array); //�ӱ����������ó����еķ���
        array[j].data = i;      //��ʼ���µõ��Ŀռ���
        array[tempBody].cur = j; //���µõ��Ľ�����ӵ����������β��
        tempBody = j;             //��ָ���������һ������ָ�����
    }
    array[tempBody].cur = 0;//�µ��������һ������ָ������Ϊ0
    return body;
}
void displayArr(component* array, int body) {
    int tempBody = body;//tempBody׼��������ʹ��
    while (array[tempBody].cur) {
        printf("%d,%d\n", array[tempBody].data, array[tempBody].cur);
        tempBody = array[tempBody].cur;
    }
    printf("%d,%d\n", array[tempBody].data, array[tempBody].cur);
}
#ifndef sms_stuct_INCLUDED   //��ֹ��������ݱ��ظ�����
#define sms_stuct_INCLUDED

	#include<stdio.h> //printf()��scanf()�Ⱥ���
	#include<string.h>//strlen()��strcpy()�Ⱥ���  
	#include<stdlib.h>//atoi()����

	//���峣��
	#define N 3            

	//����ṹ��	
	typedef struct student     
	{
		char no[11];
		char name[15];
		float score[N];
		float sum;
		float average;
		int order;
	}STUDENT;

	//��������
	int Input(STUDENT *stud,int n);		//�����¼
	void print(STUDENT *stud,int n);	//��ʾ��¼
	void sort(STUDENT *stud,int n);		//�����¼
	void search(STUDENT *stud,int n);	//���Ҽ�¼
	int insert(STUDENT *stud,int n);	//�����¼
	int delete1(STUDENT *stud,int n);	//ɾ����¼
	void save(STUDENT *stud,int n);		//�洢��¼
	int load(STUDENT *stud);			//�����¼

#endif
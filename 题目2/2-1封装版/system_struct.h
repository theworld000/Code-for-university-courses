#pragma once
#define _CRT_SECURE_NO_WARNINGS

#ifndef system_stuct_INCLUDED   //��ֹ��������ݱ��ظ�����

#define system_stuct_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include<string.h>

//����ṹ��
typedef struct date
{
    char position[50];
    char description[50];
    char account[50];
    char password[50];
    struct date* next;
} Node;

//��������

int menu_select();              //�˵�����
Node* insert(Node* head);       //�����¼
Node* load(Node* head);         //�����¼
Node* delect(Node* head);       //ɾ����¼
Node* change(Node* head);       //�޸ļ�¼
void printfList(Node* head);    //��ӡ��¼
void clear(Node* head);         //��ռ�¼
void save(Node* head);          //�����¼
void  encrypt(char* str);        //���ܺ���
void change_system_password();  //�޸�ϵͳ����


#endif

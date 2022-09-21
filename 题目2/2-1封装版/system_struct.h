#pragma once
#define _CRT_SECURE_NO_WARNINGS

#ifndef system_stuct_INCLUDED   //防止下面的内容被重复包含

#define system_stuct_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include<string.h>

//定义结构体
typedef struct date
{
    char position[50];
    char description[50];
    char account[50];
    char password[50];
    struct date* next;
} Node;

//函数声明

int menu_select();              //菜单函数
Node* insert(Node* head);       //插入记录
Node* load(Node* head);         //导入记录
Node* delect(Node* head);       //删除记录
Node* change(Node* head);       //修改记录
void printfList(Node* head);    //打印记录
void clear(Node* head);         //清空记录
void save(Node* head);          //保存记录
void  encrypt(char* str);        //加密函数
void change_system_password();  //修改系统密码


#endif

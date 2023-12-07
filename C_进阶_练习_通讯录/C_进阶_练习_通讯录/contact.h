#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>


//
// 1.静态版本
// 2.动态版本
// 3.文件版本
// 
// 
// 类型的声明
//
// 人的信息
struct PeoInfo
{
	char name[20];
	int age;
	char sex[20];
	char tele[12];
	char addr[30];
};



// 
// 通讯录
//
struct Contact
{
	PeoInfo data[100];  // 存放人的信息
	int count; // 记录当前通讯录中人的个数
};


// 初始化通信录
void IntiContact(Contact* pc);

// 增加联系人通讯录
void AddContact(Contact* pc);

// 显示通讯录
void ShowContact(const Contact* pc);

// 删除指定联系人
void DelContact(Contact* pc);

// 查找联系人
void SeaContact(Contact* pc);

// 修改通讯录
void ModContact(Contact* pc);

// 排序通讯录
// 按照姓名排序
// 按照年龄排序
void SortContact(Contact* pc);

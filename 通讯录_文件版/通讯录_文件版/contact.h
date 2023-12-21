#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#define DEFAULT_size 3
#define INC_size 2
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>


// 
// 类型的声明
//
// 人的信息
typedef struct PeoInfo
{
	char name[20];
	int age;
	char sex[20];
	char tele[12];
	char addr[30];
}PeoInfo;



// 
// 通讯录
// 文件版
//

typedef struct Contact
{
	PeoInfo* ptr;
	PeoInfo* data;  // 存放人的信息
	int count; // 记录当前通讯录中人的个数
	int capacity;//当前通讯录的容量
}Contact;

// 初始化通信录
void IntiContact(Contact* pc);

// 销毁通讯录
void DestroyContact(Contact* pc);

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

// 保存通讯录
void SavaContact(const Contact* pc);

// 排序通讯录
// 按照姓名排序
// 按照年龄排序
void SortContact(Contact* pc);

// 加载文件信息到通讯录
void LoatContact(Contact* pc);
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
// ���͵�����
//
// �˵���Ϣ
typedef struct PeoInfo
{
	char name[20];
	int age;
	char sex[20];
	char tele[12];
	char addr[30];
}PeoInfo;



// 
// ͨѶ¼
// �ļ���
//

typedef struct Contact
{
	PeoInfo* ptr;
	PeoInfo* data;  // ����˵���Ϣ
	int count; // ��¼��ǰͨѶ¼���˵ĸ���
	int capacity;//��ǰͨѶ¼������
}Contact;

// ��ʼ��ͨ��¼
void IntiContact(Contact* pc);

// ����ͨѶ¼
void DestroyContact(Contact* pc);

// ������ϵ��ͨѶ¼
void AddContact(Contact* pc);

// ��ʾͨѶ¼
void ShowContact(const Contact* pc);

// ɾ��ָ����ϵ��
void DelContact(Contact* pc);

// ������ϵ��
void SeaContact(Contact* pc);

// �޸�ͨѶ¼
void ModContact(Contact* pc);

// ����ͨѶ¼
void SavaContact(const Contact* pc);

// ����ͨѶ¼
// ������������
// ������������
void SortContact(Contact* pc);

// �����ļ���Ϣ��ͨѶ¼
void LoatContact(Contact* pc);
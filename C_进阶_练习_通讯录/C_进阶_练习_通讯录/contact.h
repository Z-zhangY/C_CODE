#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>


//
// 1.��̬�汾
// 2.��̬�汾
// 3.�ļ��汾
// 
// 
// ���͵�����
//
// �˵���Ϣ
struct PeoInfo
{
	char name[20];
	int age;
	char sex[20];
	char tele[12];
	char addr[30];
};



// 
// ͨѶ¼
//
struct Contact
{
	PeoInfo data[100];  // ����˵���Ϣ
	int count; // ��¼��ǰͨѶ¼���˵ĸ���
};


// ��ʼ��ͨ��¼
void IntiContact(Contact* pc);

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
// ������������
// ������������
void SortContact(Contact* pc);

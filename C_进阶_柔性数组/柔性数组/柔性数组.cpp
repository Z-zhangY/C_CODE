#include <stdio.h>
#include <string.h>
#include <stdlib.h>





//
// ��������
// C99 �У��ṹ�е����һ��Ԫ��������δ֪��С�����飬��ͽ������������Ա
// 
// 1.��������
//
// 1.1����������ص�
//    ���������Աǰ����������һ��������Ա
//    sizeof ���صĽṹ��С����������������ڴ�
//	  �������������Ա�Ľṹ�� malloc���������ڴ�Ķ�̬����
//	  �����ڴ�ķ���Ӧ�ô��ڽṹ�Ĵ�С������Ӧ���������Ԥ�ڴ�С
//typedef struct st_type
//{
//	int i;
//	int a[0]; // ���������Ա
//}type_a;
//int main()
//{
//	//printf("%d\n", sizeof(st_type));
//
//
//	//���������ʹ��
//	struct st_type* ps = (struct st_type*)malloc(sizeof(struct st_type) + 40);
//	if (ps == NULL)
//	{
//		return 1;
//	}
//	ps->i = 100;
//	for (int i = 0; i < 10; i++)
//	{
//		ps->a[i] = i;
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d\n", ps->a[i]);
//	}
//	struct st_type* ptr = (struct st_type*)realloc(ps, sizeof(struct st_type) + 80);
//	if (ptr != NULL)
//	{
//		ps = ptr;
//		ptr = NULL;
//	}
//	//�ͷ�
//	free(ps);
//	return 0;
//}
//


//��һ�ַ���
struct S
{
	int n;
	int* arr;
};
int main()
{
	struct S* ps = (struct S*)malloc(sizeof(struct S));
	if (ps == NULL)
	{
		return 1;
	}
	ps->n = 100;
	ps->arr = (int*)malloc(40);
	for (int i = 0; i < 10; i++)
	{
		ps->arr[i] = i;
	}
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", ps->arr[i]);
	}
	int* ptr = (int*)realloc(ps->arr, 80);
	if (ptr == NULL)
	{
		return 1;
	}
	free(ps->arr);
	free(ps);
	return 0;
}
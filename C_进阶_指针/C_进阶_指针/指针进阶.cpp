#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// 
// ��.ָ��Ľ���
// 
//		ָ����Ǹ�����
//		ָ��Ĵ�С�̶��� 4/8 ���ֽ�
//		ָ��������
//		ָ�������
// 
//int main()
//{
//
//	int p;         // ���ͱ���
//	int* p;		   // ����ָ��   ָ�����������Ϊ int �ͣ���һ�������������ݵ�ָ��
//	int p[3];      // ��������   ����������ɵ�����
//	int* p[3];     // ָ������   ����[]��ϣ�p ˵����һ�����飬�� * ˵����һ��������ָ�빹�ɵ�����
//	int(*p)[3];    // ����ָ��   *p ˵������һ��ָ�룬�� [] ˵�����ָ��ָ���������һ������
//
//	int arr[5] = { 1,2,3,4,5 };
//	
//
//
//	return 0;
//}
// 
// 
// 
// 1.�ַ�ָ��
//	char*
//int main()
//{
//	//char ch = 'w';
//	//char* pc = &ch;
//	//*pc = 'b';
//	//printf("%c\n", ch);
//
//	const char* p = "abcdef";
//	char arr[] = "abcdef";
//	printf("%s\n", p);
//	//д�����Ȩ�޳�ͻ��˵���ڱ������У�ÿ�����͵����ݶ���ר�ŵķ��ʱ��ʽ��Ҳ��ר�ŷ��ʵ�ַ������
//	//���ʽ���������ԣ�ֵ���Ժ���������
//	//�������ʽ����˼�ǰ�����ĸ a �ĵ�ַ������ ָ�� p
//	//ͬʱ��ָ��Ĵ�Сֻ�� 4 ���� 8 ���ֽڣ��߸��ֽڵ��ַ���������
//	return 0;
//}
// 
//int main()
//{
//	const char* p1 = "abcdef";
//	const char* p2 = "abcdef";
//	//p1 p2 ��ָ����ǳ����ַ�������ĸ a �ĵ�ַ������ p1=p2
//
//	char arr1[] = "abcdef";
//	char arr2[] = "abcdef";
//	//arr1 arr2 ��������һ���ڴ�ռ䴴���˱����ַ������ռ䲻ͬ����˵�ַҲ��ͬ
//
//	if (p1 == p2)
//	{
//		printf("p1==p2\n");
//	}
//	else
//	{
//		printf("p1!=p2\n");
//	}
//	if (arr1 == arr2)
//	{
//		printf("arr1==arr2\n");
//	}
//	else
//	{
//		printf("arr1!=arr2\n");
//	}
//	return 0;
//}
// 
// 2.ָ������
//		���ָ������飬�ص�������
// 
//int main()
//{
//	int i = 0;
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	//int (*p)[10] = &arr;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	int* p = arr;
//	for (i = 0; i < sz; i++)
//	{	
//		printf("%d ", p[i]);
//		printf("%d ", *(p + i));
//	}
//
//
//
//	//int a = 1;
//	//int* s = &a;
//	//printf("%d\n", *s);
//	// �����ݵ����ݴ����ָ���к󣬴�ӡ����֮ǰ��Ҫ������
//	// ����ָ���ӡʱ����ͨ��������ָ����һ�� *
//
//
//	// ����ָ�벻����ô�õ�
//	//for (i = 0; i < sz; i++)
//	//{
//	//	printf("%d ", *(*p + i));
//	//	// *p �൱������������������������Ԫ�ص�ַ
//	//}
//	//return 0;
//}
// 
//int main()
//{
//	int i = 0;
//	int arr1[] = { 1,2,3,4 };
//	int arr2[] = { 5,6,7,8 };
//	int arr3[] = { 9,10,11,12 };
//	
//	int* parr[] = { arr1,arr2,arr3 };
//	//
//	//������ѭ����ӡ��������
//	//
//	for (i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for (j = 0; j < 4; j++)
//		{
//			printf("%d ", (*parr[i] + j));
//			// *(p+i) -> p[i]
//			// *(parr[i]+j -> parr[i][j]
//		}
//		printf("\n");
//	}
//	return 0;
//}
// 
//  C����ʵ�ּ����ݽṹ
//  ָ��+�ṹ��+��̬�ڴ����
// 
// 3.����ָ��  -  ָ�������ָ��
// 
//// ����ָ�벻����ô�õ�
//int main()
//{
//	int i = 0;
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int(*p)[10] = &arr;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", *(*p + i));
//	}
//	return 0;
//}
//
// ��ȷ�÷�
// arr ��������ʾ������Ԫ�ص�ַ��
// ��λ������Ԫ�ؾ������ĵ�һ�� 
//
// 
//void print1(int arr[3][5], int r, int c)
//{
//	int i = 0;
//	for (i = 0; i < r; i++)
//	{
//		int j = 0;
//		for (j = 0; j < c; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//}
//void print2(int(*p)[5], int r, int c)
//{
//	int i = 0;
//	for (i = 0; i < r; i++)
//	{
//		int j = 0;
//		for (j = 0; j < c; j++)
//		{
//			printf("%d ", *(*p + i) + j);
//		}
//		printf("\n");
//	}
//}
////��ά��������Ԫ�ص�ַ�ǵ�һ��Ԫ�صĵ�ַ��*p ָ�������Ϊ����
////��������ÿһ�ж��� 5 ��Ԫ�� 
////
//int main()
//{
//
//	int arr[3][5] = { 1,2,3,4,5,2,3,4,5,6,3,4,5,6,7 };
//
//	//print1(arr, 3, 5);
//	print2(arr, 3, 5);
//	
//	return 0;
//}
// 
//int arr[10];
//&arr -> int(*)[10];   // ������һ�еĵ�ַ
//arr  -> int*;
// 
// 3.1 ����ָ��Ķ���
//	    ����ָ�� -> ָ��
//		����ָ�� -> ָ�������ָ��
//		����ָ�� -> ָ�����͵�ָ��
//		int *p1[10];   ָ������
//		int (*p2)[10]; ����ָ��
// 3.1.1 �ٴ����������
//		������ͨ��������Ԫ�ص�ַ
//		��������
//		1.sizeof(����������)���������������ʾ�������飬���������������Ĵ�С����λ���ֽ�
//		2.&�������������ʾ����Ȼ���������飬ȡ��ַȡ��������������ĵ�ַ
//
//int main()
//{
//	int arr[10] = { 0 };
//	int* p = arr;
//	int (*p2)[10] = { &arr };
//	
//	//int (*)[10] p2 = &arr;
//	 
//	//��������ָ��������ĵ�ַ
//	 
//	
//	//int *p = &arr;
//	//��Ϊ���������ָ�����ͣ��ұ�������ĵ�ַ
//	
//	 
//	printf("%p\n", arr);	
//	printf("%p\n", arr + 1); 
//	// ������+1������ 4 ���ֽ�
//	 
//	printf("%p\n", &arr[0]);
//	printf("%p\n", &arr[0] + 1); 
//	// ������+1������ 4 ���ֽ�
//	 
//	printf("%p\n", &arr);
//	printf("%p\n", &arr + 1); 
//	// ������+1������ 40 ���ֽ�
//	return 0;
//}
// 
//int main()
//{
//	char* arr[5] = { 0 };
//	// ָ�����飬�����ŵ��� 5 ��ָ��
//	char* (*pc)[5] = &arr; 
//	// �� pc �����Ԫ�صĵ�ַ������ pc Ҳ����һ��ָ��
//
//	// 
//	// ����ָ��
//	char ch = 'w';
//	char* ch1 = &ch;
//	char** ch2 = &ch1;
//	// ����ָ�����������һ��ָ������ĵ�ַ��
//	return 0;
//}
//
// 3.2 
// int arr[5];          arr ����������
// int *parr1[10];	    parr1 ������ָ������ 
// int (*parr2)[10];    parr2 ������ָ��
// int (*parr3[10])[5]; parr3 �Ǵ������ָ�������
//
// 
// 4.���鴫�κ�ָ�봫��
// 4.1 һά���鴫��
//void test(int arr)
//{} 
//void test(int arr[10])
//{}
////������������������Ԫ�صĵ�ַ���±��д�ɲ�д
//void test(int* arr)
//{}
////������Ԫ�صĵ�ַ��ָ�����
//void test2(int *arr[20])
//{}
////���鴫�Σ��βεĲ��ֿ���д���飬Ҳ����д��ָ�룬�±����ʡ��
//void test2(int **arr)
//{}
////ָ���������Ԫ��Ҳ��ָ�룬һ��ָ��ĵ�ַ�ö���ָ�����
//int main()
//{
//	int arr[10] = { 0 };
//	int* arr2[20] = { 0 };
//	test(arr);
//	test2(arr2);
//	return 0;
//}
//
// 
// 4.2 ��ά���鴫��
//void test(int arr[3][5])
//{}   //����
//void test(int arr[][])
//{}   //����
//void test(int arr[][5])
//{}   //���� ��ά���鴫�ε�ʱ��ֻ��ʡ�Ե�һά
//void test(int *arr)
//{}   //���� ��ά�������������ʾ���ǵ�һ�еĵĵ�ַ
//void test(int* arr[5])
//{}   //���� ����һ�����飬����һ��ָ��
//void test(int (*arr)[5])
//{}   //���� ����һ������ָ��
//void test(int **arr)
//{}   //���� ����ָ����ר�Ŵ��һ��ָ��ĵ�ַ
//
// 4.3 һ�����鴫��
// 
//void print(int* p, int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", *p + i);
//		printf("%d ", p[i]);
//	}
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8 };
//	int* p = arr;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	print(p, sz);
//	return 0;
//}
// 
//// ����������ֵĲ�����ָ�룬��ָ�룬ȡ��ַ��������
//void print(int *p)
//{}
//int main()
//{
//	int a = 0;
//	int* p = &a;
//	int* ptr = &a;
//	return 0;
//}
// 
// 4.4 ����ָ�봫��
// ����������β��Ƕ���ָ��
// ���������´���
// 
// 
////void test1(int **ptr)
////{}
////int* p1;
////test1(&p1);
////int** p2;
////test1(p2);
////int* arr[10];
////test1(arr);
//void test(int **ptr)
//{
//	printf("%d ", **ptr);
//}
//int main()
//{
//	int n = 10;
//	int* p = &n;
//	int** pp = &p;
//	test(pp);
//	test(&p);
//	return 0;
//}
// 
// 
// 
// 5.����ָ��  - ָ������ָ�� 
//int ADD(int x, int y)
//{
//	return x + y;
//}
//int main()
//{
//	int arr[5] = { 0 };
//	// &������ - ȡ����������ĵ�ַ
//	int(*p)[5] = &arr;
//	//
//	// &������ - ȡ���ľ�i�Ǻ����ĵ�ַ
//	/*printf("%p\n", ADD);
//	printf("%p\n", &ADD);*/
//	// ���ں�����˵��&�������ͺ��������Ǻ����ĵ�ַ
//	// ��ź�����ַ�ı��ʽ
//	int (*pf)(int, int) = &ADD;
//	int ret = (*pf)(2, 3);
//	int ret = pf(2, 3);
//	// * ���п���
//	int ret = ADD(2, 3);
//	printf("%d\n", ret);
//	return 0;
//}
// 
// 
// 
//int main()
//{
//	// ָ������
//	int* arr[4];
//	char* ch[4];
//	int** p = arr;
//	// ����ָ��
//	int arr2[5];
//	int(*pa)[5] = &arr2;
//
//	char* arr3[6];
//	char* (*p3)[6] = &arr3;
//	//
//	return 0;
//}
// 
// 
// 
//int test(const char* str)
//{
//	printf("test\n");
//	return 0;
//}
//int main()
//{
//	// ����ָ��  - ָ������ָ�� 
//	printf("%p\n", test);
//	printf("%p\n", &test);
//	int (*pf)(const char* ) = test;
//	// pf ��ָ�����Ĳ����� const char*
//	pf("abc");  
//	test("abc");
//	(*pf)("abc");
//	printf("%d\n", sizeof(&test));
//	return 0;
//}
// 
// 
// 
// �Ķ�����   
//int main()
//{
//	( *(void(*)())0) ();
//	int (*pf)(int*);
//	// pf= void (*)() 0
//	// void (*)()  ��һ�ֺ���ָ��
//	// (void (*)()) 0  �Ƕ� 0 ǿ������ת��
//	// �������ϴ�����һ�κ������ã����õ��� 0 ��Ϊ��ַ���ĺ���
//	// �� 0 ǿ������ת��Ϊ���޲Σ����������� void �ĺ����ĵ�ַ
//	// ���� 0 ��ַ�����������
//
//	void (*signal(int, void(*)(int)))(int);
//	// ���ϴ�����һ�κ�������
//	// ������ signal �����ĵ�һ�������� int���ڶ��������������Ǻ���ָ��
//	// �ú���ָ��ָ��ĺ��������� int ����������Ϊ void 
//	// signal �����ķ�������ҲΪ����ָ�룬ָ��ĺ�������Ϊ int ����������Ϊ void
//	// ���㺯��
//	// ����� void    
//	// �ڶ��� signal  
//	// ������ void
//
//	return 0;
//}
// 
// 
// ����ָ�����;
// дһ����������ʵ�� +-*/
//void menu()
//{
//	printf("*************************\n");
//	printf("****** 1.ADD 2.SUB ******\n");
//	printf("****** 3.MUL 4.DIV ******\n");
//	printf("********* 0.exit ********\n");
//	printf("*************************\n");
//}
//int ADD(int x, int y)
//{
//	return x + y;
//}
//int SUB(int x, int y)
//{
//	return x - y;
//}
//int MUL(int x, int y)
//{
//	return x * y;
//}
//int DIV(int x, int y)
//{
//	return x / y;
//}
//void calc(int (*pf)(int, int))
//{
//	int x = 0;
//	int y = 0;
//	int ret = 0;
//	printf("��������������\n");
//	scanf("%d %d", &x, &y);
//	ret = pf(x, y);
//	printf("%d \n", ret);
//}
//int main()
//{
//	int input = 0;
//
//	do
//	{
//		menu();
//		printf("ѡ��->" );
//		scanf("%d", &input);
//
//		switch (input)
//		{
//		case 1:
//			calc(ADD);
//			break;
//		case 2:
//			calc(SUB);
//			break;
//		case 3:
//			calc(MUL);
//			break;
//		case 4:
//			calc(DIV);	
//			break;
//		case 0:
//			printf("�˳�������\n");
//			break;
//		default:
//			printf("ѡ�����\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}
// 
// 
// 6.����ָ������
// ָ������
// int* arr1[5];
// char* arr2[5];
// ����ָ��Ҳ��ָ��
// ����ָ��������Ǵ�ź���ָ�������
// 
//int ADD(int x, int y)
//{
//	return x + y;
//}
//int SUB(int x, int y)
//{
//	return x - y;
//}
//int MUL(int x, int y)
//{
//	return x * y;
//}
//int DIV(int x, int y)
//{
//	return x / y;
//}
//int main()
//{
//	int (*pf)(int, int) = ADD;
//	// pf �Ǻ���ָ��
//	
//	int (*parr[4])(int, int) = { ADD,SUB,DIV,MUL };
//	// parr �Ǻ���ָ������
//
//	int i = 0;
//	for (i = 0; i < 4; i++)
//	{
//		int a = 3;
//		int b = 4;
//		int ret = (*parr[i])(a, b);
//		printf("%d\n", ret);
//	}
//
//	return 0;
//}
// 
// 
// ��ӹ���
// 
//
//void menu()
//{
//	printf("*************************\n");
//	printf("****** 1.ADD 2.SUB ******\n");
//	printf("****** 3.MUL 4.DIV ******\n");
//	printf("********* 0.exit ********\n");
//	printf("*************************\n");
//}
//int ADD(int x, int y)
//{
//	return x + y;
//}
//int SUB(int x, int y)
//{
//	return x - y;
//}
//int MUL(int x, int y)
//{
//	return x * y;
//}
//int DIV(int x, int y)
//{
//	return x / y;
//}
//int main()
//{
//	int input = 0;
//	int x = 0;
//	int y = 0;
//	int ret = 0;
//
//	int (*pfarr[5])(int, int) = { 0,ADD,SUB,MUL,DIV };
//	// �ú���ָ������󣬼��˳��򣬷��㹦�ܵ�����ɾ��
//	// ת�Ʊ�
//	// 
//	do
//	{
//		menu();
//		printf("ѡ��->" );
//		scanf("%d", &input);
//		if (input == 0)
//		{
//			printf("�˳�������");
//		}
//		else if (input > 0 && input <= 4)
//		{
//			printf("��������������\n");
//			scanf("%d %d", &x, &y);
//			ret = pfarr[input](x, y);
//			printf("%d \n", ret);
//		}
//		else
//		{
//			printf("�����������������\n");
//		}
//
//		
//	} while (input);
//	return 0;
//}
//
//
//
// 7.ָ����ָ�������ָ��
//int main()
//{
//	
//	int (*parr[])(int, int) = { 0,ADD,SUB,MUL,DIV };
//	// ����ָ������
//
//	int (*(*parr)[5])(int, int) = &parr;
//	// ָ����ָ�������ָ��
//
//	return 0;
//}
//
// 
// 
// 8.�ص�����
// �ص���������ͨ��һ������ָ����õĺ���������Ѻ�����ָ����Ϊ�������ݸ���һ������
// �����ָ�뱻������������ָ��ĺ���ʱ�����Ǿ�˵���ǻص�����
// �ص����������ɸú�����ʵ�ַ�ֱ�ӵ��ã��������ض����¼�����������ʱ������һ�����õģ����ڶԸ�ʱ�������������Ӧ
//
// ð������
// ֻ��������������
//void bubble_sort(int arr[], int sz)
//{
//	int i = 0;
//	// ����
//	for (i = 0; i < sz; i++)
//	{
//		int flag = 1;
//		// ��������Ѿ��ź��򣬱����ظ��Ƚ�
//		// 
//		int j = 0;
//		for (j = 0; j < sz-1-i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//				flag = 0;
//			}
//		}
//		if (flag == 1)
//		{
//			break;
//		}
//	}
//}
//int main()
//{
//	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
//	// �������ų�����
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	bubble_sort(arr, sz);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}
// 
// 
// 
// 
// qsort ��������
//void qsort(void* base,    // ��Ҫ��������ݵ���ʼλ��
//	size_t num,    // ���������ݵĸ���
//	size_t width,  // ����������Ԫ�صĴ�С����λ���ֽڣ�
//	int(*cmp)(const void* e1, const void* e2) //����ָ�롪�ȽϺ���
//
void Swap(char* buf1, char* buf2, int width)
{
	int i = 0;
	char tmp = *buf1;
	*buf1 = *buf2;
	*buf2 = tmp;
	buf1++;
	buf2++;
}
void bubble_sort(void* base, int sz, int width, int(*cmp)(const void* e1, const void* e2))
{
	int i = 0;
	// ����
	for (i = 0; i < sz - 1; i++)
	{
		int flag = 1;
		// ��������Ѿ��ź��򣬱����ظ��Ƚ�
		// 
		int j = 0;
		for (j = 0; j < sz -1 - i; j++)
		{
			if (cmp((char*) base + j * width, (char*)base + (j + 1) * width) > 0)
			{  
				// ����
				Swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
				flag = 0;
			}
		}
		if (flag == 1)
		{
			break;
		}
	}
}
// 
struct Stu
{
	char name[20];
	int age;
};
int cmp_int(const void* e1, const void* e2)
{
	return (*(int*)e1 - *(int*)e2);   // ����
	//return (*(int*)e2 - *(int*)e1); // ����
}
void test1()
{
	int arr[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, sz, sizeof(arr[0]), cmp_int);
	// �ص�����ʵ��������
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}
// �����ַ���
int cmp_stu_by_name(const void* e1, const void* e2)
{
	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
}
 // ��������
int cmp_stu_by_age(const void* e1, const void* e2)
{
	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
}
void test2()
{
	//ʹ�� qsort ����ṹ��˳��
	struct Stu s[] = { {"zhangsan",16}, {"lisi",10},{"wangwu",13} };

	int sz = sizeof(s)/sizeof(s[0]);
	//qsort(s, sz, sizeof(s[0]), cmp_stu_by_name);
	qsort(s, sz, sizeof(s[0]), cmp_stu_by_age);

}
void test3()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, sz, sizeof(arr[0]), cmp_int);

	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}
void test4()
{
	//ʹ�� qsort ����ṹ��˳��
	struct Stu s[] = { {"zhangsan",16}, {"lisi",10},{"wangwu",13} };

	int sz = sizeof(s) / sizeof(s[0]);
	//qsort(s, sz, sizeof(s[0]), cmp_stu_by_name);
	bubble_sort(s, sz, sizeof(s[0]), cmp_stu_by_age);

}
int main()
{
	//test1();
	//test2();
	//test3();
	test4();
	return 0;
 }

//int main()
//{
//	int a = 0;
//	//char* pa = &a;  // ���������� int��
//	void* pc = &a;
//	// void* ���Խ����κ����͵ĵ�ַ
//	// ���Ǿ������͵�ָ�룬����ֱ�ӽ����ú��� +-
//
//	return 0;
//}
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// 
// 二.指针的进阶
// 
//		指针就是个变量
//		指针的大小固定是 4/8 个字节
//		指针有类型
//		指针的运算
// 
//int main()
//{
//
//	int p;         // 整型变量
//	int* p;		   // 整型指针   指向的内容类型为 int 型，是一个返回整形数据的指针
//	int p[3];      // 整型数组   整形数据组成的数组
//	int* p[3];     // 指针数组   先与[]结合，p 说明是一个数组，带 * 说明是一个由整型指针构成的数组
//	int(*p)[3];    // 数组指针   *p 说明先是一个指针，带 [] 说明这个指针指向的内容是一个数组
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
// 1.字符指针
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
//	//写入访问权限冲突，说明在编译器中，每个类型的数据都有专门的访问表达式，也有专门访问地址的类型
//	//表达式有两个属性：值属性和类型属性
//	//上述表达式的意思是把首字母 a 的地址赋给了 指针 p
//	//同时，指针的大小只有 4 或者 8 个字节，七个字节的字符串超出了
//	return 0;
//}
// 
//int main()
//{
//	const char* p1 = "abcdef";
//	const char* p2 = "abcdef";
//	//p1 p2 都指向的是常量字符串首字母 a 的地址，所以 p1=p2
//
//	char arr1[] = "abcdef";
//	char arr2[] = "abcdef";
//	//arr1 arr2 都开辟了一快内存空间创建了变量字符串，空间不同，因此地址也不同
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
// 2.指针数组
//		存放指针的数组，重点是数组
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
//	// 把数据的内容存放在指针中后，打印数据之前需要解引用
//	// 数组指针打印时比普通整形数据指针多带一个 *
//
//
//	// 数组指针不是这么用的
//	//for (i = 0; i < sz; i++)
//	//{
//	//	printf("%d ", *(*p + i));
//	//	// *p 相当于数组名，本质上是数组首元素地址
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
//	//可以用循环打印数组内容
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
//  C语言实现简单数据结构
//  指针+结构体+动态内存管理
// 
// 3.数组指针  -  指向数组的指针
// 
//// 数组指针不是这么用的
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
// 正确用法
// arr 数组名表示数组首元素地址，
// 二位数组首元素就是他的第一行 
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
////二维数组中首元素地址是第一行元素的地址，*p 指向的内容为数组
////这个数组的每一行都有 5 个元素 
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
//&arr -> int(*)[10];   // 传的是一行的地址
//arr  -> int*;
// 
// 3.1 数组指针的定义
//	    数组指针 -> 指针
//		数组指针 -> 指向数组的指针
//		整型指针 -> 指向整型的指针
//		int *p1[10];   指针数组
//		int (*p2)[10]; 数组指针
// 3.1.1 再次理解数组名
//		数组名通常就是首元素地址
//		两个例外
//		1.sizeof(单独数组名)，这里的数组名表示整个数组，计算的是整个数组的大小，单位是字节
//		2.&数组名，这里表示的依然是整个数组，取地址取出的是整个数组的地址
//
//int main()
//{
//	int arr[10] = { 0 };
//	int* p = arr;
//	int (*p2)[10] = { &arr };
//	
//	//int (*)[10] p2 = &arr;
//	 
//	//利用数组指针存放数组的地址
//	 
//	
//	//int *p = &arr;
//	//因为左边是整型指针类型，右边是数组的地址
//	
//	 
//	printf("%p\n", arr);	
//	printf("%p\n", arr + 1); 
//	// 数组名+1，跳过 4 个字节
//	 
//	printf("%p\n", &arr[0]);
//	printf("%p\n", &arr[0] + 1); 
//	// 数组名+1，跳过 4 个字节
//	 
//	printf("%p\n", &arr);
//	printf("%p\n", &arr + 1); 
//	// 数组名+1，跳过 40 个字节
//	return 0;
//}
// 
//int main()
//{
//	char* arr[5] = { 0 };
//	// 指针数组，里面存放的是 5 个指针
//	char* (*pc)[5] = &arr; 
//	// 用 pc 存放首元素的地址，首先 pc 也得是一个指针
//
//	// 
//	// 二级指针
//	char ch = 'w';
//	char* ch1 = &ch;
//	char** ch2 = &ch1;
//	// 二级指针是用来存放一级指针变量的地址的
//	return 0;
//}
//
// 3.2 
// int arr[5];          arr 是整型数组
// int *parr1[10];	    parr1 是整型指针数组 
// int (*parr2)[10];    parr2 是数组指针
// int (*parr3[10])[5]; parr3 是存放数组指针的数组
//
// 
// 4.数组传参和指针传参
// 4.1 一维数组传参
//void test(int arr)
//{} 
//void test(int arr[10])
//{}
////数组名代表了数组首元素的地址，下标可写可不写
//void test(int* arr)
//{}
////数组首元素的地址用指针接收
//void test2(int *arr[20])
//{}
////数组传参，形参的部分可以写数组，也可以写成指针，下标可以省略
//void test2(int **arr)
//{}
////指针数组的首元素也是指针，一级指针的地址用二级指针接收
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
// 4.2 二维数组传参
//void test(int arr[3][5])
//{}   //可以
//void test(int arr[][])
//{}   //不行
//void test(int arr[][5])
//{}   //可以 多维数组传参的时候只能省略第一维
//void test(int *arr)
//{}   //不行 二维数组的数组名表示的是第一行的的地址
//void test(int* arr[5])
//{}   //不行 这是一个数组，不是一个指针
//void test(int (*arr)[5])
//{}   //可以 这是一个数组指针
//void test(int **arr)
//{}   //不行 二级指针是专门存放一级指针的地址
//
// 4.3 一级数组传参
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
//// 如果函数部分的参数是指针，传指针，取地址，数组名
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
// 4.4 二级指针传参
// 如果函数的形参是二级指针
// 可以如以下传参
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
// 5.函数指针  - 指向函数的指针 
//int ADD(int x, int y)
//{
//	return x + y;
//}
//int main()
//{
//	int arr[5] = { 0 };
//	// &数组名 - 取出的是数组的地址
//	int(*p)[5] = &arr;
//	//
//	// &函数名 - 取出的就i是函数的地址
//	/*printf("%p\n", ADD);
//	printf("%p\n", &ADD);*/
//	// 对于函数来说，&函数名和函数名都是函数的地址
//	// 存放函数地址的表达式
//	int (*pf)(int, int) = &ADD;
//	int ret = (*pf)(2, 3);
//	int ret = pf(2, 3);
//	// * 可有可无
//	int ret = ADD(2, 3);
//	printf("%d\n", ret);
//	return 0;
//}
// 
// 
// 
//int main()
//{
//	// 指针数组
//	int* arr[4];
//	char* ch[4];
//	int** p = arr;
//	// 数组指针
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
//	// 函数指针  - 指向函数的指针 
//	printf("%p\n", test);
//	printf("%p\n", &test);
//	int (*pf)(const char* ) = test;
//	// pf 所指向函数的参数是 const char*
//	pf("abc");  
//	test("abc");
//	(*pf)("abc");
//	printf("%d\n", sizeof(&test));
//	return 0;
//}
// 
// 
// 
// 阅读代码   
//int main()
//{
//	( *(void(*)())0) ();
//	int (*pf)(int*);
//	// pf= void (*)() 0
//	// void (*)()  是一种函数指针
//	// (void (*)()) 0  是对 0 强制类型转换
//	// 所以以上代码是一次函数调用，调用的是 0 作为地址处的函数
//	// 把 0 强制类型转换为：无参，返回类型是 void 的函数的地址
//	// 调用 0 地址处的这个函数
//
//	void (*signal(int, void(*)(int)))(int);
//	// 以上代码是一次函数声明
//	// 声明的 signal 函数的第一个参数是 int，第二个参数的类型是函数指针
//	// 该函数指针指向的函数参数是 int ，返回类型为 void 
//	// signal 函数的返回类型也为函数指针，指向的函数参数为 int ，返回类型为 void
//	// 三层函数
//	// 最外层 void    
//	// 第二层 signal  
//	// 第三层 void
//
//	return 0;
//}
// 
// 
// 函数指针的用途
// 写一个计算器，实现 +-*/
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
//	printf("请输入两个数：\n");
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
//		printf("选择->" );
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
//			printf("退出计算器\n");
//			break;
//		default:
//			printf("选择错误\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}
// 
// 
// 6.函数指针数组
// 指针数组
// int* arr1[5];
// char* arr2[5];
// 函数指针也是指针
// 函数指针数组就是存放函数指针的数组
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
//	// pf 是函数指针
//	
//	int (*parr[4])(int, int) = { ADD,SUB,DIV,MUL };
//	// parr 是函数指针数组
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
// 添加功能
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
//	// 用函数指针数组后，简化了程序，方便功能的增添删改
//	// 转移表
//	// 
//	do
//	{
//		menu();
//		printf("选择->" );
//		scanf("%d", &input);
//		if (input == 0)
//		{
//			printf("退出计算器");
//		}
//		else if (input > 0 && input <= 4)
//		{
//			printf("请输入两个数：\n");
//			scanf("%d %d", &x, &y);
//			ret = pfarr[input](x, y);
//			printf("%d \n", ret);
//		}
//		else
//		{
//			printf("输入错误，请重新输入\n");
//		}
//
//		
//	} while (input);
//	return 0;
//}
//
//
//
// 7.指向函数指针数组的指针
//int main()
//{
//	
//	int (*parr[])(int, int) = { 0,ADD,SUB,MUL,DIV };
//	// 函数指针数组
//
//	int (*(*parr)[5])(int, int) = &parr;
//	// 指向函数指针数组的指针
//
//	return 0;
//}
//
// 
// 
// 8.回调函数
// 回调函数就是通过一个函数指针调用的函数。如果把函数的指针作为参数传递给另一个函数
// 当这个指针被用来调用其所指向的函数时，我们就说这是回调函数
// 回调函数不是由该函数的实现方直接调用，而是在特定的事件或条件发生时由另外一方调用的，用于对该时间或条件予以相应
//
// 冒泡排序
// 只能排序整形数据
//void bubble_sort(int arr[], int sz)
//{
//	int i = 0;
//	// 趟数
//	for (i = 0; i < sz; i++)
//	{
//		int flag = 1;
//		// 如果数组已经排好序，避免重复比较
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
//	// 把数组排成升序
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
// qsort 快速排序
//void qsort(void* base,    // 你要排序的数据的起始位置
//	size_t num,    // 待排序数据的个数
//	size_t width,  // 待排序数据元素的大小（单位是字节）
//	int(*cmp)(const void* e1, const void* e2) //函数指针—比较函数
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
	// 趟数
	for (i = 0; i < sz - 1; i++)
	{
		int flag = 1;
		// 如果数组已经排好序，避免重复比较
		// 
		int j = 0;
		for (j = 0; j < sz -1 - i; j++)
		{
			if (cmp((char*) base + j * width, (char*)base + (j + 1) * width) > 0)
			{  
				// 交换
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
	return (*(int*)e1 - *(int*)e2);   // 升序
	//return (*(int*)e2 - *(int*)e1); // 降序
}
void test1()
{
	int arr[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, sz, sizeof(arr[0]), cmp_int);
	// 回调函数实现排序功能
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}
// 排序字符型
int cmp_stu_by_name(const void* e1, const void* e2)
{
	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
}
 // 排序整型
int cmp_stu_by_age(const void* e1, const void* e2)
{
	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
}
void test2()
{
	//使用 qsort 排序结构体顺序
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
	//使用 qsort 排序结构体顺序
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
//	//char* pa = &a;  // 报错，类型是 int型
//	void* pc = &a;
//	// void* 可以接收任何类型的地址
//	// 是是具体类型的指针，不能直接解引用和做 +-
//
//	return 0;
//}
#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
//
//// 1.枚举
//// 1.1 枚举的定义
//// 
//#define M 100
//enum day
//{
//	Mon=1, // 赋初始值
//	Tues,
//	Wed,
//	Thur,
//	Fri,
//	Sat,
//	Sun
//};
//struct s
//{
//	int a;
//	char c;
//};
//int main()
//{
//	//enum day d = Fri;  // 枚举是一种类型
//	//enum day s = 1;    // 严谨体现在 c++ 中
//	printf("%d\n", Mon);
//	printf("%d\n", Tues);
//	printf("%d\n", Wed);
//	printf("%d\n", Thur);
//	printf("%d\n", Fri);
//	printf("%d\n", Sat);
//	printf("%d\n", Sun);
//
//	return 0;
//}
//
//
//
// 1.2 枚举的优点
//     增加代码的可读性和可维护性
//	   和 define 相比，枚举有类型检查，更加严谨
//     为了防止命名污染
//	   便于调试
//	   使用方便，可以一次定义多个常量
// 
// 
// 
// 
// 1.3 枚举的使用
//







// 2.联合（共用体）
// 2.1 联合类型的定义
//     联合也是自定义类型，这种类型定义的变量包含一系列的成员
//	   特征是这些变量共用一块内存空间
// 
// 2.2 联合的声明
// 
// 2.3 联合的特点
//     共用一块空间，改 a 的时候 c 也会改
//
//union un
//{
//	int a;
//	char c;
//};
//struct S
//{
//	int a;
//	char c;
//};
//int main()
//{
//	union un u;
//	//printf("%d\n", sizeof(u)); //4
//
//	//printf("%p\n", &(u.a));
//	//printf("%p\n", &(u.c)); 
//	//printf("%p\n", &u);
//
//	u.a = 0x11223344;
//	u.c = 0x00;
//	printf("%p\n", &(u.c));
//	return 0;
//}
//
// 
// 2.3 联合的特点
//     共用一块空间，改 a 的时候 c 也会改
//
//
// 判断机器的大小端存储
//int check_system()
//{
//	int a = 1;
//	return *(char*)&a;
//}
//int check_system()
//{
//	union un
//	{
//		int a;
//		char c;
//	}u;
//	u.a = 1;
//	return u.c;
//}
//int main()
//{
//	int a = 1;
//	int ret = check_system();
//	if (ret == 1)
//		printf("小端\n");
//	else
//		printf("大端\n");
//	return 0;
//}
// 
// 
// 
// 2.4 计算联合的大小
//     联合的大小至少是最大成员的大小
//	   当最大成员大小不是最大对齐数的整数倍时，就要对齐到最大对齐数的整数倍
//
//union Un
//{
//	char arr[5]; //5
//	int i;       //4
//};
//int main()
//{
//	printf("%d\n", sizeof(union Un));
//	return 0;
//}
//
// 
// 2.5 练习
//
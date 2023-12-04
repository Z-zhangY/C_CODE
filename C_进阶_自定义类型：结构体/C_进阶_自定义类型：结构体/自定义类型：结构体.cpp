#include<stdio.h>
#include<stddef.h>


// 复杂对象
// 自定义类型：结构体、枚举、联合
//
//
// 结构体
// 1.结构体的声明
// 1.1 结构体的基础知识
//     结构是一些值的集合，这些值称为成员变量
// 1.2 结构的声明
// 
// 结构体类型的定义
//struct Stu
//{
//	// 学生的相关属性
//	char name[20];
//	int age;
//
//}s1,s2;
//// s1 s2 是 struct Stu 的变量，全局变量
//int main()
//{
//	struct Stu s1 = { "zhangsan",20 };
//	return 0;
//}
// 
// 
// 1.3 特殊的声明
//     匿名结构体类型
//     只能用一次
//struct
//{
//	char name[20];
//	int age;
//}s1;
//struct
//{
//	char name[20];
//	int age;
//}a[20],*p;
//int main()
//{
//	p = &s1;
//	// 编译器会把两个声明的变量认为两种不同类型的变量
//	return 0;
//}
// 
// 
// 1.4 结构体的自引用
// 数据结构  
// 线性 顺序表，链表
// 树形 二叉树
// 
// 链表
//struct Node
//{
//	int data;            
//	struct Node* next;
//	// 拆成两个部分
//	// 数据域和指针域
//};
//
// 1
//typedef struct Node
//{
//	int data;
//	struct Node* next;
//}* linklist;
////
//// 2
//struct Node
//{
//	int data;
//	struct Node* next;
//};
//typedef struct Node* linklist;
// 
// 
// 1.5 结构体变量的定义和初始化
//struct Point
//{
//	int x;
//	int y;
//}p1 = { 2,3 };
//struct score
//{
//	int n;
//	char ch;
//};
//struct Stu
//{
//	char name[20];
//	int age;
//	struct score s2;
//};
//int main()
//{
//	struct Point p2 = { 2,3 };
//	struct Stu s1 = { "zhangsan",20 ,100,'q' };
//	printf("%s\n %d\n %d\n %c\n", s1.name, s1.age, s1.s2.n, s1.s2.ch);
//	return 0;
//}
// 
// 
// 1.6 结构体内存对齐
//     计算结构体大小
//
// 对齐规则
// .1.第一个成员在于结构体偏移量为 0 的地址处
// .2.其他成员变量要对齐到它自身对齐数的整数倍的地址处
//	  对齐数 = 编译器默认的对齐数与该成员大小的较小值
//	  每个成员都有它自己的对齐数 
//    VS 默认对齐数为 8
// .3.结构体总大小为最大对齐数的整数倍
// .4.如果嵌套了结构体的情况，嵌套的结构体对齐到自己的最大对齐数的整数倍处
//    结构体的整体大小就是所有最大对齐数（含嵌套结构体的对齐数）的整数倍
//
//struct S1
//{
//	char c1;
//	int i;
//	char c2;
//};
//struct S2
//{
//	char c1;	
//	char c2;
//	int i;
//};
//struct S3
//{
//	double d;
//	char c;
//	int i;
//};
//struct S4
//{
//	char c1;
//	struct S3 s3;
//	double d;
//};
//int main()
//{
//	printf("%d\n", sizeof(struct S1)); // 12    
//	printf("%d\n", sizeof(struct S2)); // 8
//	printf("%d\n", sizeof(struct S3)); // 16 
//	printf("%d\n", sizeof(struct S4));
//
//	printf("%d\n", offsetof(struct S1, c1));
//	printf("%d\n", offsetof(struct S1, i));
//	printf("%d\n", offsetof(struct S1, c2));
//
//	return 0;
//}
//
// 为什么存在内存对齐
// .1.平台原因（移植原因）：
// 不是所有平台都可以任意访问任意地址上的任意数据，某些平台只能访问特定地址
// .2.性能原因：
// 数据结构（尤其是栈），应该尽可能的在自然边界上对齐
// 为了访问未对齐的内存，处理器需要做两次访问，而对齐的内存只需要做一次访问
// 总的来说-- 内存对齐就是用空间换取时间的做法
// 如果让空间小的成员尽量集中在一起，可以减少内存空间的浪费
//
// 
// 
// 
// 1.7 修改默认对齐数
//#pragma pack(4)  // 设置开始生效
//struct S
//{
//	int i;
//	//自身大小 4 默认对齐数 8 对齐数 8
//	double d;
//	//自身大小 8 默认对齐数 8 对齐数 8
//};
//#pragma pack()  // 恢复默认值
////
//#pragma pack(1)   // 不对齐
//struct S1
//{
//	char c;
//	char c1;
//	int i;
//};
//int main()
//{
//	printf("%d\n", sizeof(struct S));
//	printf("%d\n", sizeof(struct S1));
//	return 0;
//}
// #pragma once 防止头文件被多次引用 
// 
// 
// 
// 1.8 结构体传参
//struct S
//{
//	int data[100];
//	int num;
//};
//void print1(struct S ss)
//{
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		printf("%d\n", ss.data[i]);
//	}
//	printf("%d\n", ss.num);
//}
//void print2(const struct S* ps)
//{
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		printf("%d\n", ps->data[i]);
//	}
//	printf("%d\n", ps->num);
//}
//int main()
//{
//	struct S s = { {1,2,3},100 };
//	print1(s);  //传值调用
//	//传值会把所有值都传过去，参数压栈，如果结构体过大，系统开销较大
//	//压栈：在栈区开辟空间把参数一个一个放进去
//
//	print2(&s); //传址调用
//	//地址只占 4 个字节空间
//
//	return 0;
//}
//
// 
// 
// 
// 2. 位段
// 2.1 什么是位段
//     位段的结构和结构是类似的
//     位段的成员必须是 int un_int  signed int
//     位段的成员后必须跟一个冒号和数字
//	   可以用来节省空间
//struct A
//{
//	int _a : 2;
//	int _b : 5;
//	int _c : 10;
//	int _d : 30;
//	//数字代表代表所需要的比特位
//};
////  47bit    6byte = 48bit
//// 
//int main()
//{
//	printf("%d\n", sizeof(struct A));
//	return 0;
//}
//
// 
// 
// 2.2 位段的内存分配
//   2.1 位段的成员可以是 int、 unsigned int、signed int 或 char
//	 2.2 如果是 int ，一次开辟 4 个字节，如果是 char，一次开辟 1 个字节
//   2.3 位段是不跨平台的
//
struct S
{
	char a : 3;
	char b : 4;
	char c : 5;
	char d : 4;
};
int main()
{
	struct S s = { 0 };
	//内存空间从左向右使用，会产生一定空间的浪费
	printf("%d\n", sizeof(struct S));
	s.a = 10;
	s.b = 12;
	s.c = 3;
	s.d = 4;
	return 0;
}
//
//
// 
// 2.3 位段的跨平台问题
//   3.1 int 位段被当成有符号还是无符号不确定
//   3.2 位段中的最大位数目不确定 （16位机器是16，32位机器是32位）
//   3.3 位段中的成员在内存中从左向右或者从右向左不确定
//   3.4 当一个结构包含两个位段时，第二个位段较大
//		 不能分配在第一个位段剩余空间时，是浪费还是利用不确定
//     可以很好的节省空间，但是存在跨平台问题
//
//  
// 2.4 位段的使用
//     网络协议和网络编程
//

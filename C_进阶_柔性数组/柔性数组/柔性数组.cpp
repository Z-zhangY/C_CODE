#include <stdio.h>
#include <string.h>
#include <stdlib.h>





//
// 柔性数组
// C99 中，结构中的最后一个元素允许是未知大小的数组，这就叫做柔性数组成员
// 
// 1.柔性数组
//
// 1.1柔性数组的特点
//    柔性数组成员前必须至少有一个其他成员
//    sizeof 返回的结构大小不包含柔性数组的内存
//	  包含柔性数组成员的结构用 malloc函数进行内存的动态分配
//	  并且内存的分配应该大于结构的大小，以适应柔性数组的预期大小
//typedef struct st_type
//{
//	int i;
//	int a[0]; // 柔性数组成员
//}type_a;
//int main()
//{
//	//printf("%d\n", sizeof(st_type));
//
//
//	//柔性数组的使用
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
//	//释放
//	free(ps);
//	return 0;
//}
//


//另一种方法
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
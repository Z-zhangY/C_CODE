#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<assert.h>


// 作业
//  1. 陷入死循环的原因
//
//int main()
//{
//	int i = 0;
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	for (i = 0; i <= 12; i++)
//	{
//		arr[i] = 0;
//		printf("hello world!\n");
//	}
//	return 0;
//}
//
//  1.1 模拟实现 strlen 函数
//int my_strlen(const char* str)
//{
//	int count = 0;
//	while (*str != '\0')
//	{
//		str++;
//		count++;
//	}
//	return count;
//}
//int main()
//{
//	char arr[] = { "abcdef" };
//	//int len = strlen(arr);
//	//printf("%d\n", len);
//
//	int a = my_strlen(arr);
//	printf("%d\n", a);
//	return 0;
//}
// 
// 1.2 模拟实现 strcpy
// strcpy(arr1,arr2)   将第二个字符数组的内容复制到第一个字符数组中
// 字符串结束标志 '\0' 也会一同拷贝
//char* my_strcpy(char* dest, const char* str)
//{
//	char* ret = dest;
//	assert(dest != NULL);
//	assert(str != NULL); 
//	while (*str)
//	{
//		*dest = *str;
//		dest++;
//		str++;
//	}
//	*dest = *str;
//	return ret;
//}
//int main()
//{
//	char arr[20];
//
//	my_strcpy(arr, "hello world");
//	printf("%s\n", arr);
//
//	return 0;
//}
//
// 1.3 模拟实现 strcat
char* my_strcat(char* str1, const char* str2)
{
	char* ret = str1;
	assert(*str1 && *str2);
	while (*str1 != '\0')
	{
		str1++;
	}
	while (*str1++ = *str2++)
	{
		;
	}
	return ret; 
}
int main()
{
	char arr1[20] = "hello";
	char arr2[] = " world!";
	my_strcat(arr1, arr2);
	printf("%s\n", arr1);
	return 0;

}
1.4  模拟实现 strcmp
int my_strcmp(const char* str1, const char* str2)
{
	assert(*str1 && *str2);
	while (*str1 == *str2)
	{
		if (*str1 == '\0')
		{
			return 0;
		}
		*str1++;
		*str2++;
	}
	if (*str1 > *str2)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}
int main()
{
	char arr1[20] = "zhangsan" ;
	char arr2[] = "zhangsanfeng";

	//int ret = strcmp(arr1, arr2);
	
	int ret = my_strcmp(arr1, arr2);
	if (ret < 0)
	{
		printf("<\n");
	}
	else if(ret == 0)
	{
		printf("==\n");
	}
	else 
	{
		printf(">\n");
	}
//
// 长度受限制函数
2.1  strncpy
 char * strncpy ( char * destination, const char * source, size_t num );
int main()
{
	char arr1[20] = { "abcdef" };
	char arr2[] = { "hello world!" };

	//strcpy(arr1, arr2);
	strncpy(arr1, arr2, 5);
	//如果字符不够，会用 \0 顶替

	return 0;
}
2.2 strncat
// char *strncat( char *strDest, const char *strSource, size_t count );
int main()
{
	//strncat
	char arr1[20] = "hello";
	char arr2[20] = "bit";
	strncat(arr1, arr2, 6);
	//需要几个字符追加几个字符，但会在结尾追加一个 \0
	return 0;
}
2.3 strncmp
int main()
{
	char arr1[] = "abcdef";
	char arr2[] = "abcd";
	int ret = strncmp(arr1, arr2, 5 );
	if (ret == 0)
	{
		printf("==\n");
	}
	else if (ret > 0)
	{
		printf(">\n");
	}
	else
	{
		printf("<\n");
	}
	return 0;
}
//
// 
// 调整奇偶数顺序
// 输入	一个整数数组，实现一个函数
// 调整数字顺序使得奇数位于数组的前半部分，偶数位于数组的后半部分
//
void move_odd_even(int arr[], int sz)
{
	int left = 0;
	int right = sz - 1;
	
	while (left < right)
	{
		while ((left < right) && (arr[left] % 2 == 1))
		{
			left++;
		}
		while ((left < right) && (arr[right]) % 2 == 0)
		{
			right--;
		}
		if (left < right)
		{
			int tmp = arr[left];
			arr[left] = arr[right];
			tmp = arr[right];
			left++;
			right--;
		}
	}
}
int main()
{
	int arr[10] = { 0 };
	int i = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	// 
	// 输入数据
	for (i = 0; i < sz; i++)
	{
		scanf("%d", &arr[i]);
	}
	// 调整数据
	move_odd_even(arr, sz);

	// 输出数据
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}

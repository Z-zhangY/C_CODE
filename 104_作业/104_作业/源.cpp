#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<assert.h>


// ��ҵ
//  1. ������ѭ����ԭ��
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
//  2.ģ��ʵ�� strlen ����
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
// 3.ģ��ʵ�� strcpy
// strcpy(arr1,arr2)   ���ڶ����ַ���������ݸ��Ƶ���һ���ַ�������
// �ַ���������־ '\0' Ҳ��һͬ����
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
// 4.
// ������ż��˳��
// ����	һ���������飬ʵ��һ������
// ��������˳��ʹ������λ�������ǰ�벿�֣�ż��λ������ĺ�벿��
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
	// ��������
	for (i = 0; i < sz; i++)
	{
		scanf("%d", &arr[i]);
	}
	// ��������
	move_odd_even(arr, sz);

	// �������
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<errno.h>
#include<ctype.h>   // �ַ����ຯ��
//
//  ����ͷ�ļ�
//  ��Ҫ�������ͷ�ļ������ͷ�ļ��������������ִ���
// 
// 
// 
// �ַ������ڴ溯��
//
//
//
// 1.��������
// 1.1 strlen
//     size_t(const char* str)
//     �������ͣ��޷�������
// 
//int main()
//{
//	char arr[] = "abcdef";
//	char arr1[] = { 'b','i','t' };
//	// abcdef\0
//	int len = strlen(arr);
//	int len1 = strlen(arr1);
//	printf("%d\n", len);
//	printf("%d\n", len1); // ���ֵ
//	return 0;
//}
//
//int main()
//{
//	if (strlen("abc") - strlen("abcdef") > 0)
//
//		// �����޷���������������޷������ͣ� >0
//	{
//		printf(">\n");
//	}
//	else
//	{
//		printf("<\n");  
//	}
//	return 0;
//}
//
//  ���Ȳ������ƺ���
//  strlen �� strcpy�� strcpm��strcat
// 
// 1.1.1ģ��ʵ�� strlen 
//     1.����������
//     2.ָ�롪ָ��
//     3.�ݹ�ķ�ʽ
//int my_strlen(const char* arr)
//{
//	int count = 0;
//	int i = 0;
//	while (arr[i] != 0)
//	{
//		i++;
//		count++;
//	}
//	return count;
//}
//size_t my_strlen(const char* arr)  // ֻ���ַ������ȣ����ı��ַ������ݣ������� const ����
//{
//	int count = 0;
//	assert(arr);
//	if (*arr != '\0')
//	{
//		count++;
//		arr++;
//	}
//}
//int main()
//{
//	char arr[] = "abcdef";
//	//int len = my_strlen(arr);
//	size_t n = my_strlen(arr);
//	//printf("%d\n", len);
//	printf("%u\n", n);
//	return 0;
//}
//
//
// 1.2. strcpy
// strcpy 
// char* strcpy(char* destination , const char* source)
//int main()
//{
//	char name[20] = { 0 };
//	// "zhangsan"
//	// 
//	char arr[] = { 'b','i','t' };
//
//	strcpy(name, "zhangsan");
//	//ʹ�ú���ʱ���ñ�֤�ַ����� \0 
//	//�ὫԴ�ַ����е� \0 ������Ŀ��ռ���
//	//��֤Ŀ��ռ��㹻��
//	//Ŀ��ռ�Ҫ���Է���
//
//	printf("%s\n", name);
//	return 0;
//}
//
// 1.2.1ģ��ʵ�� strcpy
//
//char* my_strcpy(char* str2, const char* str1)
//{
//	assert(str1);
//	assert(str2);
//	char* ret = str2;
//	while (*str2 != '\0')
//	{
//		*str2 = *str1;
//		str1++;
//		str2++;
//	}
//	*str2 = *str1;
//	return ret;
//}
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[20];
//	my_strcpy(arr2, arr1);
//	printf("%s\n", arr2);
//	return 0;
//}
//
//
//
// 1.3 strcat
//     �ַ���׷��
//	   �����Լ����Լ�׷��
//int main()
//{
//	char arr1[20] = "hello";
//	strcat(arr1, " world!");
//	//Ŀ��ռ�������㹻�ռ�
//	//Ŀ��ռ������޸�
//	//Դ�ַ��������� \0
//
//	printf("%s\n", arr1);
//	return 0;
//}
//
//
// 1.3.1 ģ��ʵ�� strcat
//char* my_strcat(char* str1, const char* str2)
//{
//	char* ret = str1;
//	assert(*str1 && *str2);
//	while (*str1 != '\0')
//	{
//		str1++;
//	}
//	while (*str1++ = *str2++)
//	{
//		;
//	}
//	return ret; 
//}
//int main()
//{
//	char arr1[20] = "hello";
//	char arr2[] = " world!";
//	my_strcat(arr1, arr2);
//	printf("%s\n", arr1);
//	return 0;
//
//} 
//
//
// 1.4 strcmp
//  int strcmp(const char*str1,const char* arr2)
// 1.4.1 ģ��ʵ�� strcmp
//int my_strcmp(const char* str1, const char* str2)
//{
//	assert(*str1 && *str2);
//	while (*str1 == *str2)
//	{
//		if (*str1 == '\0')
//		{
//			return 0;
//		}
//		*str1++;
//		*str2++;
//	}
//	if (*str1 > *str2)
//	{
//		return 1;
//	}
//	else
//	{
//		return -1;
//	}
//}
//int main()
//{
//	char arr1[20] = "zhangsan" ;
//	char arr2[] = "zhangsanfeng";
//
//	//int ret = strcmp(arr1, arr2);
//	
//	int ret = my_strcmp(arr1, arr2);
//	if (ret < 0)
//	{
//		printf("<\n");
//	}
//	else if(ret == 0)
//	{
//		printf("==\n");
//	}
//	else 
//	{
//		printf(">\n");
//	}
//	//�����ַ�����ȣ�Ӧ��ʹ�� strcmp
//	//�Ƚ�һ�����������Ƿ����
//	//arr1 ��������������������Ԫ�صĵ�ַ
//	//arr2 ��������������������Ԫ�صĵ�ַ
//	//if (arr1 == arr2)
//	//{
//	//	printf("==\n");
//	//}
//	//else
//	//{
//	//	printf("!=\n");
//	//}
//	return 0;
//}
//
//
// �����������ַ�������
// strncpy��strncat��strncmp
//
//
//
// 1.5 strncpy
// char * strncpy ( char * destination, const char * source, size_t num );
//int main()
//{
//	char arr1[20] = { "abcdef" };
//	char arr2[] = { "hello world!" };
//
//	//strcpy(arr1, arr2);
//	strncpy(arr1, arr2, 5);
//	//����ַ����������� \0 ����
//
//	return 0;
//}
//
//
// 1.5.1 ģ��ʵ�� ctrncpy
//
//
// 1.6 strncat
// char *strncat( char *strDest, const char *strSource, size_t count );
//int main()
//{
//	//strncat
//	char arr1[20] = "hello";
//	char arr2[20] = "bit";
//	strncat(arr1, arr2, 6);
//	//��Ҫ�����ַ�׷�Ӽ����ַ��������ڽ�β׷��һ�� \0
//	return 0;
//}
//
// 1.7 strncmp
//
//int main()
//{
//	char arr1[] = "abcdef";
//	char arr2[] = "abcd";
//	int ret = strncmp(arr1, arr2, 5 );
//	if (ret == 0)
//	{
//		printf("==\n");
//	}
//	else if (ret > 0)
//	{
//		printf(">\n");
//	}
//	else
//	{
//		printf("<\n");
//	}
//	return 0;
//}
//
//
//
// 1.8 strstr   �����ִ���һ������
// char *strstr( const char *string, const char *strCharSet );
// �����ִ���һ������
//int main()
//{
//	char email[] = "zjy@shanxizhongyiya.com";
//	char substr[] = "shanxizhongyiyao";
//	//����ҵ����Ӵ����᷵���Ӵ���ʼԪ�غ����Ԫ��
//	//���û�ҵ�������һ����ָ��
//	char* ret = strstr(email, substr);	
//	if (ret == NULL)
//	{
//		printf("�Ӵ�������\n");
//	}
//	else
//	{
//		printf("%p\n", ret);
//		printf("%s\n", ret);
//	}
//
//	return 0;
//}
//
//
// 1.8.1 ģ��ʵ�� strstr ����
//
// KMP- �㷨
// ��һ���ַ����в����Ӵ�
// �Ѷȴ�
// 
// 
//  �����ʵ��
//  ���һ�� s1 -> abcdef     s2 -> bcd  
//           ��һ��ƥ��ͳɹ�
//  ������� s1 -> abbbcdef   s2 -> bcd
//           ��b ��ʼƥ�䣬��һ�εڶ��ξ�����ɹ��������β���ƥ��ɹ�
//
//char* my_strstr(const char* str1, const char* str2)
//{
//	assert(str1 && str2);
//	const char* s1 = str1;
//	const char* s2 = str2;
//	const char* p = str1;
//	while (*p)
//	{
//		s1 = p;
//		s2 = str2;
//		while (*s1!='\0' && *s2!='\0' && * s1 == *s2)
//		{
//			s1++;
//			s2++;
//		}
//		if (*s2 == '\0')
//		{
//			return (char*)p;
//		}
//		p++;
//	}
//}
//int main()
//{
//	char email[] = "abbbcdef";
//	char substr[] = "dbcd";
//	char* ret = my_strstr(email, substr);
//	if (ret == NULL)
//	{
//		printf("�Ӵ�������\n");
//	}
//	else
//	{
//		printf("%s\n", ret);
//	}
//
//	return 0;
//}
//
//
// 1.9 strtok �и��ַ���
// char* strtok(char* str , const char* sep)
// sep �Ǹ��ַ����������������ָ������ַ��ϼ�
// ��һ������ָ��һ���ַ���
// strtok ������ı䱻�������ַ���
// ����и���ַ���Ϊ \0
//
//int main()
//{
//	const char* sep = "@.";
//	char email[] = "zzz30333zhang@zhang.com";
//	char cp[30];
//
//	strcpy(cp, email);
//	char* p = NULL;
//
//	//char* p = strtok(cp, sep);
//	//printf("%s\n", p);
//
//	//p = strtok(NULL,sep);
//	//printf("%s\n", p);
//
//	//p = strtok(NULL, sep);
//	//printf("%s\n", p);
//	for (p = strtok(cp, sep); p != NULL; p = strtok(NULL, sep))
//	{
//		printf("%s\n",p);
//	}
//	return 0;
//}
//
//
// 
// 1.10 strerror
// char* strerror(int errnum)
// ���ش���������Ӧ�Ĵ�����Ϣ
// C���Կ⺯����ִ��ʧ�ܵ�ʱ�򣬶������ô�����
// ������  0 1 2 3 4 5 ��
//
//
//int main()
//{
//	//printf("%s\n",strerror(0));
//	//printf("%s\n", strerror(1));
//	//printf("%s\n", strerror(2));
//	//printf("%s\n", strerror(3));
//	//printf("%s\n", strerror(4));
//
//	//errno
//
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;
//	}
//	else
//	{
//		//
//	}
//	return 0;
//}
//
// 
// �ַ����ຯ��
// iscntrl   �κο����ַ�
// isspace   �հ��ַ� 
// int isspace (int num)
//  ' '  '\t'  '\n'  '\v'  '\f'  '\r'  ������ǿհ��ַ������ط���ֵ
// isdigit	 ʮ�������� 0 - 9
// isxdigit  ʮ���������֣���������ʮ�������֣���д A-F,Сд a-f
// islower   Сд��ĸ a-z
// isupper   ��д��ĸ A-Z
// isalpha   ��ĸ a-z ���� A-Z
// isalnum   ��ĸ a-z A-Z �������� 0-9
// ispunct   ������
// isgraph   �κ�ͼ���ַ�
// isprint   �κοɴ�ӡ�ַ�
// int tolower   �ַ�ת����תСд
// int toupper   �ַ�ת����ת��д
// 
// 
//
//int main()
//{
//	//int a = isspace(' ');
//	//printf("%d\n", a);
//	//
//	//int a = isdigit('x');
//	//printf("%d\n", a);
//
//	printf("%c\n", tolower('W'));
//	return 0;
//}  
//
//
// 1.11 memcpy   �ڴ濽��
// void* memcpy(void* destination, const void* source, size_t num); 
// void* ����ָ�룬���Խ����κ�����
//
//int main()
//{
//	int arr1[] = { 1,2,3,4,5,6 };
//	int arr2[20] = { 0 };
//	memcpy(arr2, arr1, 24);
//
//	return 0;
//}
//
// 1.11.1 ģ��ʵ�� memcpy
// �ڴ�鿽�����ڴ����������ݵĿ���
// memcpy �����������ص��ڴ�֮��Ŀ���
// memmove �������ص��ڴ�֮��Ŀ���
//void* my_memcpy(void* str1, const void* str2, size_t num)
//{
//	assert(str1&& str2);
//	void* ret = str1;
//	while (num--)
//	{
//		*(char*)str1 = *(char*)str2;
//		//ǿ��ת��Ϊ char* ָ�룬�ֽ����ٵĵ�λ
//		str1 = (char*)str1 + 1;
//		str2 = (char*)str2 + 1;
//
//	}
//	return ret;
//}
//void test1()
//{
//	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int arr2[20] = { 0 };
//
//	int i = 0;
//	my_memcpy(arr2, arr1, 20);
//	// �� 1,2,3,4,5 ������  3,4,5,6,7
//
//	for (i = 0; i < 5; i++)
//	{
//		printf("%d\n", arr2[i]);
//	}
//
//}
//void test2()
//{
//	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
//	//int arr2[20] = { 0 };
//
//	int i = 0;
//	my_memcpy(arr1 + 2, arr1, 20);
//	// �� 1,2,3,4,5 ������  3,4,5,6,7
//
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d\n", arr1[i]);
//	}
//
//}
//int main()
//{
//	//test1();
//
//	test2();
//	// 1,2,1,2,1,2,1,8,9,10 
//	return 0;
//}
// 
// 
// 
// 1.12. memmove�����ص��ڴ�֮��Ŀ���
// void *memmove( void* dest,const void* src,size_t count);
//
//void test2()
//{
//	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int arr2[20] = { 0 };
//
//	int i = 0;
//	memmove(arr1 + 2, arr1, 20);
//	 �� 1,2,3,4,5 ������  3,4,5,6,7
//
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d\n", arr1[i]);
//	}
//
//}
//int main()
//{
//	test2();
//	 1,2,1,2,1,2,1,8,9,10 
//	return 0;
//}
// 
// 
// 1.12.1 ģ��ʵ�� memmove
// ���������ʱ����Ҫ��ǰ����������
//		   ��ʱ����Ҫ�Ӻ���ǰ��������
//		   dest ��λ������ src ��ǰ�棬��ǰ���󿽱�����֮��Ӻ���ǰ
//     
//void* my_memmove(void* str1, const void* str2, size_t num)
//{
//	assert(str1 && str2);
//	void* ret = str1;	
//	if (str1 < str2)
//	{
//		//��ǰ���
//		while (num--)
//		{
//			*(char*)str1 = *(char*)str2;
//			str1 = (char*)str1 + 1;
//			str2 = (char*)str2 + 1;
//		}
//
//	}
//	else
//	{
//		//�Ӻ���ǰ��
//		while (num--)
//		{
//			*((char*)str1 + num) = *((char*)str2 + num);
//		}	
//	}
//	return ret;
//}
//void test3()
//{
//	int i = 0;
//	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
//	my_memmove(arr1, arr1 + 2, 20);
//	//my_memmove(arr1 + 2, arr1, 20);
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d\n", arr1[i]);
//	}
//}
//int main()
//{
//	test3();
//	return 0;
//}
// 
// 
// 1.13 memcmp  �ڴ�Ƚ�
//  int memcmp  ( const void* buf1, const void* buf2,size_t count  )
//  ����ֵ  >0 <0 =0
//
//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[] = { 1,3,2 };
//	// 01 00 00 00 02 00 00 00 03 00 00 00
//	// 01 00 00 00 03 00 00 00 02 00 00 00
//	// ���ֽڳɶԱȽϣ������������Ȼ�����Ƚϣ���ǰ����
//	int ret = memcmp(arr1, arr2, 12);
//	printf("%d\n", ret);
//	return 0;
//}
// 
// 
// 
// 1.14 memset  �ڴ�����
// void *memset(void* dest,int c,size_t count);
// 
//int main()
//{
//	char arr[] = "hello bit";
//	//memset(&arr[2], 's', 5);
//	//printf("%s\n", arr);
//
//	//memset(arr + 3, 'x', 4);
//	//printf("%s\n", arr);
//
//	int arr1[10] = { 0 };
//	memset(arr1, '1', 40);
//	// �����ֽڽ������ã�40���ֽ�ȫ������Ϊ 1
//	// 01 01 01 01 
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d\n", arr1[i]);
//	}
//
//	return 0;
//}
// 
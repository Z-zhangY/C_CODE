#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<errno.h>
#include<ctype.h>   // 字符分类函数
//
//  关于头文件
//  不要随意添加头文件，如果头文件互相包含，会出现错误
// 
// 
// 
// 字符串和内存函数
//
//
//
// 1.函数介绍
// 1.1 strlen
//     size_t(const char* str)
//     返回类型，无符号整型
// 
//int main()
//{
//	char arr[] = "abcdef";
//	char arr1[] = { 'b','i','t' };
//	// abcdef\0
//	int len = strlen(arr);
//	int len1 = strlen(arr1);
//	printf("%d\n", len);
//	printf("%d\n", len1); // 随机值
//	return 0;
//}
//
//int main()
//{
//	if (strlen("abc") - strlen("abcdef") > 0)
//
//		// 两个无符号整型相减还是无符号整型， >0
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
//  长度不受限制函数
//  strlen 、 strcpy、 strcpm、strcat
// 
// 1.1.1模拟实现 strlen 
//     1.计数器方法
//     2.指针—指针
//     3.递归的方式
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
//size_t my_strlen(const char* arr)  // 只求字符串长度，不改变字符串内容，可以用 const 修饰
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
//	//使用函数时，得保证字符串有 \0 
//	//会将源字符串中的 \0 拷贝到目标空间中
//	//保证目标空间足够大
//	//目标空间要可以访问
//
//	printf("%s\n", name);
//	return 0;
//}
//
// 1.2.1模拟实现 strcpy
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
//     字符串追加
//	   不能自己给自己追加
//int main()
//{
//	char arr1[20] = "hello";
//	strcat(arr1, " world!");
//	//目标空间必须有足够空间
//	//目标空间必须可修改
//	//源字符串必须有 \0
//
//	printf("%s\n", arr1);
//	return 0;
//}
//
//
// 1.3.1 模拟实现 strcat
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
// 1.4.1 模拟实现 strcmp
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
//	//两个字符串相比，应该使用 strcmp
//	//比较一下两个数组是否相等
//	//arr1 是数组名，代表数组首元素的地址
//	//arr2 是数组名，代表数组首元素的地址
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
// 长度受限制字符串函数
// strncpy、strncat、strncmp
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
//	//如果字符不够，会用 \0 顶替
//
//	return 0;
//}
//
//
// 1.5.1 模拟实现 ctrncpy
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
//	//需要几个字符追加几个字符，但会在结尾追加一个 \0
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
// 1.8 strstr   查找字串的一个函数
// char *strstr( const char *string, const char *strCharSet );
// 查找字串的一个函数
//int main()
//{
//	char email[] = "zjy@shanxizhongyiya.com";
//	char substr[] = "shanxizhongyiyao";
//	//如果找到了子串，会返回子串起始元素后面的元素
//	//如果没找到，返回一个空指针
//	char* ret = strstr(email, substr);	
//	if (ret == NULL)
//	{
//		printf("子串不存在\n");
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
// 1.8.1 模拟实现 strstr 函数
//
// KMP- 算法
// 在一个字符串中查找子串
// 难度大
// 
// 
//  分情况实现
//  情况一： s1 -> abcdef     s2 -> bcd  
//           第一次匹配就成功
//  情况二： s1 -> abbbcdef   s2 -> bcd
//           从b 开始匹配，第一次第二次均不会成功，第三次才能匹配成功
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
//		printf("子串不存在\n");
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
// 1.9 strtok 切割字符串
// char* strtok(char* str , const char* sep)
// sep 是个字符串，定义了用作分隔符的字符合集
// 第一个参数指定一个字符串
// strtok 函数会改变被操作的字符串
// 会把切割的字符改为 \0
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
// 返回错误码所对应的错误信息
// C语言库函数在执行失败的时候，都会设置错误码
// 可能有  0 1 2 3 4 5 等
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
// 字符分类函数
// iscntrl   任何控制字符
// isspace   空白字符 
// int isspace (int num)
//  ' '  '\t'  '\n'  '\v'  '\f'  '\r'  如果不是空白字符，返回非零值
// isdigit	 十进制数字 0 - 9
// isxdigit  十六进制数字，包括所有十进制数字，大写 A-F,小写 a-f
// islower   小写字母 a-z
// isupper   大写字母 A-Z
// isalpha   字母 a-z 或者 A-Z
// isalnum   字母 a-z A-Z 或者数字 0-9
// ispunct   标点符号
// isgraph   任何图形字符
// isprint   任何可打印字符
// int tolower   字符转换，转小写
// int toupper   字符转换，转大写
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
// 1.11 memcpy   内存拷贝
// void* memcpy(void* destination, const void* source, size_t num); 
// void* 泛型指针，可以接收任何类型
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
// 1.11.1 模拟实现 memcpy
// 内存块拷贝，内存里任意内容的拷贝
// memcpy 不用来处理重叠内存之间的拷贝
// memmove 来处理重叠内存之间的拷贝
//void* my_memcpy(void* str1, const void* str2, size_t num)
//{
//	assert(str1&& str2);
//	void* ret = str1;
//	while (num--)
//	{
//		*(char*)str1 = *(char*)str2;
//		//强制转换为 char* 指针，字节最少的单位
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
//	// 将 1,2,3,4,5 拷贝到  3,4,5,6,7
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
//	// 将 1,2,3,4,5 拷贝到  3,4,5,6,7
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
// 1.12. memmove处理重叠内存之间的拷贝
// void *memmove( void* dest,const void* src,size_t count);
//
//void test2()
//{
//	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int arr2[20] = { 0 };
//
//	int i = 0;
//	memmove(arr1 + 2, arr1, 20);
//	 将 1,2,3,4,5 拷贝到  3,4,5,6,7
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
// 1.12.1 模拟实现 memmove
// 分情况，有时候需要从前往后处理数据
//		   有时候需要从后往前处理数据
//		   dest 的位置落在 src 的前面，从前往后拷贝，反之则从后往前
//     
//void* my_memmove(void* str1, const void* str2, size_t num)
//{
//	assert(str1 && str2);
//	void* ret = str1;	
//	if (str1 < str2)
//	{
//		//从前向后拷
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
//		//从后向前拷
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
// 1.13 memcmp  内存比较
//  int memcmp  ( const void* buf1, const void* buf2,size_t count  )
//  返回值  >0 <0 =0
//
//int main()
//{
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[] = { 1,3,2 };
//	// 01 00 00 00 02 00 00 00 03 00 00 00
//	// 01 00 00 00 03 00 00 00 02 00 00 00
//	// 按字节成对比较，如果遇到不相等会结束比较，提前返回
//	int ret = memcmp(arr1, arr2, 12);
//	printf("%d\n", ret);
//	return 0;
//}
// 
// 
// 
// 1.14 memset  内存设置
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
//	// 按照字节进行设置，40个字节全部设置为 1
//	// 01 01 01 01 
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d\n", arr1[i]);
//	}
//
//	return 0;
//}
// 
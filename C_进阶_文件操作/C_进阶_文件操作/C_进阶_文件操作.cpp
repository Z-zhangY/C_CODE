#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<errno.h>


//
// 文件操作
// 1.为什么使用文件
// 使用文件可以直接将数据存储到电脑的硬盘上，做到了数据的持久化
// 
// 2.什么是文件
// 
// 2.1程序文件
// 包括源程序文件（.c）  目标文件（.obj）   可执行程序（.exe）
// 
// 2.2数据文件
// 文件的内容不一定是程序，是程序运行时读写的数据  
// 比如程序运行需要从中读取数据的文件，或者输出内容的文件  
// 
// 2.3文件名
// 文件路径+文件名主干+文件后缀
// 
// 3.文件的打开和关闭
// 3.1文件指针
// 每个被使用的文件都会在内存中开辟相应的文件信息区，用来存放文件的相关信息，（如文件的名字、状态和当前位置等）
// 这些信息是保存在一个结构体变量中的，该结构体类型的系统声明为 FILE
// 我们可以创建一个 FILE 的指针维护 FILE 结构的变量
// 通过 FILE* pf 可以指向某个文件信息区
// 通过文件指针变量可以找到与它关联的文件
// 
// 3.2文件的打开和关闭
// 使用 fopen 打开文件  使用 fclose 关闭文件
// fopen
// FILE *fopen (const char* filename ,const char* mode)
// 
//int main()
//{
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	//
//	//读文件
//
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
//
// 字符输入函数 fgetc
//int main()
//{
//	FILE* pf = fopen("C:\\Users\\张佳尧\\OneDrive\\桌面\\test.txt", "w");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;
//	}
//
//	//写文件
//	char i = 'a';
//	for (i = 'a'; i <= 'z'; i++)
//	{
//		fputc(i, pf);
//	}
//		
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	//文件是资源，用完之后需要及时释放
//	//文件不关闭的话可能会造成信息泄露
//	return 0;
//}
// 
// 字符输出函数  fputc
//int main()
//{
//	FILE* pf = fopen("C:\\Users\\张佳尧\\OneDrive\\桌面\\test.txt", "r");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;
//	}
//
//	//int ch = fgetc(pf);
//	//printf("%c ", ch);
//
//	int ch = 0;
//	while ((ch = fgetc(pf)) != EOF)
//	{
//		printf("%c ", ch);
//	}
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}(
//
// 文本行输出函数 fputs
//int main()
//{
//	FILE* pf = fopen("C:\\Users\\张佳尧\\OneDrive\\桌面\\test.txt", "w");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;
//	}
//
//	//写文件
//	fputs("hello bit\n", pf);
//	fputs("hello bit\n", pf);
//	//如果文件里面有内容，会全部销毁
//	
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
//
// 文本行输入函数 fgets
//int main()
//{
//	FILE* pf = fopen("C:\\Users\\张佳尧\\OneDrive\\桌面\\test.txt", "r");
//	if (pf == NULL)
//	{
//		//printf("%s\n", strerror(errno));
//		perror("fopen");
//		return 1;
//	}
//
//	//读一行文件
//	char arr[20];
//	fgets(arr, 20, pf);
//	printf("%s\n", arr);
//	//最后一位 '\0'
//	//返回值是数组的首地址
//
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
//
//
//struct S
//{
//	char arr[20];
//	int age;
//	float score;
//};
//
// 
// 格式化输出函数 fprintf      写（输出）  把数据从内存上写到文件上
// int printf(FILE *stram,const char* format)
//int main()
//{
//	struct S zh = { "zhangsan",10,100.0 };
//	FILE* pf = fopen("C:\\Users\\张佳尧\\OneDrive\\桌面\\test.txt", "w");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	fprintf(pf, "%s %d %f", zh.arr, zh.age, zh.score);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
//
//
// 格式化输入函数 fscanf       读（输入）  把数据从文件中读到内存中
// int fscanf (FILE *stram,const char* format)
//int main()
//{
//	struct S zh = {0};
//	FILE* pf = fopen("C:\\Users\\张佳尧\\OneDrive\\桌面\\test.txt", "r");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	fscanf(pf,"%s %d %f", zh.arr, &(zh.age), &(zh.score));
//	printf("%s %d %f", zh.arr, zh.age, zh.score);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
//
//
// 流
// FILE*   文件流
// 
// 任何一个C程序，只要运行起来都会默认打开三个流
// FILE* stdin - 标准输入流 （键盘）
// FILE* stdout- 标准输出流 （屏幕）
// FILE* stderr -标准错误流 （屏幕） 
// 
// 将数据打印到屏幕上
//struct S
//{
//	char arr[20];
//	int age;
//	float score;
//};
//int main()
//{
//	struct S zh = { "zhangsan",10,100.0 };
//	FILE* pf = fopen("C:\\Users\\张佳尧\\OneDrive\\桌面\\test.txt", "w");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	fprintf(stdout, "%s %d %f", zh.arr, zh.age, zh.score);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
//
// 二进制输入和输出
// fread 
// fwrite
// size_t fwrite(    const void* buffer,    size_t size,    size_t count,  FILE* stream );
//                  要写的数据               元素大小        元素个数       
//
//struct S
//{
//	char arr[20];
//	int age;
//	float score;
//};
//int main()
//{
//	struct S zh = { "zhangsan",10,10.0 };
//	//以二进制形式写到文件中
//	FILE* pf = fopen("C:\\Users\\张佳尧\\OneDrive\\桌面\\test.txt", "wb");  //二进制的 write
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//  //以二进制方式写入
//	fwrite(&zh, sizeof(struct S), 1, pf);
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
//int main()
//{
//	struct S zh = { "zhangsan",10,10.0 };
//	//以二进制形式写到文件中
//	FILE* pf = fopen("C:\\Users\\张佳尧\\OneDrive\\桌面\\test.txt", "rb");  //二进制的 write
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//二进制方式读
//	fread(&zh, sizeof(struct S), 1, pf);
//	printf("%s %d %f", zh.arr, zh.age, zh.score);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
//
//
// sscanf   从一个字符串中转化出格式化的内容
// sprintf  把一个格式化的数据转化为字符串
//
// 序列化 
// 反序列化
//
//struct S
//{
//	char arr[20];
//	int age;
//	float score;
//};
//int main()
//{
//	struct S zh = { "zhangsan",10,10.0 };
//	struct S tmp = { 0 };
//	char buf[100] = { 0 };	
//	sprintf(buf, "%s %d %f", zh.arr, zh.age, zh.score);
//	//把一个格式化的数据转化为字符串
//	printf("%s\n", buf);
//
//	sscanf(buf, "%s %d %f", tmp.arr, &(tmp.age), &(tmp.score));
//	//从字符串BUF中获取格式化的数据放到 tmp 中
//	printf("%s %d %f \n", tmp.arr, tmp.age, tmp.score);
//	return 0;
//}
//
// 
// 5.文件的随机读写
// 5.1 fseek
// int fseek(    FILE* stream,    long offset,    int origin );
// 根据文件指针的位置和偏移量来定位文件指针
//
// 5.2 ftell
// 判断文件指针目前的偏移量 
// 
// 5.3 rewind 
// 让文件指针回到文件的初始位置
//
//
//int main()
//{
//	FILE* pf = fopen("C:\\Users\\张佳尧\\OneDrive\\桌面\\test.txt", "r");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;
//	}
//	//读文件
//	//fgetc 挨个读
//	fseek(pf, 2, SEEK_SET);
//	int ch = fgetc(pf);
//	printf("%c\n", ch);
//
//	fseek(pf, 2, SEEK_CUR);
//	ch = fgetc(pf);
//	printf("%c\n", ch);
//
//	fseek(pf, -1, SEEK_END);
//	printf("%c\n", ch);
//
//	
//	//ftell
//	//判断文件指针目前的偏移量
//	printf("%d\n", ftell(pf));
//
//	rewind(pf);
//	ch = fgetc(pf);
//	printf("%c\n", ch); 
//
//	fclose(pf);
//	pf = NULL;
//}
// 
// 
// 6.文本文件和二进制文件
//   数据文件贝称为文本文件或者二进制文件
//   在内存中以二进制存储，不加转换直接输出到外存，就是二进制文件
//   如果转换成ASCII形式输出，就是文本文件
//   字符一律以ASCII形式存储，数值型数据可以二进制储存，也可以ASCII形式存储
//  
//   10000  在内存中的存储形式是二进制 （00000000 00000000 00100111 00010000）
//          ASCII形式                  （00110001 00110000 00110000 00110000）
//          二进制形式                 （00000000 00000000 00100111 00010000）
//
//int main()
//{
//	int a = 10000;
//	FILE* pf = fopen("C:\\Users\\张佳尧\\OneDrive\\桌面\\test.txt", "wb");
//	fwrite(&a, 4, 1, pf);
//	fclose(pf);
//	pf = NULL; 
//	return 0;
//}
//
// 
// 
// 7.文件读取结束的判定
// 7.1 被错误使用的 feof
// feof 不是用来判断文件是否结束
//      而是应用于当文件读取结束后，判断是读取失败结束还是遇到文件尾结束
//   1.1文本文件是否读取结束，判断返回值是否为 EOF(fgetc),或者 NULL(fgets)
//      例如：fgets 判断是否为 NULL , fgetc 判断是否为 EOF
//   1.2二进制文件的读取结束判断，判断返回值是否小于要读的个数	
//      例如：fread 判断返回值是否小于实际读的个数
//
//int main()
//{
//	int c = 0;
//	FILE* pf = fopen("C:\\Users\\张佳尧\\OneDrive\\桌面\\test.txt", "r");
//	if (!pf)
//	{
//		perror("fopen");
//		return 0;
//	}
//	//fgetc 当读取失败的时候或者遇到文件结束的时候，返回 EOF
//	while ((c = fgetc(pf)) != EOF)
//	{
//		putchar(c);
//	}
//	
//	//判断是什么原因导致文件结束的
//	if (ferror(pf))   //判断读取的时候是否遇到错误
//	{
//		puts("I\O error when reading");
//	}
//	else
//	{
//		puts("End of file reached successfully");
//	}
//	fclose(pf);
//	return 0;
//}
//
// 
// 8.文件缓冲区
// 标准C采用“缓冲文件系统”处理的数据文件的，所谓缓冲文件系统是指系统自动的在内存中为程序正在使用的文件开辟一块“文件缓冲区”
// 从内存向磁盘输出数据会先送到内存中的缓冲区装满缓冲区后才一起送到磁盘上
// 如果从磁盘文件中读取数据，则从磁盘文件中读取数据输入到内存缓冲区，然后再从缓冲区逐个的将数据送到程序数据区
//

	

#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>




// 程序环境和预处理
// 1.程序的翻译环境和执行环境
// 1.1 翻译环境把源代码转换成可执行的机器指令然后在执行环境中执行
// 
// 2.详解编译+链接
// 2.1 翻译环境
// 源文件 -> 编译器 -> 目标文件
// 目标文件+链接库 -> 链接器 -> 可执行文件
// 
// test.c -> 预处理(test.i) -> 编译(test.s) ->
// 
// 2.3 编译的几个阶段
// 
// 预处理阶段 gcc test.c -E  ->  test.i （生成一个新的文件，包含了头文件，并完成以下步骤）
// 头文件的包含 #include
// #define 定义符号的替换，删除定义的符号
// 删除注释
// 
// 编译阶段  
// 把 C 语言代码转换成汇编代码（词法、语法、语义分析和符号汇总）
// 把汇编代码转换成二进制指令
// 符号汇总形成符号表 （test.o 文件）
// gcc test.c -S  跳过预编译，直接编译
// gcc test.i -S  预编译之后编译
// 生成的符号表会产生一个地址，在链接的时候用到
// 
// 链接阶段
// 合并段表
// test.o + 链接库  -> 可执行程序
//
// 
// 
// 2.3 运行环境
// 2.3.1 程序载入到内存中
// 在有操作系统的环境中，一般由操作系统完成。在独立系统中，手工完成，也可能是通过可执行代码置入可读内存完成
// 2.3.2 程序的执行开始，接着开始调用 main 函数
// 2.3.3 开始执行程序代码
// 这时候程序将使用一个运行时堆栈，存储函数的局部变量和返回地址。
// 程序同时也可以使用静态内存，存储于静态内存中的变量在程序的整个执行过程中一直保留他们的值
// 2.3.4 终止程序
// 正常终止 main 函数，也可能是意外终止	
// 





// 3.预处理
// 3.1 预定义符号
// __FILE__  进行编译的源文件
// __LINE__  文件当前的行号
// __DATE__  文件被编译的日期
// __TIME__  文件被编译的时间
// __STDC__  如果编译器遵循 ANSI C，其值为 1，否则未定义
//
//int main()
//{
//	int i = 0;
//	FILE* pf = fopen("C:\\Users\\张佳尧\\OneDrive\\桌面\\log.txt", "w");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	for (i = 0; i < 10; i++)
//	{
//		fprintf(pf,"file:%s  line=%d date:%s time:%s i=%d\n", __FILE__, __LINE__,__DATE__,__TIME__, i);
//		//  \  续航符
//	}
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
//
// 3.2 #define 
// 3.2.1 定义标识符
// 3.2.2 定义宏
// 宏的声明方式
// #define name(parament-list)stuff
// 其中的 parament-list 是一个由逗号隔开的符号表
// 参数列表左括号必须紧挨 name
// 
//#define SQUARE(X) X*X
////写宏的时候不要省括号
//int main()
//{
//	int r = SQUARE((5+1));
//	// int r = 5+1*5+1;
//	int a = SQUARE(5 + 1);
//	printf("%d\n", r);
//	printf("%d\n", a);
//	return 0;
//}
//
//#define DOUBLE(X) ((X)+(X))
//int main()
//{
//	int r = DOUBLE(3*2);
//	int a = 18 * DOUBLE(3);
//	// int a=18*(3)+(3)
//	printf("%d\n", r);
//	return 0;
//} 
// 3.2.3 #define 替换规则
// 在调用宏时，首先对参数进行检查，看看是否包含由 #define 定义的符号，如果是，他们首先被替换
// 替换文本随后被插入到程序中原来文本的位置。对于宏，参数名被他们的值所替换
// 最后，再次对结果文件进行扫描，看看它是否
// 
//#define DOUBLE(X) ((X)+(X))
//#define ADD(X,Y) ((X)+(Y))
//#define M 100
//int main()
//{
//	DOUBLE(M + 2);
//	int a = ADD(M,100);
//	printf("%d\n", a);
//	return 0;
//}
//
//
// 3.2.4 #和##
//#define PRINT(N) printf("the value of "#N" is %d\n",N)
//               printf("the value of ""a"" is %d\n,N)  
//               #N 会转换成 "a",然后字符串自动合并
//int main()
//{
//	int a = 10;
//	PRINT(a);
//
//	int b = 10;
//	PRINT(b);
//	return 0;
//}
//
// 打印两种不同类型的数据
//#define PRINT(N,FORMAT) printf("the value of "#N" is" FORMAT "\n",N)
//int main()
//{
//	int a = 10;
//	PRINT(a, "%d");
//
//	float b = 3.14;
//	PRINT(b,  "%lf");
//	return 0;
//}
//
//
// ## 可以把位于它两边的符号合成一个符号
// 它允许宏定义从分离的文本片段创建标识符
//#define CAT(Class,Num) Class##Num
//int main()
//{
//	int Class1 = 100;	
//	printf("%d\n", CAT(Class, 1));
//	printf("%d\n", Class1);
//	return 0;
//}
// 
// 
// 3.2.5 带副作用的宏
// 
//#define MAX(a,b) ((a)>(b)?(a):(b))
//int main()
//{
//	//int a = 10;
//	//int b = a + 1;
//	//int b = ++a;  // 运行完之后 a 的值也变了
//	
//	//int r = MAX(2, 3);
//	//printf("%d\n", r);
//	int a = 2;
//	int b = 3;
//	int m = MAX(a++, b++);
//	printf("%d\n", m); 
//	return 0;
//}
//
// 3.2.6 宏和函数
// 优点：
// 函数需要调用 传参 计算 返回
// 宏直接可以计算
// 函数只能在类型合适的表达式上使用
// 宏是类型无关的
// 缺点：
// 每调用一次宏的时候，一份宏定义的代码将插入到程序中，增加了代码的冗余程度
// 宏是无法调试的
// 由于类型无关，不够严谨
// 可能会带来运算符优先级的问题
// 
//#define MAX(a,b) ((a)>(b)?(a):(b))
//int ADD(int x, int y)
//{
//	return x > y ? x : y;
//}
//int main()
//{
//	int r = MAX(2, 3);
//	printf("%d\n", r);
//
//	int d = ADD(2, 3);
//	printf("%d\n", d);
//	return 0;
//}
//#define MALLOC(Num,Type) (Type*)malloc(Num*sizeof(Type))
//int main()
//{
//	//malloc(40);
//	//malloc(10, int);
//
//	int *p = MALLOC(10, int);
//	return 0;
//}
//
// 
// 
// 3.2.7 命名约定
// 宏名全部大写
// 函数名不全大写
// 
// 
// 
// 3.3 #undef 移除一个定义
//#define M 100
//int main()
//{
//	printf("%d\n", M);
//#undef M;
//	printf("%d\n", M);
//	return 0;
//}
// 
// 
// 3.4 命名行定义
// 允许在编译的时候给某一些符号指定值
// 
// 3.5 条件编译
// 通过某些有效的调节控制代码的参与
//#define __DEBUG__
//int main()
//{
//	int i = 0;
//	int arr[10] = { 0 };
//	for (i = 0; i < 10; i++)
//	{
//		arr[i] = i;
//#ifdef __DEBUG__
//		printf("%d\n", arr[i]);
//#endif __DEBUG__
//	}
//	return 0;
//}
// 常见的条件编译指令
// #if 常量表达式
// #ifdef 如果条件为真参与编译
// ……
// #endif
//
//int main()
//{
//#if 1==3
//	printf("%d\n", 2);
//#endif 
//	return 0;
//}
//
// 多个分支的条件编译
// #if 常量表达式
// #elif 
// #else
// #endif
// 
// 
// 判断是否被定义
// #if defined(symbol)
// #ifdef symbol
//
//#define MAX 3
int main()
{
#if defined MAX
	printf("max\n");	
#endif
	return 0;
}
#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#include<math.h>
#include<string.h>
// ** 重点
// 1.函数是什么
// 由一个或多个语句块组成，负责完成某项特定任务，具有相对的独立性
// 一般会有输入参数并有返回值提供对过程的封装和对细节的隐藏，这些代码通常被集成为软件库
//
// 2.函数的分类  (库函数、自定义函数）
// 
// 2.1库函数
// 2.1.1 如何学会使用库函数
// 查询工具 MSDN
// www.cplusplus.com    http://en.cppreference.com   http://zh.cppreference.com   
// 
// 3.自定义函数(函数名 返回值类型 函数参数	)
//  写一个函数，找出两个数的最大值
//int MAX(int x,int y)
//{
//	return(x > y ? x: y);
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf_s("%d %d", &a, &b);
//	int m = MAX(a, b);
//	printf("%d\n", m);
//	return 0;
//}
// 写一个函数，交换两个整型变量的内容
//void Swap(int* px, int* py)   // 形式参数
//{
//	int m = *px;
//	*px = *py;
//	*py = m;
//}
//当实际参数传递给形式参数的时候，形参是实参的一份临时拷贝
//对形参的修改，不会影响实参
//int main()
//{
//	int a = 0;           // 实际参数
//	int b = 0;
//	scanf_s("%d%d", &a, &b);
//	Swap(&a, &b);
//	printf("%d %d\n", a, b);
//	return 0;
//}
// 
// 4.函数参数 (实际参数、形式参数)
// 实参：真实传给函数的参数，叫实参。如常量、变量、表达式、函数等。
// 无论实参是何种类型，他们调用的时候都必须有确定的值，以便把这些值传给形参 
// 形参：是指函数名后括号中的变量，因为形式参数只在函数调用的过程中实例化（分配内存单元）
// 形参实例化后是实参的一份临时拷贝
// 形式参数调用后自动销毁，因此形参只在函数范围内有效
// 
// 5.函数调用
// 5.1传值调用
// 传址调用时，函数的实参和形参分别占有不同的内存块，对形参的修改不会影响实参
// Swap1 为传值调用，Swap2 为传址调用
// 5.2传址调用
// 传址调用是把在函数外部创建变量的内存地址传递给函数参数的一种调用函数的方式
// 这种传参方式可以让函数和函数外部的变量建立起真正的练习，函数内部可以直接操作函数外部的变量
//void Swap1(int x, int y)
//{
//	int z = 0;
//	z = x;
//	x = y;
//	y = z;
//}
//void Swap2(int* px, int* py)
//{
//	int z = 0;
//	z = *px;
//	*px = *py;
//	*py = z;
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf_s("%d %d", &a, &b);
//	Swap1(a, b);
//	Swap2(&a, &b);
//	printf("%d,%d\n", a, b);
//	return 0;
//}
// 5.3 练习
// 5.3.1
// 写一个函数判断是不是素数
//int is_prime(int n)
//{
//	int j = 0;
//	for(j = 2 ; j <= sqrt(n) ; j ++)
//	{
//		if (n % j == 0)
//			return 0;
//	}
//	return 1;
//
//}
//int main()
//{
//	int a = 0;
//	int count = 0;
//	for (a = 101; a <= 200; a += 2)
//	{
//		if (is_prime(a))
//		{
//			printf("%d ", a);
//			count++;
//		}
//	}
//	printf("%d\n", count);
//	return 0;
//}
// 打印 100到200 之间的素数
//int main()
//{
//	int a = 0;
//	int count = 0;
//	for (a = 100; a <= 200; a++)
//		//偶数不可能是素数，所以 a 从 101 开始，并且 +=2，减少计算量
//	{
//		int flag = 1;
//		int j = 0;
//
//			//判断 a 是否为素数
//			//是素数就打印
//			//用 2～a-1 之间的数字去试除 a
//		for (j = 2; j <= a - 1; j++)
//		//在这里可将 j<=a-1 替换成 j<=sqrt(a)
//		//sqrt 代表开平方，
//		{
//			if (a % j == 0)
//			{
//				flag = 0;
//				break;
//			}
//		}
//		if (flag == 1)
//		{
//			count++;
//			printf("%d\n", a);
//		}
//	}
//	printf("%d\n", count);
//	return 0;
//}
// 5.3.2
// 打印 1000～2000 年之间的闰年
// 写法1
//int main()
//{
//	int a = 0;
//	int j = 0;
//	for (a = 1000; a <= 2000; a+=2)
//	{
//		if ((a % 4 == 0 && a % 100 != 0) || a % 400 == 0)
//		{
//			printf("%d\n", a);
//		}
//	}
//	return 0;
//}
// 写法2
//int main()
//{	
//	int a = 0;
//	for (a = 1000; a <= 2000; a += 2)
//	{
//		if (a % 4 == 0)
//		{
//			if (a % 10 != 0)
//			{
//				printf("%d\n", a);
//			}
//		}
//		if (a % 400 == 0)
//		{
//			printf("%d\n", a);
//		}
//	}
//	return 0;
//}
// 写法3 函数
//int is_leapyear(int i)
//{
//	if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)
//	{
//		return 1;
//	}
//	else
//		return 0;
//}
//int main()
//{
//	int a = 0;
//	for (a = 1000; a <= 2000; a += 2)
//	{
//		if (is_leapyear(a))
//		{
//			printf("%d\n", a);
//		}
//	}
//	return 0;
//}
// 5.3.3 
// 写一个函数，实现一个整型有序数组的二分查找
//int binary_search(int arr[], int k, int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	while (left <= right)
//	{
//		int mid = left + (right - left) / 2;
//		if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			return mid;
//		}
//	}
//	return -1;
//}
//// 数组在向函数传参时，并不会拷贝全部数据，只会传数组首元素的地址过去
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k = 7 ;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	// 如果找到了，返回下标
//	// 找不到，返回 -1；不能返回 0；
//
//	int ret = binary_search(arr, k, sz);
//	if (ret == -1)
//	{
//		printf("找不到\n");
//	}
//	else
//	{
//		printf("找到了，下标是：%d\n", ret);
//	}
//	return 0;
//}
// bool 类型，直接返回真假
// 5.3.4
// 写一个函数，每调用一次这个函数，就会将 num 的值 +1
// 写法1
//void ADD(int* p)
//{
//	(*p)++;
//}
//int main()
//{
//	int num = 0;
//	ADD(&num);
//	printf("%d\n", num); // 1
//	ADD(&num);
//	printf("%d\n", num); // 1
//	ADD(&num);
//	printf("%d\n", num); // 1	
//	return 0;
//}
// 写法2
//int ADD(int n)
//{
//	return n + 1;
//}
//int main()
//{
//	int num = 0;
//	num = ADD(num);
//	printf("%d\n", num);
//	num = ADD(num);
//	printf("%d\n", num);
//	return 0;
//}
// 6.函数的嵌套调用和链式访问
// 6.1 嵌套调用
// 函数只能单独定义，不能嵌套定义
// 
// 6.2 链式访问
// 链式访问的前提是函数得有返回值
// 函数不写返回值的时候默认返回是 int 
// 如果规定了函数的返回值类型但是不返回的的话，函数会返回最后一条指令的执行结果
// 明确的说，main 函数不需要参数
// 本质上 main 函数是有参数的
// main 函数有 3 个参数

//int main()
//{
//	char x[] = { "abcdef" };
//	int len = strlen(x);
//	printf("%d\n", len);
//	printf("%d\n", strlen(x));
//	// stelen 的返回值时一个无符号整型，它的返回值刚好做了 printf 函数的一个参数
//	// 这种就是链式访问
//	printf("%d", printf("%d", printf("%d", 43)));
//	// 打印出来的值为 4321
//	// printf 函数的返回值为所打印字符的个数
//	return 0;
//}
// 7.函数的声明和定义
// 7.1 函数声明：
//     告诉诉编译器有一个函数叫什么，参数是什么，返回类型是什么，
//     但具体有没有这个函数，函数声明决定不了，如果函数不存在，则函数声明无意义
//     函数的声明一般出现在函数使用之前，要满足先声明，后使用
//     函数的声明一般要放在头文件中的
// #include"Add.h"    // 头文件的包含等于声明
// #include"sub.h"
// 自己的头文件只需要用双引号即可	
// 初学编程时，觉得把所有代码写在一个文件里最好
// 1. 各个模块是不同的人负责，最后只需要拼装即可
// 2.模块化，方便多人协作
// 可以把 Add.c 编成静态库，隐藏自己的代码
// 导入静态库的方法 #program comment（lib."Add.lib"）
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf_s("%d %d", &a, &b);
//	int sum = Add(a, b);
//	int ret = sub(a, b);
//	printf("%d\n", ret);
//	printf("%d\n", sum);
//	return 0;
//}
// 7.2 函数定义
// 交代函数的功能实现
 // 举例 计算器
// 8.函数递归
// 程序调用自身的编程技巧叫做递归
// 一个过程或函数在定义或说明中有直接或间接调用自身的方法
// 大型复杂问题化为与原问题相似的小问题
// 核心思想：大事化小
// 8.1 递归的两个限制条件
// 存在限制条件，当满足限制条件后，递归停止
// 每次递归之后越来越接近这个限制条件
// 8.2.1 练习
// 接受一个无符号整型值，按照顺序打印它的每一位
// 写法一
//int main()
//{
//	unsigned int num = 0;
//	scanf_s("%u", &num);
//	while (num)
//	{
//		printf("%d ", num % 10);
//		num = num/10;
//	}
//	printf("%s\n", o);
//	return 0;
//}
// 写法二
//void print(unsigned int n)       
//{
//	if (n > 9)                // 主函数中输入 1234 >9，进入循环   这条语句是递归的停止条件
//	{
//		print(n / 10);        // 进入之后还是调用自身，n\10 后 1234 变为 123 以此类推
//	}
//	printf("%d ", n % 10);    // 一直除到第一位，返回来依次打印  先递后归，进入到最里面，再出来	
//}
//// 如果没有 if 语句，会出现栈区溢出 死递归  （stack overflow）
//// 栈区存放局部变量，和函数的形参 ，每一次函数调用都会在栈区申请空间
//int main()
//{
//	unsigned int num = 0;
//	scanf_s("%d", &num);
//	print(num);
//	return 0;
//}
// 8.2.2练习二
// 编写函数不允许创建临时变量
// int my_strlen(char str[])  两者效果一样，代表的都是数组中首位元素的地址
//int my_strlen(char* str)
//{
//	int count = 0;                 
//	// count 计数器，临时变量，用完销毁
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//int main()
//{
//	char arr[] = "abc";
//	int len = my_strlen(arr);
//	printf("%d\n ", len);
//	return 0;
//}
// 递归写法
//int my_strlen(char* str)
//{
//	if (str != '\0')
//	{
//		return 1 + my_strlen(str + 1);  // str 在第一层处于 a 的位置，+1 之后到了 b 的地址
//	}
//	else
//	{
//		return 0;
//	}
//}
//int main()
//{
//	char arr[] = "abc";
//	int len = my_strlen(arr);
//	printf("%d\n ", len);
//	return 0;
//}
// 8.3.1
// 递归与迭代
// n 的阶乘
// 递归实现
//int fac(int n)                   
//{
//	if (n <= 1)
//		return 1;
//	else
//		return n * fac(n - 1);
//}
// 
//迭代实现  --- 非递归
//int fac(int n)
//{
//	int ret = 1;
//	int i = 0;
//	for (i = 1; i < n; i++)
//	{
//		ret *= i;
//	}
//}
//int main()
//{
//	int i = 0;
//	scanf_s("%d", &i);
//	int z = fac(i);
//	printf("%d\n", z);
//	return 0;
//}
//
// 8.3.2
// 求第 n 个斐波那契数
// 斐波那契数列     1，1，2，3，5，8 ......
//int fib(int x)
//{
//	if (x <= 2)
//	{
//		return 1;
//	}
//	else
//	{
//		return fib(x - 2) + fib(x - 1);
//	}
//}
// 其中有大量的重复运算，容易出现栈溢出现象
// 这种运算不适用于递归的方法
//int fib(int x)
//{
//	while (x > 3)
//	{
//		int a = 1;
//		int b = 1;
//		int c = 0;
//		c= a + b;
//		a = b;
//		b = c;
//		x--;
//	}
//	return c;
//}
//int main()
//{
//	int n = 0;
//	scanf_s("%d", &n);
//	int z = fib(n);
//	printf("%d\n", z);
//	return 0;
//}
//
//void test(int n)
//{
//	if (n < 10000)
//	{
//		test(n + 1);
//	}
//}
//int main()
//{
//	test(1);
//	return 0;
//}
//
// 如何解决栈溢出的情况
// 1.将递归改写为非递归
// 2.使用 static（静态）对象替代 nonstatic 局部对象，将部分数据转移到静态区
//
// 自主研究 1.汉诺塔问题  2. 青蛙跳台阶问题


// 4.24 作业
// 1.下面函数的输出结果
//int main()
//{
//	int i = 0;
//	for (i = 0; i <= 10; i++)
//	{
//		if (i = 5)   // 这里不是判断而是赋值，i=5 为真 i 总是 5 和 6 循环
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}
// 死循环的打印 5
// 
// 2.关于 if 语句说法正确的
// if 语句后面可以跟多条语句										   √
// if 语句中 0 表示假，非 0 表示真									   √
// if 语句可以实现单条分支，也可以实现多分支						   √
//
// 3.关于 switch 语句说法不正确的是
// switch 语句中的 default 子句可以放在任何位置						   √
// 在同意逻辑里，default 子句可以与其他语句任意调换
//int main()
//{
//	int n = 0;
//	scanf_s("%d", &n);
//	switch (n)
//	{
//	case 1:
//		printf("1\n");
//		break;
//	case 2:
//		printf("%d\n");
//		break;
//	default:
//		printf("hehe\n");
//	}
//	return 0;
//}
// switch 语句中的 case 后面的表达式只能是整型常量的表达式             √
// char 也是属于整型家族的，因为字符存储的时侯存的是 ASCII 
// switch 语句中的 case 语句必须在 default 子句之前                    ×
// switch 语句中的 case 表达式不要求顺序
// 4. int func(1) 的结果是 b=0
//int func(int a)
//{
//	int b;
//	switch (a)
//	{
//	case 1:
//		b = 30;
//	case 2:
//		b = 20;
//	case 3:		  
//		b = 16;
//	default:     
//		b = 0;
//	}
//	return b;
//}
// a 是几从情况几进去，因为没有遇到 break 跳出来，所以一直走完所有语句
// 5.switch（c） 中，c 的类型只能是整型
//
// 6.下面代码的执行结果
//int main()
//{
//	int x = 3;
//	int y = 3;
//	switch (x % 2)
//	{
//	case 1:
//		switch (y)
//		{
//		case 0:
//			printf("first");
//		case 1:
//			printf("second");
//			break;
//		default:printf("hello");
//		}
//	case 2:
//		printf("third");
//	}
//	return 0;
//}
// 7.从小到大输出三个整数
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	int i = 0;
//	scanf_s("%d %d %d", &a, &b, &c);
//	if (a < b)
//	{
//		i = a;
//		a = b;
//		b = i;
//	}
//	if (a < c)
//	{
//		i = a;
//		a = c;
//		c = i;
//	}
//	if(b<c)
//	{
//		i = b;
//		b = c;
//		c = i;
//	}
//
//	printf("%d %d %d\n", a, b, c);
//	return 0;
//}
// 函数解决
//int swap(int* px, int* py)
//{
//	int i = *px;
//	*px = *py;
//	*py = i;
//	return *px ,*py;
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	scanf_s("%d %d %d", &a, &b, &c);
//	if (a > b)
//	{
//		swap(&a, &b);
//	}
//	if (a > c)
//	{
//		swap(&a, &c);
//	}
//	if(b>c)
//	{
//		swap(&b, &c);
//	}
//	printf("%d %d %d\n", a, b, c);
//	return 0;
//}
// 8. 写一个代码，打印 1～100之间 3 的倍数
//int main()
//{
//	int i = 0;
	//for (i = 1; i <= 100; i++)
	//{
	//	if (i % 3 == 0)
	//	{
	//		printf("%d\n", i);
	//	}
	//}
//	for (i = 3; i <= 100; i += 3)
//	{
//		printf("%d\n", i);
//	}
//	return 0;
//}
// 9.给定两个数，求最大公约数
// 第一个是求公约数，第二个求最大公约数
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	scanf_s("%d %d", &a, &b);
//	//for (i = 1; i <= 100; i++)
//	//{
//	//	if (a % i == 0 && b % i == 0)
//	//		printf("%d\n", i);
//	//}
//	// 辗转相除法
//	while (a % b)
//	{
//		c = a % b;
//		a = b;
//		b = c;
//	}
//	printf("%d\n",b);
//	return 0;
//}
// 10. 打印1000～2000 之间的闰年
// 
// 1. while 循环 条件式总是比循环体执行次数多一次
// 2.continue 的作用是跳过循环体中尚未执行的语句，执行下一次循环判定
// 3.编写程序数一下 1～100 所有整数出现多少次数字 9
//int main()
//{
//	unsigned int i = 0;
//	int a = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 10 == 9)
//		{
//			a += 1;
//		}
//		if (i / 10 == 9)
//		{
//			a += 1;
//		}
//	}
//	printf("%d\n", a);
//
//	return 0;
//}
// 4.计算出 1/1 + 1/2 - 1/3 + ……+ 1/99 -1/100 的值
//int main()
//{		
//	int i = 0;
//	double ret = 0;
//	int flag = 1;
//	for (i = 1; i <= 100; i++)
//	{
//		ret = ret + flag*(1.0/i);
//		// 除号两端都是整型，得到的结果也是整型
//		int flag = -flag;
//	}
//	// 也可以利用分部求和
//	printf("%lf\n", ret);
//	return 0;
//}
// 5.求 10 个整数中的最大值
//int main()
//{
//	int arr[10] = { 0 };
//	// 如果这里没有指定元素个数，就会根据初始内容来推定元素个数
//	int i = 0;
//	for (i = 1; i < 10; i++)
//	{
//		scanf_s("%d", &arr[i]);
//	}
//	int max = arr[0];
//	for (i = 1; i <= 10; i++) 
//	{
//		if (arr[i] > max)
//		{
//			max = arr[i];
//		}
//	}
//	printf("%d\n", max);
//}
// 6.在屏幕上输出 9*9 乘法表
// 1*1
// 1*2  2*2
// 1*3  2*3   3*3
// ……
//int main()
//{
//	int i = 0;
//	for (i = 1; i <= 9; i++)
//	{
//		int j = 0;
//		for (j = 1; j <= i; j++)
//		{
//			printf("%d*%d=%-2d", i, j, i * j);
//		}			
//		printf("\n");
//	}
//	return 0;
//}
//
// 函数作业
// 1.关于实参和形参描述错误的是
// 形参是实参的一份临时拷贝
// 函数调用如果采用传值调用，改变形参不影响实参
// 形参在函数调用的时候才实例化，才开辟空间           √
// 改变形参就是改变实参                               ×
// 
// 2.函数调用 exec（（v1，v2），（v3，v4），v5，v6）   逗号表达式 实际参数是 4 个
// 3.以下关于函数设计不正确的是
// 函数设计应该追求高内聚低耦合
// 函数参数不宜过多
// 设计函数时，尽量做到谁申请的资源由谁释放
// 要尽可能多的使用全局变量                           ×
// 4.关于 C语言描述正确的是
// 函数必有参数和返回值
// 函数的实参只能是变量
// 库函数的使用必须要包含对应的头文件
// 有了库函数就不要自定函数了
// 5.C语言规定，在一个源程序中，main函数的位置可以是任意
// 6.以下描述是正确的是
// 在不同的函数中可以使用相同名字的变量             √
// 函数的形参是保存在栈中         
// 内存划分为 栈区（局部变量 形式参数 返回值 ） 堆区（malloc  free calloc realoc ） 静态区 （静态 全局变量）
// 一个函数的内定义变量只在本函数内部有用
// 在一个函数内复合语句中定义的变量在本函数范围内有效（复合函数指函数中成对括号构成的代码）
// 实现一个函数，打印乘法口诀表，口诀表的行数和列数自己定
//void print_table(int n)
//{	
//	int i = 0;
//	for (i = 1; i <= n; i++)
//
//	{
//		int j = 0;
//		for (j = 1; j <= i; j++)
//		{
//			printf("%d*%d=%-2d", i, j, i * j);
//		}
//		printf("\n"); 
//	}
//}
//int main()
//{
//	int n = 0;
//	scanf_s("%d",&n);
//	print_table(n); 
//	return 0;
//}
//
// 1.能把函数处理结果的两个数据返回给主调函数，下面方法正确的是
// return 这两个数  
// return 在这用的是逗号表达式，从左往右计算只返回最后一个结果
// 形参用数组
//void test(int arr[])
//{
//	arr[0] = 3;
//	arr[1] = 4;
//}
//int main()
//{
//	int arr[] = { 0 };
//	test(arr);
//	return 0;
//}
// 形参用两个指针
//void test(int* px, int* py)
//{
//	*px = 3;
//	*py = 4;
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	test(&a, &b);
//	return 0;
//}
// 用两个全局变量
//int a = 0;
//int b = 0;
//void test()
//{
//	a = 3;
//	b = 4;
//}
//int main()
//{
//	test();
//	printf("%d %d\n", a, b);
//	return 0;
//}
//
// 2.关于函数调用说法不正确的是
// 函数可以传值调用，传值调用的时候形参是实参的一份临时拷贝
// 函数可以传址调用，传址调用的时候，可以通过形参操作实参
// 函数可以嵌套定义，但不能嵌套调用                      ×
// 函数可以嵌套调用，但不能嵌套定义
// 
//3.在函数调用时，以下说法
// 函数调用后必须带有返回值								错
// 实参和形参可以同名						
// 函数见数据传递不可以使用全局变量							
// 主调函数和被调函数总是放在同一个文件里				错

// 数组	
// 1.一维数组的创建和初始化
// 2.一维数组的使用
// 3.一维数组在内存中的存储
// 4.二维数组的创建和初始化
// 5.二维数组的使用
// 6.二维数组在内存中的存储
// 7.数组越界
// 8.数组作为函数参数
// 9.数组是实例应用：扫雷
// 10.数组的实例应用：三子棋


// 1.一维数组的创建和初始化、
// 1.1 数组的创建
// 数组的创建方式
// type_t arr_name  [const_n]
// type_t 数组的元素类型
// const_a  指定数组的大小
//int main()
//{
//	int a = 1;
//	int b = 3;
//	int c = 2;
//	// 1～100、
//	//一组相同类型元素的集合
//	int arr[10];
//	char ch[5];
//	double data[20];
//
//
//	int n = 10;
//	int arr2[n];    // 变长数组不支持初始化
//	// 在 C99 之前，数组的大小必须是常量或者常量表达式
//	// 在 C99 之后，数组的大小可以是变量，为了支持变长数组
//}
// 1.2 数组的初始化（在创建数组的时候给它一些合理的值）
//int main()
//{
//	//不完全初始化，剩下的值默认为 0
//	int arr[10] = [1, 2, 3];
//	int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	char ch[10] = { 'a','b',c };
//	// a b c 0 0 0 0 0 0 0
//	char ch1[10] = "abc";
//	// a b c \0 0 0 0 0 0
//	char ch2[] = { 'a','b','c' };
//	// 只有三个元素
//	char ch3[] = "abc";
//	// 有四个元素  
//}
// 
// 1.3 一维数组的使用

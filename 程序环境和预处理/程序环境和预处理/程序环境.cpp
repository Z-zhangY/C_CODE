#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>




// ���򻷾���Ԥ����
// 1.����ķ��뻷����ִ�л���
// 1.1 ���뻷����Դ����ת���ɿ�ִ�еĻ���ָ��Ȼ����ִ�л�����ִ��
// 
// 2.������+����
// 2.1 ���뻷��
// Դ�ļ� -> ������ -> Ŀ���ļ�
// Ŀ���ļ�+���ӿ� -> ������ -> ��ִ���ļ�
// 
// test.c -> Ԥ����(test.i) -> ����(test.s) ->
// 
// 2.3 ����ļ����׶�
// 
// Ԥ����׶� gcc test.c -E  ->  test.i ������һ���µ��ļ���������ͷ�ļ�����������²��裩
// ͷ�ļ��İ��� #include
// #define ������ŵ��滻��ɾ������ķ���
// ɾ��ע��
// 
// ����׶�  
// �� C ���Դ���ת���ɻ����루�ʷ����﷨����������ͷ��Ż��ܣ�
// �ѻ�����ת���ɶ�����ָ��
// ���Ż����γɷ��ű� ��test.o �ļ���
// gcc test.c -S  ����Ԥ���룬ֱ�ӱ���
// gcc test.i -S  Ԥ����֮�����
// ���ɵķ��ű�����һ����ַ�������ӵ�ʱ���õ�
// 
// ���ӽ׶�
// �ϲ��α�
// test.o + ���ӿ�  -> ��ִ�г���
//
// 
// 
// 2.3 ���л���
// 2.3.1 �������뵽�ڴ���
// ���в���ϵͳ�Ļ����У�һ���ɲ���ϵͳ��ɡ��ڶ���ϵͳ�У��ֹ���ɣ�Ҳ������ͨ����ִ�д�������ɶ��ڴ����
// 2.3.2 �����ִ�п�ʼ�����ſ�ʼ���� main ����
// 2.3.3 ��ʼִ�г������
// ��ʱ�����ʹ��һ������ʱ��ջ���洢�����ľֲ������ͷ��ص�ַ��
// ����ͬʱҲ����ʹ�þ�̬�ڴ棬�洢�ھ�̬�ڴ��еı����ڳ��������ִ�й�����һֱ�������ǵ�ֵ
// 2.3.4 ��ֹ����
// ������ֹ main ������Ҳ������������ֹ	
// 





// 3.Ԥ����
// 3.1 Ԥ�������
// __FILE__  ���б����Դ�ļ�
// __LINE__  �ļ���ǰ���к�
// __DATE__  �ļ������������
// __TIME__  �ļ��������ʱ��
// __STDC__  �����������ѭ ANSI C����ֵΪ 1������δ����
//
//int main()
//{
//	int i = 0;
//	FILE* pf = fopen("C:\\Users\\�ż�Ң\\OneDrive\\����\\log.txt", "w");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	for (i = 0; i < 10; i++)
//	{
//		fprintf(pf,"file:%s  line=%d date:%s time:%s i=%d\n", __FILE__, __LINE__,__DATE__,__TIME__, i);
//		//  \  ������
//	}
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
//
// 3.2 #define 
// 3.2.1 �����ʶ��
// 3.2.2 �����
// ���������ʽ
// #define name(parament-list)stuff
// ���е� parament-list ��һ���ɶ��Ÿ����ķ��ű�
// �����б������ű������ name
// 
//#define SQUARE(X) X*X
////д���ʱ��Ҫʡ����
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
// 3.2.3 #define �滻����
// �ڵ��ú�ʱ�����ȶԲ������м�飬�����Ƿ������ #define ����ķ��ţ�����ǣ��������ȱ��滻
// �滻�ı���󱻲��뵽������ԭ���ı���λ�á����ں꣬�����������ǵ�ֵ���滻
// ����ٴζԽ���ļ�����ɨ�裬�������Ƿ�
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
// 3.2.4 #��##
//#define PRINT(N) printf("the value of "#N" is %d\n",N)
//               printf("the value of ""a"" is %d\n,N)  
//               #N ��ת���� "a",Ȼ���ַ����Զ��ϲ�
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
// ��ӡ���ֲ�ͬ���͵�����
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
// ## ���԰�λ�������ߵķ��źϳ�һ������
// ������궨��ӷ�����ı�Ƭ�δ�����ʶ��
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
// 3.2.5 �������õĺ�
// 
//#define MAX(a,b) ((a)>(b)?(a):(b))
//int main()
//{
//	//int a = 10;
//	//int b = a + 1;
//	//int b = ++a;  // ������֮�� a ��ֵҲ����
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
// 3.2.6 ��ͺ���
// �ŵ㣺
// ������Ҫ���� ���� ���� ����
// ��ֱ�ӿ��Լ���
// ����ֻ�������ͺ��ʵı��ʽ��ʹ��
// ���������޹ص�
// ȱ�㣺
// ÿ����һ�κ��ʱ��һ�ݺ궨��Ĵ��뽫���뵽�����У������˴��������̶�
// �����޷����Ե�
// ���������޹أ������Ͻ�
// ���ܻ������������ȼ�������
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
// 3.2.7 ����Լ��
// ����ȫ����д
// ��������ȫ��д
// 
// 
// 
// 3.3 #undef �Ƴ�һ������
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
// 3.4 �����ж���
// �����ڱ����ʱ���ĳһЩ����ָ��ֵ
// 
// 3.5 ��������
// ͨ��ĳЩ��Ч�ĵ��ڿ��ƴ���Ĳ���
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
// ��������������ָ��
// #if �������ʽ
// #ifdef �������Ϊ��������
// ����
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
// �����֧����������
// #if �������ʽ
// #elif 
// #else
// #endif
// 
// 
// �ж��Ƿ񱻶���
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
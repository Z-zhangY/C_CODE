#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
//
//// 1.ö��
//// 1.1 ö�ٵĶ���
//// 
//#define M 100
//enum day
//{
//	Mon=1, // ����ʼֵ
//	Tues,
//	Wed,
//	Thur,
//	Fri,
//	Sat,
//	Sun
//};
//struct s
//{
//	int a;
//	char c;
//};
//int main()
//{
//	//enum day d = Fri;  // ö����һ������
//	//enum day s = 1;    // �Ͻ������� c++ ��
//	printf("%d\n", Mon);
//	printf("%d\n", Tues);
//	printf("%d\n", Wed);
//	printf("%d\n", Thur);
//	printf("%d\n", Fri);
//	printf("%d\n", Sat);
//	printf("%d\n", Sun);
//
//	return 0;
//}
//
//
//
// 1.2 ö�ٵ��ŵ�
//     ���Ӵ���Ŀɶ��ԺͿ�ά����
//	   �� define ��ȣ�ö�������ͼ�飬�����Ͻ�
//     Ϊ�˷�ֹ������Ⱦ
//	   ���ڵ���
//	   ʹ�÷��㣬����һ�ζ���������
// 
// 
// 
// 
// 1.3 ö�ٵ�ʹ��
//







// 2.���ϣ������壩
// 2.1 �������͵Ķ���
//     ����Ҳ���Զ������ͣ��������Ͷ���ı�������һϵ�еĳ�Ա
//	   ��������Щ��������һ���ڴ�ռ�
// 
// 2.2 ���ϵ�����
// 
// 2.3 ���ϵ��ص�
//     ����һ��ռ䣬�� a ��ʱ�� c Ҳ���
//
//union un
//{
//	int a;
//	char c;
//};
//struct S
//{
//	int a;
//	char c;
//};
//int main()
//{
//	union un u;
//	//printf("%d\n", sizeof(u)); //4
//
//	//printf("%p\n", &(u.a));
//	//printf("%p\n", &(u.c)); 
//	//printf("%p\n", &u);
//
//	u.a = 0x11223344;
//	u.c = 0x00;
//	printf("%p\n", &(u.c));
//	return 0;
//}
//
// 
// 2.3 ���ϵ��ص�
//     ����һ��ռ䣬�� a ��ʱ�� c Ҳ���
//
//
// �жϻ����Ĵ�С�˴洢
//int check_system()
//{
//	int a = 1;
//	return *(char*)&a;
//}
//int check_system()
//{
//	union un
//	{
//		int a;
//		char c;
//	}u;
//	u.a = 1;
//	return u.c;
//}
//int main()
//{
//	int a = 1;
//	int ret = check_system();
//	if (ret == 1)
//		printf("С��\n");
//	else
//		printf("���\n");
//	return 0;
//}
// 
// 
// 
// 2.4 �������ϵĴ�С
//     ���ϵĴ�С����������Ա�Ĵ�С
//	   ������Ա��С��������������������ʱ����Ҫ���뵽����������������
//
//union Un
//{
//	char arr[5]; //5
//	int i;       //4
//};
//int main()
//{
//	printf("%d\n", sizeof(union Un));
//	return 0;
//}
//
// 
// 2.5 ��ϰ
//
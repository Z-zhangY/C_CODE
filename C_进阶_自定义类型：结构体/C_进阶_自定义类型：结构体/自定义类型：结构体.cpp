#include<stdio.h>
#include<stddef.h>


// ���Ӷ���
// �Զ������ͣ��ṹ�塢ö�١�����
//
//
// �ṹ��
// 1.�ṹ�������
// 1.1 �ṹ��Ļ���֪ʶ
//     �ṹ��һЩֵ�ļ��ϣ���Щֵ��Ϊ��Ա����
// 1.2 �ṹ������
// 
// �ṹ�����͵Ķ���
//struct Stu
//{
//	// ѧ�����������
//	char name[20];
//	int age;
//
//}s1,s2;
//// s1 s2 �� struct Stu �ı�����ȫ�ֱ���
//int main()
//{
//	struct Stu s1 = { "zhangsan",20 };
//	return 0;
//}
// 
// 
// 1.3 ���������
//     �����ṹ������
//     ֻ����һ��
//struct
//{
//	char name[20];
//	int age;
//}s1;
//struct
//{
//	char name[20];
//	int age;
//}a[20],*p;
//int main()
//{
//	p = &s1;
//	// ������������������ı�����Ϊ���ֲ�ͬ���͵ı���
//	return 0;
//}
// 
// 
// 1.4 �ṹ���������
// ���ݽṹ  
// ���� ˳�������
// ���� ������
// 
// ����
//struct Node
//{
//	int data;            
//	struct Node* next;
//	// �����������
//	// �������ָ����
//};
//
// 1
//typedef struct Node
//{
//	int data;
//	struct Node* next;
//}* linklist;
////
//// 2
//struct Node
//{
//	int data;
//	struct Node* next;
//};
//typedef struct Node* linklist;
// 
// 
// 1.5 �ṹ������Ķ���ͳ�ʼ��
//struct Point
//{
//	int x;
//	int y;
//}p1 = { 2,3 };
//struct score
//{
//	int n;
//	char ch;
//};
//struct Stu
//{
//	char name[20];
//	int age;
//	struct score s2;
//};
//int main()
//{
//	struct Point p2 = { 2,3 };
//	struct Stu s1 = { "zhangsan",20 ,100,'q' };
//	printf("%s\n %d\n %d\n %c\n", s1.name, s1.age, s1.s2.n, s1.s2.ch);
//	return 0;
//}
// 
// 
// 1.6 �ṹ���ڴ����
//     ����ṹ���С
//
// �������
// .1.��һ����Ա���ڽṹ��ƫ����Ϊ 0 �ĵ�ַ��
// .2.������Ա����Ҫ���뵽��������������������ĵ�ַ��
//	  ������ = ������Ĭ�ϵĶ�������ó�Ա��С�Ľ�Сֵ
//	  ÿ����Ա�������Լ��Ķ����� 
//    VS Ĭ�϶�����Ϊ 8
// .3.�ṹ���ܴ�СΪ����������������
// .4.���Ƕ���˽ṹ��������Ƕ�׵Ľṹ����뵽�Լ���������������������
//    �ṹ��������С��������������������Ƕ�׽ṹ��Ķ���������������
//
//struct S1
//{
//	char c1;
//	int i;
//	char c2;
//};
//struct S2
//{
//	char c1;	
//	char c2;
//	int i;
//};
//struct S3
//{
//	double d;
//	char c;
//	int i;
//};
//struct S4
//{
//	char c1;
//	struct S3 s3;
//	double d;
//};
//int main()
//{
//	printf("%d\n", sizeof(struct S1)); // 12    
//	printf("%d\n", sizeof(struct S2)); // 8
//	printf("%d\n", sizeof(struct S3)); // 16 
//	printf("%d\n", sizeof(struct S4));
//
//	printf("%d\n", offsetof(struct S1, c1));
//	printf("%d\n", offsetof(struct S1, i));
//	printf("%d\n", offsetof(struct S1, c2));
//
//	return 0;
//}
//
// Ϊʲô�����ڴ����
// .1.ƽ̨ԭ����ֲԭ�򣩣�
// ��������ƽ̨������������������ַ�ϵ��������ݣ�ĳЩƽֻ̨�ܷ����ض���ַ
// .2.����ԭ��
// ���ݽṹ��������ջ����Ӧ�þ����ܵ�����Ȼ�߽��϶���
// Ϊ�˷���δ������ڴ棬��������Ҫ�����η��ʣ���������ڴ�ֻ��Ҫ��һ�η���
// �ܵ���˵-- �ڴ��������ÿռ任ȡʱ�������
// ����ÿռ�С�ĳ�Ա����������һ�𣬿��Լ����ڴ�ռ���˷�
//
// 
// 
// 
// 1.7 �޸�Ĭ�϶�����
//#pragma pack(4)  // ���ÿ�ʼ��Ч
//struct S
//{
//	int i;
//	//�����С 4 Ĭ�϶����� 8 ������ 8
//	double d;
//	//�����С 8 Ĭ�϶����� 8 ������ 8
//};
//#pragma pack()  // �ָ�Ĭ��ֵ
////
//#pragma pack(1)   // ������
//struct S1
//{
//	char c;
//	char c1;
//	int i;
//};
//int main()
//{
//	printf("%d\n", sizeof(struct S));
//	printf("%d\n", sizeof(struct S1));
//	return 0;
//}
// #pragma once ��ֹͷ�ļ���������� 
// 
// 
// 
// 1.8 �ṹ�崫��
//struct S
//{
//	int data[100];
//	int num;
//};
//void print1(struct S ss)
//{
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		printf("%d\n", ss.data[i]);
//	}
//	printf("%d\n", ss.num);
//}
//void print2(const struct S* ps)
//{
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		printf("%d\n", ps->data[i]);
//	}
//	printf("%d\n", ps->num);
//}
//int main()
//{
//	struct S s = { {1,2,3},100 };
//	print1(s);  //��ֵ����
//	//��ֵ�������ֵ������ȥ������ѹջ������ṹ�����ϵͳ�����ϴ�
//	//ѹջ����ջ�����ٿռ�Ѳ���һ��һ���Ž�ȥ
//
//	print2(&s); //��ַ����
//	//��ַֻռ 4 ���ֽڿռ�
//
//	return 0;
//}
//
// 
// 
// 
// 2. λ��
// 2.1 ʲô��λ��
//     λ�εĽṹ�ͽṹ�����Ƶ�
//     λ�εĳ�Ա������ int un_int  signed int
//     λ�εĳ�Ա������һ��ð�ź�����
//	   ����������ʡ�ռ�
//struct A
//{
//	int _a : 2;
//	int _b : 5;
//	int _c : 10;
//	int _d : 30;
//	//���ִ����������Ҫ�ı���λ
//};
////  47bit    6byte = 48bit
//// 
//int main()
//{
//	printf("%d\n", sizeof(struct A));
//	return 0;
//}
//
// 
// 
// 2.2 λ�ε��ڴ����
//   2.1 λ�εĳ�Ա������ int�� unsigned int��signed int �� char
//	 2.2 ����� int ��һ�ο��� 4 ���ֽڣ������ char��һ�ο��� 1 ���ֽ�
//   2.3 λ���ǲ���ƽ̨��
//
struct S
{
	char a : 3;
	char b : 4;
	char c : 5;
	char d : 4;
};
int main()
{
	struct S s = { 0 };
	//�ڴ�ռ��������ʹ�ã������һ���ռ���˷�
	printf("%d\n", sizeof(struct S));
	s.a = 10;
	s.b = 12;
	s.c = 3;
	s.d = 4;
	return 0;
}
//
//
// 
// 2.3 λ�εĿ�ƽ̨����
//   3.1 int λ�α������з��Ż����޷��Ų�ȷ��
//   3.2 λ���е����λ��Ŀ��ȷ�� ��16λ������16��32λ������32λ��
//   3.3 λ���еĳ�Ա���ڴ��д������һ��ߴ�������ȷ��
//   3.4 ��һ���ṹ��������λ��ʱ���ڶ���λ�νϴ�
//		 ���ܷ����ڵ�һ��λ��ʣ��ռ�ʱ�����˷ѻ������ò�ȷ��
//     ���ԺܺõĽ�ʡ�ռ䣬���Ǵ��ڿ�ƽ̨����
//
//  
// 2.4 λ�ε�ʹ��
//     ����Э���������
//

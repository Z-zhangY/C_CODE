#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<errno.h>


//
// �ļ�����
// 1.Ϊʲôʹ���ļ�
// ʹ���ļ�����ֱ�ӽ����ݴ洢�����Ե�Ӳ���ϣ����������ݵĳ־û�
// 
// 2.ʲô���ļ�
// 
// 2.1�����ļ�
// ����Դ�����ļ���.c��  Ŀ���ļ���.obj��   ��ִ�г���.exe��
// 
// 2.2�����ļ�
// �ļ������ݲ�һ���ǳ����ǳ�������ʱ��д������  
// �������������Ҫ���ж�ȡ���ݵ��ļ�������������ݵ��ļ�  
// 
// 2.3�ļ���
// �ļ�·��+�ļ�������+�ļ���׺
// 
// 3.�ļ��Ĵ򿪺͹ر�
// 3.1�ļ�ָ��
// ÿ����ʹ�õ��ļ��������ڴ��п�����Ӧ���ļ���Ϣ������������ļ��������Ϣ�������ļ������֡�״̬�͵�ǰλ�õȣ�
// ��Щ��Ϣ�Ǳ�����һ���ṹ������еģ��ýṹ�����͵�ϵͳ����Ϊ FILE
// ���ǿ��Դ���һ�� FILE ��ָ��ά�� FILE �ṹ�ı���
// ͨ�� FILE* pf ����ָ��ĳ���ļ���Ϣ��
// ͨ���ļ�ָ����������ҵ������������ļ�
// 
// 3.2�ļ��Ĵ򿪺͹ر�
// ʹ�� fopen ���ļ�  ʹ�� fclose �ر��ļ�
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
//	//���ļ�
//
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
//
// �ַ����뺯�� fgetc
//int main()
//{
//	FILE* pf = fopen("C:\\Users\\�ż�Ң\\OneDrive\\����\\test.txt", "w");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;
//	}
//
//	//д�ļ�
//	char i = 'a';
//	for (i = 'a'; i <= 'z'; i++)
//	{
//		fputc(i, pf);
//	}
//		
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//	//�ļ�����Դ������֮����Ҫ��ʱ�ͷ�
//	//�ļ����رյĻ����ܻ������Ϣй¶
//	return 0;
//}
// 
// �ַ��������  fputc
//int main()
//{
//	FILE* pf = fopen("C:\\Users\\�ż�Ң\\OneDrive\\����\\test.txt", "r");
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
// �ı���������� fputs
//int main()
//{
//	FILE* pf = fopen("C:\\Users\\�ż�Ң\\OneDrive\\����\\test.txt", "w");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;
//	}
//
//	//д�ļ�
//	fputs("hello bit\n", pf);
//	fputs("hello bit\n", pf);
//	//����ļ����������ݣ���ȫ������
//	
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
//
// �ı������뺯�� fgets
//int main()
//{
//	FILE* pf = fopen("C:\\Users\\�ż�Ң\\OneDrive\\����\\test.txt", "r");
//	if (pf == NULL)
//	{
//		//printf("%s\n", strerror(errno));
//		perror("fopen");
//		return 1;
//	}
//
//	//��һ���ļ�
//	char arr[20];
//	fgets(arr, 20, pf);
//	printf("%s\n", arr);
//	//���һλ '\0'
//	//����ֵ��������׵�ַ
//
//	//�ر��ļ�
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
// ��ʽ��������� fprintf      д�������  �����ݴ��ڴ���д���ļ���
// int printf(FILE *stram,const char* format)
//int main()
//{
//	struct S zh = { "zhangsan",10,100.0 };
//	FILE* pf = fopen("C:\\Users\\�ż�Ң\\OneDrive\\����\\test.txt", "w");
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
// ��ʽ�����뺯�� fscanf       �������룩  �����ݴ��ļ��ж����ڴ���
// int fscanf (FILE *stram,const char* format)
//int main()
//{
//	struct S zh = {0};
//	FILE* pf = fopen("C:\\Users\\�ż�Ң\\OneDrive\\����\\test.txt", "r");
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
// ��
// FILE*   �ļ���
// 
// �κ�һ��C����ֻҪ������������Ĭ�ϴ�������
// FILE* stdin - ��׼������ �����̣�
// FILE* stdout- ��׼����� ����Ļ��
// FILE* stderr -��׼������ ����Ļ�� 
// 
// �����ݴ�ӡ����Ļ��
//struct S
//{
//	char arr[20];
//	int age;
//	float score;
//};
//int main()
//{
//	struct S zh = { "zhangsan",10,100.0 };
//	FILE* pf = fopen("C:\\Users\\�ż�Ң\\OneDrive\\����\\test.txt", "w");
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
// ��������������
// fread 
// fwrite
// size_t fwrite(    const void* buffer,    size_t size,    size_t count,  FILE* stream );
//                  Ҫд������               Ԫ�ش�С        Ԫ�ظ���       
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
//	//�Զ�������ʽд���ļ���
//	FILE* pf = fopen("C:\\Users\\�ż�Ң\\OneDrive\\����\\test.txt", "wb");  //�����Ƶ� write
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//  //�Զ����Ʒ�ʽд��
//	fwrite(&zh, sizeof(struct S), 1, pf);
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
//int main()
//{
//	struct S zh = { "zhangsan",10,10.0 };
//	//�Զ�������ʽд���ļ���
//	FILE* pf = fopen("C:\\Users\\�ż�Ң\\OneDrive\\����\\test.txt", "rb");  //�����Ƶ� write
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//�����Ʒ�ʽ��
//	fread(&zh, sizeof(struct S), 1, pf);
//	printf("%s %d %f", zh.arr, zh.age, zh.score);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
//
//
// sscanf   ��һ���ַ�����ת������ʽ��������
// sprintf  ��һ����ʽ��������ת��Ϊ�ַ���
//
// ���л� 
// �����л�
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
//	//��һ����ʽ��������ת��Ϊ�ַ���
//	printf("%s\n", buf);
//
//	sscanf(buf, "%s %d %f", tmp.arr, &(tmp.age), &(tmp.score));
//	//���ַ���BUF�л�ȡ��ʽ�������ݷŵ� tmp ��
//	printf("%s %d %f \n", tmp.arr, tmp.age, tmp.score);
//	return 0;
//}
//
// 
// 5.�ļ��������д
// 5.1 fseek
// int fseek(    FILE* stream,    long offset,    int origin );
// �����ļ�ָ���λ�ú�ƫ��������λ�ļ�ָ��
//
// 5.2 ftell
// �ж��ļ�ָ��Ŀǰ��ƫ���� 
// 
// 5.3 rewind 
// ���ļ�ָ��ص��ļ��ĳ�ʼλ��
//
//
//int main()
//{
//	FILE* pf = fopen("C:\\Users\\�ż�Ң\\OneDrive\\����\\test.txt", "r");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;
//	}
//	//���ļ�
//	//fgetc ������
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
//	//�ж��ļ�ָ��Ŀǰ��ƫ����
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
// 6.�ı��ļ��Ͷ������ļ�
//   �����ļ�����Ϊ�ı��ļ����߶������ļ�
//   ���ڴ����Զ����ƴ洢������ת��ֱ���������棬���Ƕ������ļ�
//   ���ת����ASCII��ʽ����������ı��ļ�
//   �ַ�һ����ASCII��ʽ�洢����ֵ�����ݿ��Զ����ƴ��棬Ҳ����ASCII��ʽ�洢
//  
//   10000  ���ڴ��еĴ洢��ʽ�Ƕ����� ��00000000 00000000 00100111 00010000��
//          ASCII��ʽ                  ��00110001 00110000 00110000 00110000��
//          ��������ʽ                 ��00000000 00000000 00100111 00010000��
//
//int main()
//{
//	int a = 10000;
//	FILE* pf = fopen("C:\\Users\\�ż�Ң\\OneDrive\\����\\test.txt", "wb");
//	fwrite(&a, 4, 1, pf);
//	fclose(pf);
//	pf = NULL; 
//	return 0;
//}
//
// 
// 
// 7.�ļ���ȡ�������ж�
// 7.1 ������ʹ�õ� feof
// feof ���������ж��ļ��Ƿ����
//      ����Ӧ���ڵ��ļ���ȡ�������ж��Ƕ�ȡʧ�ܽ������������ļ�β����
//   1.1�ı��ļ��Ƿ��ȡ�������жϷ���ֵ�Ƿ�Ϊ EOF(fgetc),���� NULL(fgets)
//      ���磺fgets �ж��Ƿ�Ϊ NULL , fgetc �ж��Ƿ�Ϊ EOF
//   1.2�������ļ��Ķ�ȡ�����жϣ��жϷ���ֵ�Ƿ�С��Ҫ���ĸ���	
//      ���磺fread �жϷ���ֵ�Ƿ�С��ʵ�ʶ��ĸ���
//
//int main()
//{
//	int c = 0;
//	FILE* pf = fopen("C:\\Users\\�ż�Ң\\OneDrive\\����\\test.txt", "r");
//	if (!pf)
//	{
//		perror("fopen");
//		return 0;
//	}
//	//fgetc ����ȡʧ�ܵ�ʱ����������ļ�������ʱ�򣬷��� EOF
//	while ((c = fgetc(pf)) != EOF)
//	{
//		putchar(c);
//	}
//	
//	//�ж���ʲôԭ�����ļ�������
//	if (ferror(pf))   //�ж϶�ȡ��ʱ���Ƿ���������
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
// 8.�ļ�������
// ��׼C���á������ļ�ϵͳ������������ļ��ģ���ν�����ļ�ϵͳ��ָϵͳ�Զ������ڴ���Ϊ��������ʹ�õ��ļ�����һ�顰�ļ���������
// ���ڴ������������ݻ����͵��ڴ��еĻ�����װ�����������һ���͵�������
// ����Ӵ����ļ��ж�ȡ���ݣ���Ӵ����ļ��ж�ȡ�������뵽�ڴ滺������Ȼ���ٴӻ���������Ľ������͵�����������
//

	

#include"contact.h"

enum option
{
	ADD,
	DEL,
	SEAR,
	MOD,
	SHOW,
	SORT,
	EXIT
};

void menu()
{
	printf("*******************************\n");
	printf("****** 1.add       2.del ******\n");
	printf("****** 3.search    4.mod ******\n");
	printf("****** 5.show      6.sort******\n");
	printf("****** 0.exit            ******\n");
	printf("*******************************\n");
}
int main()
{
	int input = 0;

	Contact con; // ͨѶ¼
	// ��ʼ��ͨѶ¼
	IntiContact(&con);

	do
	{
		menu();
		printf("��ѡ��\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			AddContact(&con);
			break;
		case 2:
			DelContact(&con);
			break;
		case 3:
			SeaContact(&con);
			break;
		case 4:
			ModContact(&con);
			break;
		case 5:
			ShowContact(&con);
			break;
		case 6:
			SortContact(&con);
			break;
		case 0:
			SavaContact(&con);
			DestroyContact(&con);
			printf("ȷ���˳�\n");
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	} while (input);
	return 0;
}
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
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEAR:
			SeaContact(&con);
			break;
		case MOD:
			ModContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case SORT:
			SortContact(&con);
			break;
		case EXIT:
			printf("ȷ���˳�\n");
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	} while (input);
	return 0;
}
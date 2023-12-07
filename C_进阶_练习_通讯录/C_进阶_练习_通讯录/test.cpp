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

	Contact con; // 通讯录
	// 初始化通讯录
	IntiContact(&con);

	do
	{
		menu();
		printf("请选择\n");
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
			printf("确认退出\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
	return 0;
}
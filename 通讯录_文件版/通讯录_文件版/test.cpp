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
			printf("确认退出\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
	return 0;
}
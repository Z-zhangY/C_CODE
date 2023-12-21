#include"contact.h"
#define MAX 100;

// test.c 测试功能
// contact.h 通讯录相关声明
// contact.c 通讯录相关实现
//

// 实现一个通讯录
// 人的信息 ：名字、年龄、性别、电话、地址
// 功能描述：
// 1.存放 100 个人的信息
// 2.增加、删除、修改、查找联系人
// 3.排序
// 4.显示联系人
//


void  CheckCapacity(Contact* pc)
{
	if (pc->count == pc->capacity)
	{
		PeoInfo* ptr = (PeoInfo*)realloc((pc->data), (pc->capacity + INC_size) * sizeof(PeoInfo));
		if (ptr == NULL)
		{
			printf("AddContact: %s\n", strerror(errno));
			return;
		}
		else
		{
			pc->data = ptr;
			//把新开辟的空间传给data
			pc->capacity += INC_size;
			//最大容量增加2
			printf("增容成功\n");
		}
	}
}
// 
//
void LoatContact(Contact* pc)
{
	FILE* pfRead = fopen("C:\\Users\\张佳尧\\OneDrive\\桌面\\contact.txt", "rb");
	if (pfRead == NULL)
	{
		perror("LoadContact");
		return;
	}

	PeoInfo tmp = { 0 };
	while (fread(&tmp, sizeof(PeoInfo), 1, pfRead) == 1)
	{
		CheckCapacity(pc);

		pc->data[pc->count] = tmp;
		pc->count++;
	}

	fclose(pfRead);
	pfRead = NULL;
}
// 
// 动态版本
void IntiContact(Contact* pc)
{
	assert(pc);
	pc->count = 0;
	pc->data = (PeoInfo*)malloc(DEFAULT_size * sizeof(PeoInfo));
	if (pc->data == NULL)
	{
		printf("IntiContact: %s\n", strerror(errno));
		return;
	}
	pc->capacity = DEFAULT_size;

	//加载文件的信息加载到通讯录中
	LoatContact(pc);
	return;
}

void DestroyContact(Contact* pc)
{
	assert(pc);
	free(pc->data);
	pc->data = NULL;
	pc->capacity = 0;
	pc->count = 0;
	pc = NULL;
}



void AddContact(Contact* pc)
{
	assert(pc);
	CheckCapacity(pc);
	//检查容量，判断是否需要增容

	printf("请输入名字->");
	scanf("%s", pc->data[pc->count].name);
	printf("请输入年龄->");
	scanf("%d", &pc->data[pc->count].age);
	printf("请输入性别->");
	scanf("%s", pc->data[pc->count].sex);
	printf("请输入电话->");
	scanf("%s", pc->data[pc->count].tele);
	printf("请输入住址->");
	scanf("%s", pc->data[pc->count].addr);
	pc->count++;
	printf("添加成功\n");
}

//显示通讯录
void ShowContact(const Contact* pc)
{
	assert(pc);
	int i = 0;
	printf("%-20s\t%-3s\t%-5s\t%-12s\t%-30s\n", "姓名", "年龄", "性别", "电话", "住址");
	for (i = 0; i < pc->count; i++)
	{
		printf("%-20s\t%-3d\t%-5s\t%-12s\t%-30s\n",
			pc->data[i].name,
			pc->data[i].age,
			pc->data[i].sex,
			pc->data[i].tele,
			pc->data[i].addr);
	}
}

//
static int FindByName(Contact* pc, char name[])
{
	assert(pc);
	int i = 0;
	for (i = 0; i < pc->count; i++)
	{
		if (0 == strcmp(pc->data[i].name, name))
		{
			return i;
		}
	}
	return -1;

}

//删除联系人
void DelContact(Contact* pc)
{
	int i = 0;
	char name[20] = { 0 };
	assert(pc);
	if (pc->count == 0)
	{
		printf("通讯录为空\n");
		return;
	}
	printf("请输入要删除联系人名字\n");
	scanf("%s", name);

	// 查找
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("联系人不存在\n");
		return;
	}

	// 删除
	for (i = pos; i < pc->count; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->count--;
	printf("删除成功\n");
}

//查找联系人
void SeaContact(Contact* pc)
{
	assert(pc);
	char name[20];
	int i = 0;
	printf("请输入要查找联系人的姓名\n");
	scanf("%s", name);
	// 查找
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("联系人不存在\n");
		return;
	}
	// 找到 打印
	printf("%-20s\t%-3s\t%-5s\t%-12s\t%-30s\n", "姓名", "年龄", "性别", "电话", "住址");
	printf("%-20s\t%-3d\t%-5s\t%-12s\t%-30s\n",
		pc->data[pos].name,
		pc->data[pos].age,
		pc->data[pos].sex,
		pc->data[pos].tele,
		pc->data[pos].addr);
}


//修改通讯录
void ModContact(Contact* pc)
{
	assert(pc);
	char name[20];
	printf("请输入修改联系人姓名\n");
	scanf("%s", name);
	// 先查找
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("需要修改联系人不存在\n");
		return;
	}
	// 后修改（重新录入）
	printf("请输入名字->");
	scanf("%s", pc->data[pos].name);
	printf("请输入年龄->");
	scanf("%d", &pc->data[pos].age);
	printf("请输入性别->");
	scanf("%s", pc->data[pos].sex);
	printf("请输入电话->");
	scanf("%s", pc->data[pos].tele);
	printf("请输入住址->");
	scanf("%s", pc->data[pos].addr);

	printf("修改成功\n");
}


//保存通讯录
void SavaContact(const Contact* pc)
{
	assert(pc);
	FILE* pfWrite = fopen("C:\\Users\\张佳尧\\OneDrive\\桌面\\contact.txt", "wb");
	if (pfWrite == NULL)
	{
		perror("SavaContact");
		return;
	}

	//写文件-二进制形式
	int i = 0;
	for (i = 0; i < pc->count; i++)
	{
		fwrite(pc->data + i, sizeof(PeoInfo), 1, pfWrite);
	}


	//关闭文件
	fclose(pfWrite);
	pfWrite = NULL;
}


int cmp_peo_by_name(const void* p1, const void* p2)
{
	return strcmp(((PeoInfo*)p1)->name, ((PeoInfo*)p2)->name);
}
//排序
void SortContact(Contact* pc)
{
	assert(pc);
	qsort(pc->data, pc->count, sizeof(PeoInfo), cmp_peo_by_name);
	printf("排序成功\n");
}
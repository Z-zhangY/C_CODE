#include"contact.h"
#define MAX 100;

// test.c ���Թ���
// contact.h ͨѶ¼�������
// contact.c ͨѶ¼���ʵ��
//

// ʵ��һ��ͨѶ¼
// �˵���Ϣ �����֡����䡢�Ա𡢵绰����ַ
// ����������
// 1.��� 100 ���˵���Ϣ
// 2.���ӡ�ɾ�����޸ġ�������ϵ��
// 3.����
// 4.��ʾ��ϵ��
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
			//���¿��ٵĿռ䴫��data
			pc->capacity += INC_size;
			//�����������2
			printf("���ݳɹ�\n");
		}
	}
}
// 
//
void LoatContact(Contact* pc)
{
	FILE* pfRead = fopen("C:\\Users\\�ż�Ң\\OneDrive\\����\\contact.txt", "rb");
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
// ��̬�汾
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

	//�����ļ�����Ϣ���ص�ͨѶ¼��
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
	//����������ж��Ƿ���Ҫ����

	printf("����������->");
	scanf("%s", pc->data[pc->count].name);
	printf("����������->");
	scanf("%d", &pc->data[pc->count].age);
	printf("�������Ա�->");
	scanf("%s", pc->data[pc->count].sex);
	printf("������绰->");
	scanf("%s", pc->data[pc->count].tele);
	printf("������סַ->");
	scanf("%s", pc->data[pc->count].addr);
	pc->count++;
	printf("��ӳɹ�\n");
}

//��ʾͨѶ¼
void ShowContact(const Contact* pc)
{
	assert(pc);
	int i = 0;
	printf("%-20s\t%-3s\t%-5s\t%-12s\t%-30s\n", "����", "����", "�Ա�", "�绰", "סַ");
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

//ɾ����ϵ��
void DelContact(Contact* pc)
{
	int i = 0;
	char name[20] = { 0 };
	assert(pc);
	if (pc->count == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
		return;
	}
	printf("������Ҫɾ����ϵ������\n");
	scanf("%s", name);

	// ����
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("��ϵ�˲�����\n");
		return;
	}

	// ɾ��
	for (i = pos; i < pc->count; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->count--;
	printf("ɾ���ɹ�\n");
}

//������ϵ��
void SeaContact(Contact* pc)
{
	assert(pc);
	char name[20];
	int i = 0;
	printf("������Ҫ������ϵ�˵�����\n");
	scanf("%s", name);
	// ����
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("��ϵ�˲�����\n");
		return;
	}
	// �ҵ� ��ӡ
	printf("%-20s\t%-3s\t%-5s\t%-12s\t%-30s\n", "����", "����", "�Ա�", "�绰", "סַ");
	printf("%-20s\t%-3d\t%-5s\t%-12s\t%-30s\n",
		pc->data[pos].name,
		pc->data[pos].age,
		pc->data[pos].sex,
		pc->data[pos].tele,
		pc->data[pos].addr);
}


//�޸�ͨѶ¼
void ModContact(Contact* pc)
{
	assert(pc);
	char name[20];
	printf("�������޸���ϵ������\n");
	scanf("%s", name);
	// �Ȳ���
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("��Ҫ�޸���ϵ�˲�����\n");
		return;
	}
	// ���޸ģ�����¼�룩
	printf("����������->");
	scanf("%s", pc->data[pos].name);
	printf("����������->");
	scanf("%d", &pc->data[pos].age);
	printf("�������Ա�->");
	scanf("%s", pc->data[pos].sex);
	printf("������绰->");
	scanf("%s", pc->data[pos].tele);
	printf("������סַ->");
	scanf("%s", pc->data[pos].addr);

	printf("�޸ĳɹ�\n");
}


//����ͨѶ¼
void SavaContact(const Contact* pc)
{
	assert(pc);
	FILE* pfWrite = fopen("C:\\Users\\�ż�Ң\\OneDrive\\����\\contact.txt", "wb");
	if (pfWrite == NULL)
	{
		perror("SavaContact");
		return;
	}

	//д�ļ�-��������ʽ
	int i = 0;
	for (i = 0; i < pc->count; i++)
	{
		fwrite(pc->data + i, sizeof(PeoInfo), 1, pfWrite);
	}


	//�ر��ļ�
	fclose(pfWrite);
	pfWrite = NULL;
}


int cmp_peo_by_name(const void* p1, const void* p2)
{
	return strcmp(((PeoInfo*)p1)->name, ((PeoInfo*)p2)->name);
}
//����
void SortContact(Contact* pc)
{
	assert(pc);
	qsort(pc->data, pc->count, sizeof(PeoInfo), cmp_peo_by_name);
	printf("����ɹ�\n");
}
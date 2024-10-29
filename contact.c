#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

void InitContact(struct Contact* ps)
{
	memset(ps->data, 0, sizeof(ps->data));
	ps->size = 0;//初始有0个元素

}

void AddContact(struct Contact* ps)
{
	if (ps->size == MAX)
	{
		printf("通讯录已满，不能添加！\n");
	}
	else
	{
		printf("请输入姓名:");
		scanf("%s", ps->data[ps->size].name);
		printf("请输入年龄:");
		scanf("%d", &(ps->data[ps->size].age));
		printf("请输入性别:");
		scanf("%s", ps->data[ps->size].sex);
		printf("请输入电话:");
		scanf("%s", ps->data[ps->size].tele);
		printf("请输入地址:");
		scanf("%s", ps->data[ps->size].addr);
		

		ps->size++;
		printf("添加成功。\n");
		


	}

}

void ShowContact(const struct Contact* ps)
{
	if (ps->size == 0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n","姓名","年龄","性别","电话","地址");
		for (int i = 0; i < ps->size; i++)//printf遇到空字符时会空白输出
		{

			printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
				ps->data[i].name
				, ps->data[i].age
				, ps->data[i].sex
				, ps->data[i].tele
				, ps->data[i].addr);

		}
		

	}
}

//只在contact.c内部使用，不与头文件其余函数冲突
static int FindByName(const struct Contact* ps, char name[MAX_NAME])
{
	int i = 0;

	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(ps->data[i].name, name))
		{
			return i;
		}
	}
	return -1;
}


void DelContact(struct Contact* ps)
{
	char name[MAX_NAME] = { 0 };
	printf("请输入要删除的姓名：\n");
	scanf("%s", name);
	//查找人的位置，返回下标
	int pos = FindByName(ps, name);
	
	if (-1==pos)
	{
		printf("要删除的信息不存在\n");

	}
	else
	{
		int j = 0;
		for (j = pos; j < ps->size-1; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("删除成功\n");
	}
}

void SearchContact(const struct Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入要查找的姓名：\n");
	scanf("%s", name);
	int pos = FindByName(ps, name);


	if (-1==pos)
	{
		printf("要查找的信息不存在\n");

	}
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "姓名", "年龄", "性别", "电话", "地址");

		printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
			ps->data[pos].name
			, ps->data[pos].age
			, ps->data[pos].sex
			, ps->data[pos].tele
			, ps->data[pos].addr);
	}
}

void ModifyContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入要修改人的姓名：\n");
	scanf("%s", name);
	int pos = FindByName(ps, name);


	if (-1 == pos)
	{
		printf("要修改人的信息不存在\n");

	}
	else
	{
		printf("请输入姓名:");
		scanf("%s", ps->data[pos].name);
		printf("请输入年龄:");
		scanf("%d", &(ps->data[pos].age));
		printf("请输入性别:");
		scanf("%s", ps->data[pos].sex);
		printf("请输入电话:");
		scanf("%s", ps->data[pos].tele);
		printf("请输入地址:");
		scanf("%s", ps->data[pos].addr);

		printf("修改成功");
	}
}


//自定义比较函数
 static int compareByName(const void* a, const void* b) {
	struct PeoInfo* contactA = (struct PeoInfo*)a;
	struct PeoInfo* contactB = (struct PeoInfo*)b;
	return strcmp(contactA->name, contactB->name);
	//返回- 0 +
}

// 排序函数，使用 qsort 对通讯录中的联系人进行排序
void SortContact(struct Contact* ps) {
	qsort(ps->data, ps->size, sizeof(struct PeoInfo), compareByName);
	//根据比较函数返回的值决定交换元素与否
	//ps->data：要排序的元素，即一个人的信息结构体
	//ps->size：元素个数
	//sizeof(struct PeoInfo)：元素大小（字节）
	//compareByName：比较函数
}
//qsort 内部实现了一个排序算法（如快速排序或其他排序算法）。
// 这个算法会自动多次调用 compareByName，对数组中的各个元素进行比较，进而完成整个数组的排序。

#define _CRT_SECURE_NO_WARNINGS 1
#include"contest.h"

void menu()
{
	printf("************************************\n");
	printf("***** 1.添加联系人 2.删除联系人*****\n");
	printf("***** 3.编辑联系人 4.查找联系人*****\n");
	printf("***** 5.显示联系人 6.排序      *****\n");
	printf("***** 7.保存       8.清空通讯录*****\n");
	printf("*****         0.退出           *****\n");
	printf("************************************\n");
}

//初始化通讯录
void init_list(struct CONTEST* p)
{
	p->con =(struct peopinfo*)malloc(STANUM * sizeof(struct peopinfo));
	if (p->con == NULL)
		return;
	p->size = 0;
	p->nowcon = STANUM;
	loadcontest(p);
}

void loadcontest(struct CONTEST *p)
{
	struct peopinfo tmp = { 0 };
	FILE*pfread = fopen("contestload.obj", "rb");
	if (pfread == NULL)
		printf("loadcontest::%s", strerror(errno));
	else
		while (fread(&tmp, sizeof(struct peopinfo), 1, pfread))
		{
			checknowcon(p);
			p->con[p->size] = tmp;
			p -> size++;
		}
}

void checknowcon(struct CONTEST*p)
{
	if (p->size == p->nowcon)
	{
		struct peopinfo*ptr = (struct peopinfo*)realloc(p->con, (p->nowcon+2) * sizeof(struct peopinfo));
		if (ptr != NULL)
		{
			p->con = ptr;//接收con起始位
			p->nowcon += 2;//当前联系人上限加二
			printf("增容成功\n");//检查增容
		}
		else
			printf("增容失败\n");
	}
}

void addcontest(struct CONTEST *p)
{
	checknowcon(p);
	printf("请输入联系人姓名:>");
	scanf("%s", p->con[p->size].name);
	printf("请输入联系人电话:>");
	scanf("%s", p->con[p->size].tele);
	printf("请输入联系人性别:>");
	scanf("%s", p->con[p->size].sex);
	printf("请输入联系人年龄:>");
	scanf("%d",&(p->con[p->size].age));
	printf("请输入联系人住址:>");
	scanf("%s", p->con[p->size].adress);
	p->size++;
	printf("添加成功\n");
}

void discontest(const struct CONTEST* p)
{
	if (p->size == 0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		printf("	联系人			电话			性别			年龄			住址\n");
		for (int i = 0; i < p->size; i++)
		{
			printf("	%-24s%-24s%-24s%-24d%-24s\n", p->con[i].name, p->con[i].tele, p->con[i].sex,p->con[i].age, p->con[i].adress);
		}
		//printf("%d", p->size);//检测当前联系人数量
	}
}

int findcon(const struct CONTEST *p,const char *fp)
{
	int i = 0;
	for (i = 0; i < p->size; i++)
	{
		if (strcmp(p->con[i].name, fp) == 0)
		{
			return i;
		}
	}
	return -1;
}

void delcontest(struct CONTEST *p)
{
	if (p->size == 0)
		printf("通讯录为空\n");
	else
	{
		char findman[NAME_MAX];
		printf("请输入联系人姓名:>");
		scanf("%s", findman);
		int ret = findcon(p, findman);
		if (ret == -1)
		{
			printf("联系人不存在\n");
		}
		else
		{
			for (ret; ret<p->size - 1; ret++)
			{
				p->con[ret] = p->con[ret + 1];
			}
			p->size--;
			printf("删除成功\n");
		}
	}
}

void findcontest(const struct CONTEST *p)
{
	if (p->size == 0)
		printf("通讯录为空\n");
	else
	{
		char findman[NAME_MAX];
		printf("请输入联系人姓名:>");
		scanf("%s", findman);
		int ret = findcon(p, findman);
		if (ret == -1)
		{
			printf("联系人不存在\n");
		}
		else
		{
			printf("	联系人			电话			性别			年龄			住址\n");
			printf("	%-24s%-24s%-24s%-24d%-24s\n", p->con[ret].name, p->con[ret].tele, p->con[ret].sex, 
				p->con[ret].age, p->con[ret].adress);
		}
	}
}

void deitcontest(struct CONTEST *p)
{
	if (p->size == 0)
		printf("通讯录为空\n");
	else
	{
		char findman[NAME_MAX];
		printf("请输入联系人姓名:>");
		scanf("%s", findman);
		int ret = findcon(p, findman);
		if (ret == -1)
		{
			printf("联系人不存在\n");
		}
		else
		{
			printf("	联系人			电话			性别			年龄			住址\n");
			printf("	%-24s%-24s%-24s%-24d%-24s\n", p->con[ret].name, p->con[ret].tele, p->con[ret].sex, p->con[ret].age, p->con[ret].adress);
			printf("请输入更改后的联系人姓名:>");
			scanf("%s", p->con[ret].name);
			printf("请输入更改后的联系人电话:>");
			scanf("%s", p->con[ret].tele);
			printf("请输入更改后的联系人性别:>");
			scanf("%s", p->con[ret].sex);
			printf("请输入更改后的联系人年龄:>");
			scanf("%d", &(p->con[ret].age));
			printf("请输入更改后的联系人住址:>");
			scanf("%s", p->con[ret].adress);
			printf("编辑成功\n");
			printf("	联系人			电话			性别			年龄			住址\n");
			printf("	%-24s%-24s%-24s%-24d%-24s\n", p->con[ret].name, p->con[ret].tele, p->con[ret].sex, p->con[ret].age, p->con[ret].adress);

		}
	}
}

int cmp(char name1, char name2)
{
	return name1 - name2;
}

void softcontest(struct CONTEST *p)
{
	if (p->size == 0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		int i = 0;
		int j = 0;
		for (i = 0; i < p->size - 2; i++)
		{
			int num = i + 1;
			for (j = 0;j < p->size - 2; j++)
			{
				int ret = cmp(p->con[i].name[0], p->con[num].name[0]);
				if (ret == 0)
				{
					num++;
				}
				else if (ret < 0)
				{
					num++;
				}
				else
				{
					struct peopinfo temp = p->con[i];
					p->con[i] = p->con[num];
					p->con[num] = temp;
					i = num;
					num++;
				}
			}
		}
		discontest(p);
	}
}

void savecontest(struct CONTEST *p)
{
	FILE*pfwrite = fopen("contestload.obj", "wb");
	if (pfwrite == NULL)
	{
		printf("savecontest::%s\n", strerror(errno));
		return;
	}
	else
	{
		int i = 0;

		for (i = 0; i < p->size; i++)
		{
			fwrite(&(p->con[i]), sizeof(struct peopinfo), 1, pfwrite);
		}
		printf("保存成功\n");
	}
	fclose(pfwrite);
	pfwrite = NULL;
}
	
void clearcontest(struct CONTEST*p)
{
	int i = 0;
	struct peopinfo tmp = { 0 };
	for (i = 0; i < p->size; i++)
	{
		p->con[i] = tmp;
	}
	p->size = 0;
	printf("删除成功\n");
}

void freemem(struct CONTEST *p)
{
	free(p->con);
	p->con = NULL;
}

int main()
{
	struct CONTEST list;
	int input = 0;
	init_list(&list);//初始化通讯录
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case EXIT:
			savecontest(&list);
			freemem(&list);
			break;
		case ADD:
			addcontest(&list);
			break;
		case DEL:
			delcontest(&list);
			break;
		case EDIT:
			deitcontest(&list);
			break;
		case FIND:
			findcontest(&list);
			break;
		case DIS:
			discontest(&list);
			break;
		case SOFT:
			softcontest(&list);
			break;
		case SAVE:
			savecontest(&list);
			break;
		case CLEAR:
			clearcontest(&list);
			break;
		default:
			printf("选择错误,请重新选择\n");
			fflush(stdin);
			break;
		}
	} while (input);
	return 0;
}
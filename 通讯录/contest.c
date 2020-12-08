#define _CRT_SECURE_NO_WARNINGS 1
#include"contest.h"

void menu()
{
	printf("************************************\n");
	printf("***** 1.�����ϵ�� 2.ɾ����ϵ��*****\n");
	printf("***** 3.�༭��ϵ�� 4.������ϵ��*****\n");
	printf("***** 5.��ʾ��ϵ�� 6.����      *****\n");
	printf("***** 7.����       8.���ͨѶ¼*****\n");
	printf("*****         0.�˳�           *****\n");
	printf("************************************\n");
}

//��ʼ��ͨѶ¼
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
			p->con = ptr;//����con��ʼλ
			p->nowcon += 2;//��ǰ��ϵ�����޼Ӷ�
			printf("���ݳɹ�\n");//�������
		}
		else
			printf("����ʧ��\n");
	}
}

void addcontest(struct CONTEST *p)
{
	checknowcon(p);
	printf("��������ϵ������:>");
	scanf("%s", p->con[p->size].name);
	printf("��������ϵ�˵绰:>");
	scanf("%s", p->con[p->size].tele);
	printf("��������ϵ���Ա�:>");
	scanf("%s", p->con[p->size].sex);
	printf("��������ϵ������:>");
	scanf("%d",&(p->con[p->size].age));
	printf("��������ϵ��סַ:>");
	scanf("%s", p->con[p->size].adress);
	p->size++;
	printf("��ӳɹ�\n");
}

void discontest(const struct CONTEST* p)
{
	if (p->size == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
	}
	else
	{
		printf("	��ϵ��			�绰			�Ա�			����			סַ\n");
		for (int i = 0; i < p->size; i++)
		{
			printf("	%-24s%-24s%-24s%-24d%-24s\n", p->con[i].name, p->con[i].tele, p->con[i].sex,p->con[i].age, p->con[i].adress);
		}
		//printf("%d", p->size);//��⵱ǰ��ϵ������
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
		printf("ͨѶ¼Ϊ��\n");
	else
	{
		char findman[NAME_MAX];
		printf("��������ϵ������:>");
		scanf("%s", findman);
		int ret = findcon(p, findman);
		if (ret == -1)
		{
			printf("��ϵ�˲�����\n");
		}
		else
		{
			for (ret; ret<p->size - 1; ret++)
			{
				p->con[ret] = p->con[ret + 1];
			}
			p->size--;
			printf("ɾ���ɹ�\n");
		}
	}
}

void findcontest(const struct CONTEST *p)
{
	if (p->size == 0)
		printf("ͨѶ¼Ϊ��\n");
	else
	{
		char findman[NAME_MAX];
		printf("��������ϵ������:>");
		scanf("%s", findman);
		int ret = findcon(p, findman);
		if (ret == -1)
		{
			printf("��ϵ�˲�����\n");
		}
		else
		{
			printf("	��ϵ��			�绰			�Ա�			����			סַ\n");
			printf("	%-24s%-24s%-24s%-24d%-24s\n", p->con[ret].name, p->con[ret].tele, p->con[ret].sex, 
				p->con[ret].age, p->con[ret].adress);
		}
	}
}

void deitcontest(struct CONTEST *p)
{
	if (p->size == 0)
		printf("ͨѶ¼Ϊ��\n");
	else
	{
		char findman[NAME_MAX];
		printf("��������ϵ������:>");
		scanf("%s", findman);
		int ret = findcon(p, findman);
		if (ret == -1)
		{
			printf("��ϵ�˲�����\n");
		}
		else
		{
			printf("	��ϵ��			�绰			�Ա�			����			סַ\n");
			printf("	%-24s%-24s%-24s%-24d%-24s\n", p->con[ret].name, p->con[ret].tele, p->con[ret].sex, p->con[ret].age, p->con[ret].adress);
			printf("��������ĺ����ϵ������:>");
			scanf("%s", p->con[ret].name);
			printf("��������ĺ����ϵ�˵绰:>");
			scanf("%s", p->con[ret].tele);
			printf("��������ĺ����ϵ���Ա�:>");
			scanf("%s", p->con[ret].sex);
			printf("��������ĺ����ϵ������:>");
			scanf("%d", &(p->con[ret].age));
			printf("��������ĺ����ϵ��סַ:>");
			scanf("%s", p->con[ret].adress);
			printf("�༭�ɹ�\n");
			printf("	��ϵ��			�绰			�Ա�			����			סַ\n");
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
		printf("ͨѶ¼Ϊ��\n");
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
		printf("����ɹ�\n");
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
	printf("ɾ���ɹ�\n");
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
	init_list(&list);//��ʼ��ͨѶ¼
	do
	{
		menu();
		printf("��ѡ��:>");
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
			printf("ѡ�����,������ѡ��\n");
			fflush(stdin);
			break;
		}
	} while (input);
	return 0;
}
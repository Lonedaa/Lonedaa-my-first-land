#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define STANUM 3
#define NAME_MAX 20
#define SEX_MAX 5
#define COMPANY_MAX 20
#define TELE_MAX 20
#define ADRESS_MAX 20

//��ϵ����Ϣ
struct peopinfo
{
	char name[NAME_MAX];
	char tele[TELE_MAX];
	char sex[SEX_MAX];
	int age;
	char adress[ADRESS_MAX];
};

//ͨѶ¼��Ϣ


struct CONTEST
{
	int size;//ͨѶ¼��ϵ�˵ĸ���
	int nowcon;//��ǰ��ϵ�˴洢����
	struct peopinfo *con;//��ϵ����Ϣ
};

enum choice//����ѡ��
{
	EXIT,
	ADD,
	DEL,
	EDIT,
	FIND,
	DIS,
	SOFT,
	SAVE,
	CLEAR
};

//��������
void init_list(struct CONTEST* p);//��ʼ��ͨѶ¼
void loadcontest(struct CONTEST *p);//���ݳ�ʼ��
void checknowcon(struct CONTEST*p);//��鵱ǰ��ϵ�����Ƿ�ﵽͨѶ¼���ޣ��ﵽ������
void addcontest(struct CONTEST* p);//�����ϵ��
void discontest(const struct CONTEST* p);//��ʾ��ϵ��
void delcontest(struct CONTEST *p);//ɾ����ϵ��
void findcontest(const struct CONTEST *p);//��ѯ��ϵ��
void deitcontest(struct CONTEST *p);//�༭��ϵ��
void softcontest(struct CONTESET *p);//������ϵ��
void freemem(struct CONTEST *p);//�ͷ��ڴ�
void savecontest(struct CONTEST *p);//������ϵ��
void clearcontest(struct CONTEST*p);//�����ϵ��
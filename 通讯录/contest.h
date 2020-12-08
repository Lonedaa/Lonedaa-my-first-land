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

//联系人信息
struct peopinfo
{
	char name[NAME_MAX];
	char tele[TELE_MAX];
	char sex[SEX_MAX];
	int age;
	char adress[ADRESS_MAX];
};

//通讯录信息


struct CONTEST
{
	int size;//通讯录联系人的个数
	int nowcon;//当前联系人存储上限
	struct peopinfo *con;//联系人信息
};

enum choice//功能选择
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

//函数声明
void init_list(struct CONTEST* p);//初始化通讯录
void loadcontest(struct CONTEST *p);//数据初始化
void checknowcon(struct CONTEST*p);//检查当前联系人数是否达到通讯录上限，达到则扩容
void addcontest(struct CONTEST* p);//添加联系人
void discontest(const struct CONTEST* p);//显示联系人
void delcontest(struct CONTEST *p);//删除联系人
void findcontest(const struct CONTEST *p);//查询联系人
void deitcontest(struct CONTEST *p);//编辑联系人
void softcontest(struct CONTESET *p);//排序联系人
void freemem(struct CONTEST *p);//释放内存
void savecontest(struct CONTEST *p);//保存联系人
void clearcontest(struct CONTEST*p);//清空联系人
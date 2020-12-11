#define _CRT_SECURE_NO_WARNINGS 1
#include"test.h"
//�˵���ĳ�ʼ���Լ��ӿ�ʵ��

Person::Person()
{
	name = "�����ͽ����";
	age = 17;
	account = "1234567890";
	password = "0987654321";
	money = 20000;
	phone = new Phone;
}

Person::Person(const Person& P)
{
	name = P.name;
	age = P.age;
	account = P.account;
	password = P.password;
	money = P.money;
	if (phone != NULL)
	{
		delete phone;
		phone = NULL;
	}
	phone = new Phone(*P.phone);
	
}

void Person::setpassword(string newword)
{
	password = newword;
}

string Person::getpassword()
{
	return password;
}

//��һ��Person�����ͣ��ڶ�����������
Person Person:: operator+(Person& P)//��ֵ����ʽ���ؾֲ�����Ҫ�õ�����������
{
	Person tmp;
	tmp.age = this->age + P.age;
	tmp.money = this->money + P.money;
	return tmp;
}

ostream & operator<<(ostream &out,Person& P)
{
	out << P.name << endl;
	out << P.age << endl;
	out << P.phone->brand << endl;
	out << P.money;
	return out;
}

Person& Person::operator++()
{
	++money;
	return *this;
}

Person tmp;
Person& Person:: operator++(int)
{
	tmp = *this;
	this->money++;
	return tmp;
}

Person& Person:: operator=(Person& P)
{
	name = P.name;
	age = P.age;
	account = P.account;
	password = P.password;
	money = P.money;
	if (phone != NULL)
	{
		delete phone;
		phone = NULL;
	}
	phone = new Phone(*P.phone);
	return *this;
}

bool Person::operator==(Person&P)
{
	if (name == P.name && age == P.age && account == P.account)//����д�ˣ��Ե�һЩ����
		return 1;
	return 0;
}

int Person::operator()(int a, int b)
{
	return (a + b);
}

Person::~Person()
{
	delete phone;
	cout << "�������������ͷ��ڴ�" << endl;
}
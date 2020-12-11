#define _CRT_SECURE_NO_WARNINGS 1
#include"test.h"
//人的类的初始化以及接口实现

Person::Person()
{
	name = "法外狂徒张三";
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

//第一个Person是类型，第二个是作用域；
Person Person:: operator+(Person& P)//以值的形式返回局部对象要用到拷贝函数；
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
	if (name == P.name && age == P.age && account == P.account)//懒得写了，略掉一些类型
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
	cout << "调用析构函数释放内存" << endl;
}
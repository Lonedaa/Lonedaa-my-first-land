#define _CRT_SECURE_NO_WARNINGS 1
#include"test.h"
string Phone::Cpu = "麒麟970";

//手机类的初始化以及接口实现

Phone::Phone() :brand("华为"), price(4999), password("000000")
{
	
}

Phone::Phone(const Phone& P)
{
	this->brand = P.brand;
	this->price = P.price;
	this->password = P.password;
}

Phone Phone::operator+(Phone& P)//局部函数调用结束就会销毁所以只能进行值返回
{
	Phone tmp;
	tmp.price = this->price + P.price;
	return tmp;
}

string Phone::getpassword()//提供外部接口，方便取出数据
{
	return password;
}

void Phone::setCPU()
{
	Cpu = "麒麟980";
}

string Phone::getCPU()
{
	return Cpu;
}

Phone::~Phone()
{
	cout << "调用析构函数" << endl;
}
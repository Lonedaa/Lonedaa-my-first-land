#define _CRT_SECURE_NO_WARNINGS 1
#include"test.h"
string Phone::Cpu = "����970";

//�ֻ���ĳ�ʼ���Լ��ӿ�ʵ��

Phone::Phone() :brand("��Ϊ"), price(4999), password("000000")
{
	
}

Phone::Phone(const Phone& P)
{
	this->brand = P.brand;
	this->price = P.price;
	this->password = P.password;
}

Phone Phone::operator+(Phone& P)//�ֲ��������ý����ͻ���������ֻ�ܽ���ֵ����
{
	Phone tmp;
	tmp.price = this->price + P.price;
	return tmp;
}

string Phone::getpassword()//�ṩ�ⲿ�ӿڣ�����ȡ������
{
	return password;
}

void Phone::setCPU()
{
	Cpu = "����980";
}

string Phone::getCPU()
{
	return Cpu;
}

Phone::~Phone()
{
	cout << "������������" << endl;
}
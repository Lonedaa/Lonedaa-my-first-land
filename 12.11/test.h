#define _CRT_SECURE_NO_WARNINGS 1
using namespace std;
#include<iostream>
#include<string>

#ifndef _TEST_H 
#define	_TEST_H 
class Phone;
class Person
{
	//��Ԫ
	friend ostream & operator<<(ostream& cout, Person& P);//���������ֻ����һ������Ҫ������&cout
public:
	Person();
	Person(const Person& P);
	Person operator+(Person& P);
	void setpassword(string newword);
	string getpassword();
	Person & operator++(int);
	Person &operator++();
	Person& operator=(Person& P);
	bool operator==(Person&P);
	int operator()(int a, int b);
	~Person();
public:
	string name;
	int age;
	string account;
	Phone *phone;
private:
	int money;
	string password;
};

class Phone
{
public:
	Phone();
	Phone(const Phone& P);
	Phone operator+(Phone& P);
	string getpassword();
	static void setCPU();
	static string getCPU();
	~Phone();
public:
	string brand;
	int price;
	static string Cpu;
private:
	string password;
};
#endif
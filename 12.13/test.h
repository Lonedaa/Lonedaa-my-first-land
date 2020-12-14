#define _CRT_SECURE_NO_WARNINGS 1
using namespace std;
#include<string>
#include<fstream>
#include<iostream>

class A
{
	friend class B;
public:
	int a;
private:
	int c;
};

class B
{
public:
	void out()
	{
		cout << A_.a << endl;
		cout << A_.c << endl;
	}
public:
	A A_;
};

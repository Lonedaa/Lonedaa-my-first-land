#define _CRT_SECURE_NO_WARNINGS 1
#include<string>
#include<iostream>

using namespace std;

class Wearing
{
public:
	void wearing()
	{
		cout << "红领巾，校服，校卡" << endl;
	}
};

class Father1
{

public:
	int a;
protected:
	int b;
private:
	int c;
};

class Dad1
{
public:
	Dad1()
	{
		cout << "调用dad构造函数" << endl;
	}
	~Dad1()
	{
		cout << "调用dad析构函数" << endl;
	}
};

class Base
{
public:
	Base()
	{
		a = 10;
	}
	int a;
	void visit()
	{
		cout << "正在访问父类中的成员函数" << endl;
	}
};

class A
{
public:
	virtual void out()
	{
		cout << a << endl;
	}
	int a;
};

class B:virtual public A
{
public:
	B()
	{
		a = 10;
	}
	void out()
	{
		cout << a << endl;
	}
};

class C :virtual public A
{
public:
	C()
	{
		a = 20;
	}
	void out()
	{
		cout << a << endl;
	}
};

class D : public B, public C
{
public:
	D()
	{
		a = 30;
	}
	void out()
	{
		cout << a << endl;
		/*cout << B::a << endl;
		cout << C::a << endl;*/
	} 
};

class Calculator
{
public:
	virtual int cal()
	{
		return 0;
	}
	int a;
	int b;
};

class Add :public Calculator
{
public:
	int cal()
	{
		return a + b;
	}
};

class Sub :public Calculator
{
public:
	int cal()
	{
		return a - b;
	}
};

class Mul :public Calculator
{
public:
	int cal()
	{
		return a * b;
	}
};

class Div :public Calculator
{
public:
	int cal()
	{
		return a / b;
	}
};

class Animal//纯虚函数   有纯虚函数的类成为抽象类
{
public:
	virtual void animal() = 0;
	int a;
	/*virtual ~Animal()
	{
		cout << "释放父类" << endl;
	}*/
	virtual ~Animal() = 0;
};
Animal::~Animal()
{
	cout << "释放父类" << endl;
}

class Pig :public Animal
{
public:
	void animal()
	{
		a = 10;
		cout << a << endl;
		cout << "猪在叫" << endl;
	}
	~Pig()
	{
		cout << "释放子类" << endl;
	}
};
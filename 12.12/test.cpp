//继承和多态学习————代码草稿

#include"test.h"

class Student :public Wearing
{
public:
	void name()
	{
		cout << "张三" << endl;
	}
};

class Son1 :public Father1
{
	void out()
	{
		a = 20;
		b = 30;
		//c = 40;//c是父类的私有成员，不能继承
	}
};

class Son2 :protected Father1
{
	void out()
	{
		a = 20;
		b = 30;
		//c = 40;//c是父类的私有成员，不能继承
	}
};

class Son3 :private Father1
{
	void out()
	{
		a = 20;
		b = 30;
		//c = 40;//c是父类的私有成员，不能继承
	}
};

class grandson :public Son3
{
	void out()
	{
		//a = 10;因为son3在继承时是私有继承，
		        //所以继承后的成员权限都是私有权限
		//b = 10;
	}
};

class Son4:public Dad1
{
public:
	Son4()
	{
		cout << "调用son构造函数" << endl;
	}
	~Son4()
	{
		cout << "调用son析构函数" << endl;
	}
};

class Son5 :public Base
{
public:
	Son5()
	{
		a = 20;
	}
	int a;
	void visit()
	{
		cout << "正在访问子类中的成员函数" << endl;
	}
};

void test()
{
	Student zs;
	zs.name();
	zs.wearing();
}

//void test01()
//{
//	Son1 x;
//	Son2 y;
//	Son3 z;
//	x.a = 40;
//	//x.b = 30;公有继承除了私有成员外都是按原有权限继承，此时b为保护权限
//	//x.c = 50;c为私有权限，未继承过来
//	//y.a = 30;保护权限继承除了私有权限成员之外都是按保护权限继承过来
//	//y.b = 30;因此除了c没有继承过来其他的都是保护权限，外部无法访问
//	//y.c = 30;
//	//z.a = 10;私有全新啊继承除了私有权限成员之外都是按私有权限继承过来
//	//z.b = 10;因此除了c没有继承过来之外其他的都是私有权限，外部无法访问
//	//z.c = 10;
//}

void test02()
{
	Son4 s1;
}

void test03()
{
	Son5 s;
	cout << s.a << endl;
	cout << s.Base::a << endl; 
	s.visit();
	s.Base::visit();
}

void test04()
{
	B b;
	C c;
	D d;
	b.out();
	c.out();
	d.out();
}

//----------------------多态---------------------------------------

void out_(A & a)//动态多态满足条件：要有继承关系，子类要重写父类的虚函数
{
	a.out();//动态多态的使用：父类的指针后者引用执行子类的对象
}

void test05()
{
	B b;
	C c;
	D d;
	out_(b);
	out_(c);
	out_(d);
}

void test06()
{
	Calculator *cal = new Add;
	cal->a = 10;
	cal->b = 20;
	cout << cal->cal() << endl;
	delete cal;
	cal = NULL;
}

void test07()
{
	Animal * A = new Pig;
	A->animal();
	delete A;
}

int main()
{
	//test();
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	//test06();
	test07();
	system("PAUSE");
	return 0;
}

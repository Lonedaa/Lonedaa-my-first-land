//�̳кͶ�̬ѧϰ������������ݸ�

#include"test.h"

class Student :public Wearing
{
public:
	void name()
	{
		cout << "����" << endl;
	}
};

class Son1 :public Father1
{
	void out()
	{
		a = 20;
		b = 30;
		//c = 40;//c�Ǹ����˽�г�Ա�����ܼ̳�
	}
};

class Son2 :protected Father1
{
	void out()
	{
		a = 20;
		b = 30;
		//c = 40;//c�Ǹ����˽�г�Ա�����ܼ̳�
	}
};

class Son3 :private Father1
{
	void out()
	{
		a = 20;
		b = 30;
		//c = 40;//c�Ǹ����˽�г�Ա�����ܼ̳�
	}
};

class grandson :public Son3
{
	void out()
	{
		//a = 10;��Ϊson3�ڼ̳�ʱ��˽�м̳У�
		        //���Լ̳к�ĳ�ԱȨ�޶���˽��Ȩ��
		//b = 10;
	}
};

class Son4:public Dad1
{
public:
	Son4()
	{
		cout << "����son���캯��" << endl;
	}
	~Son4()
	{
		cout << "����son��������" << endl;
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
		cout << "���ڷ��������еĳ�Ա����" << endl;
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
//	//x.b = 30;���м̳г���˽�г�Ա�ⶼ�ǰ�ԭ��Ȩ�޼̳У���ʱbΪ����Ȩ��
//	//x.c = 50;cΪ˽��Ȩ�ޣ�δ�̳й���
//	//y.a = 30;����Ȩ�޼̳г���˽��Ȩ�޳�Ա֮�ⶼ�ǰ�����Ȩ�޼̳й���
//	//y.b = 30;��˳���cû�м̳й��������Ķ��Ǳ���Ȩ�ޣ��ⲿ�޷�����
//	//y.c = 30;
//	//z.a = 10;˽��ȫ�°��̳г���˽��Ȩ�޳�Ա֮�ⶼ�ǰ�˽��Ȩ�޼̳й���
//	//z.b = 10;��˳���cû�м̳й���֮�������Ķ���˽��Ȩ�ޣ��ⲿ�޷�����
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

//----------------------��̬---------------------------------------

void out_(A & a)//��̬��̬����������Ҫ�м̳й�ϵ������Ҫ��д������麯��
{
	a.out();//��̬��̬��ʹ�ã������ָ���������ִ������Ķ���
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

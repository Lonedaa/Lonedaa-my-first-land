#define _CRT_SECURE_NO_WARNINGS 1
using namespace std;
#include<iostream>
#include<string>
//class PEOPLE;
//class GoodGay
//{
//	friend class PEOPLE;
//public:
//	GoodGay();
//	string room;
//private:
//	string living;
//};
//
//GoodGay::GoodGay()
//{
//	room = "����";
//	living = "����";
//	cout << "creat successful" << endl;
//}
//
//class Phone
//{
//public:
//	Phone()
//	{
//
//	}
//	Phone(string phone_, int price_) :phone(phone_), price(price_)
//	{
//		cout << "�����вι���111" << endl; 
//	}
//	~Phone()
//	{
//		cout << "������������111" << endl;
//	}
//	void setpname(string pname)
//	{
//		phone = pname;
//	}
//	string getpname()
//	{
//		return phone;
//	}
//	string phone;
//	int price;
//};
//class PEOPLE
//{
//	friend void goodgay(PEOPLE*gay);//��Ԫ
//
//public:
//	GoodGay *gg;
//	PEOPLE()
//	{
//		cout << "�����޲ι���" << endl;
//		age = 10;
//		gg = new GoodGay;
//	}
//	~PEOPLE()
//	{
//		cout << "������������" << endl;
//	}
//	PEOPLE(string name__, int height_,string namep,int price) :
//		age(10), name(name__), height(new int(height_)), phone(namep,price)
//	{
//		cout << "�����вι���" << endl;
//		gg = new GoodGay;
//	}
//	PEOPLE(const PEOPLE &P)
//	{
//		cout << "���ÿ�������" << endl;
//		gg = new GoodGay;
//		age = P.age;
//	}
//	int* getheight()
//	{
//		return height;
//	}
//	PEOPLE& addage(int age_)
//	{
//		age += age_;
//		return *this;
//	}
//	void setname(string name_)
//	{
//		name = name_;
//	}
//	void setage(int age_)
//	{
//		if (this == NULL)
//			return;
//		age = age_;
//	}
//	int getage()
//	{
//		if (this == NULL)
//			return 0;
//		return age;
//	}
//	void setpname(string pname)
//	{
//		phone.setpname(pname);
//	}
//	string getname()
//	{
//		return name;
//	}
//	string getpname()
//	{
//		return phone.getpname();
//	}
//	static void print()
//	{
//		hair = 10;
//		cout << "��̬��������" << endl;
//	}
//	void setgrade(string grade_)const
//	{
//		grade = grade_;
//	}
//	string getgrade()
//	{
//		return grade;
//	}
//	void visit();
//	void visit01();
//private:
//	mutable string grade;
//	static int hair;
//	Phone phone;
//	int age;
//	string name;
//	int *height;
//};
//
//
//
//int PEOPLE::hair = 0;
//void PEOPLE::visit()
//{
//	cout << "���ڷ��ʺû��ѵģ�" << gg->room << endl;
//	cout << "���ڷ��ʺû��ѵģ�" << gg->living << endl;
//}
//
//void PEOPLE::visit01()
//{
//	cout << "���ڷ��ʺû��ѵģ�" << gg->room << endl;
//	cout << "���ڷ��ʺû��ѵģ�" << gg->living << endl;
//}

//class Building;
//
//class GoodGay
//{
//public:
//	GoodGay();
//	void visit();
//	void visit01();
//public:
//	Building *gg;
//private:
//	string name;
//};
//
//class Building
//{
//	friend void GoodGay::visit();
//public:
//	Building();
//	Building(const Building& g)
//	{
//		living = g.living;
//		room = g.room;
//	}
//public:
//	string living;
//private:
//	string room;
//};
//
//Building::Building()
//{
//	living = "����";
//	room = "����";
//}
//
//GoodGay::GoodGay()
//{
//	name = "����";
//	gg = new Building;
//}
//
//void GoodGay::visit()
//{
//	cout << "���ڷ��ʺû��ѵģ� " << gg->living << endl;
//	cout << "���ڷ��ʺû��ѵģ� " << gg->room << endl;
//}
//
//void GoodGay::visit01()
//{
//	cout << "���ڷ��ʺû��ѵģ� " << gg->living << endl;
//	//cout << "���ڷ��ʺû��ѵģ� " << gg->room << endl;
//}



class Number
{
	//friend ostream operator<<(ostream out, Number N);
public:
	Number()
	{
		a = 10;
		b = 20;
	}
	Number(const Number&P)
	{
		a = P.a;
		b = P.b;
	}
	Number operator+ (Number& P)
	{
		Number temp;
		temp.a = a + P.a;
		temp.b = b + P.b;
		return temp;
	}
public:
	int a;
	int b;
};

ostream & operator<<(ostream &out, Number &N)
{
	out << "a��ֵ��" << N.a << "  b��ֵ��" << N.b;
	return out;
}






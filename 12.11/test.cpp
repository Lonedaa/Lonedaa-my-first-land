#define _CRT_SECURE_NO_WARNINGS 1
#include"test.h"

void test()
{
	Person P1;
	Person P2;
	cout << P1.phone->brand << endl;
	cout << P1.phone->price << endl;
	cout << P1.phone->getpassword() << endl;
	cout << P1 << endl;
	cout << P1.phone->price << endl;
	P1.phone->setCPU();
	P2 = P1;
	if (P1 == P2)
	{
		cout << "P1ºÍP2ÏàµÈ" << endl;
	}
	cout << P2.phone->brand << endl;
	cout << P2.phone->price << endl;
	cout << P2.phone->getpassword() << endl;
	cout << P2 << endl;
	cout << P2.phone->price << endl;
	cout << ++(P2++) << endl;
	cout << P2++<< endl;
	cout << P2++ << endl;
	cout << P2 << endl;
	cout << P1(200, 300) << endl;
	cout << Person()(200, 300) << endl;
}

int main()
{
	test();
	system("PAUSE");
	return 0;
}
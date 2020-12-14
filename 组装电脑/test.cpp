#include"test.h"

void test()
{
	IntelCPU*Cpu = new IntelCPU;
	IntelDisplayCord*Dis = new IntelDisplayCord;
	IntelMemry*Mem = new IntelMemry;
	Computer*Com = new Computer(Cpu, Dis, Mem);
	Com->work();
}

int main()
{
	test();
	system("PAUSE");
	return 0;
}
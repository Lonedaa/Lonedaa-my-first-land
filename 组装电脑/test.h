#define _CRT_SECURE_NO_WARNINGS 1
using namespace std;
#include<string>
#include<iostream>

class CPU
{
public:
	virtual void cpu() = 0;
};

class DisplayCord
{
public:
	virtual void dis() = 0;
};

class Memry
{
public:
	virtual void mem() = 0;
};

class Computer
{
public:
	Computer(CPU* cpu, DisplayCord*dis, Memry*mem)
	{
		m_cpu = cpu;
		m_dis = dis;
		m_mem = mem;
	}
	void work()
	{
		m_cpu->cpu();
		m_dis->dis();
		m_mem->mem();
	}
public:
	CPU *m_cpu;
	DisplayCord* m_dis;
	Memry* m_mem;
};

class IntelCPU :public CPU
{
public:
	void cpu()//��д�麯��
	{
		cout << "CPU���ڹ���" << endl;
	}
};

class IntelDisplayCord :public DisplayCord
{
public:
	void dis()//��д�麯��
	{
		cout << "DisplayCord���ڹ���" << endl;
	}
};

class IntelMemry :public Memry
{
public:
	void mem()//��д�麯��
	{
		cout << "Memry���ڹ���" << endl;
	}
};
#include"test.h"


void test()
{
	ofstream ofs;//�������������
	ofs.open("test.txt", ios::out);
	//�����ʱ���ָ���ļ�δ�������Զ��������ļ�
	if (!ofs.is_open())//������һ��ע�ͣ�������жϿ���ʡ��
	{
		cout << "��ʧ��" << endl;
		return;
	}
	ofs << "���� " << "17 " << "��";
	ofs.close();


	//��ȡ�ļ�
	ifstream ifs;
	ifs.open("test.txt", ios::in);
	//��ȡ�ļ�ʱû��ָ���ļ�ʱ�ͻ᷵�ؿ�ָ��NULL
	if (!ifs.is_open())
	{
		cout << "���ļ�ʧ��" << endl;
		return;
	}
	//��ȡ�ļ�ʱҪ��һ���������洢����
	/*char buf[1024] = { 0 };
	while (ifs.getline(buf, sizeof(buf)))
	{
		cout << buf << endl;
	}*/
	string buf_;
	while(getline(ifs, buf_))
	{
		cout << buf_ << endl;
	}
	ifs.close();


	//�������ļ����
	ofs.open("test.txt", ios::out | ios::binary);
	int p = 10;
	ofs.write((const char*)&p, sizeof(int));
	ofs.close();

	//�������ļ�д��
	ifs.open("test.txt", ios::in | ios::binary);
	int q;
	ifs.read((char*)&q, sizeof(int));
	cout << q << endl;
	ifs.close();

}


int main()
{
	test();
	system("PAUSE");
	return 0;
}
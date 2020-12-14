#include"test.h"


void test()
{
	ofstream ofs;//创建输出流对象
	ofs.open("test.txt", ios::out);
	//输出流时如果指定文件未创建会自动创建该文件
	if (!ofs.is_open())//根据上一句注释，这里的判断可以省略
	{
		cout << "打开失败" << endl;
		return;
	}
	ofs << "张三 " << "17 " << "男";
	ofs.close();


	//读取文件
	ifstream ifs;
	ifs.open("test.txt", ios::in);
	//读取文件时没有指定文件时就会返回空指针NULL
	if (!ifs.is_open())
	{
		cout << "打开文件失败" << endl;
		return;
	}
	//读取文件时要有一个容器出存储数据
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


	//二进制文件输出
	ofs.open("test.txt", ios::out | ios::binary);
	int p = 10;
	ofs.write((const char*)&p, sizeof(int));
	ofs.close();

	//二进制文件写入
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
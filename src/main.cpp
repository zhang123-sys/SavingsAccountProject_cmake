//main.cpp
#include "account.h"
#include <iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<sstream>
using namespace std;
void menu(string msg);
struct deleter
{
	template<class T>
	void operator()(T* p) {
		delete p;
	}
};
class Controller //�����������������˻��б��ʹ�������
{
private:
	Date date;					//��ǰ����
	vector<Account*>accounts;	//�˻��б�
	bool end;					//�û��Ƿ��������˳�����
public:
	Controller(const Date& date) :date(date), end(false) {}
	~Controller();
	const Date& getDate()const { return date; }
	bool isEnd()const { return end; }
	//ִ��һ�����������ظ������Ƿ�ı��˵�ǰ״̬�����Ƿ���Ҫ��������
	bool runCommand(const string& cmdLine);
};

Controller::~Controller()
{
	for_each(accounts.begin(), accounts.end(), deleter());
}
bool Controller::runCommand(const string& cmdLine)
{
	istringstream str(cmdLine);
	char cmd, type;
	int index, day;
	double amount;
	string desc;
	Account* account;
	Date date1, date2;
	bool flag = false;//�Ƿ�ı�״̬

	str >> cmd;
	switch (cmd)
	{
	case 'a':	//�����˻�
		//menu("(1)savingsAccount (2)creditAccount");
		str >> type;
		if (type == 's')
		{
			account = new SavingsAccount(date, "S" + to_string(accounts.size()));
		}
		else if (type == 'c')
		{
			account = new CreditAccount(date, "C" + to_string(accounts.size()));
		}
		accounts.push_back(account);
		flag = true;
		break;
	case 'd':	//�����ֽ�
		str >> index >> amount;
		getline(str, desc);
		accounts[index]->deposit(date, amount, desc);
		flag = true;
		break;
	case 'w':	//ȡ���ֽ�
		str >> index >> amount;
		getline(str, desc);
		accounts[index]->withdraw(date, amount, desc);
		flag = true;
		break;
	case 's':	//��ѯ���˻���Ϣ
		for (size_t i = 0; i < accounts.size(); i++)
		{
			cout << "[" << i << "] " << *(accounts[i]) << endl;
		}
		break;
	case 'c':	//�ı�����
		str >> day;
		if (day < date.getDay())
		{
			cout << "You cannot specify a previous day";
		}
		else if (day > date.getMaxDay()) {
			cout << "Invalid day";
		}
		else
		{
			date = Date(date.getYear(), date.getMonth(), day);
		}
		flag = true;
		break;
	case 'n':	//�����¸���
		if (date.getMonth() == 12)
		{
			date = Date(date.getYear() + 1, 1, 1);
		}
		else
		{
			date = Date(date.getYear(), date.getMonth() + 1, 1);
		}
		for (auto account : accounts)
		{
			account->settle(date);
		}
		flag = true;
		break;
	case 'q':	//��ѯһ��ʱ���ڵ���Ŀ
		str >> date1 >> date2;
		Account::query(date1, date2);
		break;
	case 'e':	//�˳�
		end = true;
		break;
	default:
		cerr << "Invalid command: " << cmdLine << endl;
	}
	return flag;
}

int main() {
	Date date(2022, 11, 1);	//��ʼ����
	Controller controller(date);
	string cmdLine;
	const char* FILE_NAME = "../resources/commands.txt";

	ifstream fileIn(FILE_NAME);	//�Զ�ģʽ���ļ�
	if (fileIn)	//��������򿪣���ִ���ļ��е�ÿһ������
	{
		while (getline(fileIn, cmdLine))
		{
			try
			{
				controller.runCommand(cmdLine);
			}
			catch (const exception& e)
			{
				cout << "Bad line in " << FILE_NAME << ": " << cmdLine << endl;
				cout << "Error: " << e.what() << endl;
				return 1;
			}
		}
		fileIn.close();	//�ر��ļ�
	}

	ofstream fileOut(FILE_NAME, ios_base::app);	//��׷��ģʽ
	menu("(a)add account (d)deposit (w)withdraw (s)show (c)change day (n)next month (q)query (e)exit");
	while (!controller.isEnd())	//�ӱ�׼����������ִ�У�ֱ���˳�
	{
		cout << controller.getDate() << "\tTotal: " << Account::getTotal() << "\tcommand> ";
		string cmdLine;
		getline(cin, cmdLine);
		try
		{
			if (controller.runCommand(cmdLine)) {
				fileOut << cmdLine << endl;	//������д���ļ�
			}
		}
		catch (const AccountException& e)
		{
			cout << "Error(#" << e.getAccount()->getId() << "): " << e.what() << endl;
		}
		catch (const exception& e)
		{
			cout << "Error: " << e.what() << endl;
		}
	}
	return 0;
}



void menu(string msg) {
	cout << msg << endl;
}


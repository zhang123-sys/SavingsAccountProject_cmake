//account.h
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__
#include<string>
#include<map>
#include"date.h"
#include "accumulator.h"

class Account; //ǰ������

using namespace std;

class AccountRecord	//��Ŀ��¼
{
private:
	Date date;				 //����
	const Account* account;  //�˻�
	double amount;			 //���
	double balance;			//���
	string desc;		//����
public:
	AccountRecord(const Date& date, const Account* account, double amount, double balance, const string& desc);
	void show()const;	//�����ǰ��¼
};

class AccountException :public runtime_error
{
private:
	const Account* account;
public:
	AccountException(const Account* account, const string& msg)
		:runtime_error(msg), account(account) {}
	const Account* getAccount()const { return account; }
	~AccountException()
	{
	}

private:

};


//���������洢��Ŀ��¼�Ķ���ӳ������
typedef multimap<Date, AccountRecord>RecordMap;

class Account //�˻���
{
private:
	string id;				//�˺�
	double balance;			//���
	static double total;	//�����˻����ܽ��
	static RecordMap recordMap;	//��Ŀ��¼
protected:
	//����������õĹ��캯����idΪ�˻�
	Account(const Date& date, const string& id); //���캯��
	//��¼һ���ʣ�dateΪ���ڣ�amountΪ��descΪ˵��
	void record(const Date& date, double amount, const string& desc);
	//���������Ϣ
	void error(const string& msg)const;
public:
	const string& getId() const { return id; }
	double getBalance() const { return balance; }
	static double getTotal() { return total; }
	//��ʾ�˻���Ϣ
	virtual void show(ostream& out) const;
	//�����ֽ�dateΪ���ڣ�amountΪ��descΪ����˵��
	virtual void deposit(const Date& date, double amount, const string& desc) = 0;
	//ȡ���ֽ�dateΪ���ڣ�amountΪ��descΪ����˵��
	virtual void withdraw(const Date& date, double amount, const string& desc) = 0;
	//���㣨������Ϣ����ѵȣ���ÿ�½���һ�Σ�dateΪ��������
	virtual void settle(const Date& date) = 0;
	//��ѯָ��ʱ����
	static void query(const Date& begin, const Date& end);
};


inline ostream& operator<<(ostream& out, const Account& account) //����<<�����
{
	account.show(out);
	return out;
}

class SavingsAccount : public Account { //�����˻���
private:
	Accumulator acc;	//����������Ϣ���ۼ���
	double rate;		//����������
public:
	SavingsAccount(const Date& date, const string& id, double rate = 0.015); //���캯��
	//SavingsAccount() :SavingsAccount(Date(), "sa1", 1.0) {}   //ί�й��캯��
	double getRate() const { return rate; }
	//�����ֽ�
	virtual void deposit(const Date& date, double amount, const string& desc);
	//ȡ���ֽ�
	virtual void withdraw(const Date& date, double amount, const string& desc);
	//������Ϣ��ÿ��1��1�յ���һ�θú���
	virtual void settle(const Date& date);
};

class CreditAccount :public Account //�����˻���
{
private:
	Accumulator acc;	//����������Ϣ���ۼ���
	double credit;		//���ö��
	double rate;		//Ƿ���������
	double fee;			//���ÿ����
	double getDebt()const {	//���Ƿ���
		double balance = getBalance();
		return (balance < 0 ? balance : 0);
	}
public:
	//���캯��
	CreditAccount(const Date& date, const string& id, double credit = 10000, double rate = 0.0005, double fee = 50);
	double getCredit() const { return credit; }
	double getRate() const { return rate; }
	double getFee() const { return fee; }
	double getAvailableCredit() const {	//��ÿ�������
		double balance = getBalance();
		if (balance < 0)
		{
			return credit + balance;
		}
		else
		{
			return credit;
		}
	}
	//�����ֽ�
	virtual void deposit(const Date& date, double amount, const string& desc);
	//ȡ���ֽ�
	virtual void withdraw(const Date& date, double amount, const string& desc);
	//������Ϣ��ÿ��1��1�յ���һ�θú���
	virtual void settle(const Date& date);
	//��ʾ�˻���Ϣ
	virtual void show(ostream& out) const;
};

#endif //__ACCOUNT_H__

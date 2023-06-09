//account.h
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__
#include<string>
#include<map>
#include"date.h"
#include "accumulator.h"

class Account; //前置声明

using namespace std;

class AccountRecord	//账目记录
{
private:
	Date date;				 //日期
	const Account* account;  //账户
	double amount;			 //金额
	double balance;			//余额
	string desc;		//描述
public:
	AccountRecord(const Date& date, const Account* account, double amount, double balance, const string& desc);
	void show()const;	//输出当前记录
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


//定义用来存储账目记录的多重映射类型
typedef multimap<Date, AccountRecord>RecordMap;

class Account //账户类
{
private:
	string id;				//账号
	double balance;			//余额
	static double total;	//所有账户的总金额
	static RecordMap recordMap;	//账目记录
protected:
	//供派生类调用的构造函数，id为账户
	Account(const Date& date, const string& id); //构造函数
	//记录一笔帐，date为日期，amount为金额，desc为说明
	void record(const Date& date, double amount, const string& desc);
	//报告错误信息
	void error(const string& msg)const;
public:
	const string& getId() const { return id; }
	double getBalance() const { return balance; }
	static double getTotal() { return total; }
	//显示账户信息
	virtual void show(ostream& out) const;
	//存入现金，date为日期，amount为金额，desc为款项说明
	virtual void deposit(const Date& date, double amount, const string& desc) = 0;
	//取出现金，date为日期，amount为金额，desc为款项说明
	virtual void withdraw(const Date& date, double amount, const string& desc) = 0;
	//结算（计算利息、年费等），每月结算一次，date为结算日期
	virtual void settle(const Date& date) = 0;
	//查询指定时间内
	static void query(const Date& begin, const Date& end);
};


inline ostream& operator<<(ostream& out, const Account& account) //重载<<运算符
{
	account.show(out);
	return out;
}

class SavingsAccount : public Account { //储蓄账户类
private:
	Accumulator acc;	//辅助计算利息的累加器
	double rate;		//存款的年利率
public:
	SavingsAccount(const Date& date, const string& id, double rate = 0.015); //构造函数
	//SavingsAccount() :SavingsAccount(Date(), "sa1", 1.0) {}   //委托构造函数
	double getRate() const { return rate; }
	//存入现金
	virtual void deposit(const Date& date, double amount, const string& desc);
	//取出现金
	virtual void withdraw(const Date& date, double amount, const string& desc);
	//结算利息，每年1月1日调用一次该函数
	virtual void settle(const Date& date);
};

class CreditAccount :public Account //信用账户类
{
private:
	Accumulator acc;	//辅助计算利息的累加器
	double credit;		//信用额度
	double rate;		//欠款的日利率
	double fee;			//信用卡年费
	double getDebt()const {	//获得欠款额
		double balance = getBalance();
		return (balance < 0 ? balance : 0);
	}
public:
	//构造函数
	CreditAccount(const Date& date, const string& id, double credit = 10000, double rate = 0.0005, double fee = 50);
	double getCredit() const { return credit; }
	double getRate() const { return rate; }
	double getFee() const { return fee; }
	double getAvailableCredit() const {	//获得可用信用
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
	//存入现金
	virtual void deposit(const Date& date, double amount, const string& desc);
	//取出现金
	virtual void withdraw(const Date& date, double amount, const string& desc);
	//结算利息，每年1月1日调用一次该函数
	virtual void settle(const Date& date);
	//显示账户信息
	virtual void show(ostream& out) const;
};

#endif //__ACCOUNT_H__

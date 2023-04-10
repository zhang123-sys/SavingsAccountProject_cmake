#pragma once
#include <iostream>
#include<cstdlib>
#include<stdexcept>
using namespace std;
class Date {		//日期类
private:
	int year;		//年
	int month;		//月
	int day;		//日
	int totalDays;  //该日期是从公元元年1月1日开始的第几天
public:
	Date(int year = 1, int month = 1, int day = 1);	//用年、月、日构造日期
	//Date() :Date(1, 1, 1) {}; //委托构造函数
	int getYear() const { return year; }
	int getMonth() const { return month; }
	int getDay() const { return day; }
	int getMaxDay() const;		//获得当月有多少天
	bool isLeapYear(int year) const	//判断当年是否为闰年
	{
		return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
	}
	//计算两个日期之间差多少天
	int operator-(const Date& date) const {
		return totalDays - date.totalDays;
	}
	//判断两个日期的前后顺序
	bool operator < (const Date& date) const
	{
		return totalDays < date.totalDays;
	}
	friend istream& operator>>(istream& in, Date& date); //重载>>运算符
	friend ostream& operator<<(ostream& out, const Date& date); //重载<<运算符
};


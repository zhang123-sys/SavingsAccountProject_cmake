#pragma once
#include <iostream>
#include<cstdlib>
#include<stdexcept>
using namespace std;
class Date {		//������
private:
	int year;		//��
	int month;		//��
	int day;		//��
	int totalDays;  //�������Ǵӹ�ԪԪ��1��1�տ�ʼ�ĵڼ���
public:
	Date(int year = 1, int month = 1, int day = 1);	//���ꡢ�¡��չ�������
	//Date() :Date(1, 1, 1) {}; //ί�й��캯��
	int getYear() const { return year; }
	int getMonth() const { return month; }
	int getDay() const { return day; }
	int getMaxDay() const;		//��õ����ж�����
	bool isLeapYear(int year) const	//�жϵ����Ƿ�Ϊ����
	{
		return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
	}
	//������������֮��������
	int operator-(const Date& date) const {
		return totalDays - date.totalDays;
	}
	//�ж��������ڵ�ǰ��˳��
	bool operator < (const Date& date) const
	{
		return totalDays < date.totalDays;
	}
	friend istream& operator>>(istream& in, Date& date); //����>>�����
	friend ostream& operator<<(ostream& out, const Date& date); //����<<�����
};


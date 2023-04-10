#include "date.h"
namespace {
	//namespaceʹ����Ķ���ֻ�ڵ�ǰ�ļ�����Ч
	//�洢ƽ����ĳ����1��֮ǰ�ж����죬Ϊ����getMaxDay������ʵ�֣���������һ��
	const int DAYS_BEFORE_MONTH[] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
}
Date::Date(int year, int month, int day) :year(year), month(month), day(day) {
	if (day <= 0 || day > getMaxDay())
	{
		cout << "Invalid date: " << *this << endl;
		//exit(1);
		throw runtime_error("Invalid date!");
	}
	int years = year - 1;
	totalDays = years * 365 + years / 4 - years / 100 + years / 400
		+ DAYS_BEFORE_MONTH[month - 1] + day;
	if (isLeapYear(year) && month > 2) {
		totalDays++;
	}
}

int Date::getMaxDay() const {
	if (isLeapYear(year) && month == 2)
	{
		return 29;
	}
	else
	{
		return DAYS_BEFORE_MONTH[month] - DAYS_BEFORE_MONTH[month - 1];
	}

}

ostream& operator<<(ostream& out, const Date& date) {
	out << date.year << "-" << date.month << "-" << date.day;
	return out;
}

istream& operator>>(istream& in, Date& date)
{
	int year, month, day;
	char c;
	in >> year >> c >> month >> c >> day;
	date = Date(year, month, day);
	return in;
}

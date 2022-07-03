#include <iostream>
#include <string>
using namespace std;

class Date
{
private:
	int day, month, year;
public:
	Date();
	Date(int, int, int);
	Date(const Date&);

	Date operator=(const Date& other) { if (this == &other) return *this; else { day = other.day; month = other.month; year = other.year; return *this; }; }
	bool operator>(Date other) { if ((year > other.year) || ((year == other.year) && (month > other.month)) || ((year == other.year) && (month == other.month) && (day > other.day))) return 1; else return 0; }
	bool operator<(Date other) { if ((year < other.year) || ((year == other.year) && (month < other.month)) || ((year == other.year) && (month == other.month) && (day < other.day))) return 1; else return 0; }
	bool operator==(Date other) { if ((year == other.year) && (month == other.month) && (day == other.day)) return 1; else return 0; }
	Date operator+=(int number) { return Date(day + number, month, year); }
	Date operator-=(int number) { return Date(day - number, month, year); }
	friend ostream& operator<<(std::ostream& os, const Date& date) { return os << date.day << "." << date.month << "." << date.year << endl; }
	friend istream& operator>>(std::istream& is, Date& date) { return is >> date.day >> date.month >> date.year; }
};

Date::Date()
{
	day = 0;
	month = 0;
	year = 0;
}

Date::Date(int _day, int _month, int _year)
{
	if (((_day > 31) || (_day <= 0)) && ((_month == 1) || (_month == 3) || (_month == 5) || (_month == 7) || (_month == 8) || (_month == 10) || (_month == 12)))
	{
		if (_day > 31)
		{
			day = _day - 31;
			_month += 1;
		}
		else
		{
			day = 31 - _day;
			_month -= 1;
		}
	}
	else
		if (((_day > 30) || (_day <= 0)) && ((_month == 4) || (_month == 6) || (_month == 9) || (_month == 11)))
		{
			if (_day > 30)
			{
				day = _day - 30;
				_month += 1;
			}
			else
			{
				day = 30 - _day;
				_month -= 1;
			}
		}
		else
			if (((_day > 28) || (_day <= 0)) && (_month == 2) && (_year % 4 != 0))
			{
				if (_day > 28)
				{
					day = _day - 28;
					_month += 1;
				}
				else
				{
					day = 28 - _day;
					_month -= 1;
				}
			}
			else
				if (((_day > 29) || (_day <= 0)) && (_month == 2) && (_year % 4 == 0))
				{
					if (_day > 29)
					{
						day = _day - 29;
						_month += 1;
					}
					else
					{
						day = 29 - _day;
						_month -= 1;
					}
				}
				else
					day = _day;
	if (_month > 12)
	{
		month = _month - 12;
		_year += 1;
	}
	else
		if (_month <= 0)
		{
			month = _month + 12;
			_year += 1;
		}
	month = _month;
	year = _year;
}

Date::Date(const Date& date)
{
	day = date.day;
	month = date.month;
	year = date.year;
}

int main()
{
	Date a, b;
	cin >> a;
	b = Date(4, 10, 2004);
	cout << "a = " << a << endl << "b = " << b << endl << "a > b? " << (a > b) << endl << "a += 20 == " << (a += 20);
}

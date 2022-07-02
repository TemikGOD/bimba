#include <iostream>
#include <locale>
using namespace std;

class Money
{
private:
	int rub, cop;
public:
	Money(int _rub, int _cop);
	Money(double number);
	Money(const Money& money);

	Money operator=(Money other) { return Money(other); }
	Money operator=(double other) { return Money(other); }
	bool operator>(Money other) { if ((rub == other.rub) && (cop > other.cop) || (rub > other.rub)) return 1; else return 0; }
	bool operator<(Money other) { if ((rub == other.rub) && (cop < other.cop) || (rub < other.rub)) return 1; else return 0; }
	bool operator==(Money other) { if ((rub == other.rub) && (cop == other.cop)) return 1; else return 0; }
	Money operator+(Money other) { return Money(rub + other.rub, cop + other.cop); }
	Money operator-(Money other) { return Money(rub - other.rub, cop - other.cop); }
	double operator/(Money other) { return (rub + cop * 0.01) / (other.rub + other.cop * 0.01); }
	Money operator/(int other) { return Money((rub + cop * 0.01) / other); }
	Money operator*(int other) { return Money(rub * other, cop * other); }
	friend ostream& operator<<(std::ostream& os, const Money& money) { return os << money.rub << " руб " << money.cop << " коп"; }
	//friend istream& operator>>(std::istream& is, const Money& money) { return is >> money; }
};

Money::Money(int _rub, int _cop)
{
	rub = _rub;
	if (_cop >= 100)
	{
		rub += _cop / 100;
		cop = _cop % 100;
	}
	else
		cop = _cop;
}

Money::Money(double number)
{
	rub = int(number);
	cop = int((number - rub) * 100);
}

Money::Money(const Money& money)
{
	rub = money.rub;
	cop = money.cop;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	Money a = 0;
	double e;
	cin >> e;
	a = e;
	Money b = 45.23;
	cout << (a < b) << " " << (a - b);
	return 0;
}
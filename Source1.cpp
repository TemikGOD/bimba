#include <iostream>
#include <locale>
#include <cmath>
using namespace std;

class Money
{
private:
	int rub, cop;
public:
	Money();
	Money(int _rub, int _cop);
	Money(double number);
	Money(const Money& money);

	Money operator=(const Money& other) { if (this == &other) return *this; else { rub = other.rub; cop = other. cop; return *this; }; }
	Money operator=(const double& other) { rub = int(other); cop = (other - rub) * 100; return *this; }
	bool operator>(Money other) { if ((rub == other.rub) && (cop > other.cop) || (rub > other.rub)) return 1; else return 0; }
	bool operator<(Money other) { if ((rub == other.rub) && (cop < other.cop) || (rub < other.rub)) return 1; else return 0; }
	bool operator==(Money other) { if ((rub == other.rub) && (cop == other.cop)) return 1; else return 0; }
	Money operator+(Money other) { return Money(rub + other.rub, cop + other.cop); }
	Money operator-(Money other) { return Money(rub - other.rub, cop - other.cop); }
	double operator/(Money other) { return (rub + cop * 0.01) / (other.rub + other.cop * 0.01); }
	Money operator/(int other) { return Money((rub + cop * 0.01) / other); }
	Money operator*(int other) { return Money(rub * other, cop * other); }
	friend ostream& operator<<(std::ostream& os, const Money& money) { return os << money.rub << " руб " << money.cop << " коп"; }
	friend istream& operator>>(std::istream& is, Money& money) { return is >> money.rub >> money.cop; }
};

Money::Money()
{
	rub = 0;
	cop = 0;
}

Money::Money(int _rub, int _cop)
{
	rub = _rub;
	if (_cop >= 100)
	{
		rub += _cop / 100;
		cop = _cop % 100;
	}
	else
		if ((_cop < 0) && (_rub > 0))
		{
			rub -= abs(_cop) / 100;
			cop = abs(_cop) % 100;
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
	double e = 3;
	while (e != 0)
	{
		Money a;
		cin >> a;
		Money b = 45.29;
		cout << a << " " << b << " " << (a < b) << " " << (a - b) << " " << (a + b) << endl;
		cin >> e;
	}
	return 0;
}
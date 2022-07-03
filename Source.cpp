#include <iostream>
using namespace std;

class Drob
{
private:
	int numerator, denominator;
public:
	Drob();
	Drob(int, int);
	Drob(const Drob&);

	Drob operator+(Drob other) { return Drob(numerator * other.denominator + other.numerator * denominator, denominator * other.denominator); }
	Drob operator-(Drob other) { return Drob(numerator * other.denominator - other.numerator * denominator, denominator * other.denominator); }
	Drob operator*(Drob other) { return Drob(numerator * other.numerator, denominator * other.denominator); }
	Drob operator/(Drob other) { return Drob(numerator * other.denominator, denominator * other.numerator); }

	friend ostream& operator<<(std::ostream& os, const Drob& drob) { return os << drob.numerator << "/" << drob.denominator; }
	friend istream& operator>>(std::istream& is, Drob& drob) { return is >> drob.numerator >> drob.denominator; }
};

Drob::Drob()
{
	numerator = 0;
	denominator = 1;
}

Drob::Drob(int num, int denom)
{
	int a = 1;
	for (int i = 1; i <= num; i++)
		if ((num % i == 0) && (denom % i == 0))
			a = i;
	numerator = num / a;
	denominator = denom / a;
}

Drob::Drob(const Drob& other)
{
	numerator = other.numerator;
	denominator = other.denominator;
}

int main()
{
	Drob a;
	cin >> a;
	Drob b = Drob(5, 10);
	cout << a << " " << b << " " << (a - b) << " " << (a / b);
}
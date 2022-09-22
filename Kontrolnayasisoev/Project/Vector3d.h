#include <iostream>
class Vector3d
{
private:
	double x, y, z;
public:
	Vector3d();
	Vector3d(double, double, double);
	Vector3d(const Vector3d&);

	Vector3d operator=(const Vector3d&);
	Vector3d operator+(const Vector3d&);
	Vector3d operator-(const Vector3d&);
	Vector3d operator*(const Vector3d&);
	Vector3d operator*(const double&);
	bool operator>(const Vector3d&);
	bool operator<(const Vector3d&);
	bool operator==(const Vector3d&);
	friend std::ostream& operator<<(std::ostream&, const Vector3d&);
	friend std::istream& operator>>(std::istream&, Vector3d&);
};


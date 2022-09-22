#include "Vector3d.h"

Vector3d::Vector3d()
{
	x = y = z = 0;
}

Vector3d::Vector3d(double _x, double _y, double _z)
{
	x = _x;
	y = _y;
	z = _z;
}

Vector3d::Vector3d(const Vector3d& vector2)
{
	x = vector2.x;
	y = vector2.y;
	z = vector2.z;
}

Vector3d Vector3d::operator=(const Vector3d& vector2)
{
	if (this == &vector2)
		return *this;
	else
	{
		return Vector3d(vector2);
	}
}

Vector3d Vector3d::operator+(const Vector3d& vector2)
{
	return Vector3d(this->x + vector2.x, this->y + vector2.y, this->z + vector2.z);
}

Vector3d Vector3d::operator-(const Vector3d& vector2)
{
	return Vector3d(this->x - vector2.x, this->y - vector2.y, this->z - vector2.z);
}

Vector3d Vector3d::operator*(const Vector3d& vector2)
{
	return Vector3d(this->x * vector2.x, this->y * vector2.y, this->z * vector2.z);
}

Vector3d Vector3d::operator*(const double& num)
{
	return Vector3d(this->x * num, this->y * num, this->z * num);
}

bool Vector3d::operator>(const Vector3d& vector2)
{
	if (std::sqrt(this->x * this->x + this->y * this->y + this->z * this->z) > std::sqrt(vector2.x * vector2.x + vector2.y * vector2.y + vector2.z * vector2.z))
		return 1;
	else
		return 0;
}

bool Vector3d::operator<(const Vector3d& vector2)
{
	if (std::sqrt(this->x * this->x + this->y * this->y + this->z * this->z) < std::sqrt(vector2.x * vector2.x + vector2.y * vector2.y + vector2.z * vector2.z))
		return 1;
	else
		return 0;
}

bool Vector3d::operator==(const Vector3d& vector2)
{
	if (std::sqrt(this->x * this->x + this->y * this->y + this->z * this->z) == std::sqrt(vector2.x * vector2.x + vector2.y * vector2.y + vector2.z * vector2.z))
		return 1;
	else
		return 0;
}

std::ostream& operator<<(std::ostream& os, const Vector3d& vector2)
{
	return os << "x = " << vector2.x << std::endl << "y = " << vector2.y << std::endl << "z = " << vector2.z << std::endl;
}

std::istream& operator>>(std::istream& is, Vector3d& vector2)
{
	return is >> vector2.x >> vector2.y >> vector2.z;
}
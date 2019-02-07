#include <iostream>
#include<iomanip>
using namespace std;
 
class MyComplex
{
private:
	double x, y;
public:
	double getx()const {
		return x;
	}
	double gety()const {
		return y;
	}
	MyComplex();
	MyComplex(double tmp1, double tmp2);
	const MyComplex operator=(MyComplex& one);
	const MyComplex operator+(const MyComplex& one)const;
	const MyComplex operator-(const MyComplex& one)const;
	const MyComplex operator*(const MyComplex& one)const;
	const MyComplex operator/(const MyComplex& one)const;
	MyComplex operator+=(MyComplex& one);
	MyComplex operator-=(MyComplex& one);
	MyComplex operator*=(MyComplex& one);
	MyComplex operator/=(MyComplex& one);
	friend istream& operator >>(istream& inputStream, MyComplex& one);
	friend ostream& operator <<(ostream& outputStream, MyComplex& one);
};
 
istream& operator >>(istream& inputStream, MyComplex& one)
{
	double a, b;
	inputStream >> a >> b;
	one.x = a, one.y = b;
	return inputStream;
}
 
ostream& operator <<(ostream& outputStream, const MyComplex& one)
{
	double a = one.getx(), b = one.gety();
	outputStream << setiosflags(ios::fixed) << setprecision(2);
	outputStream << a << " " << b;
	return outputStream;
}
 
const MyComplex MyComplex::operator=(MyComplex& one)
{
	x = one.x;
	y = one.y;
	return *this;
}
 
MyComplex::MyComplex()
	:x(0), y(0)
{
}
 
MyComplex::MyComplex(double tmp1, double tmp2)
	: x(tmp1), y(tmp2)
{
}
 
const MyComplex MyComplex::operator+(const MyComplex& one)const
{
	double tmp1 = x + one.x, tmp2 = y + one.y;
	return MyComplex(tmp1, tmp2);
}
 
const MyComplex MyComplex::operator-(const MyComplex& one)const
{
	double tmp1 = x - one.x, tmp2 = y - one.y;
	return MyComplex(tmp1, tmp2);
}
 
const MyComplex MyComplex::operator*(const MyComplex& one)const
{
	double a = x, b = y, c = one.x, d = one.y;
	return MyComplex(a*c - b * d, a*d + b * c);
}
 
const MyComplex MyComplex::operator/(const MyComplex& one)const
{
	double a = x, b = y, c = one.x, d = one.y;
	return MyComplex((a*c + b * d) / (c*c + d * d), (b*c - a * d) / (c*c + d * d));
}
 
MyComplex MyComplex::operator+=(MyComplex& one)
{
	x = x + one.x, y = y + one.y;
	return *this;
}
 
MyComplex MyComplex::operator-=(MyComplex& one)
{
	x = x - one.x, y = y - one.y;
	return *this;
}
 
MyComplex MyComplex::operator*=(MyComplex& one)
{
	double a = x, b = y, c = one.x, d = one.y;
	x = a * c - b * d, y = a * d + b * c;
	return *this;
}
 
MyComplex MyComplex::operator/=(MyComplex& one)
{
	double a = x, b = y, c = one.x, d = one.y;
	x = (a*c + b * d) / (c*c + d * d), y = (b*c - a * d) / (c*c + d * d);
	return *this;
}
 
int main()
{
	MyComplex z1;
	MyComplex z2;
 
	cin >> z1 >> z2;
 
	cout << (z1 + z2) << endl;
	cout << z1 - z2 << endl;
	cout << z1 * z2 << endl;
	cout << z1 / z2 << endl;
	cout << (z1 += z2) << endl;
	cout << (z1 -= z2) << endl;
	cout << (z1 *= z2) << endl;
	cout << (z1 /= z2) << endl;
 
 
	return 0;
}

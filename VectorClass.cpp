#include "header.h"
class Vector {
	double x;
	double y;
public:
	Vector(double a = 0, double b = 0) :x(a), y(b) {} // conversion constructor. 
	//If I add explicit then you can't add Vector to scalar.
	double x1() const { return x; }
	double y1() const { return y; }
	void print()const { cout << "{" << x << "," << y << "}"; }
	// this is inclass operator. Only one argument.
	Vector operator/(const Vector&a) const { return Vector(a.x1() + x, a.y1() + y); }
	Vector operator-(void) const { return Vector(-x, -y); } // zero argument 

	void operator<< (const Vector a) const { // so this must be vector << vector
		print();
		cout << " + ";
		a.print();
	}
	//ostream& operator<<(ostream& os) const // this. The order must be obj << (ostream obj).
	//{
	//	return os << "(" << x << "," << y << ")";
	//}
	const Vector& operator+=(const Vector& b) { // return by const reference. so things like
		// (r1+=r2)=r3; is not allowed (i.e.r1=r3), but r1+=r2;r1=r3; is allowed
		x += b.x; // other vectors private members can be used here
		y += b.y;
		return *this;
	}
	const Vector& operator= (const Vector& b) { x = b.x; y = b.y; return*this; }
	//In const reference a=b=c is allowed, which is actually a=(b=c), but (a=b)=c is not.
	double operator[](int j) const // can only read r[i] values.
	{
		switch (j)
		{
		default:
			cerr << "Out of bound!" << endl;
		case 0:
			return x;
		case 1:
			return y;
		}
	}
	double& operator[](int j) // can read or write r[i] values. 
	//if you make it const mem func then there'll be const double to ref double, which is not allowed.
	{
		switch (j)
		{
		default:
			cerr << "Out of bound!" << endl;
		case 0:
			return x;
		case 1:
			return y;
		}
	}

	Vector& operator++() { ++x; ++y; return *this; } //++Vec return vec(++x,++y)
	Vector operator++(int) //vec++" " return vec(x,y) but x++ and y++.
	{
		Vector temp(x, y);
		x++; y++; return temp;
	}
};

//template <class C> C operator+(const C& a, const C& b) { // template for + operator
//	return Vector(a.x1() + b.x1(), a.y1() + b.y1());
//}
// Vector+scalar and scalar+Vector also works in this particular function. Doesn't work in above func,
// doesn't work in inclass func.
Vector operator+(const Vector&a, const Vector& b) { return Vector(a.x1() + b.x1(), a.y1() + b.y1()); }
Vector operator*(const Vector&a, const Vector&b) { // the precedence order is still unchanged, 
	// so first * then +
	return Vector(a.x1()*b.x1(), a.y1()*b.y1());
}

Vector operator-(const Vector&a) { // 1 argument
	return Vector(-a.x1(), -a.y1());
}

ostream& operator<<(ostream& os, const Vector& a) { return os << "(" << a[0] << "," << a[1] << ")"; }

int main()
{
	Vector r1(4, 5), r2(3, 3), r3(2, 2);

	system("pause");
	return 0;
}
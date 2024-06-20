#include<iostream>
using namespace std;

using std::cin;
using std::cout;
using std::endl;
#define delimiter "--------------------------------"
class Fraction {
	int integer;
	int numerator;
	int denominator;

public:
	int get_integer()const {
		return integer;
	}
	int get_numerator()const {
		return numerator;
	}
	int get_denominator()const {
		return denominator;
	}
	void set_integer(int integer) {
		this->integer = integer;
	}
	void set_numerator(int numerator) {
		this->numerator = numerator;
	}
	void set_denominator(int denominator) {
		this->denominator = denominator;
	}
	//		Constructor
	Fraction()
	{
		integer = 0;
		numerator = 0;
		set_denominator(1);
		cout << "DefaultConstructor:\t" << this << endl;
	}
	Fraction(int integer) {
		this->integer = integer;
		this->numerator = 0;
		set_denominator(1);
		cout << "SingleArgumentConstructor: " << this << endl;
	}
	Fraction(double decimal) {
		decimal += 1e-10;
		integer = decimal;
		decimal -= integer;
		denominator = 1e+9;
		numerator = decimal * denominator;
		reduce();
	}
	Fraction(int numerator, int denominator) {
		this->integer = 0;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << "TwoArgumentConstructor: " << this << endl;
	}
	Fraction(int integer, int numerator, int denominator = 1) {
		set_integer(integer);
		set_numerator(numerator);
		set_denominator(denominator);
		cout << "ThreeArgumentConstructor:\t\t" << this << endl;
	}

	Fraction(const Fraction& other) {
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:\t" << this << endl;
	}

	~Fraction()
	{
		cout << "Destructor: \t\t" << this << endl;
	}
	//		Operators
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}
	Fraction& operator++()
	{
		this->integer++;
		return *this;
	}
	Fraction operator++(int)
	{
		Fraction old = *this;
		integer++;
		return old;
	}
	Fraction& operator--()
	{
		this->integer--;
		return *this;
	}
	Fraction operator--(int)
	{
		Fraction old = *this;
		integer--;
		return old;
	}
	//		Methods
	Fraction& to_improper() {
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	Fraction& to_proper() {
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	Fraction inverted()const
	{
		Fraction inverted = *this;
		inverted.to_improper();
		swap(inverted.numerator, inverted.denominator);
		return inverted;
	}
	Fraction& reduce()
	{
		int more, less, rest;
		if (numerator > denominator)more = numerator, less = denominator;
		else less = numerator, more = denominator;
		do
		{
			rest = more % less;
			more = less;
			less = rest;
		} while (rest);
		int GCD = more;	//GCD - Greatest Common Divisor
		numerator /= GCD;
		denominator /= GCD;
		return *this;
	}
	double quotient() {
		to_improper();
		return (numerator / denominator);
	}
	void print()const {
		if (integer)cout << integer;
		if (numerator) {
			if (integer)cout << "(";
			cout << numerator << "/" << denominator;
			if (integer) cout << ")";
		}
		else if (integer == 0)cout << 0;
		cout << endl;
	}
};

//#define CONSTRUCTORS_CHECK
//#define ARITHMETICAL_OPERATORS_CHECK
//#define INPUT_OUTPUT_CHECK
//#define COMPARISON_CHECK
#define CONVERSIONS_HOMEWORK

//	Arithmetical operators

Fraction operator*(Fraction& left, Fraction& right)
{
	left.to_improper();
	right.to_improper();
	Fraction result;
	result.set_numerator(left.get_numerator() * right.get_numerator());
	result.set_denominator(left.get_denominator() * right.get_denominator());
	return result.to_proper();
}
Fraction operator/(Fraction& left, Fraction& right)
{
	left.to_improper();
	right.to_improper();
	Fraction result;
	result.set_numerator(left.get_numerator() * right.get_denominator());
	result.set_denominator(left.get_denominator() * right.get_numerator());
	return result.to_proper();
}
Fraction operator+(Fraction& left, Fraction& right)
{
	left.to_improper();
	right.to_improper();
	Fraction result;
	result.set_numerator((left.get_numerator()*right.get_denominator()) + (right.get_numerator() * left.get_denominator()));
	result.set_denominator(left.get_denominator() * right.get_denominator());
	return result.to_proper();
}
Fraction operator-(Fraction& left, Fraction& right)
{
	left.to_improper();
	right.to_improper();
	Fraction result;
	result.set_numerator(left.get_numerator() * right.get_numerator());
	result.set_denominator(left.get_denominator() * right.get_denominator());
	return result.to_proper();
}

//		Comparison Operators

bool operator==(Fraction left, Fraction right) {
	left.to_improper();
	right.to_improper();
	return left.quotient() == right.quotient();
}
bool operator!=(const Fraction& left, const Fraction& right) {
	return !(left == right);
}
bool operator>( Fraction left,  Fraction right) {
	return left.quotient() > right.quotient();
}
bool operator<( Fraction left,  Fraction right) {
	return left.quotient() < right.quotient();
}
bool operator>=(const Fraction& left, const Fraction& right) {
	return !(left < right);
}
bool operator<=(const Fraction& left, const Fraction& right) {
	return !(left > right);
}

//		Output and input operators
std::ostream& operator<<(std::ostream& os, const Fraction& obj) {
	if (obj.get_integer() && obj.get_numerator()) return os << obj.get_integer() << "(" << obj.get_numerator() << "/" << obj.get_denominator() << ")" << endl;
	if (obj.get_numerator()) {
		if (obj.get_integer())return os <<  obj.get_numerator() << "/" << obj.get_denominator();
	}
	else if (obj.get_integer() == 0) return os << 0 << endl;
}

std::istream& operator>>(std::istream& in, Fraction& obj) {

	int n;
	cout << "Введите целую часть: ";  in >> n; cout << endl;
	obj.set_integer(n);
	cout << "Введите числитель: ";  in >> n; cout << endl;
	obj.set_numerator(n);
	cout << "Введите знаменатель: ";  in >> n; cout << endl;
	obj.set_denominator(n);
	obj.to_proper();
	return in;
}




void main() {
	setlocale(LC_ALL, "");

#ifdef CONSTRUCTORS_CHECK
	cout << delimiter << endl;
	Fraction A;
	Fraction B(2);
	Fraction C(3, 4);
	Fraction D(3, 6, 2);
	Fraction E(D);
	A.print();
	cout << delimiter << endl;
	B.print();
	cout << delimiter << endl;
	C.print();
	cout << delimiter << endl;
	D.print();
	cout << delimiter << endl;
	E.print();
	cout << delimiter << endl;
	cout << endl;

#endif // CONSTRUCTORS_CHECK
	
#ifdef ARITHMETICAL_OPERATORS_CHECK
	Fraction F(7, 3, 2);
	Fraction G(2, 5, 1);
	cout << delimiter << endl;
	F++;
	F.print();
	cout << delimiter << endl;
	F--;
	F.print();
	cout << delimiter << endl;
	++F;
	F.print();
	cout << delimiter << endl;
	--F;
	F.print();
	cout << delimiter << endl;
	Fraction H;
	H = F * G;
	H.print();
	cout << delimiter << endl;
	H = F / G;
	H.print();
	cout << delimiter << endl;
	H = F - G;
	H.print();
	cout << delimiter << endl;
	H = F + G;
	H.print();
	cout << delimiter << endl;
	cout << endl;

#endif // ARITHMETICAL_OPERATORS_CHECK
	
#ifdef INPUT_OUTPUT_CHECK
	Fraction I(6, 2, 1);
	cout << delimiter << endl;
	cout << I;
	cout << delimiter << endl;
	cin >> I;
	I.print();
	cout << delimiter << endl;
	cout << I;
	cout << delimiter << endl;
	cout << endl;
#endif // INPUT_OUTPUT_CHECK
#ifdef COMPARISON_CHECK
	cout << delimiter << endl;
	cout << (Fraction(2, 6, 2) == Fraction(3, 6, 5)) << endl;
	cout << delimiter << endl;
	cout << (Fraction(2, 6, 2) != Fraction(3, 6, 5)) << endl;
	cout << delimiter << endl;
	cout << (Fraction(2, 6, 2) > Fraction(3, 6, 5)) << endl;
	cout << delimiter << endl;
	cout << (Fraction(2, 6, 2) < Fraction(3, 6, 5)) << endl;
	cout << delimiter << endl;
	cout << (Fraction(2, 6, 2) >= Fraction(3, 6, 5)) << endl;
	cout << delimiter << endl;
	cout << (Fraction(2, 6, 2) <= Fraction(3, 6, 5)) << endl;
	cout << delimiter << endl;
#endif // COMPARISON_CHECK
	Fraction A = 3.33;
	cout << A << endl;



}
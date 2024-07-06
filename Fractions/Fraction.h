#pragma once
using namespace std;

using std::cin;

using std::cout;

using std::endl;

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
	//		Type-cast operators
	explicit operator int() {

		return to_proper().integer;
	}
	explicit operator double() {
		return ((integer * denominator) + numerator) / double(denominator);
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
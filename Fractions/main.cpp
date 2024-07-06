#include<iostream>
#include"Fraction.h"
using namespace std;

using std::cin;
using std::cout;
using std::endl;
#define delimiter "--------------------------------"


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
	Fraction A(3, 4, 5);
	double da = double(A);
	cout << da << endl;


}
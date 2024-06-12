#include<iostream>
using namespace std;

using std::cin;
using std::cout;
using std::endl;
#define delimiter "--------------------------------"
class Fraction {
	double dividend;
	double divider;

public:
	double get_dividend()const {
		return dividend;
	}
	double get_divider()const {
		return divider;
	}

	void set_dividend(double dividend) {
		this->dividend = dividend;
	}
	void set_divider(double divider) {
		this->divider = divider;
	}
	//		Constructor
	Fraction()
	{
		dividend = divider = 0;
		cout << "DefaultConstructor:\t" << this << endl;
	}

	Fraction(double dividend, double divider) {
		this->dividend = dividend;
		this->divider = divider;
		cout << "Constructor:\t" << this << endl;
	}

	Fraction(const Fraction& other) {
		this->dividend = other.dividend;
		this->divider = other.divider;
		cout << "CopyConstructor:\t" << this << endl;
	}

	~Fraction()
	{
		cout << "Destructor: \t\t" << this << endl;
	}

	//		Methods
	double quotient() {
		return dividend / divider;
	}
};




void main() {
	setlocale(LC_ALL, "");
	cout << delimiter << endl;
	Fraction A(2, 3);
	cout << A.get_dividend() << " / " << A.get_divider() << " = " << A.quotient() << endl;
	cout << delimiter << endl;
	A.set_dividend(5);
	A.set_divider(7);
	cout << A.get_dividend() << " / " << A.get_divider() << " = " << A.quotient() << endl;
	cout << delimiter << endl;
}
#include<iostream>
using namespace std;

class Point
{
	double x;
	double y;
	// Incapsulation:
	public:
	double get_x()const {
		return x;
	}
	double get_y()const {
		return y;
	}
	void set_x(double x) {
		this->x = x;
	}
	void set_y(double y) {
		this->y = y;
	}
	//	Constructors:
	Point() 
	{
		x = y = 0;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	Point(double x) {
		this->x = x;
		this->y = 0;
		cout << "1ArgConstructor:\t" << this << endl;
	}
	Point(double x, double y) {
		this->x = x;
		this->y = y;
		cout << "2ArgConstructor:\t" << this << endl;
	}
	~Point() 
	{
		cout << "Destructor: \t\t" << this << endl;
	}

	// Methods:

	double distance(Point other) {
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distance;
	}

	void print()const {
		cout << "X = " << x << "\t Y = " << y << endl;
	}
};

double Distance(const Point& A, const Point& B) {
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	return sqrt(x_distance * x_distance + y_distance * y_distance);
}

void main() {
	setlocale(LC_ALL, "");

	Point A;
	//A.set_x(2);
	//A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y() << endl;
	A.print();

	Point B = 5; //1ArgumentConstructor
	B.print();
	Point C(2, 3); //2ArgumentConstructor
	C.print();
	cout << A.distance(C) << endl;
	cout << Distance(B, C) << endl;
}


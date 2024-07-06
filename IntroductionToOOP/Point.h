#pragma once

using namespace std;

using std::cin;

using std::cout;

using std::endl;

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
		cout << "Constructor:\t" << this << endl;
	}

	Point(const Point& other) {
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:\t" << this << endl;
	}

	~Point()
	{
		cout << "Destructor: \t\t" << this << endl;
	}

	//	Operators;
	Point& operator=(const Point& other) {
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}
	Point& operator++() {
		x++;
		y++;
		return *this;
	}

	Point operator++(int) {
		Point old = *this;
		x++;
		y++;
		return old;
	}



	// Methods:

	double distance(Point& other)const {
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		//this->x *= 10;
		return distance;
	}

	void print()const {
		cout << "X = " << x << "\t Y = " << y << endl;
	}
};
#include<iostream>
using namespace std;

template<typename T> void PrintDistance(T a, T b);
template<typename T> void PrintDistance(T a, T b);

class Point
{
public:
	double x;
	double y;
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
	double distance(Point other) {
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distance;
	}
	void print()const {
		cout << "X = " << x << "\tY = " << y << endl;
	}
};

void main() {
	double my_point = -28;
	Point A;
	A.set_x(5);
	A.set_y(2);
	PrintDistance(A.x, A.y);
}

template<typename T> void PrintDistance(T a, T b) {
	T distance = a > b? a - b: b - a;
	cout << distance;
}
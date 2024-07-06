#include<iostream>
#include"Point.h"
using namespace std;

using std::cin;

using std::cout;

using std::endl;
#define delimiter "\n--------------------------------------\n"


double distance(const Point& A, const Point& B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance*x_distance + y_distance * y_distance);
	return distance;
}

Point operator+(const Point& left, const Point& right) {
	Point result;
	result.set_x(left.get_x() + right.get_x());
	result.set_y(left.get_y() + right.get_y());
	return result;
}
Point operator-(const Point& left, const Point& right) {
	Point result;
	result.set_x(left.get_x() - right.get_x());
	result.set_y(left.get_y() - right.get_y());
	return result;
}
Point operator*(const Point& left, const Point& right) {
	Point result;
	result.set_x(left.get_x() * right.get_x());
	result.set_y(left.get_y() * right.get_y());
	return result;
}
Point operator/(const Point& left, const Point& right) {
	Point result;
	result.set_x(left.get_x() / right.get_x());
	result.set_y(left.get_y() / right.get_y());
	return result;
}
bool operator==(const Point& left, const Point& right) {
	return left.get_x() == right.get_x() && left.get_y() == right.get_y();
}
std::ostream& operator<<(std::ostream& os, const Point& obj) {
	return os << "X = " << obj.get_x() << "\tY = " << obj.get_y();
}
//#define CONSTRUCTORS_CHECK
//#define DISTANCE_CHECK
//#define ASSIGNMENT_CHECK
//#define ARITHMETICAL_OPERATORS_CHECK
//#define COMPARISON_OPERATORS_CHECK

void main() {
	setlocale(LC_ALL, "");

#ifdef CONSTRUCTORS_CHECK
	Point A;
	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y() << endl;
	A.print();

	Point B = 5; //1ArgumentConstructor
	B.print();
	Point C(2, 3); //2ArgumentConstructor
	C.print();
	Point D = C;
	D.print();
	
	Point E;
	E = D;
	E.print();
#endif // CONSTRUCTORS_CHECK
#ifdef DISTANCE_CHECK

	Point A(2, 3);
	Point B(7, 8);

	A.print();
	B.print();

	cout << delimiter << endl;
	cout << "Расстояние от точки 'A' до точки 'B':" <<  A.distance(B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние от точки 'B' до точки 'A':" << B.distance(A) << endl;
	cout << delimiter << endl;
	cout << "Расстояние между точками 'A' до точки 'B':" << distance(A, B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние между точками 'B' до точки 'A':" << distance(B, A) << endl;
	cout << delimiter << endl;
#endif // DISTANCE_CHECK
#ifdef ASSIGNMENT_CHECK
	Point A, B, C;
	cout << delimiter << endl;
	A = B = C = Point(2, 3);		//Point(2,3) - явно вызываем конструктор\
									//и создаём временный безымянный объект,\
									//этот объект и передаётся как параметр\
									//в первый CopyAssignment.
	cout << delimiter << endl;
	A.print();
	B.print();
	C.print();
#endif // ASSIGNMENT_CHECK
#ifdef ARITHMETICAL_OPERATORS_CHECK
	Point A(2, 3);
	A.print();
	Point B(7, 8);
	B.print();
	Point C = A + B;
	C.print();
	Point D = C++;
	C.print();
	D.print();
#endif // ARITHMETICAL_OPERATORS_CHECK
#ifdef COMPARISON_OPERATORS_CHECK
	Point A(2, 3);
	Point B(2, 3);
	cout << (A == B) << endl;
#endif // COMPARISON_OPERATORS_CHECK
	Point A(2, 3);
	cout << A << endl;
}


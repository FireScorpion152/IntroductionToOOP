#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;
#define delimiter "\n--------------------------------------\n"
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

double distance(const Point& A, const Point& B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance*x_distance + y_distance * y_distance);
	return distance;
}
//#define CONSTRUCTORS_CHECK
//#define DISTANCE_CHECK
#define ASSIGNMENT_CHECK
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
									и создаём временный безымянный объект,\
									этот объект и передаётся как параметр\
									в первый CopyAssignment.
	cout << delimiter << endl;
	A.print();
	B.print();
	C.print();
#endif // ASSIGNMENT_CHECK


}


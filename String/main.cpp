#include<iostream>
using namespace std;

#define delimiter "\n--------------------------------------------------------------------\n"

class String
{
	int size;
	char* str;
public:
	int get_size()const
	{
		return size;
	}
	const char* get_str()const
	{
		return str;
	}
	char* get_str()
	{
		return str;
	}

	//				Constructors:
	explicit String(int size = 80) :size(size), str(new char[size] {})
	{
		//this->size = size;
		//this->str = new char[size] {};
		cout << "Constructor:\t" << this << endl;
	}
	String(const char str[]) :String(strlen(str) + 1)
	{
		//this->size = strlen(str) + 1;
		//Функция strlen() возвращает размер строки в символах,
		//и нам нужно добавить еще один Байт для NULL-Terminator-а
		//this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = str[i];
		cout << "Constructor:\t" << this << endl;
	}
	String(const String& other) :String(other.str)
	{
		//Deep copy (Побитовое копирование):
		//this->size = other.size;
		//this->str = new char[size] {};
		//for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyConstructor:" << this << endl;
	}
	String(String&& other)noexcept :size(other.size), str(other.str)//r-value reference
	{
		//Shallow copy:
		//this->size = other.size;
		//this->str = other.str;	//Shallow copy

		//Reset other:
		other.size = 0;
		other.str = nullptr;
		cout << "MoveConstructor:" << this << endl;
	}
	~String()
	{
		delete[] str;
		cout << "Destructor:\t" << this << endl;
	}


	//				 Operators:
	String& operator=(const String& other)
	{
		delete[] this->str;
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}
	String& operator=(String&& other) noexcept
	{
		if (this == &other) return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = other.str;
		other.size = 0;
		other.str = nullptr;
		cout << "MoveAssignment:\t" << this << endl;
		return *this;
	}
	char& operator[](int i)
	{
		return str[i];
	}
	const char& operator[](int i)const
	{
		return str[i];
	}

	//				  Methods:
	void print()const
	{
		cout << "Obj:\t\t" << this << endl;
		cout << "Size:\t\t" << size << endl;
		cout << "Addr:\t\t" << &str << endl;
		cout << "Str:\t\t" << str << endl;
		cout << delimiter << endl;
	}
};
String operator+(const String& left, const String& right)
{
	cout << "Operator + " << endl;
	String buffer(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
	{
		buffer[i] = left[i];
	}
	for (int i = 0; i < right.get_size(); i++)
	{
		buffer[i + left.get_size() - 1] = right[i];
	}
	return buffer;
}
std::ostream& operator<<(std::ostream& os, const String& obj) {
	return os << obj.get_str();
}
//#define CLASSWORK
//#define PLUS_OPERATOR_CHECK
//#define MOVE_ASSIGNMENT_CHECK
#define CALLING_CONSTRUCTORS
void main() {
	setlocale(LC_ALL, "");

#ifdef CLASSWORK
	String str1;
	str1.print();
	cout << delimiter << endl;

	String str2(8);
	str2.print();
	cout << delimiter << endl;

	String str3 = "Hello";
	str3.print();
	cout << delimiter << endl;

	String str4 = "World";
	cout << "String: " << str4 << endl;
	cout << str4.get_size();
	cout << delimiter << endl;
#endif // CLASSWORK


#ifdef PLUS_OPERATOR_CHECK
	str4 = str3 + str4;
	cout << str4 << endl;
	cout << delimiter << endl;

#endif // PLUS_OPERATOR_CHECK

#ifdef MOVE_ASSIGNMENT_CHECK
	String str5;
	str5 = move(str4);
	cout << str5 << endl;
	cout << delimiter << endl;
#endif // MOVE_ASSIGNMENT_CHECK
#ifdef CALLING_CONSTRUCTORS
	String str1;
	str1.print();
	cout << delimiter << endl;
	String str2(8);
	str2.print();
	cout << delimiter << endl;
	String str3 = "Hello";
	str3.print();
	cout << delimiter << endl;
	String str4{};
	str4.print();
	cout << delimiter << endl;
	String str6{ str3 };
	str6.print();
#endif // CALLING_CONSTRUCTORS


}
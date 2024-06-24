#define _CRT_SECURE_NO_WARNINGS
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
	char* get_str()const
	{
		return str;
	}
	void set_size(int size)
	{
		this->size = size;
	}

	//				Constructors:
	String()
	{
		this->size = 80;
		this->str = new char[size] {};
		cout << "DefaultConstructor:\t" << this << endl;
	}
	String(int size)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "1ArgConstructor:\t" << this << endl;
	}
	String(const char* other)
	{
		size = strlen(other) + 1;
		str = new char[size] {};
		strcpy(str, other);
		cout << "Constructor:\t\t" << this << endl;
	}
	String(const String& other)
	{
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
		{
			this->str[i] = other.str[i];
		}
		cout << "CopyConstructor:\t" << this << endl;
	}
	~String()
	{
		delete[] str;
		cout << "Destructor:\t\t" << this << endl;
	}

	//				 Operators:
	String& operator=(const String& other)
	{
		delete[] this->str;
		this->size = other.get_size();
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}

	//				  Methods:
	void print()const
	{
		cout << "String:\t" << str << endl;
		cout << "Size:\t" << size << endl;
	}
};

String operator+(const String& left, const String& right)
{
	String buffer = left.get_size() + right.get_size() - 1;
	for (int i = 0; i < left.get_size(); i++)
	{
		buffer.get_str()[i] = left.get_str()[i];
	}
	for (int i = 0; i < right.get_size(); i++)
	{
		buffer.get_str()[i + left.get_size() - 1] = right.get_str()[i];
	}
	return buffer;
}

std::ostream& operator<<(std::ostream& os, const String& obj) {
	return os << obj.get_str();
}

void main(){
	setlocale(LC_ALL, "");

	String str1;
	str1.print();
	cout << delimiter << endl;

	String str2(8);
	str2.print();
	cout << delimiter << endl;

	String str3 = "Hello";
	str3 = String(str3);
	str3.print();
	cout << delimiter << endl;

	String str4 = "World";
	cout << "String: " << str4 << endl;
	cout << str4.get_size();
	cout << delimiter << endl;

	//str4 = str3;
	//str4.print();
	//cout << delimiter << endl;

	String str5;
	str5 = str3 + str4;		//Copy assignment
	str5.print();
	cout << str5 << endl;
}

//							The rule of five.
// Для предотвращения излишней издержки на копирование, нужно объявить все пять конструкторов для класса: Конструктор по умолчанию, конструктор копирования, конструктор перемещения, 
// конструктор оператора копирования, конструктор оператора перемещения.
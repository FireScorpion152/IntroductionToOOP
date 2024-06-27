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
	String(const char* str)
	{
		this->size = strlen(str) + 1;
		this->str = new char[size] {};
		for (int i = 0; str[i]; i++)
		{
			this->str[i] = str[i];
		}
		cout << "DefaultConstructor:\t" << this << endl;
	}
	explicit String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "1ArgConstructor:\t" << this << endl;
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
		this->size = 0;
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
		cout << "String:\t" << str << endl;
		cout << "Size:\t" << size << endl;
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
#define PLUS_OPERATOR_CHECK
#define MOVE_ASSIGNMENT_CHECK
void main(){
	setlocale(LC_ALL, "");

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


}